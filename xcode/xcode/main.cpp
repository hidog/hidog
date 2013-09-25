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
#include "math/polynomial.h"
#include "math/complex.h"



int main(int argc, const char * argv[])
{
    srand( (int)time(0) );
    
    hidog::numeric::matrix<hidog::math::Polynomial<int>>    M;
    
    M.resize(6,6);
    
    int     i,  j,  a[2];
    
    for( i = 0; i < 6; i++ )
        for( j = 0; j < 6; j++ )
        {
            if( i == j )
            {
                a[1]    =   -1;
                a[0]    =   rand()%10 - 5;
                M(i,j)  =   hidog::math::Polynomial<int>(1,a);
            }
            else
            {
                a[1]    =   0;
                a[0]    =   rand()%10-5;
                M(i,j)  =   hidog::math::Polynomial<int>(0,a);
            }
        }
    
    std::cout << M << "\n" << det(M) << "\n";
    
    return 0;
}

