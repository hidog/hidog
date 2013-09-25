#ifndef _HIDOG_DLL_H
#define _HIDOG_DLL_H

#include "stdafx.h"


#include "../../src/shared.h"
#include "../../src/numeric/vector.h"

#include <iostream>



HIDOG_EXPORT_DLL	void	hidog_dll_test();


void	hidog_dll_test2();


class	HIDOG_EXPORT_DLL	hidog_abc_class_test
{
public:
	hidog_abc_class_test();
	//{
	//	std::cout << "hidog_abc_class_test" ;
	//}
};




#endif