﻿// lab3_4_shaker_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
// Lab 3 (4th task)
int main()
{
	// Cocktail shaker sort of an initialized array

	int num_array[10] = { 3, 1, 0, 1, 13, 5, 34, 21, 8, 2 };
	int n = 10;
	int tmp; // buffer

	std::cout << "Initial array:\t";
	for (int i = 0; i < n; ++i) std::cout << " " << num_array[i];
	std::cout << "\n";

	for (int i = 0; i < n / 2; ++i)
	{
		int begin_idx = 0;
		int end_idx = n - 1;
		while (begin_idx < end_idx)
		{
			if (num_array[begin_idx] > num_array[begin_idx + 1])
			{
				tmp = num_array[begin_idx];
				num_array[begin_idx] = num_array[begin_idx + 1];
				num_array[begin_idx + 1] = tmp;
			}
			++begin_idx;

			if (num_array[end_idx - 1] > num_array[end_idx])
			{
				tmp = num_array[end_idx - 1];
				num_array[end_idx - 1] = num_array[end_idx];
				num_array[end_idx] = tmp;
			}
			--end_idx;
		}
	}

	std::cout << "Sorted array:\t";
	for (int i = 0; i < n; ++i) std::cout << " " << num_array[i];
	std::cout << "\n";

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
