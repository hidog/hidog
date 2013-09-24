#include "fraction.h"

// test

namespace	hidog
{
namespace	math
{





/************************************************************************************************************
    constructor 
*************************************************************************************************************/
Fraction::Fraction()
{
	num		=	0;		// 分子
	den		=	1;		// 分母
}



/************************************************************************************************************
    constructor
    _n : 分子
    _d : 分母
*************************************************************************************************************/
Fraction::Fraction( int _n, int _d )
{
    ErrorExceptionMacro( _d != 0 );
    
    int     __n     =   abs(_n);
    int     __d     =   abs(_d);
	int		gcd		=	GCD( __n, __d );

	num		=	_n / gcd;
	den		=	_d / gcd;

	ckeck_den_positive();		// 確保分母是正數
}



/************************************************************************************************************
    destructor 
*************************************************************************************************************/
Fraction::~Fraction()
{}



/************************************************************************************************************
    copy constructor 
*************************************************************************************************************/
Fraction::Fraction( Fraction &f)
{
	num		=	f.num;
	den		=	f.den;

	ckeck_den_positive();		// 確保分母是正數
}



#if defined(MAC_OS) || defined(LINUX)
/************************************************************************************************************
    copy constructor 
*************************************************************************************************************/
Fraction::Fraction( const Fraction &f)
{
	num		=	f.num;
	den		=	f.den;

	ckeck_den_positive();		// 確保分母是正數
}
#endif




/************************************************************************************************************
    求最大公因數
*************************************************************************************************************/
int		Fraction::GCD( int a, int b )
{
	if( a <= 0 || b <= 0 )
		return	1;

	int		tmp;

	while( a % b != 0 )
	{
		tmp	=	b;
		b	=	a%b;
		a	=	tmp;
	}

	return	b;
}




/************************************************************************************************************
	轉成浮點數型態
*************************************************************************************************************/
Fraction::operator double ()
{
	return	static_cast<double>(num) / den;
}



/************************************************************************************************************
    絕對值
*************************************************************************************************************/
int		Fraction::abs( int a )
{
	if( a < 0 )
		a	=	-a;
	return	a;
}




/************************************************************************************************************
    = operator 
*************************************************************************************************************/
Fraction	Fraction::operator = ( Fraction f )
{
	den		=	f.den;
	num		=	f.num;

	ckeck_den_positive();		// 確保分母是正數

	return	*this;
}






/************************************************************************************************************
     - operator
*************************************************************************************************************/
Fraction    Fraction::operator - ()
{
    num     =   -num;
    ckeck_den_positive();       // 保證分母大於零
    
    return *this;
}

    
    



/************************************************************************************************************
    -= operator
*************************************************************************************************************/
Fraction    Fraction::operator -= ( Fraction a )
{
    int     _den    =   den * a.den;
    int     _num    =   num*a.den - den*a.num;
    int     __den   =   abs(_den);
    int     __num   =   abs(_num);
    int     gcd     =   GCD(__den,__num);
    
    _den    /=  gcd;
    _num    /=  gcd;
    
    // 回寫資料
    den     =   _den;
    num     =   _num;
    
	ckeck_den_positive();		// 保證分母大於零
    
	return	*this;
}




/************************************************************************************************************
    *= operator
*************************************************************************************************************/
Fraction    Fraction::operator *= ( Fraction a )
{
    int     _den    =   den * a.den;
    int     _num    =	num * a.num;
    int     __den   =   abs(_den);
    int     __num   =   abs(_num);
    int     gcd     =   GCD(__den,__num);
    
    _den    /=  gcd;
    _num    /=  gcd;
    
    // 回寫資料
    den     =   _den;
    num     =   _num;
    
	ckeck_den_positive();		// 保證分母大於零
    
	return	*this;
}




/************************************************************************************************************
    /= operator
*************************************************************************************************************/
Fraction    Fraction::operator /= ( Fraction a )
{
    int     _den    =   den * a.num;
    int     _num    =	num * a.den;
    int     __den   =   abs(_den);
    int     __num   =   abs(_num);
    int     gcd     =   GCD(__den,__num);
    
    _den    /=  gcd;
    _num    /=  gcd;
    
    // 回寫資料
    den     =   _den;
    num     =   _num;
    
	ckeck_den_positive();		// 保證分母大於零
    
	return	*this;
}




/************************************************************************************************************
    += operator
*************************************************************************************************************/
Fraction    Fraction::operator += ( Fraction a )
{
    int     _den    =   den * a.den;
    int     _num    =   num*a.den + den*a.num;
    int     __den   =   abs(_den);
    int     __num   =   abs(_num);
	int		gcd		=	GCD(__den,__num);
	//int     gcd     =   __num == 0 ? 1 : GCD(__den,__num);
    
    _den    /=  gcd;
    _num    /=  gcd;
    
    // 回寫資料
    den     =   _den;
    num     =   _num;
    
	ckeck_den_positive();		// 保證分母大於零
    
	return	*this;
}


    
    
/************************************************************************************************************
    讓分母固定為正數
*************************************************************************************************************/
void	Fraction::ckeck_den_positive()
{
	if( den < 0 )
	{
		den		=	-den;
		num		=	-num;
	}
}



/************************************************************************************************************
    轉成 double
*************************************************************************************************************/
double		Fraction::toDouble()
{
	return	static_cast<double>(num) / den;
}


/************************************************************************************************************
    轉成 float
*************************************************************************************************************/
float		Fraction::toFloat()
{
	return	static_cast<float>(num) / den;
}






// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/************************************************************************************************************
    << operator 
*************************************************************************************************************/
std::ostream&	operator << ( std::ostream &out, Fraction f )
{
	out << f.num << "/" << f.den ;

	return	out;
}



/************************************************************************************************************
    + operator 
*************************************************************************************************************/
Fraction	operator + ( Fraction a, Fraction b )
{
	Fraction	c;

	int		den	=	a.den * b.den;
	int		num	=	a.num*b.den + a.den*b.num;

	int		_den	=	c.abs( den );
	int		_num	=	c.abs( num );
	int		gcd		=	c.GCD(_den,_num);
	//int		gcd		=	_num == 0 ? 1 : c.GCD( _den, _num );

	den		/=	gcd;
	num		/=	gcd;

	c.den	=	den;
	c.num	=	num;

	c.ckeck_den_positive();		// 確保分母是正數

	return	c;
}




/************************************************************************************************************
    - operator 
*************************************************************************************************************/
Fraction	operator - ( Fraction a, Fraction b )
{
	Fraction	c;

	int		den	=	a.den * b.den;
	int		num	=	a.num*b.den - a.den*b.num;

	int		_den	=	c.abs( den );
	int		_num	=	c.abs( num );
	int		gcd		=	c.GCD( _den, _num );

	den		/=	gcd;
	num		/=	gcd;

	c.den	=	den;
	c.num	=	num;

	c.ckeck_den_positive();		// 確保分母是正數

	return	c;
}






/************************************************************************************************************
    * operator 
*************************************************************************************************************/
Fraction	operator * ( Fraction a, Fraction b )
{
	Fraction	c;

	int		den	=	a.den * b.den;
	int		num	=	a.num * b.num;

	int		_den	=	c.abs( den );
	int		_num	=	c.abs( num );
	int		gcd		=	c.GCD(_den,_num);
	//int		gcd		=	_num == 0 ? 1 : c.GCD( _den, _num );

	den		/=	gcd;
	num		/=	gcd;

	c.den	=	den;
	c.num	=	num;

	c.ckeck_den_positive();		// 確保分母是正數

	return	c;
}






/************************************************************************************************************
    / operator 
*************************************************************************************************************/
Fraction	operator / ( Fraction a, Fraction b )
{
	Fraction	c;

	int		den	=	a.den * b.num;
	int		num	=	a.num * b.den;

	int		_den	=	c.abs( den );
	int		_num	=	c.abs( num );
	int		gcd		=	c.GCD( _den, _num );

	den		/=	gcd;
	num		/=	gcd;

	c.den	=	den;
	c.num	=	num;

	c.ckeck_den_positive();		// 確保分母是正數

	return	c;
}






}	// end namespace math
}	// end namespace hidog





