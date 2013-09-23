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
    coef    =   new T[1];
    coef[0] =   T();            // 預設初始化為 f(x) = 0
    deg     =   0;
    
}


/************************************************************************************************************
     constructor
*************************************************************************************************************/
template<typename T>
Polynomial<T>::~Polynomial()
{
    delete [] coef;
    coef    =   NULL;
    deg     =   0;
}



    
hnPolynomialTypeDefineMacro(int);
hnPolynomialTypeDefineMacro(double);


} // end namespace math
} // end namespace hidog