//
//  main.cpp
//  xcode
//
//  Created by hidog on 13/9/8.
//  Copyright (c) 2013年 hidog. All rights reserved.
//

#include <iostream>


#ifdef MAC_OS
#include "../../src/numeric/matrix.cpp"
#include "../../src/numeric/vector.cpp"
#endif



int main(int argc, const char * argv[])
{
    hidog::numeric::vector<int>     vec(100);
    
    for( int i = 0; i < 100; i++ )
        vec(i)  =   i + 10;
    
    std::cout << vec << std::endl;
    
    
    return 0;
}

