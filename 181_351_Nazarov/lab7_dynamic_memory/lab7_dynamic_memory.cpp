﻿// lab7_dynamic_memory.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
/* ЛР 7.
	ДИНАМИЧЕСКОЕ ВЫДЕЛЕНИЕ ПАМЯТИ
	--------------------------------------
	Для использования свободной памяти ОС (heap - "куча")
	объявляются динамические переменные по синтаксису
	указатель_на_тип имя_переменной = new тип;
	или
	тип * имя_переменной = new тип;
	Работа с динамической памятью происходит через указатели
	Преимущества
	1) доступно гораздо больше памяти, нежели в стеке
	2) размеры массиво
	Особенность:
	Можно очищать
	Чтобы очистить память delete название_указателя
	В динамической памяти могут выделяться только одномерные массивы
	тип * имя_указателя = new тип [длина];
	удаляются одномерные массивы с помощью записи
	delete[] имя_указателя
	Для выделения двумерного массива сначала создаётся одномерный массив
	содержащий указатели на другие массивы (строки)
	int ** dynamic2Darray = new int[l1]
	затем выделяется блок памяти под каждую строку и указатель на неё
	возвращается в созданный массив указателей
	for (int i = 0; i < l1; i++){
	dynamic2darray[i] = new int[l2];
		for (int j = 0; j < l2; j++){
		dynamic2Darray[i][j] = j;
		}}
	Чтобы удалить двумерный массив
	for(int i = 0; i < l1; i++){
		delete[] dynemic2Darray[i];
		}
	delete[] dynamic2Darray;*/

#include <iostream>

int main()
{
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
