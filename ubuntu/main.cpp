#include <iostream>

#include "../src/numeric/vector.h"
#include "../src/numeric/matrix.h"


int	main()
{
  hidog::numeric::vector<int>	v(10);

  int	i;

  for( i = 0; i < 10; i++ )
	v(i)	=	i;

  std::cout << v << "\n";

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

  //m3   =   m1 + m2;

  std::cout << m1 << "\n";
  std::cout << m1 + m2 << "\n";
  std::cout << m1 - m2 << "\n";


  return   0;
}
