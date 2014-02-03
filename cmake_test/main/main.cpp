#include <iostream>
#include <cstdlib>
#include "cmake.h"
#include "cmake_1.h"

#include "lib_1.h"
#include "lib_2.h"


using namespace std;



int		main()
{
	cout << "Hello World.\n";

	cmake_test_function(3);

#ifdef CMAKE_TEST
	cout << "CMAKE_TEST define\n" ;
#endif
#ifdef CMAKE_TEST2
	cout << "CMAKE_TEST2 define\n" ;
#endif

	lib_1_message(4);


#ifdef MSVC
	cout << "Using MSVC" << endl ;
#endif

	cmake_1_func();

	lib_2_test();

	system("PAUSE");
	return 	0;
}