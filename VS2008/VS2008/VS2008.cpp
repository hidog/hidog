// VS2008.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "numeric/matrix.h"
#include "math/fraction.h"




int _tmain(int argc, _TCHAR* argv[])
{
	srand( (int)time(NULL) );

	int		size	=	3;

	hidog::numeric::matrix<hidog::math::Fraction>	M(size,size);
	hidog::numeric::vector<hidog::math::Fraction>	v(size);

	int		i,	j,	r1,	r2;

	for( i = 0; i < M.width(); i++ )
		for( j = 0; j < M.height(); j++ )
		{
			r1	=	rand() % 100 - 50;
			r2	=	rand() % 50 + 1;

			M(i,j)	=	hidog::math::Fraction(r1,r2);
		}

	for( i = 0; i < v.size(); i++ )
	{
		r1	=	rand() % 100 - 50;
		r2	=	rand() % 50 + 1;

		v(i)	=	hidog::math::Fraction(r1,r2);
	}

	std::cout << M << "\n";
	std::cout << v << "\n";

	std::cout << v * M * v << "\n";
	std::cout << det(M) << "\n";




	system("PAUSE");
	return 0;
}

