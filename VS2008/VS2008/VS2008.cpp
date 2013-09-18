// VS2008.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>

#include "numeric/matrix.h"




int _tmain(int argc, _TCHAR* argv[])
{
#if 1
	hidog::numeric::vector<int>		vec1,	vec2(10),	vec3;

	vec1.resize(10);

	for( int i = 0; i < 10; i++ )
	{
		vec1[i]	=	i + 1;
		vec2(i)	=	2 - i*i;
	}

	vec3	=	vec1;
	vec3	-=	5;

	print(vec3);
	std::cout <<  vec1 * vec2;
	std::cout << vec1 * 10 << " " << 2 * vec2;
	std::cout << vec1 - vec2;
	std::cout << "inner product = " << inner_prod( vec1, vec2 );
	

#endif


#if 1
	hidog::numeric::matrix<int>		mat(10,10);

	int		i,	j;

	for( i = 0; i < 10; i++ )
		for( j = 0; j < 10; j++ )
			mat( i, j )	=	i + j;

	std::cout << mat;

	mat.resize( 10, 20 );

	hidog::numeric::matrix<int>		mat2;

	for( i = 0; i < 10; i++ )
		for( j = 0; j < 20; j++ )
			mat( i, j )	=	i + j;

	mat2	=	mat;

	std::cout << mat2;
		

#endif


	system("PAUSE");
	return 0;
}

