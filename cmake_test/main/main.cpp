#include <iostream>
#include <cstdlib>
#include "cmake.h"
#include "cmake_1.h"

#include "lib_1.h"
#include "lib_2.h"

#include "dlltest.h"

//#ifdef WIN32
	#include <windows.h>
//#endif


using namespace std;


typedef int (*LPFNDLLFUNC1)(char*);


void	load_dll_test()
{
	HINSTANCE	hDLL;
	hDLL	=	LoadLibrary("dlldyn");
	if( hDLL != NULL )
		cout << "load sucess!!\n" ;
	else
		cout << "load fail.\n" ;

	LPFNDLLFUNC1 	lpfnDlFunc1;

	lpfnDlFunc1	=	(LPFNDLLFUNC1)GetProcAddress(hDLL, "dll_dynamic_message");
	if( lpfnDlFunc1 != NULL )
		cout << "get func point sucess\n" ;
	else
		cout << "Get func point fail.\n" ;

	lpfnDlFunc1("load from main");

	FreeLibrary(hDLL);
}



int		main()
{
	load_dll_test();

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



	DllTestObj	dll_obj;
	dll_obj.set_data( 100 );
	dll_obj.message();


#ifdef WIN32
	system("PAUSE");
#endif
	return 	0;
}