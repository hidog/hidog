// VS2008.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>

#include "numeric/vector.h"



int _tmain(int argc, _TCHAR* argv[])
{
	hidog::numeric::vector<int>		vec1,	vec2(100);

	vec1.resize(100);

	for( int i = 0; i < 100; i++ )
	{
		vec1[i]	=	i + 10;
		vec2(i)	=	-i;
	}

	//print(vec);
	std::cout <<  vec1 + vec2;




	system("PAUSE");
	return 0;
}

