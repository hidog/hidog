// hidog_dll.cpp : �w�q DLL ���ε{�����ץX�禡�C
//


#include "xcode_dylib.h""




void	hidog_dll_test()
{
	hidog::numeric::vector<int>		v;

	v.resize(10);

	for( int i = 0; i < 10; i++ )
		v(i)	=	i;

	std::cout << v << std::endl;


	hidog_dll_test2();

}


hidog_abc_class_test::hidog_abc_class_test()
{
	std::cout << "hidog_abc_class_test";
}


void	hidog_dll_test2()
{
	std::cout << "hidog_dll_test2\n" ;
}



#if 0
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		std::cout << "DLL_PROCESS_ATTACH\n";
		break;

	case DLL_THREAD_ATTACH:
		std::cout << "DLL_THREAD_ATTACH\n";

	case DLL_THREAD_DETACH:
		std::cout << "DLL_THREAD_DETACH\n";

	case DLL_PROCESS_DETACH:
		std::cout << "DLL_PROCESS_DETACH\n";
		break;
	}
	return TRUE; 
}
#endif






// ���ոѯx�}
hnVectorDouble	hidog_dll_solve_matrix( hnMatrixDouble A, hnVectorDouble b )
{
	ErrorExceptionMacro( A.width() == A.height() && A.width() == b.size() );

	const int	width	=	A.width();
	const int	height	=	A.height();

	int		i,	j,	k;
	double	r;				// �P�_����

	for( i = 0; i < width; i++ )
	{
		for( j = 0; j < width; j++ )
		{
			if( i == j )
				continue;

			ErrorExceptionMacro( A(i,i) != 0 );

			r	=	- A(j,i) / A( i,i );

			for( k = 0; k < height; k++ )
				A(j,k)	+=	A(i,k) * r;
			b(j)	+=	b(i) * r;

			//std::cout << A << "\n";
		}
	}

	// �̫ᰣ�W�﨤�x�}
	for( i = 0; i < b.size(); i++ )
		b(i)	/=	A(i,i);

	return	b;
}
