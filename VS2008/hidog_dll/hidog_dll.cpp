// hidog_dll.cpp : �w�q DLL ���ε{�����ץX�禡�C
//

#include "stdafx.h"
#include "hidog_dll.h"

#include <iostream>



void	hidog_dll_test( int a )
{
	static	int	b	=	a;

	std::cout << b << "\n";
}




BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		std::cout << "DLL_PROCESS_ATTACH\n";
		break;

	case DLL_THREAD_ATTACH:
		std::cout << "DLL_THREAD_ATTACH\n";

	case DLL_THREAD_DETACH:
		std::cout << "DLL_THREAD_DETACH\n";

	case DLL_PROCESS_DETACH:
		std::cout << "DLL_PROCESS_DETACH\n";
		break;
	}
	return TRUE;
}

