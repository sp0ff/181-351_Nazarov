// dynamic_matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

class Matrix {
private:
	double **matr;
	int rows, columns;
public:
	Matrix();
	~Matrix();

	bool input();
	bool print();
	bool summMatrix(Matrix matr2);
	bool multMatrix(Matrix matr2);
	bool transp();
	int getRows()
	{
		return rows;
	}
	int getColumns()
	{
		return columns;
	}
	double getElem(int row, int col)
	{
		if (row < rows && col < columns && row > -1 && col > -1)
		{
			return matr[row][col];
		}
		std::cout << "Index error!\n";
		return -1;
	}
	friend Matrix operator+(Matrix& matrA, Matrix& matrB) {
		if (matrB.rows == matrA.rows && matrB.columns == matrA.columns)
		{
			Matrix res;
			res.rows = matrA.rows;
			res.columns = matrA.columns;
			res.matr = new double*[res.rows];
			for (int i = 0; i < res.rows; i++)
			{
				res.matr[i] = new double[res.columns];
				for (int j = 0; j < res.columns; j++)
				{
					res.matr[i][j] = matrA.matr[i][j] + matrB.matr[i][j];
				}
			}
			return res;
		}
		else
		{
			std::cout << "Ivalid matrix size!\n";
		}
	}
	friend Matrix operator-(Matrix& matrA, Matrix& matrB) {
		if (matrB.rows == matrA.rows && matrB.columns == matrA.columns)
		{
			Matrix res;
			res.rows = matrA.rows;
			res.columns = matrA.columns;
			res.matr = new double*[res.rows];
			for (int i = 0; i < res.rows; i++)
			{
				res.matr[i] = new double[res.columns];
				for (int j = 0; j < res.columns; j++)
				{
					res.matr[i][j] = matrA.matr[i][j] - matrB.matr[i][j];
				}
			}
			return res;
		}
		else
		{
			std::cout << "Ivalid matrix size!\n";
		}
	}
	friend Matrix operator*(Matrix& matrA, Matrix& matrB) {

		if (matrA.rows == matrB.columns)
		{
			Matrix res;
			res.columns = matrB.columns;
			res.rows = matrA.rows;
			res.matr = new double*[res.rows];
			for (int k = 0; k < res.columns; k++)
			{
				res.matr[k] = new double[res.columns];
				for (int i = 0; i < res.rows; i++)
				{
					for (int j = 0; j < matrB.columns; j++)
					{
						res.matr[i][j] += matrA.matr[i][k] * matrB.matr[k][j];
					}
				}
			}	
			return res;
		}
		else
		{
			std::cout << "Invalid matrix size!";
		}
	}
};
class Vector : public Matrix {
protected:
	double *vec;
	int elements;
public:

};
int main()
{
	Matrix x, y;
	x.input(); 
	x.print();
	y.input();
	y.print();
	(x + y).print();
	(x - y).print();
	(x * y).print();
	return 0;
}

Matrix::Matrix()
{

}

Matrix::~Matrix()
{

}

bool Matrix::input()
{
	std::cout << "Enter the number of rows and columns: ";
	std::cin >> rows >> columns;
	if (rows < 1 || columns < 1)
	{
		std::cout << "Invalid parameters!\n";
		return false;
	}
	std::cout << '\n';
	matr = new double*[rows];
	std::cout << "Enter the elements:\n";
	for (int i = 0; i < rows; i++)
	{
		matr[i] = new double[columns];
		for (int j = 0; j < columns; j++)
		{
			std::cin >> matr[i][j];
		}
	}
	return true;
}

bool Matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			std::cout << matr[i][j] << '\t';
		}
		std::cout << '\n';
	}
	return true;
}

bool Matrix::summMatrix(Matrix matr2)
{
	if (matr2.getRows() == rows && matr2.getColumns() == columns)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				matr[i][j] += matr2.getElem(i, j);
			}
		}
		return true;
	}
	else
	{
		std::cout << "Ivalid matrix size!\n";
		return false;
	}
}

bool Matrix::multMatrix(Matrix matr2)
{
	if (columns == matr2.getRows())
	{
		for (int k = 0; k < columns; k++)
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < matr2.getColumns(); j++)
				{
					matr[i][j] += matr[i][k] * matr2.getElem(k, j);
				}
			}

		}
		return true;
	}
	else
	{
		std::cout << "Invalid matrix size!\n";
		return false;
	}
}

bool Matrix::transp()
{
	double tmp;
	for (int i = 0; i < rows; i++)
	{
		for (int j = i + 1; j < columns; j++)
		{
			tmp = matr[i][j];
			matr[i][j] = matr[j][i];
			matr[j][i] = tmp;
		}
	}
	return true;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
