// VS2008.cpp : �w�q�D���x���ε{�����i�J�I�C
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

