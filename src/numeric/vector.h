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
	
	vector<T>	operator = ( vector<T> v );


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
// class
template	vector<int>;

// function
template	void print<int>( vector<int> vec );

template	std::ostream&	operator << ( std::ostream& out, vector<int>& vec );

template	vector<int>		operator +  ( vector<int> &a, vector<int> &b );


	
}	// end namespace numeric
}	// end namespace hidog




#endif