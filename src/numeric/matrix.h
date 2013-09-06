#ifndef _HIDOG_MATRIX_H
#define _HIDOG_MATRIX_H

#include "shared.h"
#include "vector.h"



namespace	hidog
{
namespace	numeric
{






template<class T>
class	matrix
{
public:
	matrix();
	matrix( int _w, int _h );
	~matrix();

	T&	operator () ( int x, int y );


private:
	vector<T>	*data;
	int			_width;
	int			_height;

};




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~




// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ template ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// �� define �ӧֳt���ͻݭn���˪O�Ҳ�
#define	hnMatrixTypeDefineMacro( type ) \
	template	matrix<type>; 


hnMatrixTypeDefineMacro(int);
hnMatrixTypeDefineMacro(double);






}	// end namespace numeric
}	// end namespace hidog


#endif