/*
 *  xcode_dylib.h
 *  xcode_dylib
 *
 *  Created by hidog on 13/10/1.
 *  Copyright (c) 2013年 hidog. All rights reserved.
 *
 */

#ifndef xcode_dylib_
#define xcode_dylib_

#include "../../src/shared.h"
#include "../../src/shared.h"
#include "../../src/numeric/vector.h"
#include "../../src/numeric/matrix.h"


/* The classes below are exported */
#pragma GCC visibility push(default)





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


HIDOG_DLL_EXPORT	struct	hidog_abc_struct_test		// dll exportºg¶b≠˛√‰¶¸•G®SÆt
{
	int		data;
};



typedef	hidog::numeric::vector<double>	hnVectorDouble;
typedef hidog::numeric::matrix<double>	hnMatrixDouble;

HIDOG_DLL_EXPORT	hnVectorDouble	hidog_dll_solve_matrix( hnMatrixDouble, hnVectorDouble );	// ¥˙∏’∏—Øx∞}





#pragma GCC visibility pop
#endif
