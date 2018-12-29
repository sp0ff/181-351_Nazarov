// lab2_escape_sequences.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
// Lab 2
int main()
{
	// List of escape sequences

	std::cout << "Hello, world!\n";         // newline
	std::cout << "Hello, world!\t\n";       // horisontal tab
	std::cout << "Hello, world!\v\n";       // vertical tab
	std::cout << "Hello, world!\b\n";       // backspace
	std::cout << "Hello, world!\r\n";       // carriage return
	std::cout << "Hello, world!\f\n";       // form feed
	std::cout << "Hello, world!\a\n";       // alert
	std::cout << "Hello, world!\\\n";       // backslash
	std::cout << "Hello, world!\?\n";       // question mark
	std::cout << "Hello, world!\'\n";       // single quote
	std::cout << "Hello, world!\"\n";       // double quote
	std::cout << "Hello, world!\036\n";     // octal number
	std::cout << "Hello, world!\x0ff\n";    // hex number

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
