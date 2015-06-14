#ifndef GAUSS_FILTER_H
#define GAUSS_FILTER_H

#include <vector>
#include <cmath>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/math/distributions/normal.hpp>

#include <QtGui\QImage>
#include "imgproc_def.h"

#include <fstream>
#include <iostream>


using namespace std;



/*******************************************************************************
	GaussFilter1D
********************************************************************************/
class	GaussFilter1D
{
public:
	GaussFilter1D();
	GaussFilter1D( int _scale );
	~GaussFilter1D();

	// �� map �ȥ�, �|�۰ʱNindex �ন �H 0 ������
	double&		operator [] ( int index );

	// �� map �ȥ�, �|�۰ʱNindex �ন �H 0 ������
	double&		operator () ( int index );

	// ����filter map  �T�w k = 2
	void	generate_DoG_map();		

	// ���XDog��Map
	double	get_DoG( int index );

private:
	int					scale;					// ���q�ث� �|�v�Tmean deviation

	double				mean;					// ����
	double				deviation;				// �зǮt

	vector<double>		filter_map;				// filter���x�}
	vector<double>		DoG;					// Laplacian of Gaussian���x�}

	void				generate_map();			// ����filter map
};



/*******************************************************************************
	GaussFilter
********************************************************************************/
class	GaussFilter
{
public:
	GaussFilter();
	GaussFilter( int _w, int _l );
	~GaussFilter();

	void	generate_map();

	// �� map �ȥ�, �|�۰ʱNindex �ন �H 0 ������
	// ���ӬݬO�_��令 [] ���覡. (�]��boost��matrix�S���ѳo�˪��@�k...�o�ۤv�g)
	//double&		get_map ( int i, int j );
	double&		operator	()	( int i, int j );


	QImage	do_filter( QImage passImage );


	// �S��progress��do_filter
	QImage	do_filter_no_progress( QImage passImage );


private:
	int				w_scale;		// scale of width and length.
	int				l_scale;									

	double			mean_w,	mean_l;								// ������  �P�˰Ϥ�����Ӥ�V  �򧡤@������
	double			mean;

	double			deviation_w;								// �зǮt
	double			deviation_l;
	double			deviation;

	double			normalized;									// normalized�Y��

	bVectorDouble	filter_map_w;								// ��V��filter
	bVectorDouble	filter_map_l;								// �a�V��filter
	bMatrixDouble	filter_map;									// filter���x�}
	bMatrixDouble	DOG;										// DoG���x�}  �Τj�g�O���F�קK��1D�d�V

};












/*======================================================================================
	function��
========================================================================================*/



#endif