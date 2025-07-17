#include <locale.h> //библиотека для задач, связанных с локализацией
#include <iostream>
#include <fstream> //для считывания данных из файла и для записи в файл
#include <string>
#include <vector> //для динамических массивов
#include <Windows.h>

using namespace std;

struct str { //структура для списка
	string Surname;
	string Name;
	string Age;
};

template <typename T> //объявление параметра шаблона
void sort(vector<T>& mas, int var, int first, int last) {
	if (var == 1) { // по фамилии
		int f = first;
		int l = last;
		str mid = mas[(f + l) / 2]; // вычисление начального элемента середины
		do { //меняем аргументы местами, пока первые символы меньше последних
			while (mas[f].Surname < mid.Surname)
				f++;
			while (mas[l].Surname > mid.Surname)
				l--;
			if (f <= l)
				std::swap(mas[f++], mas[l--]); //swap обменивает значения аргументов
		} while (f <= l);
		if (first < l)
			sort(mas, var, first, l);
		if (f < last)
			sort(mas, var, f, last);
	}
	if (var == 2) // по имени
	{
		int f = first, l = last;
		str mid = mas[(f + l) / 2]; // вычисление начального элемента середины
		do {
			while (mas[f].Name < mid.Name)
				f++;
			while (mas[l].Name > mid.Name)
				l--;
			if (f <= l)
				std::swap(mas[f++], mas[l--]); //swap обменивает значения аргументов
		} while (f <= l);
		if (first < l)
			sort(mas, var, first, l);
		if (f < last)
			sort(mas, var, f, last);
	}
	if (var == 3) { // по возрасту
		int f = first;
		int l = last;
		str mid = mas[(f + l) / 2]; // вычисление начального элемента середины
		do {
			while (mas[f].Age < mid.Age)
				f++;
			while (mas[l].Age > mid.Age)
				l--;
			if (f <= l)
				std::swap(mas[f++], mas[l--]); //swap обменивает значения аргументов
		} while (f <= l);
		if (first < l)
			sort(mas, var, first, l);
		if (f < last)
			sort(mas, var, f, last);
	}
}

void output(vector<str>& mas) {
	for (auto i : mas)
		cout << i.Surname << " " << i.Name << " " << i.Age << endl;
}

int main(){
	SetConsoleCP(1251); //устанавливает кодировку ввода из консоли и из редактора кода
	SetConsoleOutputCP(1251); //устанавливает кодировку вывода на консоль
	int n = 5; // возраст и количество учеников в классе
	int var = 0; // здесь будет храниться выбор пользователя
	vector <str> massort(n); //динамический массив для сортировки
	string path = "D:\\Study\\Универ\\Языки программирования\\file.txt"; //ссылка на файл с данными
	ifstream file(path); //открытие файла с данными
	if (file.is_open()) { // ввод с файла где каждая строка через пробел имеет значения Фамилия Имя Возраст
		int i = 0;
		while (!file.eof()) { //метод проверки достигнут ли конец файла
			getline(file, massort[i].Surname, ' '); //считывание фамилии
			getline(file, massort[i].Name, ' '); //считывание имени
			getline(file, massort[i].Age); //считывание возраста
			i++;
		}
		file.close(); //закрытие файла
	}
	else {
		cout << "Файл не найден \n";
	}
	int first = 0, last = n - 1;
	while (true) { //создание непрерывного цикла
		cout << "Что вы хотите выполнить? \n"
			<< "1. Сортировка по фамилии;\n"
			<< "2. Сортировка по имени;\n"
			<< "3. Сортировка по возрасту;\n"
			<< "4. Выход.\n";
		cin >> var;
		switch (var) {
		case 1:
			sort(massort, var, first, last);
			output(massort);
			break;
		case 2:
			sort(massort, var, first, last);
			output(massort);
			break;
		case 3:
			sort(massort, var, first, last);
			output(massort);
			break;
		case 4:
			return 0;
		default:
			cout << "Ошибка ввода " << endl;
		}
	}
	return 0;
}