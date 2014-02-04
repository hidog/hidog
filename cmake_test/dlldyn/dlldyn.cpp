#include "dlldyn.h"

#include <iostream>
using namespace std;


int		dll_dynamic_message( char *s )
{
	cout << "dll dynamic = " << s << endl;
	return	1;
}

