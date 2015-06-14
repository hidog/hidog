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



	system("PAUSE");
	return 0;
}

