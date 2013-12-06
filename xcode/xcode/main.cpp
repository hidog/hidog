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


using namespace std;


int main(int argc, const char * argv[])
{
    hidog::container::QueueStatic<int>    qs;
    
    qs.init(100);
    
    for( int i = 0; i < 100; i++ )
        qs.push(i);
    
    for( int i = 0; i < 100; i++ )
        cout << qs.pop() << endl;
    
    for( int i = 0; i < 70; i++ )
        qs.push(i);
    
    for( int i = 0; i < 30; i++ )
        cout << qs.pop() << endl;
    
    for( int i = 0; i < 10; i++ )
        qs.push(i);
    
    for( int i = 0; i < 50; i++ )
        cout << qs.pop() << endl;
    
    
    std::cout << "test" << endl;
    
    return 0;
}

