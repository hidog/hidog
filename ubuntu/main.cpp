#include <iostream>
#include <ctime>
#include <stdlib.h>

#include "../src/math/fraction.h"
#include "../src/numeric/matrix.h"
#include "../src/math/polynomial.h"

int	main()
{
  srand( (int)time(NULL) );

  int	r,	*a;

  r	=	rand() % 10 + 5;

  a	=	new int[r];

  for( int i = 0; i < r; i++ )
	a[i]	=	rand() % 20 - 10;

  hidog::math::Polynomial<int>	p( r-1, a );

  std::cout << p << "\n";

  hidog::math::Polynomial<int>	p2	=	p;

  std::cout << p2 << "\n";

  return   0;
}
