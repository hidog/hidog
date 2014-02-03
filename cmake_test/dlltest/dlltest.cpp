#include "dlltest.h"
#include <iostream>


using namespace std;






DllTestObj::DllTestObj()
{
	data 	=	0;
}


DllTestObj::~DllTestObj()
{}

	
void 	DllTestObj::message()
{
	cout << "Dll Test Obj : data = " << data << endl;
}





