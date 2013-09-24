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
    
    hidog::math::Complex    c( rand()%100, rand()%100 );
    
    std::cout << c << "\n";
    
    return 0;
}

