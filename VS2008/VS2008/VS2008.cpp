// VS2008.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "numeric/matrix.h"
#include "math/fraction.h"
#include "math/polynomial.h"



int _tmain(int argc, _TCHAR* argv[])
{
	srand( (int)time(NULL) );

	hidog::numeric::matrix<double>	M,	M2;
	hidog::numeric::vector<double>	v;

	int		r1,	r2,	r3;
	int		n,	i,	j;

	for( n = 0; n < 99999999; n++ )
	{
		r1	=	rand() % 50 + 30;

		M.resize( r1, r1 );
		M2.resize( r1, r1 );
		v.resize( r1 );

		for( i = 0; i < M.width(); i++ )
			for( j = 0; j < M.height(); j++ )
			{
				r1	=	rand() % 200 - 100;
				r2	=	rand() % 90 + 1;

				M(i,j)	=	1.0 * r1 / r2;

				r1	=	rand() % 200 - 100;
				r2	=	rand() % 90 + 1;

				M2(i,j)	=	1.0 * r1 / r2;
			}

		for( i = 0; i < v.size(); i++ )
		{
			r1	=	rand() % 200 - 100;
			r2	=	rand() % 90 + 1;

			v(i)	=	1.0 * r1 / r2;	
		}

		std::cout << M << "\n";
		std::cout << v << "\n";
		std::cout << M*v << "\n";
		std::cout << v*M*v << "\n";
		std::cout << M + M2 << "\n";
		std::cout << M - M2 << "\n";
		std::cout << M * M2 << "\n";

	}
	


	system("PAUSE");
	return 0;
}

