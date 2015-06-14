// vs2012.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <QtGui\QImage>
#include <stdio.h>
#include <stdlib.h>
#include "../src/imgproc/gaussfilter.h"

int _tmain(int argc, _TCHAR* argv[])
{
	QImage	img( "test.jpg" );

	GaussFilter		gf( 3, 5 );
	gf(img).save("output.bmp");
	

	system("PAUSE");
	return 0;
}

