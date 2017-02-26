#include <fstream>
#include <iostream>
#include <string>
#include <Windows.h>
int Enter(std::string &buff) { // Функция для определения кол-ва строк
	setlocale(LC_ALL, "rus");
	int n = 0;
	char *st = new char[buff.length() + 1];
	strcpy_s(st, buff.length() + 1, buff.c_str());
	char *next_token = NULL;
	char* pch = strtok_s(st, " ,.-", &next_token);
	while (pch != NULL)
	{
		pch = strtok_s(NULL, " ,.-", &next_token);
		n++;
	}
	delete[]st;
	return n;
}
void Find(int n, std::string* STR) {
	int Sos = 0, d = 0; //Кол-во слов в радиусе для вывода
	std::string str;
	std::cout << "Введите слов для поиска и радиус вывода: ";
	std::cin >> str >> Sos;
	for (int i = 0; i < n; i++)
	{
		if (STR[i] == str)
		{
			if (i < Sos)
			{
				for (d = i; d >= 0; d--)
				{
					std::cout << STR[i - d];
				}
				for (d = 1; d <= Sos; d++)
				{
					std::cout << STR[i + d];
				}
				std::cout << "|" << std::endl;
			}
			else if (i > n - i)
			{
				for (d = Sos; d >= 0; d--)
				{
					std::cout << STR[i - d];
				}
				for (d = 1; d < n - i; d++)
				{
					std::cout << STR[i + d];
				}
				std::cout << "|" << std::endl;
			}
			else
			{
				for (d = Sos; d >= 0; d--)
				{
					std::cout << STR[i - d];
				}
				for (d = 1; d <= Sos; d++)
				{
					std::cout << STR[i + d];
				}
				std::cout << "|" << std::endl;
			}
		}

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
	n = Enter(buff);
	STR = new std::string[n];
	char *st = new char[buff.length() + 1];
	strcpy_s(st, buff.length() + 1, buff.c_str());
	char *next_token = NULL;
	char* pch2 = strtok_s(st, " ,.-", &next_token);
	int i = 0;
	while (pch2 != NULL)
	{
		STR[i] = pch2;
		pch2 = strtok_s(NULL, " ,.-", &next_token);
		i++;
	}
	Find(n, STR);
	fin.close();
	delete[]STR;
	delete[]st;
}
