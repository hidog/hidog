#ifndef GAUSS_FILTER_H
#define GAUSS_FILTER_H

#include <vector>
#include <cmath>
#include <boost/numeric/ublas/matrix.hpp>

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
	GaussFilter1D( int s );
	~GaussFilter1D();

	void		set_scale( int s );
	void		generate_map();			
	double&		operator () ( int index );		// get filter value.

private:
	int					scale;					

	double				mean;					
	double				deviation;				

	bVectorDouble		filter_map;				
};



/*******************************************************************************
	GaussFilter
********************************************************************************/
class	GaussFilter
{
public:
	GaussFilter();
	GaussFilter( int w, int l );
	~GaussFilter();

	void	generate_map();

	double&		operator	()	( int i, int j );	// get filter data.
	QImage		operator	()  ( QImage input );	// do gauss filter.

private:
	int				w_scale;						// scale of width and length.
	int				l_scale;									

	double			normalized;						// normalized«Y¼Æ

	GaussFilter1D	filter_w;
	GaussFilter1D	filter_l;
	bMatrixDouble	filter_map;						// filterªº¯x°}
};



#endif