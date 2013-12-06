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

#include <cv.h>

#include "../xcode_dylib/xcode_dylib.h"



int main(int argc, const char * argv[])
{
    srand((int)time(0));
    
    hidog::numeric::matrix<double>  M;
    hidog::numeric::vector<double>  b;
    
    int     r,  r1, r2, i,  j;
    
    r   =   rand() % 20 + 10;
    
    M.resize( r, r );
    b.resize( r );
    
    for( i = 0; i < r; i++ )
        for( j = 0; j < r; j++ )
        {
            r1  =   rand() % 200 - 100;
            r2  =   rand() % 100 + 1;
            
            M( i, j )   =   1.0 * r1 / r2;
        }
    
    for( i = 0; i < r; i++ )
    {
        r1  =   rand() % 200 - 100;
        r2  =   rand() % 100 + 1;
        
        b( i )  =   1.0 * r1 / r2;
    }
    
    std::cout << hidog_dll_solve_matrix( M, b );
    
    
    return 0;
}

