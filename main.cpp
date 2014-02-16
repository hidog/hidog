
#include <iostream>
#include <cstdlib>

#include "./src/numeric/vector.h"

using namespace std;

int		main()
{
	cout << "This is hidog's test\n";

	hidog::numeric::vector<int>	vec(10);
	for( int i = 0; i < 10; i++ )
		vec(i)	=	i + 3;
	for( int i = 0; i < 10; i++ )
		cout << vec(i) << endl;


#ifdef _WIN32
	system("PAUSE");
#endif
	return	0;
}