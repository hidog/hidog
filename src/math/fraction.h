#ifndef	_FRACTION_H
#define	_FRACTION_H


#include "../shared.h"
#include <iostream>
#include <cmath>



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

	double		toDouble();					// 轉成 double 型態
	float		toFloat();					// 轉成 float 型態

	Fraction	operator =	( Fraction );

	operator double	();

	friend	std::ostream&	operator << ( std::ostream&, Fraction );
	friend	Fraction		operator +  ( Fraction, Fraction );
	friend	Fraction		operator -	( Fraction, Fraction );
	friend	Fraction		operator *	( Fraction, Fraction );
	friend	Fraction		operator /	( Fraction, Fraction );

private:
	int		den;							// 分母 denominator
	int		num;							// 分子 numerator

	int		GCD( int, int );
	int		abs(int);
	void	ckeck_den_positive();			// 確定分母是正數

};



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



}	// end namespace math
}	// end namespace hidog




#endif
