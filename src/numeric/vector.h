#ifndef _HIDOG_VECTOR_H
#define _HIDOG_VECTOR_H

#include "../shared.h"


namespace	hidog
{
namespace	numeric
{






template<class T>
class	vector
{
public:
	vector();
	~vector();

private:
	T		*data;
	int		size;
};







template	vector<int>;




	
}	// end namespace numeric
}	// end namespace hidog




#endif