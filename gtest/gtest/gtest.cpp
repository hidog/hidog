// gtest.cpp : �w�q�D���x���ε{�����i�J�I�C
//

#include "stdafx.h"
#include <stdlib.h>
#include <gtest/gtest.h>


int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest( &argc, argv );
	RUN_ALL_TESTS();
		
	system("PAUSE");
	return	0;
}

