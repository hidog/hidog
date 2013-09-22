#include "vector.h"




namespace	hidog
{
namespace	numeric
{




/************************************************************************************************************
    建構
*************************************************************************************************************/
template<typename T>
vector<T>::vector()
{
	data	=	NULL;
	_size	=	0;
}


/************************************************************************************************************
    建構
*************************************************************************************************************/
template<typename T>
vector<T>::vector( int _s )
{
    int     i;
    
	data	=	NULL;	// 為了檢查是否正確取得空間

	_size	=	_s;
	data	=	new	T[_size];

    ErrorExceptionMacro( data != NULL );

    for( i = 0; i < _size; i++ )
        data[i]     =   T();    // 用預設的constructor   int等形態會預設給 0
}


#if defined(MAC_OS) || defined(LINUX)
/************************************************************************************************************
	copy construct
*************************************************************************************************************/
template<typename T>
vector<T>::vector( const vector<T>& v )
{
	data	=	NULL;       // 為了檢查是否正確取得空間
    
	_size	=	v._size;
	data	=	new	T[_size];

	ErrorExceptionMacro( data != NULL );

	// copy
	for( int i = 0; i < _size; i++ )
		data[i]	=	v.data[i];
}
#endif


    
/************************************************************************************************************
     copy construct
*************************************************************************************************************/
template<typename T>
vector<T>::vector( vector<T>& v )
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
template<typename T>
vector<T>::~vector()
{
	delete	[]	data;
	data	=	NULL;
	_size	=	0;
}




/************************************************************************************************************
    清除全部資料
*************************************************************************************************************/
template<typename T>
void	vector<T>::destroy()
{
	delete	[]	data;
	data	=	NULL;
	_size	=	0;
}






/************************************************************************************************************
    resize
*************************************************************************************************************/
template<typename T>
void	vector<T>::resize( int _s )
{
    int     i;
    
	destroy();
	
	_size	=	_s;
	data	=	new	T[_size];

	ErrorExceptionMacro( data != NULL );
    
    for( i = 0; i < _size; i++ )
        data[i]     =   T();
}



/************************************************************************************************************
    () operator
*************************************************************************************************************/
template<typename T>
T&	vector<T>::operator () ( int index )
{
	ErrorExceptionMacro( index < _size );

	return	data[index];
}
    
    
    
/************************************************************************************************************
     - operator
    轉成負號
 *************************************************************************************************************/
template<typename T>
vector<T>   vector<T>::operator - ()
{
    int     i;
    
    vector<T>   c;
    c.resize(_size);
    
    for( i = 0; i < _size; i++ )
        c(i)    =   -data[i];
    
    return c;
}
    



/************************************************************************************************************
    [] operator
*************************************************************************************************************/
template<typename T>
T&	vector<T>::operator [] ( int index )
{
	return	(*this)(index);
}



/************************************************************************************************************
	get size
*************************************************************************************************************/
template<typename T>
int		vector<T>::size()
{
	return	_size;
}



/************************************************************************************************************
	= operator
*************************************************************************************************************/
template<typename T>
vector<T>	vector<T>::operator = ( vector<T> v )
{
	int		i;

	//if( this != &v )  如果用reference就需要注意這件事情 避免 a = a;
	//{
		delete	[]	data;
		data	=	NULL;

		_size	=	v._size;
		data	=	new	T[_size];

		ErrorExceptionMacro( data != NULL );

		for( i = 0; i < _size; i++ )
			data[i]	=	v.data[i];
    //}


	return	*this;
}


/************************************************************************************************************
	+=	operator
*************************************************************************************************************/
template<typename T>
vector<T>	vector<T>::operator +=	( vector<T> v )
{
	const int	size	=	v.size();

	int		i;

	ErrorExceptionMacro( _size == size );

	for( i = 0; i < size; i++ )
		data[i]	+=	v(i);

	return	*this;
}



// 測試用 拿掉
#if 0
/************************************************************************************************************
	+=	operator
*************************************************************************************************************/
template<typename T>
vector<T>	vector<T>::operator +=	( T value )
{
	const int	size	=	_size;

	int		i;

	for( i = 0; i < size; i++ )
		data[i]	+=	value;

	return	*this;
}
#endif



/************************************************************************************************************
	-=	operator
*************************************************************************************************************/
template<typename T>
vector<T>	vector<T>::operator -=	( vector<T> v )
{
	const int	size	=	v.size();

	int		i;

	ErrorExceptionMacro( _size == size );

	for( i = 0; i < size; i++ )
		data[i]	-=	v(i);

	return	*this;
}



    
// 測試用  拿掉
#if 0
/************************************************************************************************************
	+=	operator
*************************************************************************************************************/
template<typename T>
vector<T>	vector<T>::operator -=	( T value )
{
	const int	size	=	_size;

	int		i;

	for( i = 0; i < size; i++ )
		data[i]	-=	value;

	return	*this;
}
#endif







//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/************************************************************************************************************
	測試用
*************************************************************************************************************/
template<typename T>
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
template<typename T>
std::ostream&	operator << ( std::ostream &out, vector<T> vec )
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
template<typename	T>
vector<T>	operator +  ( vector<T> a, vector<T> b )
{
	ErrorExceptionMacro( a.size() == b.size() );

	const int	size	=	a.size();

	int		i;

    vector<T>	c;		// ≠t≥d¶^∂«•Œ

	c.resize( size );

	for( i = 0; i < size; i++ )
		c(i)	=	a(i) + b(i);

	return	c;
}


/************************************************************************************************************
    -
*************************************************************************************************************/
template<typename	T>
vector<T>	operator -  ( vector<T> a, vector<T> b )
{
	ErrorExceptionMacro( a.size() == b.size() );

	const int	size	=	a.size();

	int		i;

    vector<T>	c;

	c.resize(size);

	for( i = 0; i < size; i++ )
		c(i)	=	a(i) - b(i);

	return	c;
}




/************************************************************************************************************
	 類似 inner_prod  
	 為了實現  x * A * x^T 而實作.  
	 (點乘似乎不常用到 以後再說吧)
*************************************************************************************************************/
template<typename T>
T		operator * ( vector<T> a, vector<T> b )
{
	ErrorExceptionMacro( a.size() == b.size() );

	const int	size	=	a.size();

	int		i;

	T	sum		=	T();

	for( i = 0; i < size; i++ )
		sum		+=	a(i) * b(i);

	return	sum;
}



/************************************************************************************************************
    multiple
*************************************************************************************************************/
template<typename T>
vector<T>	operator *	( vector<T> a, T value )
{
	const int	size	=	a.size();

	int		i;

    vector<T>	c;
	c.resize(size);

	for( i = 0; i < size; i++ )
		c(i)		=	a(i) * value;

	return	c;
}


/************************************************************************************************************
    multiple
*************************************************************************************************************/
template<typename T>
vector<T>	operator *	( T value, vector<T> a )
{
	const int	size	=	a.size();

	int		i;

    vector<T>	c;
	c.resize(size);

	for( i = 0; i < size; i++ )
		c(i)		=	value * a(i);

	return	c;
}



/************************************************************************************************************
    == 
*************************************************************************************************************/
template<typename T>
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
template<typename T>
T   inner_prod( vector<T> &a, vector<T> &b )
{
    ErrorExceptionMacro( a.size() == b.size() );
    
    const int   size    =   a.size();
    
    int     i;
    T       sum;
    
    sum     =   T();
    for( i = 0; i < size; i++ )
        sum     +=  a(i) * b(i);

    return  sum;
}
    
    

// use macro to general 
hnVectorTypeDefineMacro(int);
hnVectorTypeDefineMacro(double);
hnVectorTypeDefineMacro(float);
hnVectorTypeDefineMacro(hidog::math::Fraction);
    
    
    
}	// end namespace numeric
}	// end namespace hidog
