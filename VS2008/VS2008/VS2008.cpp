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
	hidog::math::Fraction	f( 157964, 4522 );

	std::cout << f << "\n";

	srand( (int)time(NULL) );

	hidog::numeric::matrix<double>	M(15,15);

	for( int i = 0; i < M.width(); i++ )
		for( int j = 0; j < M.height(); j++ )
		{
			int		r1	=	rand() % 100 - 50;
			int		r2	=	rand() % 50 + 1;

			M( i, j )	=	1.0 * r1 / r2;
		}

	hidog::numeric::vector<double>	v(15);

	for( int i = 0; i < v.size(); i++ )
	{
		int		r1	=	rand() % 100 - 50;
		int		r2	=	rand() % 50 + 1;

		v(i)	=	1.0 * r1 / r2;
	}

	std::cout << v * M * v << "\n";

	hidog::math::Fraction	f1( 352, 85 ),	f2( 24, 47 ),	f3( 21,	3 );

	std::cout << (f1 - f2*f3).toDouble() << std::endl;
	std::cout << (double)f1 << " " << static_cast<double>(f2) << "\n";


	system("PAUSE");
	return 0;
}

