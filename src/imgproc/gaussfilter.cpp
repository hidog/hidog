#include "gaussfilter.h"


using namespace std;

#define MAX(A,B)   A>B ? A : B
#define MIN(A,B)   A<B ? A : B






/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	這邊放 GaussFilter 1D
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/


/*======================================================================================
	GaussFilter 1D
	建構函式
========================================================================================*/
GaussFilter1D::GaussFilter1D()
{}
GaussFilter1D::GaussFilter1D( int _scale )
{

	//if( _scale %2 == 0 )
	//	error_msg( "scale must be odd" );
	//if( _scale <= 0 )	error_msg( "scale must lager than 0");

	scale		=	_scale;
	mean		=	0;
	deviation	=	scale / sqrt( 3.0 );

	// 產生filter map
	generate_map();

}
GaussFilter1D::~GaussFilter1D()
{}









/*======================================================================================
	產生filter map
========================================================================================*/
void	GaussFilter1D::generate_map()
{
	int			i;//,	j;

	boost::math::normal		gauss( 0, deviation );


	/*
		deviation	=	scale / sqrt(3)
		搜尋範圍	=	deviation * sqrt(3)	=	scale
	*/
	filter_map.resize( 2*scale+1 );
	

	for( i = -scale; i<=scale; i++ )
		filter_map[ i+scale ]	=	pdf( gauss, i );


}




/*======================================================================================
	取 map 值用, 會自動將index 轉成 以 0 為中心  
	可以處理 -index ~ index
	並且做檢查index是否合理等等
========================================================================================*/
double&		GaussFilter1D::operator [] ( int index )
{
	//if( index < -scale || index > scale )	error_msg( "GaussFilter_1D [] out of range" );

	return	filter_map[ index + scale ];
}


/*======================================================================================
	取出Dog的Map
========================================================================================*/
double	GaussFilter1D::get_DoG( int index )
{
	int		k	=	2;
	int		scale2	=	k*scale;

	//if( index < -scale2 || index > scale2 )	error_msg("GaussFilter_1D::get_DoG");

	return	DoG[ index + scale2 ];
}


/*======================================================================================
	取 map 值用, 會自動將index 轉成 以 0 為中心  
	可以處理 -index ~ index
	並且做檢查index是否合理等等
========================================================================================*/
double&		GaussFilter1D::operator () ( int index )
{
	//if( index < -scale || index > scale )		error_msg( "GaussFilter_1D () out of range" );

	return	filter_map[ index + scale ];
}






/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	這邊放 GaussFilter 2D
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/










/*******************************************************************************
	conscturcot
********************************************************************************/
QImage	GaussFilter::do_filter( QImage passImage )
{
	const int	w	=	w_scale,	l	=	l_scale;
	
	const int	width	=	passImage.width();
	const int	height	=	passImage.height();

	QImage			img		=	passImage;								// 原始圖像
	bMatrixDouble	wmatrix( width, height );							// 存放橫向filter結果的圖像
	bMatrixDouble	lmatrix( width, height );							// 存放縱向filter結果的圖像   (最後的結果)

	int				i,	j,	x,	y;
	double			dsum;

	wmatrix.clear();
	lmatrix.clear();



	// 開始進行filter
	for(  i = 0;  i < width;  i++  )
	{



		for(  j = 0;  j < height;  j++ )
		{
			// 對每一個pixel的位置做橫向的filter
			dsum	=	0;
			for(  x = -w;  x <= w;  x++  )
			{
				if( i+x < 0 || i+x >= width )	continue;

				dsum	+=	filter_map_w( x+w ) * img.gray_channel( i+x, j );
			}
			wmatrix( i, j )	=	dsum;
		}
	}


	// 進行縱向的filter
	for( i = 0;  i < width;  i++  )
	{


		for( j = 0;  j < height;  j++ )
		{
			// 對wimg做縱向的filter
			dsum	=	0;
			for( y = -l;  y <= l;  y++ )
			{
				if(  j+y < 0 || j+y >= height )		continue;

				dsum	+=	filter_map_l( y+l ) * wmatrix( i, j+y );
			}
			lmatrix( i, j )	=	dsum;
		}
	}

	QImage	filter( width, height, QImage::Format_RGB888 );

	for( i = 0;  i < width;  i++  )
		for(  j = 0;  j < height;  j++  )
			filter.gray_channel( i, j, static_cast<int>( lmatrix(i,j) ) );



	//filter.save("filter1.bmp");

	return		filter;

	/*
	//int			i,	j,	x,	y;
	int			itmp;
	BYTE		tmp;
	//double		dsum,	sum;
	
	//const int	width	=	passImage.width();
	//const int	height	=	passImage.height();

	//dsum	=	new double[l];

	QImage	image222	=	passImage;
	QRgb	rgb;
	//int		r,	g,	b;
	int		gray;
	
#ifdef _OPENPIV_
	// 進度條控制
	if( progress != NULL )
		progress->setGress(0);
#endif

	for(     i = 0;       i < width;   i++    )
	{

#ifdef _OPENPIV_
		if( progress != NULL )
			progress->setGress( (i-w)*100/(width-2*w) );
#endif

		for(  j = 0;    j < height;     j++     )
		{

			// 針對此 pixel 做 filter
			dsum	=	0;

			for( x = -w;    x <= w;    x++  )
				for( y = -l;    y <= l;   y++  )
				{

					if( i+x < 0 || i+x >= width || j+y < 0 || j+y >= height )	continue;

					rgb		=	passImage.pixel( i+x, j+y );
					gray	=	qGray( rgb );
					dsum	+=	gray * get(x,y);
				}
			
			// 寫入資料 (避免影響到原本的資料)
			tmp		=	static_cast<BYTE>(dsum);
			rgb		=	qRgb( tmp, tmp, tmp );
			image222.setPixel( i, j, rgb );


		}
	}

	image222.save("filter2.bmp");

#ifdef _OPENPIV_
	if( progress != NULL )
		progress->setGress( 100 );
#endif

	//delete	[]	dsum;

	return	image222;*/
}





/*======================================================================================
	將圖檔讀進來, 做filter的動作
	(不做progress)
========================================================================================*/
QImage	GaussFilter::do_filter_no_progress( QImage passImage )
{
	const int	w	=	w_scale,	l	=	l_scale;

	const int	width	=	passImage.width();
	const int	height	=	passImage.height();

	QImage			img		=	passImage;								// 原始圖像
	bMatrixDouble	wmatrix( width, height );							// 存放橫向filter結果的圖像
	bMatrixDouble	lmatrix( width, height );							// 存放縱向filter結果的圖像   (最後的結果)

	int				i,	j,	x,	y;
	double			dsum;

	wmatrix.clear();
	lmatrix.clear();

	// 開始進行filter
	for(  i = 0;  i < width;  i++  )
	{
		for(  j = 0;  j < height;  j++ )
		{
			// 對每一個pixel的位置做橫向的filter
			dsum	=	0;
			for(  x = -w;  x <= w;  x++  )
			{
				if( i+x < 0 || i+x >= width )	continue;

				dsum	+=	filter_map_w( x+w ) * img.gray_channel( i+x, j );
			}
			wmatrix( i, j )	=	dsum;
		}
	}

	// 進行縱向的filter
	for( i = 0;  i < width;  i++  )
	{
		for( j = 0;  j < height;  j++ )
		{
			// 對wimg做縱向的filter
			dsum	=	0;
			for( y = -l;  y <= l;  y++ )
			{
				if(  j+y < 0 || j+y >= height )		continue;

				dsum	+=	filter_map_l( y+l ) * wmatrix( i, j+y );
			}
			lmatrix( i, j )	=	dsum;
		}
	}

	QImage	filter( width, height, QImage::Format_RGB888 );

	for( i = 0;  i < width;  i++  )
		for(  j = 0;  j < height;  j++  )
			filter.gray_channel( i, j, static_cast<int>( lmatrix(i,j) ) );

	return		filter;
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
GaussFilter::GaussFilter( int _w, int _l )
{
	w_scale		=	_w;
	l_scale		=	_l;

	// 
	generate_map();
}






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
	GaussFilter1D		gw( w ),	gl( l );
	filter_map.resize( w*2+1, l*2+1 );

	// generate filter map
	for( i = -w;   i <= w;   i++ )
		for(   j = -l;   j <= l;    j++  )
			filter_map(  i + w,  j + l  )	=	gw[i] * gl[j] ;

	// generate normalized coefficient.
	dsum	=	0;
	for( i = 0; i < filter_map.size1(); i++ )
		for( j = 0; j < filter_map.size2(); j++ )
			dsum	+=	filter_map( i, j );
	normalized	=	1.0 / dsum ;

	// normalized
	for( i = 0; i < filter_map.size1(); i++ )
		for( j = 0; j < filter_map.size2(); j++ )
			filter_map( i, j )	*=	normalized;

	

	// 產生橫向的filter
	filter_map_w.resize( 2*w + 1 );
	for(  i = -w;  i <= w;  i++ )
		filter_map_w( i+w )		=	gw[i];

	printf("\n\n\n");
	for(  i = 0;  i < (int)filter_map_w.size();  i++ )
		cout << filter_map_w(i) << " ";
	cout << endl;

	// normalized
	/*dsum	=	0;
	for(  i = 0;  i < filter_map_w.size();  i++  )
		dsum	+=	filter_map_w( i );
	normalized	=	1.0 / dsum;
	for(  i = 0; i < filter_map_w.size();  i++ )
		filter_map_w( i )	*=	normalized;*/

	// 產生縱向的filter
	filter_map_l.resize( 2*l + 1 );
	for( i = -l;  i <= l;  i++  )
		filter_map_l( i+l )		=	gl[i];

	// normalized
	/*dsum	=	0;
	for( i = 0;  i < filter_map_l.size();  i++ )
		dsum	+=	filter_map_l(i);
	normalized	=	1.0 / dsum;*/
	for( i = 0;  i < (int)filter_map_l.size();  i++ )
		filter_map_l(i)		*=	normalized;

	for(  i = 0;  i < (int)filter_map_l.size();  i++  )
		cout << filter_map_l(i) << " ";
	cout << endl;


	printf("\n\n");

	for( i = 0;  i < (int)filter_map.size1();  i++  )
	{
		for( j = 0; j < (int)filter_map.size2();  j++ )
			printf("%.3lf ", filter_map_w(i) * filter_map_l(j) );
		printf("\n");
	}

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


