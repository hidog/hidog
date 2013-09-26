#ifndef _HIDOG_DLL_H
#define _HIDOG_DLL_H

#include "stdafx.h"


#include "../../src/shared.h"
#include "../../src/numeric/vector.h"
#include "../../src/numeric/matrix.h"

#include <iostream>



HIDOG_DLL_EXPORT	void	hidog_dll_test();


void	hidog_dll_test2();


class	HIDOG_DLL_EXPORT	hidog_abc_class_test
{
public:
	hidog_abc_class_test();
	//{
	//	std::cout << "hidog_abc_class_test" ;
	//}
};


HIDOG_DLL_EXPORT	struct	hidog_abc_struct_test		// dll export寫在哪邊似乎沒差
{
	int		data;
};



typedef	hidog::numeric::vector<double>	hnVectorDouble;
typedef hidog::numeric::matrix<double>	hnMatrixDouble;

HIDOG_DLL_EXPORT	hnVectorDouble	hidog_dll_solve_matrix( hnMatrixDouble, hnVectorDouble );	// 測試解矩陣



#endif