/**
 * @file Radiks.hpp
 * @author MEHMET SARBAK mehmet.sarbak@ogr.sakarya.edu.tr
 * @description Bu dosya Radiks sınıfının tanımını içerir. Radiks sort algoritması ile sıralama yapar.
 * @date 2022-12-25
 * @course 1 A
 * @assignment Odev 2
 */

#ifndef RADIKS_HPP
#define RADIKS_HPP

#include "Queue.hpp"
#include "Doku.hpp"
#include <cmath>

class Radiks{

	private:	
		Doku *doku;
		int MaxStepNumber(Doku *, int);
		int StepCount(int);
		
	public:
		Radiks(Doku *);
		Doku * sort(Doku*, int);
		~Radiks();
};

#endif