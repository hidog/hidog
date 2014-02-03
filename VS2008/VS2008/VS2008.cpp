// VS2008.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "numeric/matrix.h"
#include "math/fraction.h"
#include "math/polynomial.h"
#include "math/complex.h"

#include "../hidog_dll/hidog_dll.h"


using namespace std;






int _tmain(int argc, _TCHAR* argv[])
{

	FILE	*p;
	char	str[100];
	p	=	fopen("test.txt", "r");

	fgets( str, 100, p );

	printf( "%s",str);



	system("PAUSE");
	return 0;
}

