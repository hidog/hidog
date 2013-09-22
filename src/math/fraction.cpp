#include "fraction.h"


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
    建構 
*************************************************************************************************************/
Fraction::Fraction( int _n, int _d )
{
    int     __n     =   std::abs(_n);
    int     __d     =   std::abs(_d);
	int		gcd		=	GCD( __n, __d );

	num		=	_n / gcd;
	den		=	_d / gcd;
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
}



#if defined(MAC_OS) || defined(LINUX)
/************************************************************************************************************
    copy constructor 
*************************************************************************************************************/
Fraction::Fraction( const Fraction &f)
{
	num		=	f.num;
	den		=	f.den;
}
#endif




/************************************************************************************************************
    最大公因數 
*************************************************************************************************************/
int		Fraction::GCD( int a, int b )
{
	int		tmp;

	while( a % b != 0 )
	{
		tmp	=	b;
		b	=	a%b;
		a	=	tmp;
	}

	return	b;
}













// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ global function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

/************************************************************************************************************
    << operator 
*************************************************************************************************************/
std::ostream&	operator << ( std::ostream &out, Fraction f )
{
	out << f.num << "/" << f.den << "\n";

	return	out;
}







}	// end namespace math
}	// end namespace hidog
