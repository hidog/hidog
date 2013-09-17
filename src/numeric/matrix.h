#ifndef _HIDOG_MATRIX_H
#define _HIDOG_MATRIX_H

#include "shared.h"
#include "vector.h"
#include <ostream>




namespace	hidog
{
namespace	numeric
{






template<class T>
class	matrix
{
public:
	matrix();
	matrix( int _w, int _h );
	matrix( matrix<T> &m );
	~matrix();

	int		width();
	int		height();

	T&	operator () ( int x, int y );


private:
	vector<T>	*data;
	int			_width;
	int			_height;

};




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T>
std::ostream&	operator << ( std::ostream &out, matrix<T>& mat );




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ template ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 用 define 來快速產生需要的樣板模組
#define	hnMatrixTypeDefineMacro( type ) \
	template class	matrix<type>; \
	template std::ostream&	operator << <type>( std::ostream &out, matrix<type>& mat );






}	// end namespace numeric
}	// end namespace hidog


#endif