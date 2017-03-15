#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
int Enter(std::string &buff) { // Функция для определения кол-ва строк
	setlocale(LC_ALL, "rus");
	int n = 0;
	char *st = new char[buff.length() + 1];
	strcpy_s(st, buff.length() + 1, buff.c_str());
	char *Next = NULL;
	char* Sep = strtok_s(st, " ,.-", &Next);
	while (Sep != NULL)
	{
		Sep = strtok_s(NULL, " ,.-", &Next);
		n++;
	}
	delete[]st;
	return n;
}
void Find(int n, std::string* STR) {
	int Sos = 0; //Кол-во слов в радиусе для вывода
	std::string str;
	std::cout << std::endl << "Введите слов для поиска и радиус вывода: ";
	std::cin >> str >> Sos;
	int nm = 0, *num;
	num = new int[n];
	for (int i = 0; i < n; i++)
	{
		if (STR[i] == str)
		{
			num[nm] = i;
			nm++;
		}
	}
	int min = 0, max = 0;
	for (int i = 0; i <= nm; i++)
	{
		if ((num[i] - Sos) < 0)
		{
			min = 0;
			max = num[i] + Sos;
		}
		else if (num[i] + Sos >= n)
		{
			min = num[i] - Sos;
			max = n-1;
		}
		else
		{
			min = num[i] - Sos;
			max = num[i] + Sos;
		}
		for (int j = min; j <= max; j++)
		{
			std::cout << STR[j];
		}
		std::cout << std::endl;
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::ifstream fin("C:\\Users\\Синед\\Desktop\\ex.txt");
	std::string buff;
	std::string *STR;
	std::getline(fin, buff);
	int n = 0;
	char *st = new char[buff.length() + 1];
	strcpy_s(st, buff.length() + 1, buff.c_str());
	char *Next = NULL;
	char* Sep = strtok_s(st, " ,.-", &Next);
	n = Enter(buff);
	STR = new std::string[n];
	int i = 0;
	while (Sep != NULL)
	{
		STR[i] = Sep;
		std::cout << STR[i] << "|";
		Sep = strtok_s(NULL, " ,.-", &Next);
		i++;
	}
	Find(n, STR);
	fin.close();
	delete[]STR;
	delete[]st;
}
