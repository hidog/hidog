#include "vector.h"

namespace	hidog
{
namespace	numeric
{




/************************************************************************************************************
    建構
*************************************************************************************************************/
template<class T>
vector<T>::vector()
{
	data	=	NULL;
	_size	=	0;
}


/************************************************************************************************************
    建構
*************************************************************************************************************/
template<class T>
vector<T>::vector( int _s )
{
	data	=	NULL;	// 為了檢查是否正確取得空間

	_size	=	_s;
	data	=	new	T[_size];

    ErrorExceptionMacro( data != NULL );
}


/************************************************************************************************************
	copy construct
*************************************************************************************************************/
template<class T>
vector<T>::vector( vector& v )
{
	data	=	NULL;       // 為了檢查是否正確取得空間
    
	_size	=	v.size();
	data	=	new	T[_size];

	ErrorExceptionMacro( data != NULL );

	// copy
	for( int i = 0; i < _size; i++ )
		data[i]	=	v(i);
}



/************************************************************************************************************
    解構
*************************************************************************************************************/
template<class T>
vector<T>::~vector()
{
	delete	[]	data;
	data	=	NULL;
	_size	=	0;
}




/************************************************************************************************************
    清除全部資料
*************************************************************************************************************/
template<class T>
void	vector<T>::destroy()
{
	delete	[]	data;
	data	=	NULL;
	_size	=	0;
}






/************************************************************************************************************
    resize
*************************************************************************************************************/
template<class T>
void	vector<T>::resize( int _s )
{
	destroy();
	
	_size	=	_s;
	data	=	new	T[_size];

	ErrorExceptionMacro( data != NULL );
	//if( data == NULL )
	//	error_msg("resize error.");
}



/************************************************************************************************************
    () operator
*************************************************************************************************************/
template<class T>
T&	vector<T>::operator () ( int index )
{
	ErrorExceptionMacro( index < _size );
	//if( index >= _size )
	//	error_msg("index out of bound.");

	return	data[index];
}



/************************************************************************************************************
    [] operator
*************************************************************************************************************/
template<class T>
T&	vector<T>::operator [] ( int index )
{
	return	(*this)(index);
}



/************************************************************************************************************
	get size
*************************************************************************************************************/
template<class T>
int		vector<T>::size()
{
	return	_size;
}



/************************************************************************************************************
	= operator
*************************************************************************************************************/
template<class T>
vector<T>&	vector<T>::operator = ( vector<T>& v )
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


/************************************************************************************************************
	+=	operator
*************************************************************************************************************/
template<class T>
vector<T>&	vector<T>::operator +=	( vector<T>& v )
{
	const int	size	=	v.size();

	int		i;

	ErrorExceptionMacro( _size == size );

	for( i = 0; i < size; i++ )
		data[i]	+=	v(i);

	return	*this;
}




/************************************************************************************************************
	+=	operator
*************************************************************************************************************/
template<class T>
vector<T>&	vector<T>::operator +=	( T value )
{
	const int	size	=	_size;

	int		i;

	for( i = 0; i < size; i++ )
		data[i]	+=	value;

	return	*this;
}



/************************************************************************************************************
	-=	operator
*************************************************************************************************************/
template<class T>
vector<T>&	vector<T>::operator -=	( vector<T>& v )
{
	const int	size	=	v.size();

	int		i;

	ErrorExceptionMacro( _size == size );

	for( i = 0; i < size; i++ )
		data[i]	-=	v(i);

	return	*this;
}




/************************************************************************************************************
	+=	operator
*************************************************************************************************************/
template<class T>
vector<T>&	vector<T>::operator -=	( T value )
{
	const int	size	=	_size;

	int		i;

	for( i = 0; i < size; i++ )
		data[i]	-=	value;

	return	*this;
}







//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/************************************************************************************************************
	測試用
*************************************************************************************************************/
template<class T>
void	print( vector<T>& vec )
{
	const int	size	=	vec.size();

	int		i;

	std::cout << "numeric vector size : " << size << std::endl;

	for( i = 0; i < size; i++ )
		//std::cout << vec(i) << " ";
		std::cout << "data[" << i << "] = " << vec(i) << std::endl;

	std::cout << "\n\n";
}





/************************************************************************************************************
    << operator
*************************************************************************************************************/
template<class T>
std::ostream&	operator << ( std::ostream &out, vector<T> &vec )
{
	const int	s	=	vec.size();

	int		i;

	out << "numeric vector size : " << s << "\n";

	for( i = 0; i < s; i++ )
		out << vec(i) << " ";
		//std::cout << "data[" << i << "] = " << vec(i) << std::endl;
	out << "\n";

	return	out;
}



/************************************************************************************************************
    +
*************************************************************************************************************/
template<class	T>
vector<T>&		operator +  ( vector<T> &a, vector<T> &b )
{
	ErrorExceptionMacro( a.size() == b.size() );

	const int	size	=	a.size();

	int		i;

	static  vector<T>	c;		// ≠t≥d¶^∂«•Œ

	c.resize( size );

	for( i = 0; i < size; i++ )
		c(i)	=	a(i) + b(i);

	return	c;
}


/************************************************************************************************************
    -
*************************************************************************************************************/
template<class	T>
vector<T>&		operator -  ( vector<T> &a, vector<T> &b )
{
	ErrorExceptionMacro( a.size() == b.size() );

	const int	size	=	a.size();

	int		i;

	static  vector<T>	c;

	c.resize(size);

	for( i = 0; i < size; i++ )
		c(i)	=	a(i) - b(i);

	return	c;
}




/************************************************************************************************************
	dot 點乘
*************************************************************************************************************/
template<class T>
vector<T>&	operator * ( vector<T> &a, vector<T> &b )
{
	ErrorExceptionMacro( a.size() == b.size() );

	const int	size	=	a.size();

	int		i;

	static	vector<T>	c;
	c.resize(size);

	for( i = 0; i < size; i++ )
		c(i)	=	a(i) * b(i);

	return	c;
}



/************************************************************************************************************
    multiple
*************************************************************************************************************/
template<class T>
vector<T>&	operator *	( vector<T> &a, T value )
{
	const int	size	=	a.size();

	int		i;

	static	vector<T>	c;
	c.resize(size);

	for( i = 0; i < size; i++ )
		c(i)		=	a(i) * value;

	return	c;
}


/************************************************************************************************************
    multiple
*************************************************************************************************************/
template<class T>
vector<T>&	operator *	( T value, vector<T> &a )
{
	const int	size	=	a.size();

	int		i;

	static	vector<T>	c;
	c.resize(size);

	for( i = 0; i < size; i++ )
		c(i)		=	value * a(i);

	return	c;
}



/************************************************************************************************************
    == 
*************************************************************************************************************/
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

/************************************************************************************************************
    inner product
*************************************************************************************************************/
template<class T>
T   inner_prod( vector<T> &a, vector<T> &b )
{
    ErrorExceptionMacro( a.size() == b.size() );
    
    const int   size    =   a.size();
    
    int     i;
    T       sum;
    
    sum     =   0;
    for( i = 0; i < size; i++ )
        sum     +=  a(i) * b(i);

    return  sum;
}
    
    

// use macro to general 
hnVectorTypeDefineMacro(int);
hnVectorTypeDefineMacro(double);
    
    
    
}	// end namespace numeric
}	// end namespace hidog