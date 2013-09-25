#include "polynomial.h"




namespace hidog
{
namespace math
{



/************************************************************************************************************
     constructor
*************************************************************************************************************/
template<typename T>
Polynomial<T>::Polynomial()
{
    _coef    =   new T[1];

	ErrorExceptionMacro( _coef != NULL );

    _coef[0] =   T();            // 預設初始化為 f(x) = 0
    _deg     =   0;
    
}


/************************************************************************************************************
     destructor
*************************************************************************************************************/
template<typename T>
Polynomial<T>::~Polynomial()
{
    delete [] _coef;
    _coef    =   NULL;
    _deg     =   0;
}


/************************************************************************************************************
     constructor
	 丟入 degree, array 做 setting
*************************************************************************************************************/
template<typename T>
Polynomial<T>::Polynomial( int deg, T *coef )
{
	int		i;

	_coef	=	NULL;
	
	// 開始建置資料
	_deg	=	deg;
	_coef	=	new T[ _deg + 1 ];	// 注意 + 1

	ErrorExceptionMacro( _coef != NULL );

	for( i = _deg; i >= 0; i-- )
		_coef[i]	=	coef[i];	// 注意順序是由高次項到低次項
}




/************************************************************************************************************
     constructor
*************************************************************************************************************/
template<typename T>
Polynomial<T>::Polynomial( Polynomial &p )
{ 
	int		i;

	_coef	=	NULL;
	_deg	=	0;

	// 取得新資料
	_deg		=	p._deg;
	_coef	=	new T[ _deg + 1 ];		// 注意 +1

	ErrorExceptionMacro( _coef != NULL );

	for( i = 0; i < _deg + 1; i++ )
		_coef[i]		=	p._coef[i];
}



#if defined(MAC_OS) || defined(LINUX)
/************************************************************************************************************
     constructor
*************************************************************************************************************/
template<typename T>
Polynomial<T>::Polynomial( const Polynomial &p )
{ 
	int		i;

	_coef	=	NULL;
	_deg		=	0;

	// 取得新資料
	_deg	=	p._deg;
	_coef	=	new T[ _deg + 1 ];		// 注意 +1

	ErrorExceptionMacro( _coef != NULL );

	for( i = 0; i < _deg; i++ )
		_coef[i]	=	p._coef[i];
}
#endif



/************************************************************************************************************
     回傳degree
*************************************************************************************************************/
template<typename T>
int		Polynomial<T>::deg()
{
	return	_deg;
}




/************************************************************************************************************
     回傳第 n 個 coef
	只可以讀取
*************************************************************************************************************/
template<typename T>
T	Polynomial<T>::coef( int n )
{
	if( n < _deg + 1 )
		return	_coef[n];
	else
		return	T();
}


/************************************************************************************************************
     回傳第 n 個 coef
	可以讀寫
*************************************************************************************************************/
template<typename T>
T&	Polynomial<T>::operator [] ( int n )
{
	ErrorExceptionMacro( n < _deg + 1 );

	return	_coef[n];	
}




/************************************************************************************************************
     = operator
*************************************************************************************************************/
template<typename T>
Polynomial<T>	Polynomial<T>::operator = ( Polynomial<T> p )
{
	int	i;

	delete	[] _coef;
	_coef	=	NULL;
	
	_deg	=	p.deg();
	_coef	=	new T[ _deg + 1 ];
	
	ErrorExceptionMacro( _coef != NULL );

	for( i = 0; i < _deg + 1; i++ )
		_coef[i]	=	p.coef(i);

	return	*this;	
}



/************************************************************************************************************
    -	非相減 回傳負值
*************************************************************************************************************/
template<typename T>
Polynomial<T>	Polynomial<T>::operator - ()
{
	int		i;

	hidog::math::Polynomial<T>	c(*this);

	for( i = 0; i < _deg; i++ )
		c[i]	=	-c[i];

	return	c;	
}



/************************************************************************************************************
     += operator
*************************************************************************************************************/
template<typename T>
Polynomial<T>	Polynomial<T>::operator += ( Polynomial<T> p )
{
	const int	degree	=	_deg > p.deg() ? _deg : p.deg();		// 取得最大的當 degree

	T		*a	=	new T[ degree + 1 ];		// 注意 +1
	int		i;

	for( i = 0; i < degree+1; i++ )
		a[i]	=	coef(i) + p.coef(i);

	// 刪除舊資料
	delete	[] _coef;
	_coef	=	NULL;

	_coef	=	new T[ degree + 1 ];
	_deg	=	degree;

	ErrorExceptionMacro( _coef != NULL );

	// 複製資料
	for( i = 0; i < degree+1; i++ )
		_coef[i]	=	a[i];

	delete	[] a;

	return	*this;	
}




/************************************************************************************************************
	-= operator
*************************************************************************************************************/
template<typename T>
Polynomial<T>	Polynomial<T>::operator -= ( Polynomial<T> p )
{
	const int	degree	=	_deg > p.deg() ? _deg : p.deg();		// 取得最大的當 degree

	T		*a	=	new T[ degree + 1 ];		// 注意 +1
	int		i;

	for( i = 0; i < degree+1; i++ )
		a[i]	=	coef(i) - p.coef(i);

	// 刪除舊資料
	delete	[] _coef;
	_coef	=	NULL;

	_coef	=	new T[ degree + 1 ];
	_deg	=	degree;

	ErrorExceptionMacro( _coef != NULL );

	// 複製資料
	for( i = 0; i < degree+1; i++ )
		_coef[i]	=	a[i];

	delete	[] a;

	return	*this;	
}





/************************************************************************************************************
	*= operator
*************************************************************************************************************/
template<typename T>
Polynomial<T>	Polynomial<T>::operator *= ( Polynomial<T> p )
{
	const int	p_deg	=	p.deg();
	const int	degree	=	_deg + p_deg;

	T		*a	=	new T[ degree + 1 ];		// 注意 +1
	int		i,	j;

	// 歸零
	for( i = 0; i < degree+1; i++ )
		a[i]	=	T();

	for( i = 0; i < _deg; i++ )
		for( j = 0; j < p_deg; j++ )
			a[i+j]	+=	_coef[i] * p.coef(j);

	// 刪除舊資料
	delete	[] _coef;
	_coef	=	NULL;

	_coef	=	new T[ degree + 1 ];
	_deg	=	degree;

	ErrorExceptionMacro( _coef != NULL );

	// 複製資料
	for( i = 0; i < degree+1; i++ )
		_coef[i]	=	a[i];

	delete	[] a;

	return	*this;	
}




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/************************************************************************************************************
     << operator
*************************************************************************************************************/
template<typename T>
std::ostream&	operator << ( std::ostream &out, Polynomial<T> p )
{
	int		i;

	for( i = p.deg(); i >= 0; i-- )
	{
		out << p.coef(i);
		if( i > 0 )
			out << "x^" << i << " + " ;
	}
	//out << std::endl;
	out << " ";

	return	out;
}


/************************************************************************************************************
     + operator
*************************************************************************************************************/
template<typename T>
Polynomial<T>	operator + ( Polynomial<T> p1, Polynomial<T> p2 )
{
	const int	deg	=	p1.deg() > p2.deg() ? p1.deg() : p2.deg();

	T		*a	=	new T[ deg + 1 ];
	int		i;

	for( i = 0; i < deg+1; i++ )
		a[i]	=	p1.coef(i) + p2.coef(i);		// 超出index的會自動回傳 0
	
	Polynomial<T>	p( deg, a );

	delete	[] a;

	return	p;
}




/************************************************************************************************************
     - operator
*************************************************************************************************************/
template<typename T>
Polynomial<T>	operator - ( Polynomial<T> p1, Polynomial<T> p2 )
{
	const int	deg	=	p1.deg() > p2.deg() ? p1.deg() : p2.deg();

	T		*a	=	new T[ deg + 1 ];
	int		i;

	for( i = 0; i < deg+1; i++ )
		a[i]	=	p1.coef(i) - p2.coef(i);		// 超出index的會自動回傳 0
	
	Polynomial<T>	p( deg, a );

	delete	[] a;

	return	p;
}




/************************************************************************************************************
     * operator
*************************************************************************************************************/
template<typename T>
Polynomial<T>	operator * ( Polynomial<T> p1, Polynomial<T> p2 )
{
	const int	deg	=	p1.deg() + p2.deg();

	T		*a	=	new T[ deg + 1 ];
	int		i,	j;

	for( i = 0; i < deg+1; i++ )	
		a[i]	=	T();		// 歸零

	for( i = 0; i < p1.deg()+1; i++ )
		for( j = 0; j < p2.deg()+1; j++ )
			a[i+j]	+=	p1.coef(i) * p2.coef(j);

	Polynomial<T>	p( deg, a );

	delete	[] a;

	return	p;
}





/************************************************************************************************************
     == operator
*************************************************************************************************************/
template<typename T>
bool	operator == ( Polynomial<T> p1, Polynomial<T> p2 )
{
	bool	is	=	true;
	int		i;
	int		degree;

	if( p1.deg() != p2.deg() )
		return	false;

	degree	=	p1.deg();

	for( i = 0; i < degree; i++ )
	{
		if( p1[i] != p2[i] )
		{
			is	=	false;
			break;
		}
	}

	return	is;
}


    

/************************************************************************************************************
     != operator
*************************************************************************************************************/
template<typename T>
bool	operator != ( Polynomial<T> p1, Polynomial<T> p2 )
{
	bool	is	=	false;
	int		i;
	int		degree;

	if( p1.deg() != p2.deg() )
		return	true;

	degree	=	p1.deg();

	for( i = 0; i < degree; i++ )
	{
		if( p1[i] != p2[i] )
		{
			is	=	true;
			break;
		}
	}

	return	is;
}




hnPolynomialTypeDefineMacro(int);
hnPolynomialTypeDefineMacro(double);


} // end namespace math
} // end namespace hidog
