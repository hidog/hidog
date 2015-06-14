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

	// 取 map 值用, 會自動將index 轉成 以 0 為中心
	double&		operator [] ( int index );

	// 取 map 值用, 會自動將index 轉成 以 0 為中心
	double&		operator () ( int index );

	// 產生filter map  固定 k = 2
	void	generate_DoG_map();		

	// 取出Dog的Map
	double	get_DoG( int index );

private:
	int					scale;					// 測量尺度 會影響mean deviation

	double				mean;					// 平均
	double				deviation;				// 標準差

	vector<double>		filter_map;				// filter的矩陣
	vector<double>		DoG;					// Laplacian of Gaussian的矩陣

	void				generate_map();			// 產生filter map
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

	// 取 map 值用, 會自動將index 轉成 以 0 為中心
	// 未來看是否能改成 [] 的方式. (因為boost的matrix沒提供這樣的作法...得自己寫)
	//double&		get_map ( int i, int j );
	double&		operator	()	( int i, int j );


	QImage	do_filter( QImage passImage );


	// 沒有progress的do_filter
	QImage	do_filter_no_progress( QImage passImage );


private:
	int				w_scale;		// scale of width and length.
	int				l_scale;									

	double			mean_w,	mean_l;								// 平均值  同樣區分成兩個方向  跟均一平均值
	double			mean;

	double			deviation_w;								// 標準差
	double			deviation_l;
	double			deviation;

	double			normalized;									// normalized係數

	bVectorDouble	filter_map_w;								// 橫向的filter
	bVectorDouble	filter_map_l;								// 縱向的filter
	bMatrixDouble	filter_map;									// filter的矩陣
	bMatrixDouble	DOG;										// DoG的矩陣  用大寫是為了避免跟1D搞混

};












/*======================================================================================
	function區
========================================================================================*/



#endif