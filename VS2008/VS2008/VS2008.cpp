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

	hidog::numeric::vector<hidog::math::Fraction>	v1(10),	v2(10);

	int		i,	r1,	r2;

	for( i = 0; i < 10; i++ )
	{
		r1		=	rand() % 100 - 50;
		r2		=	rand() % 50 + 1;

		v1(i)	=	hidog::math::Fraction(r1,r2);

		r1		=	rand() % 100 - 50;
		r2		=	rand() % 50 + 1;

		v2(i)	=	hidog::math::Fraction(r1,r2);
	}

	std::cout << v1 << "\n";
	std::cout << v2 << "\n";
	std::cout << v1 + v2 << "\n";
	std::cout << v1 * v2 << "\n";

	v1	+=	v2;
	std::cout << v1 << "\n";


	system("PAUSE");
	return 0;
}

