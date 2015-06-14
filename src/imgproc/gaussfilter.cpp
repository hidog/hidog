#include "gaussfilter.h"

#include <boost/math/distributions/normal.hpp>


using namespace std;






/*******************************************************************************
	constructor
********************************************************************************/
GaussFilter1D::GaussFilter1D()
{
	scale		=	1;
	mean		=	0;
	deviation	=	1.0 * scale / sqrt(3.0);

	generate_map();
}


/*******************************************************************************
	constructor
********************************************************************************/
GaussFilter1D::GaussFilter1D( int s )
{
#ifdef _DEBUG
	if( s%2 == 0 )
		assert(false);
	if( s <= 0 )
		assert(false);
#endif

	scale		=	s;
	mean		=	0;
	deviation	=	1.0 * scale / sqrt( 3.0 );

	// 產生filter map
	generate_map();
}



/*******************************************************************************
	destructor
********************************************************************************/
GaussFilter1D::~GaussFilter1D()
{}




/*******************************************************************************
	set_scale
********************************************************************************/
void	GaussFilter1D::set_scale( int s )
{
#ifdef _DEBUG
	if( s%2 == 0 )
		assert(false);
	if( s <= 0 )
		assert(false);
#endif
	scale		=	s;
	mean		=	0;
	deviation	=	1.0 * scale / sqrt( 3.0 );

	// 產生filter map
	generate_map();
}



/*******************************************************************************
	generate_map
********************************************************************************/
void	GaussFilter1D::generate_map()
{
	boost::math::normal		gauss( mean, deviation );

	int			i;

	/*
		deviation		=	scale / sqrt(3)
		search range	=	deviation * sqrt(3)	=	scale
	*/
	filter_map.resize( 2*scale+1 );
	
	//
	for( i = -scale; i<=scale; i++ )
		filter_map( i+scale )	=	pdf( gauss, i );	// use boost gauss 
}



/*******************************************************************************
	operator (int) 
********************************************************************************/
double&		GaussFilter1D::operator () ( int index )
{
#ifdef _DEBUG
	if( index < -scale || index > scale )		
		assert(false);
#endif
	return	filter_map( index + scale );
}




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GaussFileter ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~





/*******************************************************************************
	operator(QImage)
********************************************************************************/
QImage	GaussFilter::operator () ( QImage input )
{
	const int	w	=	w_scale,
				l	=	l_scale;
	
	const int	width	=	input.width();
	const int	height	=	input.height();
							
	bMatrixDouble	w_red_mat( width, height ),			// 用橫向 縱向的filter來處理 加速用.
					w_green_mat( width, height ),
					w_blue_mat( width, height );
	bMatrixDouble	l_red_mat( width, height ),
					l_green_mat( width, height ),
					l_blue_mat( width, height );

	int				i,	j,	x,	y,	r,	g,	b;
	double			dsum_r,	dsum_g,	dsum_b;

	//  橫向的filter
	for(  i = 0;  i < width;  i++  )
		for(  j = 0;  j < height;  j++ )
		{
			// 對每一個pixel的位置做橫向的filter
			dsum_r	=	0;
			dsum_g	=	0;
			dsum_b	=	0;
			for(  x = -w;  x <= w;  x++  )
			{
				if( i+x < 0 || i+x >= width )	
					continue;
				dsum_r	+=	filter_w(x) * input.red_channel( i+x, j );
				dsum_g	+=	filter_w(x) * input.green_channel( i+x, j );
				dsum_b	+=	filter_w(x) * input.blue_channel( i+x, j );
			}
			w_red_mat(i,j)		=	dsum_r;
			w_green_mat(i,j)	=	dsum_g;
			w_blue_mat(i,j)		=	dsum_b;
		}

	// 進行縱向的filter
	for( i = 0;  i < width;  i++  )
		for( j = 0;  j < height;  j++ )
		{
			// 對wimg做縱向的filter
			dsum_r	=	0;
			dsum_g	=	0;
			dsum_b	=	0;
			for( y = -l;  y <= l;  y++ )
			{
				if(  j+y < 0 || j+y >= height )		
					continue;
				dsum_r	+=	filter_l(y) * input.red_channel( i, j+y );
				dsum_g	+=	filter_l(y) * input.green_channel( i, j+y );
				dsum_b	+=	filter_l(y) * input.blue_channel( i, j+y );
			}
			l_red_mat(i,j)		=	dsum_r;
			l_green_mat(i,j)	=	dsum_g;
			l_blue_mat(i,j)		=	dsum_b;
		}

	// result output
	QImage	&result	=	input;
	for( i = 0;  i < width;  i++  )
		for(  j = 0;  j < height;  j++  )
		{
			r	=	l_red_mat(i,j);
			g	=	l_green_mat(i,j);
			b	=	l_blue_mat(i,j);
			result.rgb_channel( i, j, r, g, b );
		}

	return		result;
}




/*******************************************************************************
	conscturcot
********************************************************************************/
GaussFilter::GaussFilter()
{
	w_scale	=	1;
	l_scale	=	1;

	//
	generate_map();
}


/*******************************************************************************
	conscturcot
********************************************************************************/
GaussFilter::GaussFilter( int w, int l )
{
	w_scale		=	w;
	l_scale		=	l;

	filter_w.set_scale(w);
	filter_l.set_scale(l);

	// 
	generate_map();
}

/*******************************************************************************
	destructor
********************************************************************************/
GaussFilter::~GaussFilter()
{}




/****************************************************************************************
	generate_map
*****************************************************************************************/
void	GaussFilter::generate_map()
{	
	const int	w	=	w_scale,
				l	=	l_scale;
	int			i,	j;
	double		dsum;
	double		normalized;

	// use gauss filter 1d to generate 2d filter.
	filter_map.resize( w*2+1, l*2+1 );

	// generate filter map
	for( i = -w;   i <= w;   i++ )
		for(   j = -l;   j <= l;    j++  )
			filter_map(  i + w,  j + l  )	=	filter_w(i) * filter_l(j) ;

	// generate normalized coefficient.
	dsum	=	0;
	for( i = 0; i < (int)filter_map.size1(); i++ )
		for( j = 0; j < (int)filter_map.size2(); j++ )
			dsum	+=	filter_map( i, j );
	normalized	=	1.0 / dsum ;

	// normalized
	for( i = 0; i < (int)filter_map.size1(); i++ )
		for( j = 0; j < (int)filter_map.size2(); j++ )
			filter_map( i, j )	*=	normalized;
}


/****************************************************************************************
	operator ()
*****************************************************************************************/
double&		GaussFilter::operator () ( int i, int j )
{
#ifdef _DEBUG
	if( i + w_scale < 0 || i + w_scale >= filter_map.size1() || j + l_scale < 0 || j + l_scale >= filter_map.size2() )
		assert(0);
#endif

	return		filter_map( i + w_scale,  j + l_scale  );
}
