#ifndef _HIDOG_VECTOR_H
#define _HIDOG_VECTOR_H

#include "../shared.h"
#include <iostream>




namespace	hidog
{
namespace	numeric
{



/*******************************************************************************************
    vector obj
********************************************************************************************/
template<typename T>
class	vector
{
public:
	vector();		
	vector( int );
    vector( vector& );
//#ifdef MAC_OS
	vector( const vector& );
//#endif
	~vector();

	void	resize( int );              			// resize
	void	destroy();								// destroy
	int		size();

	T&	operator () ( int );
	T&	operator [] ( int );
	
	vector	operator =  ( vector );             // =  operator
	vector	operator +=	( vector );             // += operator
	vector	operator +=	( T );					// += operator
	vector	operator -=	( vector );             // -= operator
	vector	operator -=	( T );					// -= operator
    vector  operator -  ();                     // 轉成負號

private:
	T		*data;
	int		_size;

};


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
template<typename T>
void	print( vector<T>& );                                    // 測試用

template<typename T>
std::ostream&	operator << ( std::ostream&, vector<T> );		// << operator
    
template<typename T>
vector<T>	operator + ( vector<T>& , vector<T>& );

template<typename T>
vector<T>	operator - ( vector<T>&, vector<T>& );

template<typename T>
vector<T>	operator * ( vector<T>&, vector<T>& );              // dot

template<typename T>
vector<T>	operator * ( vector<T>&, T );                       // multiple

template<typename T>
vector<T>	operator * ( T , vector<T>& );                      // multiple

template<typename T>
bool		operator == ( vector<T>&, vector<T>& );
    
template<typename T>
T   inner_prod( vector<T>&, vector<T>& );


// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ template ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 利用macro來產生實體 俱現化等等
#define	hnVectorTypeDefineMacro( type ) \
	template class	vector<type>; \
	template 	void            print<type>( vector<type>& ); \
	template 	std::ostream&	operator << ( std::ostream&, vector<type> );	 \
	template 	vector<type>	operator +  ( vector<type>&, vector<type>& );	 \
	template	vector<type>	operator -	( vector<type>&, vector<type>& );	 \
	template	vector<type>	operator *	( vector<type>&, vector<type>& );	 \
	template	vector<type>	operator *	( vector<type>&, type );		 	 \
	template	vector<type>	operator *	( type , vector<type>& );		 	 \
	template 	bool			operator == ( vector<type>&, vector<type>& );	 \
    template    type            inner_prod( vector<type>&, vector<type>& );





	
}	// end namespace numeric
}	// end namespace hidog




#endif
