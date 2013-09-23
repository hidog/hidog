#include "matrix.h"





namespace	hidog
{
namespace	numeric
{






/************************************************************************************************************
	constructor 
*************************************************************************************************************/
template<typename T>
matrix<T>::matrix()
{
	data		=	NULL;
	_width		=	0;
	_height		=	0;

}



/************************************************************************************************************
	constructor 
*************************************************************************************************************/
template<typename T>
matrix<T>::matrix( int _w, int _h )
{
	int		i;

	data		=	NULL;	// 為了檢查是否正確宣告動態記憶體

	_width		=	_w;
	_height		=	_h;

	data		=	new vector<T>[_width];

	ErrorExceptionMacro( data != NULL );

	for( i = 0; i < _width; i++ )
		data[i].resize(_height);
}






/************************************************************************************************************
	copy constructor 
*************************************************************************************************************/
template<typename T>
matrix<T>::matrix( matrix<T> &m )
{
	int		i,	j;

	data	=	NULL;

	_width	=	m.width();
	_height	=	m.height();

	data	=	new vector<T> [_width];

	ErrorExceptionMacro( data != NULL );

	for( i = 0; i < _width; i++ )
	{
		data[i].resize(_height);
		for( j = 0; j < _height; j++ )
			data[i](j)	=	m( i, j );
	}
}
	


#if defined(MAC_OS) || defined(LINUX)
/************************************************************************************************************
	copy constructor 
*************************************************************************************************************/
template<typename T>
matrix<T>::matrix( const matrix<T> &m )
{
	int		i,	j;

	data	=	NULL;

	_width	=	m._width;
	_height	=	m._height;

	data	=	new vector<T> [_width];

	ErrorExceptionMacro( data != NULL );

	for( i = 0; i < _width; i++ )
	{
		data[i].resize(_height);
		for( j = 0; j < _height; j++ )
			data[i](j)	=	m.data[i](j);
	}
}
#endif




/************************************************************************************************************
	resize
*************************************************************************************************************/
template<typename T>
void	matrix<T>::resize( int _w, int _h )
{
	int		i;

	// 清除舊的資料
	delete	[]	data;
	data	=	NULL;
	_width	=	0;
	_height	=	0;

	_width	=	_w;
	_height	=	_h;

	data	=	new vector<T>[_width];

	ErrorExceptionMacro( data != NULL );

	for( i = 0; i < _width; i++ )
		data[i].resize(_height);

}




/************************************************************************************************************
	destructor 
*************************************************************************************************************/
template<typename T>
matrix<T>::~matrix()
{
	delete	[]	data;
	data	=	NULL;

	_width	=	0;
	_height	=	0;
}




/************************************************************************************************************
	取出元素 
*************************************************************************************************************/
template<typename T>
T&	matrix<T>::operator () ( int x, int y )
{
	ErrorExceptionMacro( x >= 0 && x < _width && y >= 0 && y < _height );

	return	data[x](y);
}



/************************************************************************************************************
	width
*************************************************************************************************************/
template<typename T>
int		matrix<T>::width()
{
	return	_width;
}



/************************************************************************************************************
	height
*************************************************************************************************************/
template<typename T>
int		matrix<T>::height()
{
	return	_height;
}



template<typename T>
matrix<T>		matrix<T>::operator = ( matrix<T> m )
{
	int		i,	j;

	//if( this != &m )
	//{
		resize( m.width(), m.height() );

		for( i = 0; i < _width; i++ )
			for( j = 0; j < _height; j++ )
				data[i](j)	=	m( i, j );
	//}
	//else
	//	error_msg("matrix this == ref\n");

	return	*this;
}


    
    
/************************************************************************************************************
	+= operator
*************************************************************************************************************/
template<typename T>
matrix<T>   matrix<T>::operator += ( matrix<T> m )
{
    ErrorExceptionMacro( _width == m.width() && _height == m.height() );
    
    int     i,  j;
    
    for( i = 0; i < _width; i++ )
        for( j = 0; j < _height; j++ )
            data[i](j)  +=  m( i, j );
    
    return *this;
}
    
    
    

    
    

    
    
    
      
    
/************************************************************************************************************
	- operator
*************************************************************************************************************/
template<typename T>
matrix<T>	matrix<T>::operator - ()
{
	int		i,	j;

	matrix<T>	c;
	c.resize(_width,_height);

	for( i = 0; i < _width; i++ )
		for( j = 0; j < _height; j++ )
			c( i, j )	=	-data[i](j);


	return	c;
}





// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/************************************************************************************************************
     << operator
*************************************************************************************************************/
template<typename T>
std::ostream&	operator << ( std::ostream &out, matrix<T> mat )
{
	const int		width	=	mat.width();
	const int		height	=	mat.height();

	int		i,	j;

    out << "width = " << mat.width() << "\n";
    out << "height = " << mat.height() << "\n";
	for( i = 0; i < width; i++ )
	{
		for( j = 0; j < height; j++ )
			out << mat( i, j ) << " ";
		out << "\n";
	}

	return	out;
}
    
    
    
/************************************************************************************************************
     + operator
*************************************************************************************************************/
template<typename T>
matrix<T>   operator + ( matrix<T> a, matrix<T> b )
{
    ErrorExceptionMacro( a.width() == b.height() && a.height() == b.height() );
    
    const int   width   =   a.width();
    const int   height  =   a.height();
    
    int     i,  j;
    
    matrix<T>   c;
    c.resize( width, height );
    
    for( i = 0; i < width; i++ )
        for( j = 0; j < height; j++ )
            c( i, j )   =   a( i, j ) + b( i, j );
    
    return c;
}
    
    
    
/************************************************************************************************************
     - operator
*************************************************************************************************************/
template<typename T>
matrix<T>   operator - ( matrix<T> a, matrix<T> b )
{
    ErrorExceptionMacro( a.width() == b.height() && a.height() == b.height() );
    
    const int   width   =   a.width();
    const int   height  =   a.height();
    
    int     i,  j;
    
    matrix<T>   c;
    c.resize( width, height );
    
    for( i = 0; i < width; i++ )
        for( j = 0; j < height; j++ )
            c( i, j )   =   a( i, j ) - b( i, j );
    
    return c;
}
    
    



/************************************************************************************************************
     * operator
*************************************************************************************************************/
template<typename T>
matrix<T>   operator * ( matrix<T> a, matrix<T> b )
{
	ErrorExceptionMacro( a.height() == b.width() );		
    
	const int	a_width		=	a.width();
	const int	a_height	=	a.height();
	//const int	b_width		=	b.width();
	const int	b_height	=	b.height();
	const int	c_width		=	a_width;
	const int	c_height	=	b_height;

	T		sum;		// 計算每行的累加
	int		i,	j,	k;
	
    matrix<T>   c;
    c.resize( c_width, c_height );

	for( i = 0; i < a_width; i++ )
		for( j = 0; j < b_height; j++ )
		{
			sum		=	T();
			for( k = 0; k < a_height; k++ )
				sum		+=	a( i, k ) * b( k, j );
			c( i, j )	=	sum;
		}

    return c;
}
    
    


/************************************************************************************************************
     * operator
*************************************************************************************************************/
template<typename T>
vector<T>   operator * ( matrix<T> a, vector<T> b )
{
	ErrorExceptionMacro( a.height() == b.size() );

	const int	a_width		=	a.width();
	const int	a_height	=	a.height();
	//const int	b_size		=	b.size();
	const int	c_size		=	a_width;

	T		sum;
	int		i,	j;

	vector<T>	c;
	c.resize(c_size);

	for( i = 0; i < a_width; i++ )
	{
		sum		=	T();
		for( j = 0; j < a_height; j++ )
			sum		+=	a( i, j ) * b( j );
		c( i )	=	sum;
	}

	return	c;
}
    



/************************************************************************************************************
     * operator
*************************************************************************************************************/
template<typename T>
vector<T>   operator * ( vector<T> a, matrix<T> b )
{
	ErrorExceptionMacro( a.size() == b.width() );

	const int	a_size		=	a.size();
	//const int	b_width		=	b.width();
	const int	b_height	=	b.height();
	const int	c_size		=	b_height;

	T		sum;
	int		i,	j;

	vector<T>	c;
	c.resize(c_size);

	for( i = 0; i < b_height; i++ )
	{
		sum		=	T();
		for( j = 0; j < a_size; j++ )
			sum		+=	a( j ) * b( j, i );
		c( i )	=	sum;
	}

	return	c;
}




/************************************************************************************************************
     determine
*************************************************************************************************************/
template<typename T>
T		det( matrix<T> &m )
{
	ErrorExceptionMacro( m.width() == m.height() );

	if( m.width() == 2 )
	{
		return	m( 0, 0 ) * m( 1, 1 ) - m( 0, 1 ) * m( 1, 0 );
	}
	else
	{
		const int	width	=	m.width();
		const int	height	=	m.height();

		T			sum		=	T();
		int			x;
		int			i,	j;

		matrix<T>	m_tmp( width-1, height-1 );

		for( x = 0; x < height; x++ )
		{
			// 產生 sub matrix
			// 前半
			for( j = 0; j < x; j++ )
				for( i = 1; i < width; i++ )
					m_tmp( i-1, j )	=	m( i, j );
			// 後半
			for( j = x+1; j < height; j++ )
				for( i = 1; i < width; i++ )
					m_tmp( i-1, j-1 )	=	m( i, j );

			sum	+=	x%2 ? -m(0,x) * det(m_tmp) : m(0,x) * det(m_tmp);
			              /* 區分正負 */
		}

		return	sum;
	}

}




// use macro to general
hnMatrixTypeDefineMacro(int);
hnMatrixTypeDefineMacro(double);
hnMatrixTypeDefineMacro(hidog::math::Fraction);





}	// end namespace numeric
}	// end namespace hidog
