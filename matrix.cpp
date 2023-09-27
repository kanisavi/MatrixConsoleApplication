#include "matrix.h"
#include <iostream>

using namespace std;

TMatrix::TMatrix(int size)   // �������� ������� �� ���������
{
	r = size;      // ������ �������
	data = new number* [r];
	for (int j = 0; j < r; j++) {
		data[j] = new number[r];
		for (int i = 0; i < r; i++) {
			data[j][i] = 0.0;     // ���������� ������
		}
	}
	return;
};

void TMatrix::fill(int size)    // ���������� ������� � ����������
{
	r = size;
	data = new number* [r];
	for (int j = 0; j < r; j++) {
		data[j] = new number[r];
		for (int i = 0; i < r; i++) {
			cout << "element [" << j << "][" << i << "] = ";     
			cin >> data[j][i];   // ���� �������� �������� �������
		}
	}
	return;
}

void TMatrix::display()     // ����� ������� �� �����
{
	printf(" Matrix: \n");
	for (int j = 0; j < r; j++) {
		for (int i = 0; i < r; i++) {
			printf("%5.2f ", data[j][i]);    // ����� ������� �������� �������
		}
		cout << "\n";
	}
	cout << "\n";
	return;
}

number** TMatrix::TempMatrix(int size)    // �������� ��������� �������
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

void TMatrix::specialMatrix(number** m, number** temp, int i, int j, int size) {   // ������� ��� ���������� ������������
	int ki, kj, di, dj;
	di = 0;
	r = size;
	for (ki = 0; ki < r - 1; ki++) { // �������� ������� ������
		if (ki == i) di = 1;
		dj = 0;
		for (kj = 0; kj < r - 1; kj++) { // �������� ������� �������
			if (kj == j) dj = 1;
			temp[ki][kj] = m[ki + di][kj + dj];
		}
	}
}

number TMatrix::Determinant(number** m, int size) {     // ���������� ������������
	int i, j, k, n, r = size;
	number d;
	number** temp;
	temp = new number* [r];
	for (i = 0; i < r; i++)
		temp[i] = new number[r];
	j = 0; d = 0;
	k = 1; //(-1) � ������� i
	n = r - 1;
	if (r < 1) cout << "������������ ��������� ����������!";
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
		number** B = new number* [q]; // ��������� ����� ������� ������� q
		for (int w = 0; w < q; w++) 
			B[w] = new number[q];

		for (int a = 0; a < (r - (q - 1)); a++) // ������� ������ q-�� �������
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

				if (!(Determinant(B, q) == 0)) // ���� ������������ ������� ������� �� ����
				{ 
					rang = q; // ������������ ����� �������� q
				}
			}
		}
		q++; 
	}

	return rang;

}

void TMatrix::displayTransp(int size)    // ����� ����������������� �������
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
TMatrix::~TMatrix()    // ����������
{
	for (int j = 0; j < r; j++) {
		delete data[j];
	}
	delete[] data;
};
