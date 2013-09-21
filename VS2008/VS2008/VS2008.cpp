// VS2008.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>

#include "numeric/matrix.h"




int _tmain(int argc, _TCHAR* argv[])
{
	int		i,	j;

	hidog::numeric::matrix<int>		m1,	m2,	m3;

	m1.resize( 2, 4 );
	m2.resize( 4, 3 );

	for( i = 0; i < 2; i++ )
		for( j = 0; j < 4; j++ )
			m1( i, j )	=	i + j;

	for( i = 0; i < 4; i++ )
		for( j = 0; j < 3; j++ )
			m2( i, j )	=	i + j;

	m3	=	m1 * m2;

	std::cout << m1 << "\n";
	std::cout << m2 << "\n";
	std::cout << m3 << "\n";


	system("PAUSE");
	return 0;
}

