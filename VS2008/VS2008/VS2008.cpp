// VS2008.cpp : �w�q�D���x���ε{�����i�J�I�C
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
		vec[i]	=	i + 10;

	print(vec);


	try{
		if( 1 != 3 )
			throw	0;
	}catch( int e ){
		std::cout << "abc";
	}


	system("PAUSE");
	return 0;
}

