// lab5_classes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
// 1. СИНТАКСИС ОБЪЯВЛЕНИЯ КЛАССА
//	class Имя_Класса
//	{
//		int hp; // число ХП
//		double speed; // скорость персонажа
//		void heal(); // восстановление ХП
//		void move(); // проигрывание анимации движения
//	}

// Определение класса и объекта
// СВОЙСТВО (property) - переменная в составе класса
// МЕТОД (method) - функция в составе класса
// ИНКАПСУЛЯЦИЯ - фактически, объединение данных и методов, объединённых
// единым смыслом, в одну конструкцию языка
// НАСЛЕДОВАНИЕ - создание производных классов от родительского и заимствование
// его свойств и методов
// ПОЛИМОРФИЗМ простыми словами: экземпляры одного класса ведут себя по-разному
// инкапсуляци, наследование и полиморфизм - три основные идеи ООП


// 2. СИНТАКСИС ОБЪЯВЛЕНИЯ ОБЪЕКТА И ОБРАЩЕНИЯ К СВОЙСТВАМ И МЕТОДАМ
// Имя_Класса объект1;
// car.speed = 123;
// объект1.свойство1 = 1;
// объект1.метод3();

// 3. СПЕЦИФИКАТОРЫ ДОСТУПА
// К  полям (свойствам и методам), объявленным в разделе public:
// можно обращаться везде (и из методов класса, и снаружи, где виден объект)
// К  полям private и protected можно обращаться только из методов
// самого класса. Различие между private и protected объясняется в следующей теме
// про наследование классов

#include <iostream>
#include <string>

void arr_equal(char *arr1, char *arr2)
{
	int len = strlen(arr1);
	for (int i = 0; i < len; i++)
	{
		arr2[i] = arr1[i];

	}
}
void print_arr(char *arr)
{
	int len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[i];
	}
}
class User_data
{
private:
	char first_name[255];
	char second_name[255];
	char str_passport[10];
	char str_birthdate[10];
public:
	User_data();
	User_data(char p_first_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10]);
	User_data(char p_first_name[255], char p_second_name[255]);
	~User_data();

	bool set_first_name(char *p_first_name)
	{
		// проверять на отсутствие цифр, точек и других знаков перпинания кроме "-"

		for (int i = 0; i != '\0'; i++)
		{
			if ((p_first_name[i] < 'A' || p_first_name[i] > 'Z') &&
				(p_first_name[i] < 'a' || p_first_name[i] > 'z') &&
				p_first_name[i] != '-')
			{
				return false;
			}
		}
		arr_equal(p_first_name, first_name);
		return true;
	}
	bool set_second_name(char *p_second_name)
	{
		for (int i = 0; i != '\0'; i++)
		{
			if ((p_second_name[i] < 'A' || p_second_name[i] < 'Z') &&
				(p_second_name[i] < 'a' || p_second_name[i] > 'z') &&
				p_second_name[i] != '-')
			{
				return false;
			}
		}
		arr_equal(p_second_name, second_name);
		return true;
	}
	bool set_birthdate(char *p_birthdate)
	{
		// должно соответствовать формату "00.00.0000"

		for (int i = 0; i < 10; i++)
		{
			if ((i == 2 || i == 5) && (p_birthdate[i] != '.'))
				return false;
			if (p_birthdate[i] < 0 || p_birthdate[i] > 9)
				return false;
		}
		arr_equal(p_birthdate, str_birthdate);
		return true;
	}
	bool set_passport(char *p_passport)
	{
		// должно соответствовать формату "0000000000"

		for (int i = 0; i < 10; i++)
		{
			if (p_passport[i] < 0 || p_passport[i] > 9)
				return false;
		}
		arr_equal(p_passport, str_passport);
		return true;

	}
};

User_data::User_data() {}
User_data::~User_data() {}
User_data::User_data(char p_f_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10]) {}
User_data::User_data(char p_f_name[255], char p_second_name[255]) {}
int main()
{
	User_data citizenfour;
	if (citizenfour.set_first_name("Edward"))
		std::cout << "First name OK\n";
	else
		std::cout << "Invalid first name!\n";

	if (citizenfour.set_second_name("Snowden"))
		std::cout << "Second name OK\n";
	else
		std::cout << "Invalid second name!\n";

	if (citizenfour.set_birthdate("21.06.1983"))
		std::cout << "Birthdate OK\n";
	else
		std::cout << "Invalid birthdate!\n";

	if (citizenfour.set_passport("0112358132"))
		std::cout << "Passport OK\n";
	else
		std::cout << "Invalid passport!\n";

	return 0;
}

// 4. КОНСТРУКТОР И ДЕСТРУКТОР КЛАССА
// В случае, если при создании объекта нужно выполнять сложные действия по
// инициализации, устновлению сетевого соединения, действия с файлами,
// выделение ОП и т.д. эти действия прописываются в специальном методе - конструкторе
// Конструктор вызывается автоматически при создании объекта
// В случае если при исчезновении объекта нужно общие системные ресурсы освобождать:
// закрывать порты, освобождать ОП, сохранять файлы и т.д. - эти действия
// прописываются в методе - деструкторе (вызывается автоматически при исчезновении объекта)
/*
user_data::user_data()
{
}
user_data::~user_data()
{
}
user_data::user_data(char p_first_name[255], char p_second_name[255],
	char p_str_passport[10], char p_str_birthdate[10])
{
	if(set_first_name(p_first_name) &&
	set_second_name(p_second_name) &&
	set_passport(p_str_passport) &&
	set_birthdate(p_str_birthdate))
		std::cout << "User OK\n";
	else
		std::cout << "User error\n";
}
user_data::user_data(char first_name[255], char second_name[255])
{
	//first_name = p_first_name
	//second_name = p_second_name
}
// 5. СТРУКТУРЫ
// Несмотря на то, что в литературе структура как правило хранит только данные,
// на самом деле это то же самое, что и класс. Единственное отличие - поля по
// умолчанию public
int main()
{
	std::cout << "Lab Classes" << std::endl;
	Student ivanov, petrov(331,21);
	petrov.age = 345;
	petrov.set_group(21322);
	std::cout << petrov.age << std::endl;
	user_data user1;
	user_data user2("asdas", "Ivanov", "123Ivan", "12.13.2345");
	user_data user3("Petrov", "Petr");
	return 0;
}
*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
