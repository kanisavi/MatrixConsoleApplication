#include "application.h"
#include "matrix.h"
#include <iostream>

using namespace std;

TApplication::TApplication()
{

}

int TApplication::exec()
{
	int ch, n = 2;
	TMatrix p(2);

	while (true)
	{
		ch = menu();
		switch (ch)
		{
		case 1:
		{
			cout << "size: ";
			cin >> n;
			p.fill(n);
			p.display();
			break;
		}
		case 2:
		{
			number** temp = p.TempMatrix(n);
			cout << "Determinant = " << p.Determinant(temp, n) << "\n\n";
		}
		break;
		case 3:
		{ 
			cout << "Rank = " << p.rang(n) << "\n\n";
		}
			break;
		case 4:
		{
			p.displayTransp(n);
		}
		break;
		case 5:
		{
			p.display();
		}
		break;
		case 0:
			return 0;
		default:
			cout << "Incorrect input. Try again\n\n";
			break;
		}
	}
}

int TApplication::menu()
{
	int ch;
	cout << "1 - fill matrix" << endl;
	cout << "2 - determinant" << endl;
	cout << "3 - rank" << endl;
	cout << "4 - transponent matrix" << endl;
	cout << "5 - display current matrix" << endl;
	cout << "0 - exit" << endl << "Your choice: ";
	cin >> ch;
	return ch;
}