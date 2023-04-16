#include <iostream>
#include <cmath>
using namespace std;
void print_decimal(double a[][10], int x, int y)
{
	double m;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			m = a[i][j];
			m = round(m);
			if (m == -0)
			{
				cout << abs(m) << ' ';

			}
			else {
				cout << (long long)m << ' ';
			}
		}
		cout << endl;
	}
}
void print(int a[][10], int x, int y)
{
	int m;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			m = a[i][j];

			cout << m << ' ';
		}
		cout << endl;
	}
}
int determinant(int a[][10])
{
	int x;
	x = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
	return x;

}
long long short_cut(int a[][10], int x, int y, int s)
{
	long long product = 0;
	int KO[10][10];


	int c1 = 0;
	int z = 0;
	for (int i = 0; i < x - 1; i++)
	{


		if (i == 0)
		{
			c1++;
		}
		int c2 = 0;
		for (int j = 0; j < y - 1; j++)
		{
			if (j == s)
			{
				c2++;
			}
			KO[i][j] = a[c1][c2];

			c2++;



		}
		c1++;
		z = i;

	}
	if (z + 1 > 3)
	{

		for (int o = 0; o < z + 1; o++) {

			product = KO[0][o] * short_cut(KO, z + 1, z + 1, o) * ((long long)pow(-1, o)) + product;
		}
	}
	else {
		return determinant(KO);
	}


	return product;

}
long long determinant_YxZ(int a[][10], int x, int y)
{

	long long result = 0;
	if (x > 3)
	{
		for (int i = 0; i < x; i++) {
			result = a[0][i] * short_cut(a, x, y, i) * (long long)pow(-1, i) + result;
		}
		return result;
	}
	else if (x == 3)
	{
		int m;
		m = a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) - a[0][1] * (a[1][0] * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
		return m;
	}
	else if (x == 2)
	{
		int m;
		m = a[0][0] * a[1][1] - a[1][0] * a[0][1];
		return m;
	}
	else {
		return a[0][0];
	}

}
void arr_content(int a[][10], int x, int y)
{
	int m;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cin >> m;


			a[i][j] = m;

		}
	}
}
void addition(int a[][10], int b[][10], int x, int y)
{

	int sum[10][10];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			sum[i][j] = a[i][j] + b[i][j];
		}

	}
	print(sum, x, y);
}
void substraction(int a[][10], int b[][10], int x, int y)
{
	int subtraction[10][10];
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			subtraction[i][j] = a[i][j] - b[i][j];
		}

	}
	print(subtraction, x, y);
}
void multiplication(int a[][10], int b[][10], int x, int y, int z, int m)
{
	int multiplication[10][10];

	int p;
	int sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int k = 0; k < m; k++)
		{

			for (int j = 0; j < y; j++)
			{
				p = a[i][j] * b[j][k];
				sum = sum + p;
			}
			multiplication[i][k] = sum;
			sum = 0;
			p = 0;
		}
	}
	print(multiplication, x, m);
}
void multiplication_decimal(int a[][10], double b[][10], int x, int y, int z, int m)
{
	double multiplication[10][10];

	double p;
	double sum = 0;
	for (int i = 0; i < x; i++)
	{
		for (int k = 0; k < m; k++)
		{

			for (int j = 0; j < y; j++)
			{
				p = (float)a[i][j] * b[j][k];
				sum = sum + p;
			}
			multiplication[i][k] = sum;
			sum = 0;
			p = 0;
		}
	}
	print_decimal(multiplication, x, m);
}
void division(int a[][10], int b[][10], int x, int y, int z, int m)
{
	double matrix[10][10];


	double h;


	double inverse[10][10];

	long long KO2[10][10];

	if (z > 2) {

		for (int t = 0; t < z; t++)
		{

			for (int s = 0; s < m; s++)
			{


				int KO[10][10];
				int c1 = 0;
				for (int i = 0; i < z - 1; i++)
				{


					if (i == t)
					{
						c1++;
					}
					int c2 = 0;
					for (int j = 0; j < m - 1; j++)
					{
						if (j == s)
						{
							c2++;
						}
						KO[i][j] = b[c1][c2];

						c2++;



					}
					c1++;


				}
				KO2[t][s] = (long long)pow(-1, (t + s)) * determinant_YxZ(KO, z - 1, m - 1);


			}
		}

		for (int q = 0; q < z; q++)
		{
			for (int w = 0; w < m; w++)
			{
				inverse[q][w] = (1.0 / determinant_YxZ(b, z, m)) * KO2[q][w];

			}
		}

		double v;

		for (int q = 0; q < z; q++)
		{
			for (int w = 0; w < m; w++)
			{
				v = inverse[w][q];
				matrix[q][w] = v;
			}
		}

		double matrix_2[10][10];
		for (int q = 0; q < x; q++)
		{
			for (int w = 0; w < y; w++)
			{
				h = a[q][w];
				matrix_2[q][w] = h;
			}
		}

		multiplication_decimal(a, matrix, x, y, z, m);
	}
	else if (z == 2) {
		int matrixb[10][10];

		for (int f = 0; f < 2; f++)
		{
			for (int s = 0; s < 2; s++)
			{
				matrixb[f][s] = b[f][s];
			}
		}
		int temp;
		temp = matrixb[0][0];
		matrixb[0][0] = matrixb[1][1];
		matrixb[1][1] = temp;
		temp = -1 * matrixb[1][0];
		matrixb[1][0] = temp;
		temp = -1 * b[0][1];
		matrixb[0][1] = temp;
		double matrix_2[10][10];
		for (int q = 0; q < z; q++)
		{
			for (int w = 0; w < m; w++)
			{
				inverse[q][w] = (1.0 / (determinant_YxZ(b, z, m))) * matrixb[q][w];

			}
		}
		for (int q = 0; q < x; q++)
		{
			for (int w = 0; w < y; w++)
			{
				h = a[q][w];
				matrix_2[q][w] = h;
			}
		}

		multiplication_decimal(a, inverse, x, y, z, m);
	}
	else {
		double matrix_2[10][10];
		inverse[0][0] = (1.0 / b[0][0]);
		for (int q = 0; q < x; q++)
		{
			for (int w = 0; w < y; w++)
			{
				h = a[q][w];
				matrix_2[q][w] = h;
			}
		}
		multiplication_decimal(a, inverse, x, y, 1, 1);
	}

}
int main()
{
	int operation;
	int x, y, z, m;
	int A[10][10];
	int B[10][10];
	cout << "Please enter dimensions of Matrix A:" << endl;
	cin >> x >> y;
	while (x < 1 || y < 1) {
		cout << "Please enter dimensions of Matrix A:" << endl;
		cin >> x >> y;
	}
	cout << "Please enter dimensions of Matrix B:" << endl;
	cin >> z >> m;
	while (z < 1 || m < 1) {
		cout << "Please enter dimensions of Matrix B:" << endl;
		cin >> z >> m;
	}
	cout << "Please enter values of Matrix A:" << endl;
	arr_content(A, x, y);
	cout << "Please enter values of Matrix B:" << endl;
	arr_content(B, z, m);


	do {
		cout << "Please choose operation type(1: A+B, 2: A-B, 3: AxB, 4: A*inverse(B), 5: |A|, 6: |B|, 7: quit):" << endl;
		cin >> operation;
		switch (operation)
		{
		case 1: { if (x == z && y == m)
		{
			addition(A, B, x, y);
		}
			  else {
			cout << "The operation you chose is invalid for the given matrices." << endl;
		}
		}
			  break;
		case 2: { if (x == z && y == m)
		{
			substraction(A, B, x, y);
		}
			  else {
			cout << "The operation you chose is invalid for the given matrices." << endl;
		}
		}
			  break;
		case 3:if (y == z) {
			multiplication(A, B, x, y, z, m);
		}
			  else {
			cout << "The operation you chose is invalid for the given matrices." << endl;
		}
			  break;
		case 4:  if (y == z && determinant_YxZ(B, z, m) != 0 && z == m)
		{

			division(A, B, x, y, z, m);
		}

			  else {
			cout << "The operation you chose is invalid for the given matrices." << endl;
		}
			  break;
		case 5: if (x == y) {

			cout << determinant_YxZ(A, x, y) << endl;
		}

			  else {
			cout << "The operation you chose is invalid for the given matrices." << endl;
		}
			  break;
		case 6: if (z == m) {

			cout << determinant_YxZ(B, m, z) << endl;;
		}

			  else {
			cout << "The operation you chose is invalid for the given matrices." << endl;
		}
			  break;
		case 7: cout << "Thank you!" << endl;

		}
	} while ((operation >= 1) && (operation < 7));
}