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
	vector( int );
	vector( vector& );
	~vector();

	void	resize( int );			// ≠´∑s®˙±o∞Oæ–≈È™≈∂°
	void	destroy();					// ≤M∞£∏ÍÆ∆ ƒ¿©Ò∞Oæ–≈È
	int		size();

	T&	operator () ( int );
	T&	operator [] ( int );
	
	vector<T>&	operator =  ( vector<T>& );			// ¶≥®«ºg¶®≠˚ ¶≥®«ºg•˛∞Ï ¨O¨∞§F∑ÌΩd®“•Œ   
	vector<T>&	operator +=	( vector<T>& );			// += operator
	vector<T>&	operator +=	( T );					// += operator
	vector<T>&	operator -=	( vector<T>& );			// -= operator
	vector<T>&	operator -=	( T );					// -= operator


private:
	T		*data;
	int		_size;

};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<class T>
void	print( vector<T>& );

template<class T>
std::ostream&	operator << ( std::ostream&, vector<T>& );		// ºg¶® global function, ∑ÌΩd®“∞—¶“

template<class T>
vector<T>&	operator + ( vector<T>& , vector<T>& );

template<class T>
vector<T>&	operator - ( vector<T>&, vector<T>& );

template<class T>
vector<T>&	operator * ( vector<T>&, vector<T>& );		// dot

template<class T>
vector<T>&	operator * ( vector<T>&, T );			// multiple

template<class T>
vector<T>&	operator * ( T , vector<T>& );			// multiple

template<class T>
bool	operator == ( vector<T>&, vector<T>& );
    
template<class T>
T   inner_prod( vector<T>&, vector<T>& );


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ template ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// •Œ define ®”ß÷≥t≤£•Õª›≠n™∫ºÀ™Oº“≤’
#define	hnVectorTypeDefineMacro( type ) \
	template class	vector<type>; \
	template 	void            print<type>( vector<type>& ); \
	template 	std::ostream&	operator << ( std::ostream&, vector<type>& );	 \
	template 	vector<type>&	operator +  ( vector<type>&, vector<type>& );	 \
	template	vector<type>&	operator -	( vector<type>&, vector<type>& );	 \
	template	vector<type>&	operator *	( vector<type>&, vector<type>& );	 \
	template	vector<type>&	operator *	( vector<type>&, type );		 	 \
	template	vector<type>&	operator *	( type , vector<type>& );		 	 \
	template 	bool			operator == ( vector<type>&, vector<type>& );	 \
    template    type            inner_prod( vector<type>&, vector<type>& );





	
}	// end namespace numeric
}	// end namespace hidog




#endif