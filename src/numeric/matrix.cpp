#include "matrix.h"





namespace	hidog
{
namespace	numeric
{






/************************************************************************************************************
	constructor 
*************************************************************************************************************/
template<class T>
matrix<T>::matrix()
{
	data		=	NULL;
	_width		=	0;
	_height		=	0;

}



/************************************************************************************************************
	constructor 
*************************************************************************************************************/
template<class T>
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
template<class T>
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
	


#ifdef MAC_OS
/************************************************************************************************************
	copy constructor 
*************************************************************************************************************/
template<class T>
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
template<class T>
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
template<class T>
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
template<class T>
T&	matrix<T>::operator () ( int x, int y )
{
	ErrorExceptionMacro( x >= 0 && x < _width && y >= 0 && y < _height );

	return	data[x](y);
}



/************************************************************************************************************
	width
*************************************************************************************************************/
template<class T>
int		matrix<T>::width()
{
	return	_width;
}



/************************************************************************************************************
	height
*************************************************************************************************************/
template<class T>
int		matrix<T>::height()
{
	return	_height;
}



/************************************************************************************************************
	= operator
*************************************************************************************************************/
template<class T>
matrix<T>&		matrix<T>::operator = ( matrix<T>& m )
{
	int		i,	j;

	if( this != &m )
	{
		resize( m.width(), m.height() );

		for( i = 0; i < _width; i++ )
			for( j = 0; j < _height; j++ )
				data[i](j)	=	m( i, j );
	}
	else
		error_msg("matrix this == ref\n");

	return	*this;
}





// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T>
std::ostream&	operator << ( std::ostream &out, matrix<T>& mat )
{
	const int		width	=	mat.width();
	const int		height	=	mat.height();

	int		i,	j;

	for( i = 0; i < width; i++ )
	{
		for( j = 0; j < height; j++ )
			out << mat( i, j ) << " ";
		out << "\n";
	}

	return	out;
}

    
    
// use macro to general
hnMatrixTypeDefineMacro(int);
hnMatrixTypeDefineMacro(double);





}	// end namespace numeric
}	// end namespace hidog
