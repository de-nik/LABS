#include <iostream>
#include <string>
#include <locale>
int main() {
	setlocale(LC_ALL, "rus");
	std::string pal, lap;
	while (pal != "exit") 
	{
		system("cls");
		std::cout << "Что-нибудь введите: ";
		std::cin >> pal;
		if (pal == "exit")
		{
			return 0;
		}
		lap = pal;
		std::reverse(lap.begin(), lap.end());
		if (lap == pal) 
		{
			std::cout << "Это палиндром!\n";
		}
		else 
		{
			std::cout << "К сожалению, это не палиндром\n";
		}
		system("pause");
	}
}
