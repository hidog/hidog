// vs2012.cpp : �w�q�D���x���ε{�����i�J�I�C
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

