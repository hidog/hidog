// VS2008.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "numeric/matrix.h"
#include "math/fraction.h"
#include "math/polynomial.h"
#include "math/complex.h"

#include "../hidog_dll/hidog_dll.h"





int _tmain(int argc, _TCHAR* argv[])
{
	hnMatrixDouble	M;
	hnVectorDouble	b,	x;

	srand( (unsigned int)time(NULL) );

	int		i,	j;
	int		r;
	int		r1,	r2;

	r	=	rand() % 10 + 15;

	M.resize( r, r );
	b.resize( r );

	for( i = 0; i < M.width(); i++ )
		for( j = 0; j < M.height(); j++ )
		{
			r1	=	rand() % 100 - 50;
			r2	=	rand() % 50 + 1;

			M( i, j )	=	1.0 * r1 / r2;
		}

	for( i = 0; i < b.size(); i++ )
	{
		r1	=	rand() % 100 - 50;
		r2	=	rand() % 50 + 1;

		b( i )	=	1.0 * r1 / r2;
	}

	x	=	hidog_dll_solve_matrix( M, b );

	std::cout << M*x << "\n" << b << "\n";
	std::cout << M*x - b << "\n";


	system("PAUSE");
	return 0;
}

