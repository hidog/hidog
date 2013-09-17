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

	void	resize( int _s );			// ≠´∑s®˙±o∞Oæ–≈È™≈∂°
	void	destroy();					// ≤M∞£∏ÍÆ∆ ƒ¿©Ò∞Oæ–≈È
	int		size();

	T&	operator () ( int index );
	T&	operator [] ( int index );
	
	vector<T>&	operator =  ( vector<T>& v );		// ¶≥®«ºg¶®≠˚ ¶≥®«ºg•˛∞Ï ¨O¨∞§F∑ÌΩd®“•Œ


    //friend  vector<T>& operator + <>( vector<T> &a, vector<T> &b );
    
    
private:
	T		*data;
	int		_size;

};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T>
void	print( vector<T> &vec );

template<class T>
std::ostream&	operator << ( std::ostream &out, vector<T> &vec );		// ºg¶® global function, ∑ÌΩd®“∞—¶“

template<class T>
vector<T>&	operator + ( vector<T> &a, vector<T> &b );

template<class T>
vector<T>&	operator - ( vector<T> &a, vector<T> &b );

template<class T>
bool	operator == ( vector<T> &a, vector<T> &b );
    
template<class T>
T   inner_prod( vector<T> &a, vector<T> &b );


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ template ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// •Œ define ®”ß÷≥t≤£•Õª›≠n™∫ºÀ™Oº“≤’
#define	hnVectorTypeDefineMacro( type ) \
	template class	vector<type>; \
	template 	void            print<type>( vector<type> &vec ); \
	template 	std::ostream&	operator << ( std::ostream &out, vector<type> &vec ); \
	template 	vector<type>&	operator +  ( vector<type> &a, vector<type> &b ); \
	template	vector<type>&	operator -	( vector<type> &a, vector<type> &b ); \
	template 	bool			operator == ( vector<type> &a, vector<type> &b ); \
    template    type            inner_prod( vector<type> &a, vector<type> &b );



	
}	// end namespace numeric
}	// end namespace hidog




#endif