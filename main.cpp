
#include <iostream>
#include <cstdlib>

#include "./src/numeric/vector.h"
#include "./src/math/complex.h"
#include "./src/math/Fraction.h"
#include "./src/math/polynomial.h"



using namespace std;

int		main()
{
	cout << "This is hidog's test\n";

	hidog::numeric::vector<int>	vec(10);
	for( int i = 0; i < 10; i++ )
		vec(i)	=	i + 3;
	for( int i = 0; i < 10; i++ )
		cout << vec(i) << endl;


	hidog::math::Complex	c;
	c.image()	=	10;
	c.real()	=	-5;
	cout << c << endl;

	hidog::math::Fraction	f(10,23);
	cout << f.toDouble() << endl;
	
	int		a[10]	=	{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	hidog::math::Polynomial<int>	p( 10, a );
	cout << p << endl;


#ifdef _WIN32
	system("PAUSE");
#endif
	return	0;
}