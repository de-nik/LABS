#include <thread>
#include <iostream>
#include "TZoo.h"



int main()
{
	TZoo myZoo(10);
	TAnimal * Leo = new TLeo("Leo_1", 1);
	TAnimal * Leo_2 = new TLeo("Leo_2", 2);
	TAnimal * Tigris_1 = new TTigris("Tigris_1", 2);
	TAnimal * Tigris_2 = new TTigris("Tigris_2", 2);
	if (!myZoo.AddNewAnimal(&Leo))
		delete Leo;
	if (!myZoo.AddNewAnimal(&Leo_2))
		delete Leo_2;
	if (!myZoo.AddNewAnimal(&Tigris_1))
		delete Tigris_1;
	if (!myZoo.AddNewAnimal(&Tigris_2))
		delete Tigris_2;
	for (size_t i = 0; i < 100; ++i)
	{
		myZoo.Work();
		std::cout << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	system("pause");
}