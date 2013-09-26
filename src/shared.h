#ifndef _HIDOG_SHARED_H
#define _HIDOG_SHARED_H


#include <iostream>
#include <cstring>
#include <cassert>



#ifdef WIN32
#define		HIDOG_DLL_EXPORT	__declspec(dllexport)
#else
#define		HIDOG_DLL_EXPORT
#endif



// error exception handling 處理異常
#define	ErrorExceptionMacro( statement ) \
	try{ \
		if( !(statement) ) \
			throw	0; \
	}catch( int err ){ \
		std::cout << "error = " << err << " \n"; \
		assert(0); \
	}
		




void	error_msg( char *str );		// 印出錯誤訊息


#endif