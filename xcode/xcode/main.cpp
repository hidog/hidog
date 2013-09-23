//
//  main.cpp
//  xcode
//
//  Created by hidog on 13/9/8.
//  Copyright (c) 2013年 hidog. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "numeric/matrix.h"
#include "math/fraction.h"



int main(int argc, const char * argv[])
{
    srand( (int)time(0) );
    
    hidog::numeric::matrix<hidog::math::Fraction>   M(10,10);
    hidog::numeric::vector<hidog::math::Fraction>   v(10);
    
    int     i, j,   r1, r2;
    
    for( i = 0; i < M.width(); i++ )
        for( j = 0; j < M.height(); j++ )
        {
            r1  =   rand() % 100 - 50;
            r2  =   rand() % 50 + 1;
            
            M(i,j)  =   hidog::math::Fraction(r1,r2);
        }
    
    for( i = 0; i < v.size(); i++ )
    {
        r1  =   rand() % 100 - 50;
        r2  =   rand() % 50 + 1;
        
        v(i)    =   hidog::math::Fraction(r1,r2);
    }
    
    std::cout << v * M * v;
    std::cout << M;
    M   +=  M;
    std::cout << M;
    
    return 0;
}

