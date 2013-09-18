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
	matrix( int , int  );
	matrix( matrix<T>& );
#ifdef MAC_OS
	matrix( const matrix<T>& );
#endif
	~matrix();

	int		width();
	int		height();

	void	resize( int, int );

	T&		operator () ( int, int );
	matrix&	operator =  ( matrix& );		


private:
	vector<T>	*data;
	int			_width;
	int			_height;

};




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T>
std::ostream&	operator << ( std::ostream&, matrix<T>& );




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ template ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 用 define 來快速產生需要的樣板模組
#define	hnMatrixTypeDefineMacro( type ) \
	template class	matrix<type>; \
	template std::ostream&	operator << <type>( std::ostream&, matrix<type>& );






}	// end namespace numeric
}	// end namespace hidog


#endif