//
//  main.cpp
//  xcode
//
//  Created by hidog on 13/9/8.
//  Copyright (c) 2013年 hidog. All rights reserved.
//

#include <iostream>


#include "numeric/vector.h"
#include "numeric/matrix.h"



int main(int argc, const char * argv[])
{
    hidog::numeric::matrix<double>  M1(12,12),  M2(12,12);
    
    for( int i = 0; i < 12; i++ )
        for( int j = 0; j < 12; j++ )
        {
            M1( i, j )  =   i + j;
            M2( i, j )  =   i > j ? i+2 : j*2;
        }
    
    std::cout << M1 << "\n" << M2 << "\n";
    std::cout << M2 - M1 << "\n";

    //M1  =   M1 + M2;
    
    return 0;
}

