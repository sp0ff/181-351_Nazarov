#include "pch.h"
#include <iostream>
class Matrix {
	double **mat;
	int rows, columns;
public:
	Matrix();
	Matrix(int n_rows, int n_cols);
	Matrix(int n_cols)
	{
		rows = 1;
		columns = n_cols;
	}
	~Matrix();
	friend Matrix operator+(Matrix& a, Matrix& b);
	friend Matrix operator-(Matrix& a, Matrix& b);
	friend Matrix operator*(Matrix& a, Matrix& b);
	friend std::ostream& operator<<(std::ostream &os, Matrix& b);
	bool input();
	bool print();
	bool summMatrix(Matrix &mat2);
	bool multMatrix(Matrix &mat2);
	bool transp();
	int getRows() { return rows; }
	int getColumns() { return columns; }
	double getElem(int row, int col)
	{
		if (row < rows && col < columns && row > -1 && col > -1)
			return mat[row][col];
		std::cout << "Index error!" << std::endl;
		return -1;
	}
};
class Vector : public Matrix {
public:
	Vector();
	~Vector();
	double multVector(Vector &vec2);
	bool scalVector(double scal);
};
Matrix::Matrix()
{
}
Matrix::Matrix(int n_rows, int n_cols)
{
	rows = n_rows;
	columns = n_cols;
	mat = new double *[rows];
	for (int i = 0; i < rows; i++)
		mat[i] = new double[columns];
	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < columns; k++)
			mat[j][k] = 0;
	}

}
Matrix::~Matrix()
{
}
bool Matrix::input()
{
	std::cout << "Enter number of rows: ";
	std::cin >> rows;
	std::cout << std::endl;
	std::cout << "Enter number of columns: ";
	std::cin >> columns;
	std::cout << std::endl;

	if (rows > 0 && columns > 0)
	{
		mat = new double *[rows];
		for (int i = 0; i < rows; i++)
			mat[i] = new double[columns];

		for (int j = 0; j < rows; j++)
		{
			std::cout << "[row " << j + 1 << "]:" << std::endl;
			for (int k = 0; k < columns; k++)
				std::cin >> mat[j][k];
		}
		std::cout << std::endl;
		return true;
	}
	else
	{
		std::cout << "Invalid size!" << std::endl;
		std::cout << std::endl;
		return false;
	}
}
bool Matrix::print()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			std::cout << mat[i][j] << "\t";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return true;
}
bool Matrix::summMatrix(Matrix& mat2)
{
	if (rows == mat2.getRows() && columns == mat2.getColumns())
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				mat[i][j] += mat2.getElem(i, j);
		}
		return true;
	}
	else
	{
		std::cout << "Invalid summands!" << std::endl;
		std::cout << std::endl;
		return false;
	}
}
bool Matrix::multMatrix(Matrix& mat2)
{
	if (columns == mat2.getRows())
	{
		Matrix temp(this->rows, mat2.getColumns());
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < mat2.getColumns(); j++)
			{
				for (int k = 0; k < columns; k++)
				{
					temp.mat[i][j] +=
						mat[i][k] * mat2.mat[k][j];
				}
			}
		}
		columns = mat2.getColumns();
		for (int i = 0; i < rows; i++)
			delete[] mat[i];
		delete[] mat;
		mat = nullptr;
		mat = new double*[temp.getRows()];
		for (int i = 0; i < temp.getRows(); i++)
			mat[i] = new double[columns];
		for (int j = 0; j < rows; j++)
		{
			for (int k = 0; k < columns; k++)
				mat[j][k] = temp.mat[j][k];
		}
		return true;
	}
	else
	{
		std::cout << "Invalid multipliers!" << std::endl;
		std::cout << std::endl;
		return false;
	}
}
bool Matrix::transp()
{
	Matrix temp(this->columns, this->rows);
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < rows; j++)
		{
			temp.mat[i][j] = mat[j][i];
		}
	}
	for (int i = 0; i < rows; i++)
		delete[] mat[i];
	delete[] mat;
	mat = nullptr;
	mat = new double*[temp.getRows()];
	for (int i = 0; i < temp.getRows(); i++)
		mat[i] = new double[temp.getColumns()];
	rows = temp.getRows();
	columns = temp.getColumns();
	for (int j = 0; j < rows; j++)
	{
		for (int k = 0; k < columns; k++)
			mat[j][k] = temp.mat[j][k];
	}
	return true;
}
double Vector::multVector(Vector &vec2)
{
	double prod = 0;
	if (this->getColumns() == vec2.getColumns())
	{
		for (int i = 0; i < this->getRows(); i++)
		{
			for (int j = 0; j < this->getColumns(); j++)
				prod += this->getElem(i, j) * vec2.getElem(i, j);
		}
		return prod;
	}
}
bool Vector::scalVector(double scal)
{
	return true;
}
Matrix operator+(Matrix& a, Matrix& b)
{
	Matrix res(a.getRows(), a.getColumns());
	for (int i = 0; i < res.getRows(); i++)
	{
		for (int j = 0; j < res.getColumns(); j++)
			res.mat[i][j] = a.getElem(i, j) + b.getElem(i, j);
	}
	return res;
}
Matrix operator-(Matrix& a, Matrix& b)
{
	Matrix res(a.getRows(), a.getColumns());
	for (int i = 0; i < res.getRows(); i++)
	{
		for (int j = 0; j < res.getColumns(); j++)
			res.mat[i][j] = a.getElem(i, j) - b.getElem(i, j);
	}
	return res;
}
Matrix operator*(Matrix& a, Matrix& b)
{
	Matrix res(a.getRows(), b.getColumns());
	for (int i = 0; i < a.getRows(); i++)
	{
		for (int j = 0; j < b.getColumns(); j++)
		{
			for (int k = 0; k < a.getColumns(); k++)
				res.mat[i][j] += a.getElem(i, k)*b.getElem(k, j);
		}
	}
	return res;
}
Vector::Vector() {}
Vector::~Vector() {}

int main()
{
	std::cout << "[Matrices]" << std::endl;
	Matrix a; Matrix b;
	a.input(); b.input();
	std::cout << "---------------------------" << std::endl;
	std::cout << "Matrix A:" << std::endl;
	a.print();
	std::cout << "Matrix B:" << std::endl;
	b.print();
	std::cout << "A = A + B =" << std::endl;
	a.summMatrix(b); a.print();
	std::cout << "A = A * B =" << std::endl;
	a.multMatrix(b); a.print();
	std::cout << "A + B =" << std::endl;
	(a + b).print();
	std::cout << "A - B =" << std::endl;
	(a - b).print();
	std::cout << "A * B =" << std::endl;
	(a * b).print();
	std::cout << "Transposed A =" << std::endl;
	a.transp(); a.print();
	std::cout << "Transposed B =" << std::endl;
	b.transp(); b.print();
	std::cout << "[Vectors]" << std::endl;
	Vector c, d;
	c.input(); d.input();
	std::cout << "Vector C =" << std::endl;
	c.print();
	std::cout << "Vector D =" << std::endl;
	d.print();
	double prod = c.multVector(d);
	std::cout << "C * D = " << prod << std::endl;
	std::cout << "C + D = " << std::endl;
	(c + d).print();

	return 0;
}