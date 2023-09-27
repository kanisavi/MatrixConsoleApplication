#ifndef MATRIX_H
#define MATRIX_H

#include "number.h"

class TMatrix
{
	int r;
	number** data;
public:
	TMatrix(int);
	~TMatrix(void);
	void display();
	void fill(int);
	void specialMatrix(number**, number**, int, int, int);
	double Determinant(number**, int);
	double** TempMatrix(int);
	int rang(int);
	void displayTransp(int);
};

#endif

