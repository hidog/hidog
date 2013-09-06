// VS2008.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>

#include "numeric/vector.h"


int _tmain(int argc, _TCHAR* argv[])
{
	hidog::numeric::vector<int>		vec;


	vec.resize(100);

	for( int i = 0; i < 100; i++ )
	{
		vec[i]	=	i + 10;
		std::cout << vec(i) << std::endl;
	}


	system("PAUSE");
	return 0;
}

