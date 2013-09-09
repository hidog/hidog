#ifndef _HIDOG_MATRIX_H
#define _HIDOG_MATRIX_H

#include "shared.h"
#include "vector.hpp"
#include <ostream>




namespace	hidog
{
namespace	numeric
{






template<class T>
class	matrix
{
public:
	// constructor
	matrix()
	{
		data		=	NULL;
		_width		=	0;
		_height		=	0;
	}

	// constructor
	matrix( int _w, int _h )
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

	// copy constructor
	matrix( matrix<T> &m )
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

	// destructor
	~matrix()
	{
		delete	[]	data;
		data	=	NULL;

		_width	=	0;
		_height	=	0;
	}

	// get width
	int		width()
	{
		return	_width;
	}

	// get height
	int		height()
	{
		return	_height;
	}

	// operator ()
	T&	operator () ( int x, int y )
	{
		ErrorExceptionMacro( x >= 0 && x < _width && y >= 0 && y < _height );

		return	data[x](y);
	}


private:
	vector<T>	*data;
	int			_width;
	int			_height;

};




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T>
std::ostream&	operator << ( std::ostream &out, matrix<T> &mat )
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





}	// end namespace numeric
}	// end namespace hidog


#endif