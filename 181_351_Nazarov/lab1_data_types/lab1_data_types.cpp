// lab1_data_types.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "pch.h"
#include <iostream>
// Lab 1
int main()
{
	// Table of sizes and min/max values of basic C++ data types

	char separator[] = "+-----------------------+---------------+------------"
		"-------------------+-------------------------------+\n";
	std::cout << "\t\t\t\t\t      C++ DATA TYPES\n";
	std::cout << separator;
	std::cout << "|\tTYPE\t\t|\tSIZE\t|\tMIN\t\t\t|\tMAX\t\t\t|\n";
	std::cout << separator;
	std::cout << "|\tchar\t\t|\t" << sizeof(char) << "\t|\t" << CHAR_MIN
		<< "\t\t\t|\t" << CHAR_MAX << "\t\t\t|\n";
	std::cout << separator;
	std::cout << "|\tbool\t\t|\t" << sizeof(bool)
		<< "\t|\t0\t\t\t|\t1        \t\t|\n";
	std::cout << separator;
	std::cout << "|\tint\t\t|\t" << sizeof(int) << "\t|\t" << INT_MIN
		<< "\t\t|\t" << INT_MAX << "\t\t|\n";
	std::cout << separator;
	std::cout << "|\tshort\t\t|\t" << sizeof(short) << "\t|\t" << SHRT_MIN
		<< "\t\t\t|\t" << SHRT_MAX << "\t\t\t|\n";
	std::cout << separator;
	std::cout << "|\tlong\t\t|\t" << sizeof(long) << "\t|\t" << LONG_MIN
		<< "\t\t|\t" << LONG_MAX << "\t\t|\n";
	std::cout << separator;
	std::cout << "|\tlong long\t|\t" << sizeof(long long) << "\t|\t" << LLONG_MIN
		<< "\t|\t" << LLONG_MAX << "\t|\n";
	std::cout << separator;
	std::cout << "|\tdouble\t\t|\t" << sizeof(double) << "\t|\t" << DBL_MIN
		<< "\t\t|\t" << DBL_MAX << "\t\t|\n";
	std::cout << separator;

	return 0;
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
