// vs2012.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <QtGui\QImage>
#include <stdio.h>
#include <stdlib.h>


int _tmain(int argc, _TCHAR* argv[])
{
	QImage	img( 123, 123, QImage::Format_RGB888 );
	img.fill(0);

	img.setPixel( 10, 10, qRgb(255, 12, 44) );
	int r = qRed(img.pixel(10,10));

	printf("r = %d",r);

	img.save("123.bmp");


	system("PAUSE");
	return 0;
}

