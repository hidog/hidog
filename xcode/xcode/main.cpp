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

//#include "../xcode_dylib/xcode_dylib.h"

#include "../src/container/queue_static.h"
#include "../src/numeric/vector.h"

int main(int argc, const char * argv[])
{
    QueueStatic    qs(10);
    
    for( int i = 1; i < 10; i++ )
        qs.push(i);
    
    std::cout << qs.top() << std::endl;
    hidog::numeric::vector<int>     a;
    
    
    
    std::cout << "test";
    
    return 0;
}

