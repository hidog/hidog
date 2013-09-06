#ifndef _HIDOG_SHARED_H
#define _HIDOG_SHARED_H


#include <iostream>
#include <cstring>
#include <cassert>


// error exception handling  ���ե�
#define	ErrorExceptionMacro( statement ) \
	try{ \
		if( !(statement) ) \
			throw	0; \
	}catch( int err ){ \
		std::cout << "error = " << err << " \n"; \
		assert(0); \
	}
		




void	error_msg( char *str );		//  �L�X���~�T��



#endif