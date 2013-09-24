#include <iostream>
#include <ctime>
#include <stdlib.h>

#include "../src/math/fraction.h"
#include "../src/numeric/matrix.h"
#include "../src/math/polynomial.h"

int	main()
{
  srand( (int)time(NULL) );

  hidog::numeric::matrix<int>	M(10,10);
  hidog::numeric::vector<int>   v(10);

  for( int i = 0; i < M.width(); i++ )
     for( int j = 0; j < M.height(); j++ )
     {
         M( i, j ) = rand() % 100 - 50;
     }

  for( int i = 0; i < v.size(); i++ )
     v(i) = rand() % 100 - 50;

  std::cout << M << "\n" << v << "\n";
  std::cout << v*M*v << "\n";
  std::cout << det(M) << "\n";

  hidog::math::Fraction   f(10,15);
  std::cout << f << "\n";
 

  return   0;
}
