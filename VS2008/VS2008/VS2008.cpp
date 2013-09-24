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



int _tmain(int argc, _TCHAR* argv[])
{
	srand( (int)time(NULL) );

	hidog::math::Complex	c(12,3.4);

	std::cout << c << "\n";
	


	system("PAUSE");
	return 0;
}

