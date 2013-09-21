// VS2008.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>

#include "numeric/matrix.h"




int _tmain(int argc, _TCHAR* argv[])
{
	int		i,	j;

	hidog::numeric::matrix<int>		m;

	m.resize( 4, 4 );

	for( i = 0; i < 4; i++ )
		for( j = 0; j < 4; j++ )
			m( i, j )	=	i + j;

	hidog::numeric::vector<int>		v,	x;

	v.resize(4);

	for( i = 0; i < 4; i++ )
		v(i)	=	i+1;

	std::cout << v * m * v << "\n";



	system("PAUSE");
	return 0;
}

