#include <iostream>
#include <ctime>
#include <stdlib.h>

#include "../src/math/fraction.h"
#include "../src/numeric/matrix.h"
#include "../src/math/polynomial.h"
#include "../src/math/complex.h"

int	main()
{
  srand( (int)time(NULL) );


  hidog::math::Complex	c1,	c2;
  
  c1.real()		=	2;
  c1.image()	=	5;
  
  c2.real()	=	33.44;
  c2.image()	=	-5;
  

	std::cout << c1 << "\n";
	std::cout << c1 + c2 << "\n";
	std::cout << c1 * c2 << "\n";
	std::cout << c1 - c2 << "\n";
	std::cout << c1 / c2 << "\n";

  return   0;
}
