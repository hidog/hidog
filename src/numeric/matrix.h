#ifndef _HIDOG_MATRIX_H
#define _HIDOG_MATRIX_H

#include "../shared.h"
#include "vector.h"
#include <ostream>




namespace	hidog
{
namespace	numeric
{






template<typename T>
class	matrix
{
public:
	matrix();
	matrix( int , int  );
	matrix( matrix<T>& );
#if defined(MAC_OS) || defined(LINUX)
	matrix( const matrix<T>& );
#endif
	~matrix();

	int		width();
	int		height();

	void	resize( int, int );

	T&		operator () ( int, int );
	matrix	operator =  ( matrix );		
	matrix	operator -  ();


private:
	vector<T>	*data;
	int			_width;
	int			_height;

};




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<typename T>
std::ostream&	operator << ( std::ostream&, matrix<T> );

template<typename T>
matrix<T>   operator + ( matrix<T>, matrix<T> );
    
template<typename T>
matrix<T>   operator - ( matrix<T>, matrix<T> );

template<typename T>
matrix<T>	operator * ( matrix<T>, matrix<T> );

template<typename T>
vector<T>	operator * ( matrix<T>, vector<T> );

template<typename T>
vector<T>	operator * ( vector<T>, matrix<T> );

template<typename T>
T		det( matrix<T>& );		// determine



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ template ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 用 define 來快速產生需要的樣板模組
#define	hnMatrixTypeDefineMacro( type ) \
	template class	matrix<type>; \
	template std::ostream&	operator << ( std::ostream&, matrix<type> ); \
    template matrix<type>   operator +  ( matrix<type>, matrix<type> ); \
    template matrix<type>   operator -  ( matrix<type>, matrix<type> ); \
	template matrix<type>	operator *	( matrix<type>, matrix<type> ); \
	template vector<type>	operator *	( matrix<type>, vector<type> ); \
	template vector<type>	operator *	( vector<type>, matrix<type> ); \
	template type			det( matrix<type>& );






}	// end namespace numeric
}	// end namespace hidog


#endif
