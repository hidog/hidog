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



int _tmain(int argc, _TCHAR* argv[])
{
	srand( (int)time(NULL) );


	hidog::numeric::matrix<hidog::math::Polynomial<int>>	M;

	M.resize( 5, 5 );

	int		i,	j;
	int		a[2];

	for( i = 0; i < M.width(); i++ )
		for( j = 0; j < M.height(); j++ )
		{
			if( i == j )
			{
				a[1]	=	-1;
				a[0]	=	rand() % 10 - 5;
				M(i,j)	=	hidog::math::Polynomial<int>(1,a);
			}
			else
			{
				a[1]	=	0;
				a[0]	=	rand() % 10 - 5;
				M(i,j)	=	hidog::math::Polynomial<int>(0,a);
			}
		}

	std::cout << M << "\n";
	std::cout << det(M) << "\n";

	system("PAUSE");
	return 0;
}

