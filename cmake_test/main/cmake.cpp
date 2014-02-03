#include "cmake.h"


int		cmake_test_function( int n )
{
	int 	i;
	for( i = 0; i < n; i++ )
		cout << "The cmake test for i = " << i << endl;
		
	return 	1;
}