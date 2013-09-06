#ifndef _HIDOG_VECTOR_H
#define _HIDOG_VECTOR_H

#include "../shared.h"
#include <iostream>






namespace	hidog
{
namespace	numeric
{






template<class T>
class	vector
{
public:
	vector();		
	vector( int _s );
	vector( vector& v );
	~vector();

	void	resize( int _s );			// 重新取得記憶體空間
	void	destroy();					// 清除資料 釋放記憶體
	int		size();

	T&	operator () ( int index );
	T&	operator [] ( int index );
	
	vector<T>	operator = ( vector<T> v );		// 當範例用



private:
	T		*data;
	int		_size;

};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T>
void	print( vector<T> vec );

template<class T>
std::ostream&	operator << ( std::ostream& out, vector<T>& vec );

template<class T>
vector<T>	operator + ( vector<T> &a, vector<T> &b );


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ template ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 用 define 來快速產生需要的樣板模組
#define	hnVectorTypeDefineMacro( type ) \
	template	vector<type>; \
	template	void print<type>( vector<type> vec ); \
	template	std::ostream&	operator << ( std::ostream& out, vector<type>& vec ); \
	template	vector<type>		operator +  ( vector<type> &a, vector<type> &b ); 


hnVectorTypeDefineMacro(int);
hnVectorTypeDefineMacro(double);




	
}	// end namespace numeric
}	// end namespace hidog




#endif