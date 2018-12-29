// lab3_2_caesar_cipher.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
// Lab 3 (task 2)
int main()
{
	// Caesar cipher encryption of an initialized char array

	char plaintext[] = "The quick brown fox jumps over the lazy dog"; // initialize original array
	char c; // var for the current character
	char *ciphertext = plaintext; // for clarity sake
	int shift_size = 3;

	std::cout << "PLAINTEXT:\t" << plaintext << std::endl;

	for (int i = 0; plaintext[i] != '\0'; ++i) // walk through the array
	{
		c = plaintext[i];

		if (c >= 'a' && c <= 'z') // lowercase letter
		{
			c += shift_size;
			if (c > 'z') // if the new c is not a letter
			{
				c = c - 'z' + 'a' - 1;
			}
			plaintext[i] = c;
		}
		else if (c >= 'A' && c <= 'Z') // uppercase letter
		{
			c += shift_size;
			if (c > 'Z')
			{
				c = c - 'Z' + 'A' - 1;
			}
			plaintext[i] = c;
		}
	}
	std::cout << "CIPHERTEXT:\t" << ciphertext << std::endl;

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
