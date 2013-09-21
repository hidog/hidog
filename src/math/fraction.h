#ifndef	_FRACTION_H
#define	_FRACTION_H


#include "../shared.h"
#include <iostream>




namespace	hidog
{
namespace	math
{




/*******************************************************************************************
    fraction obj
	分數型別
********************************************************************************************/
class	Fraction
{
public:
	Fraction();
	Fraction( int, int );
	~Fraction();
	Fraction( Fraction& );
#if defined(MAC_OS) || defined(LINUX)
	Fraction( const Fraction& );
#endif

	friend	std::ostream&	operator << ( std::ostream&, Fraction );

private:
	int		den;				// 分母 denominator
	int		num;				// 分子 numerator

	int		GCD( int, int );

};





// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



}	// end namespace math
}	// end namespace hidog




#endif