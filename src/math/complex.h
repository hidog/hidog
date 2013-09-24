#ifndef	_COMPLEX_H
#define	_COMPLEX_H


#include "../shared.h"
#include <iostream>



namespace	hidog
{
namespace math
{
	
	

class	Complex
{
public:
	Complex();
	~Complex();
	Complex( double, double );
	Complex( Complex& );
#if defined(MAC_OS) || defined(LINUX)
	Complex( const Complex& );
#endif

	double&	real();			// 取得 real part 可讀寫
	double&	image();		// 取得 image part 可讀寫

private:
	double	_real;				// real part
	double	_image;			// image part
};




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
std::ostream&	operator << ( std::ostream&, Complex );

Complex		operator + ( Complex, Complex );
Complex		operator  -  ( Complex, Complex );
Complex		operator  *  ( Complex, Complex );
Complex		operator  /  ( Complex, Complex );



}	// end namespace math
}  // end namespace hidog



#endif
