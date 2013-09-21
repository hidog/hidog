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


	system("PAUSE");
	return 0;
}

