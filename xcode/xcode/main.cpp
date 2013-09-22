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
    
    hidog::numeric::matrix<double>  M(5,5);
    
    for( int i = 0; i < M.width(); i++ )
        for( int j = 0; j < M.height(); j++ )
        {
            int     r1  =   rand() % 100 - 50;
            int     r2  =   rand() % 100 + 1;
            M( i, j )   =   1.0 * r1 / r2;
        }
    
    hidog::numeric::vector<double>     v(5);
    
    for( int i = 0; i < v.size(); i++ )
    {
        int     r1  =   rand() % 100 - 50;
        int     r2  =   rand() % 100 + 1;
        v( i )  =   1.0 * r1 / r2;
    }
    
    std::cout << M << "\n";
    std::cout << v << "\n";
    std::cout << v * M * v << "\n";
    std::cout << det(M) << "\n";
    
    
    
    hidog::math::Fraction   f1(-14,10), f2(32,7);
    std::cout << f1 + f2 << "\n";
    std::cout << (double)(f1/f2) << "\n";
    
    return 0;
}

