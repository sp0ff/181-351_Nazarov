// lab4_functions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

// Here are some functions for arrays processing


void Caesar(char *text, int shift_size)
{
	// Caesar cipher encryption of a string

	char ch; // var for the current character

	std::cout << "Plantext:\t" << text << std::endl;

	for (int i = 0; text[i] != '\0'; ++i) // walk through the array
	{
		ch = text[i];

		if (ch >= 'a' && ch <= 'z') // lowercase letter
		{
			ch += shift_size;
			if (ch > 'z') // if the new c is not a letter
			{
				ch = ch - 'z' + 'a' - 1;
			}
			text[i] = ch;
		}
		else if (ch >= 'A' && ch <= 'Z') // uppercase letter
		{
			ch += shift_size;
			if (ch > 'Z')
			{
				ch = ch - 'Z' + 'A' - 1;
			}
			text[i] = ch;
		}
	}

	std::cout << "Ciphertext:\t" << text << "\n\n\n";
}

void Bubble(int *num_array, int number)
{
	// Bubble sort of an int array

	int tmp; // buffer

	std::cout << "Initial array:\t";
	for (int i = 0; i < number; ++i)
		std::cout << " " << num_array[i];
	std::cout << "\n";

	for (int i = 0; i < number - 1; ++i)
	{
		for (int j = 0; j < number - i - 1; ++j)
		{
			if (num_array[j] > num_array[j + 1])
			{
				tmp = num_array[j];
				num_array[j] = num_array[j + 1];
				num_array[j + 1] = tmp;
			}
		}
	}

	std::cout << "Sorted array:\t";
	for (int i = 0; i < number; ++i) std::cout << " " << num_array[i];

	std::cout << "\n\n\n";
}

void Shaker(int *num_array, int number)
{
	// Cocktail shaker sort of an int array

	int tmp; // buffer

	std::cout << "Initial array:\t";
	for (int i = 0; i < number; ++i) std::cout << " " << num_array[i];
	std::cout << "\n";

	for (int i = 0; i < number / 2; ++i)
	{
		int begin_idx = 0;
		int end_idx = number - 1;
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
	for (int i = 0; i < number; ++i) std::cout << " " << num_array[i];

	std::cout << "\n\n\n";
}

int main()
{
	char plaintext[] = "The quick brown fox jumps over the lazy dog";
	int numbers1[10] = { 1, 3, 2, 1, 0, 8, 34, 5, 13, 21 };
	int numbers2[10] = { 89, 55, 34, 610, 377, 233, 144, 2584, 1597, 987 };

	std::cout << "CAESAR CIPHER\n\n";
	Caesar(plaintext, 3);

	std::cout << "BUBBLE SORTING\n\n";
	Bubble(numbers1, 10);

	std::cout << "SHAKER SORTING\n\n";
	Shaker(numbers2, 10);

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
