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
*************************************************************************************************************/
template<typename T>
T&	Polynomial<T>::coef( int n )
{
	ErrorExceptionMacro( n < _deg + 1 );

	return	_coef[n];
}




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
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
	out << std::endl;

	return	out;
}





    
hnPolynomialTypeDefineMacro(int);
hnPolynomialTypeDefineMacro(double);


} // end namespace math
} // end namespace hidog