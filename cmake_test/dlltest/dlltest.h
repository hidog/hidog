#ifndef DLL_TEST_H
#define DLL_TEST_H


#include "shared.h"





class 	DLL_EXPORT 	DllTestObj
{
public:
	DllTestObj();
	~DllTestObj();
	
	void 	message();
	
	setMemberDataMacro( int, data )
	getMemberDataMacro( int, data )

private:
	int 	data;

};


#endif