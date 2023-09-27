#include "matrix.h"
#include <iostream>

using namespace std;

TMatrix::TMatrix(int size)   // создание матрицы по умолчанию
{
	r = size;      // размер матрицы
	data = new number* [r];
	for (int j = 0; j < r; j++) {
		data[j] = new number[r];
		for (int i = 0; i < r; i++) {
			data[j][i] = 0.0;     // заполнение нулями
		}
	}
	return;
};

void TMatrix::fill(int size)    // заполнение матрицы с клавиатуры
{
	r = size;
	data = new number* [r];
	for (int j = 0; j < r; j++) {
		data[j] = new number[r];
		for (int i = 0; i < r; i++) {
			cout << "element [" << j << "][" << i << "] = ";     
			cin >> data[j][i];   // ввод значения элемента матрицы
		}
	}
	return;
}

void TMatrix::display()     // вывод матрицы на экран
{
	printf(" Matrix: \n");
	for (int j = 0; j < r; j++) {
		for (int i = 0; i < r; i++) {
			printf("%5.2f ", data[j][i]);    // вывод каждого элемента матрицы
		}
		cout << "\n";
	}
	cout << "\n";
	return;
}

number** TMatrix::TempMatrix(int size)    // создание временной матрицы
{
	r = size;
	number** m;
	m = new number* [r];
	for (int i = 0; i < r; i++)
		m[i] = new number[r];
	for (int j = 0; j < r; j++)
	{
		for (int i = 0; i < r; i++)
			m[j][i] = data[j][i];
	}
	return m;
}

void TMatrix::specialMatrix(number** m, number** temp, int i, int j, int size) {   // матрица для вычисления определителя
	int ki, kj, di, dj;
	di = 0;
	r = size;
	for (ki = 0; ki < r - 1; ki++) { // проверка индекса строки
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < r - 1; kj++) { // проверка индекса столбца
			if (kj == j) dj = 1;
			temp[ki][kj] = m[ki + di][kj + dj];
		}
	}
}

number TMatrix::Determinant(number** m, int size) {     // вычисление определителя
	int i, j, k, n, r = size;
	number d;
	number** temp;
	temp = new number* [r];
	for (i = 0; i < r; i++)
		temp[i] = new number[r];
	j = 0; d = 0;
	k = 1; //(-1) в степени i
	n = r - 1;
	if (r < 1) cout << "Определитель вычислить невозможно!";
	if (r == 1) {
		d = m[0][0];
		return(d);
	}
	if (r == 2) {
		d = m[0][0] * m[1][1] -(m[1][0] * m[0][1]);
		return(d);
	}
	if (r > 2) {
		for (i = 0; i < r; i++) {
			specialMatrix(m, temp, i, 0, r);
			d = d + k * m[i][0] * Determinant(temp, n);
			k = -k;
		}
	}
	return(d);
}

int TMatrix::rang(int size)

{
	r = size;
	int rang = 0;
	int q = 1;

	while (q <= r) 
	{ 
		number** B = new number* [q]; // создаение новой матрицы размера q
		for (int w = 0; w < q; w++) 
			B[w] = new number[q];

		for (int a = 0; a < (r - (q - 1)); a++) // перебор матриц q-го порядка
		{
			for (int b = 0; b < (r - (q - 1)); b++)
			{
				for (int c = 0; c < q; c++)
				{
					for (int d = 0; d < q; d++)
					{
						B[c][d] = data[a + c][b + d];
					}
				}

				if (!(Determinant(B, q) == 0)) // если определитель матрицы отличен от нуля
				{ 
					rang = q; // присваивание рангу значения q
				}
			}
		}
		q++; 
	}

	return rang;

}

void TMatrix::displayTransp(int size)    // вывод транспонированной матрицы
{
	r = size;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++)
			printf("%5.2f ", data[j][i]);
		cout << "\n";
	}
	cout << "\n";
	return;
}
TMatrix::~TMatrix()    // деструктор
{
	for (int j = 0; j < r; j++) {
		delete data[j];
	}
	delete[] data;
};
