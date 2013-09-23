#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H


#include <iostream>



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
    
private:
    T       *coef;      // 各項系數
    int     deg;        //
    
};
    
    
    
#define hnPolynomialTypeDefineMacro(type) \
    template class  Polynomial<type>;
    
        
        
} // end namespace math
} // end namespace hidog







#endif