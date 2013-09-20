#include <iostream>

#include "../src/numeric/vector.h"
#include "../src/numeric/matrix.h"


int	main()
{
  hidog::numeric::vector<int>	v1(10), v2(10), v3;

  int	i;

  for( i = 0; i < 10; i++ )
  {
	v1(i)	=	i;
	v2(i)	=	i%2 ? i+1 : 0;
  }

  v3 = v1 - v2;
  std::cout << v3 << "\n";
  std::cout << v1 + v2 << "\n";

  hidog::numeric::matrix<int>	m1, m2;

  m1.resize( 10, 10 );
  m2.resize( 10, 10 );

  int	j;

  for( i = 0; i < 10; i++ )	
	for( j = 0; j < 10; j++ )
  	{
		m1( i, j )	=	i + j;
		m2( i, j )	=	i > j ? i+3 : j-3;
	}

  hidog::numeric::matrix<int>	m3;

  m3   =   m1 + m2;

  std::cout << m3 << "\n";
  std::cout << m1 + m2 << "\n";
  std::cout << m1 - m2 << "\n";


  return   0;
}
