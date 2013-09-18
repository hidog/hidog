#ifndef SET_GTEST_CPP
#define SET_GTEST_CPP

#include <gtest/gtest.h>
#include "../test_src/vector_test.h"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ vector ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
TEST( vector, obj )
{
	for( int i = 0; i <= 1; i++ )
		EXPECT_EQ( true, vector_obj_test(i) );

}



#endif