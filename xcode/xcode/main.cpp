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
    
    hidog::numeric::vector<hidog::math::Fraction>   v1(10), v2(10);
    
    int     i,  r1, r2;
    
    for( i = 0; i < v1.size(); i++ )
    {
        r1      =   rand() % 100 - 50;
        r2      =   rand() % 50 + 1;
        
        v1(i)  =   hidog::math::Fraction(r1,r2);
        
        r1      =   rand() % 100 - 50;
        r2      =   rand() % 50 + 1;
        
        v2(i)  =   hidog::math::Fraction(r1,r2);
    }
    
    std::cout << (double)(v1*v2) << "\n";
    std::cout << v1 + v2 << "\n";

    v1  -=  v2;
    
    std::cout << v1 << "\n";
    
    
    return 0;
}

