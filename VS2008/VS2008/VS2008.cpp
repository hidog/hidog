// VS2008.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

#include "numeric/matrix.h"
#include "math/fraction.h"
#include "math/polynomial.h"
#include "math/complex.h"

#include "../hidog_dll/hidog_dll.h"

#include <cv.h>
#include <highgui.h>



using namespace std;
using namespace cv;




int _tmain(int argc, _TCHAR* argv[])
{
	Mat		image;
	image	=	imread("test.bmp");
	
	imwrite( "output.bmp", image );

	imshow( "image show", image );
	waitKey(1);
	


	system("PAUSE");
	return 0;
}

