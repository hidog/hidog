#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H


#include <iostream>
#include "../shared.h"


namespace hidog
{
namespace math
{
        
        
    
/*******************************************************************************************
     polynomail obj
********************************************************************************************/
template<typename T>
class   Polynomial
{
    
public:
    Polynomial();
    ~Polynomial();
	Polynomial( Polynomial& );
	Polynomial( int, T* );					// 丟入 degree, array 做 setting
#if defined(MAC_OS) || defined(LINUX)
	Polynomial( const Polynomial& );
#endif

	int		deg();				// 回傳 degree
	T&		coef( int n );		// 回傳第 n 個 coef  (可讀寫)

	Polynomial	operator = ( Polynomial );

private:
    T       *_coef;      // 各項系數
    int     _deg;        // degree
    
};
    
    




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<typename T>
std::ostream&	operator << ( std::ostream&, Polynomial<T> );













#define hnPolynomialTypeDefineMacro(type) \
    template class  Polynomial<type>; \
	template	std::ostream&	operator << ( std::ostream&, Polynomial<type> );
    






        
} // end namespace math
} // end namespace hidog







#endif
