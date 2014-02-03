#include <iostream>
#include <cstdlib>
#include "cmake.h"

using namespace std;

int		main()
{
	cout << "Hello World.\n";

	cmake_test_function(10);

#ifdef CMAKE_TEST
	cout << "CMAKE_TEST define\n" ;
#endif
#ifdef CMAKE_TEST2
	cout << "CMAKE_TEST2 define\n" ;
#endif

	lib_1_message(4);

	system("PAUSE");
	return 	0;
}