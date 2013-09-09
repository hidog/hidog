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
	
	vector<T>&	operator =  ( vector<T>& v );		// 有些寫成員 有些寫全域 是為了當範例用


private:
	T		*data;
	int		_size;

};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T>
void	print( vector<T> vec );

template<class T>
std::ostream&	operator << ( std::ostream &out, vector<T> &vec );		// 寫成 global function, 當範例參考

template<class T>
vector<T>&	operator + ( vector<T> &a, vector<T> &b );

template<class T>
vector<T>&	operator - ( vector<T> &a, vector<T> &b );

template<class T>
bool	operator == ( vector<T> &a, vector<T> &b );
    
template<class T>
T   inner_prod( vector<T> &a, vector<T> &b );


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ template ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 用 define 來快速產生需要的樣板模組
#ifndef MAC_OS
#define	hnVectorTypeDefineMacro( type ) \
	template class	vector<type>; \
	template 	void print<type>( vector<type> vec ); \
	template 	std::ostream&	operator << ( std::ostream &out, vector<type> &vec ); \
	template 	vector<type>&	operator +  ( vector<type> &a, vector<type> &b ); \
	template	vector<type>&	operator -	( vector<type> &a, vector<type> &b ); \
	template 	bool			operator == ( vector<type> &a, vector<type> &b ); \
    template    type            inner_prod( vector<type> &a, vector<type> &b );


hnVectorTypeDefineMacro(int);
hnVectorTypeDefineMacro(double);
#endif



	
}	// end namespace numeric
}	// end namespace hidog




#endif