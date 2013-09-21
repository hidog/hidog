// VS2008.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "numeric/matrix.h"




int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));

	int		i,	j;

	hidog::numeric::matrix<double>		m;

	m.resize( 10, 10 );

	for( i = 0; i < m.width(); i++ )
		for( j = 0; j < m.height(); j++ )
		{
			int		r1	=	rand() % 10 - 5;
			int		r2	=	rand() % 20 + 1;
			m( i, j )	=	1.0 * r1 / r2;
		}

	std::cout << m << "\n" <<  det(m) << "\n";

	system("PAUSE");
	return 0;
}

