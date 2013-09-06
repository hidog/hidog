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
	vector( int _size );
	~vector();

	void	resize( int _size );		// 重新取得記憶體空間
	void	destroy();					// 清除資料 釋放記憶體

	T&	operator () ( int index );
	T&	operator [] ( int index );


private:
	T		*data;
	int		size;


};







template	vector<int>;




	
}	// end namespace numeric
}	// end namespace hidog




#endif