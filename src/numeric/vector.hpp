#ifndef _HIDOG_VECTOR_H
#define _HIDOG_VECTOR_H

#include "../shared.h"
#include <iostream>




namespace	hidog
{
namespace	numeric
{




template<class T>
class	vector
{
public:

	// constructor
	vector()
	{
		data	=	NULL;
		_size	=	0;
	}

	// constructor
	vector( int _s )
	{
		data	=	NULL;	// 為了檢察有沒有new成功

		_size	=	_s;
		data	=	new	T[_size];

		ErrorExceptionMacro( data != NULL );
	}

	// copy constructor
	vector( vector& v )
	{
		data	=	NULL;	// 為了檢查有沒有 new 成功

		_size	=	v.size();
		data	=	new	T[_size];

		ErrorExceptionMacro( data != NULL );
		//if( data == NULL )
		//	error_msg("error");

		// copy
		for( int i = 0; i < _size; i++ )
			data[i]	=	v(i);
	}

	// destructor
	~vector()
	{
		delete	[]	data;
		data	=	NULL;
		_size	=	0;
	}

	// resize
	void	resize( int _s )
	{	
		destroy();
	
		_size	=	_s;
		data	=	new	T[_size];

		ErrorExceptionMacro( data != NULL );
	}
	
	// destroy
	void	destroy()
	{
		delete	[]	data;
		data	=	NULL;
		_size	=	0;
	}

	// size
	int		size()
	{
		return	_size;
	}

	// operator ()
	T&	operator () ( int index )
	{
		ErrorExceptionMacro( index < _size );
		//if( index >= _size )
		//	error_msg("index out of bound.");
		return	data[index];
	}

	// operator []
	T&	operator [] ( int index )
	{
		return	(*this)(index);
	}
	
	// operator = 
	vector<T>	operator =  ( vector<T> v )
	{
		int		i;

		delete	[]	data;
		data	=	NULL;

		_size	=	v.size();
		data	=	new	T[_size];

		ErrorExceptionMacro( data != NULL );

		for( i = 0; i < _size; i++ )
			data[i]	=	v(i);

		return	*this;
	}


private:
	T		*data;
	int		_size;

};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// operator << 
template<class T>
std::ostream&	operator << ( std::ostream &out, vector<T> &vec )
{
	const int	s	=	vec.size();

	int		i;

	out << "numeric vector size : " << s << "\n";

	for( i = 0; i < s; i++ )
		out << vec(i) << " ";
		//std::cout << "data[" << i << "] = " << vec(i) << std::endl;
	out << "\n\n";

	return	out;
}

// operator +
template<class T>
vector<T>	operator + ( vector<T> &a, vector<T> &b )
{
	ErrorExceptionMacro( a.size() == b.size() );

	const int	size	=	a.size();

	int		i;

	vector<T>	c(size);

	for( i = 0; i < size; i++ )
		c(i)	=	a(i) + b(i);

	return	c;
}

// operator -
template<class T>
vector<T>	operator - ( vector<T> &a, vector<T> &b )
{
	ErrorExceptionMacro( a.size() == b.size() );

	const int	size	=	a.size();

	int		i;

	vector<T>	c(size);

	for( i = 0; i < size; i++ )
		c(i)	=	a(i) - b(i);

	return	c;
}


// operator == 
template<class T>
bool	operator == ( vector<T> &a, vector<T> &b )
{
	ErrorExceptionMacro( a.size() == b.size() );

	const int	size	=	a.size();

	int		i;
	bool	is;

	is	=	true;
	for( i = 0; i < size; i++ )
	{
		if( a(i) != b(i) )
		{
			is	=	false;
			break;
		}
	}
	
	return	is;
}



	
}	// end namespace numeric
}	// end namespace hidog




#endif