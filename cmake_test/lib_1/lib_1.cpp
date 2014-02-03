#ifndef LIB_1_CPP
#define LIB_1_CPP

#include <iostream>
using namespace std;


int 	lib_1_message( int n )
{
#ifdef LIB_1
	cout << "lib 1 message = " << n << endl;
#else
	cout << "error\n";
#endif

	return 	1;
}



#endif