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
	hidog::math::Fraction	f1( 352, 85 ),	f2( 24, 47 ),	f3( 21,	4 );

	std::cout << (f1 - f2*f3).toDouble() << std::endl;
	std::cout << (double)f1 << " " << static_cast<double>(f2) << "\n";
	std::cout << f1/f3 << "\n";


	system("PAUSE");
	return 0;
}

