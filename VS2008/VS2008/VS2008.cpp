// VS2008.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>

#include "numeric/matrix.h"




int _tmain(int argc, _TCHAR* argv[])
{
#if 0
	hidog::numeric::vector<int>		vec1,	vec2(100);

	vec1.resize(100);

	for( int i = 0; i < 100; i++ )
	{
		vec1[i]	=	i + 10;
		vec2(i)	=	-i;
	}

	//print(vec);
	std::cout <<  vec1 + vec2;
#endif

	hidog::numeric::matrix<int>		mat(10,10);

	int		i,	j;

	for( i = 0; i < 10; i++ )
		for( j = 0; j < 10; j++ )
			mat( i, j )	=	i+j;

	for( i = 0; i < 10; i++ )
		for( j = 0; j < 10; j++ )
			std::cout << mat( i, j );



	system("PAUSE");
	return 0;
}

