// matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

class matrix {
	double matr[10][10];
	int rows, columns;
public:
	matrix();
	~matrix();
	matrix(int m_rows, int m_columns)
	{
		rows = m_rows; columns = m_columns;
	}
	int getRows() { return rows; }
	int getColumns() { return columns; }
	double getElem(int row, int col)
	{
		if (row < rows && col < columns && row > -1 && col > -1)
		{
			return matr[row][col];
		}
		else
		{
			std::cout << "Cannot get element. Index error!\n";
			return -1;
		}
	}
	
	bool summMatrix(matrix matr2)
	{
		if (matr2.getRows() != rows || matr2.getColumns() != columns)
		{
			std::cout << "Invalid size!";
			return false;
		}
		else
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

	}
	bool multMatrix(matrix matr2)
	{
		if (matr2.getRows() != columns)
		{
			std::cout << "Invalid size!";
			return false;
		}
		else
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

	}
	bool transp()
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				double tmp = matr[i][i];
				matr[i][j] = matr[j][i];
				matr[j][i] = tmp;
			}
		}
		return true;
	}
	bool print()
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
	bool input()
	{
		std::cout << "Enter number of rows: ";
		std::cin >> rows;
		if (rows < 1 || rows > 10)
		{
			std::cout << "Invalid value!";
			return false;
		}
		std::cout << "Enter number of columns: ";
		std::cin >> columns;
		if (columns < 1 || columns > 10)
		{
			std::cout << "Invalid value!";
			return false;
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
			{
				std::cin >> matr[i][j];
			}
		}
	}
};
class vector : public matrix {
private:
	double vec[10];
	int elements;
public:
	double getElem(int el)
	{
		if (el > 0 && el < elements)
			return vec[el];
		else
			return -1;
	}
	double scalMultVector(vector vec2)
	{
		double result;
		for (int i = 0; i < elements; i++)
		{
			result += vec[i] * vec2.getElem(i);
		}
		return result;
	}
	bool scalVector(double scalar)
	{
		for (int i = 0; i < elements; i++)
		{
			vec[i] *= scalar;
		}
		return true;
	}
};

int main()
{
	matrix matrA, matrB;
	matrA.input();
	matrB.input();
	matrA.transp(); matrA.print();
	matrA.summMatrix(matrB); matrA.print();
	matrA.multMatrix(matrB); matrA.print();
	return 0;
}
matrix::matrix() {}
matrix::~matrix() {}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
