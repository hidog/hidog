//
//  main.cpp
//  xcode
//
//  Created by hidog on 13/9/8.
//  Copyright (c) 2013年 hidog. All rights reserved.
//

#include <iostream>


#include "../../src/numeric/vector.hpp"




int main(int argc, const char * argv[])
{
    vector     vec(10), vec2(10);
    
    for( int i = 0; i < 100; i++ )
    {
        vec(i)  =   i + 10;
        vec2(i) =   i - 3;
    }
    
    vec =   vec + vec2;
    //std::cout <<  vec + vec2 << std::endl;
    
    
    return 0;
}

