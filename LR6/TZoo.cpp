#include "TZoo.h"
TZoo::TZoo(size_t capacity)
	: Capacity(capacity)
	, NumAnimals(0)
	, Time(0)

{
	Animals = new TPtrAnimal[Capacity];
	memset(Animals, 0, sizeof(TPtrAnimal) * Capacity);
}
bool TZoo::AddNewAnimal(TAnimal ** newAnimal)
{
	// Проверяем корректность входного параметра
	if (newAnimal == nullptr)
		return false;

	// Зоопарк полон, нельзя добавить нового зверя
	if (NumAnimals == Capacity)
		return false;

	// Добавляем зверя в массив
	Animals[NumAnimals] = *newAnimal;

	// Забираем зверя у старого владельца, чтобы не удалить зверя дважды
	*newAnimal = nullptr;

	// Увеличиваем счетчик
	++NumAnimals;

	return true;
}
size_t TZoo::Delete() {
	int CountOfDeath (0);
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		if (Animals[i] != nullptr) 
		{
			if (Animals[i]->Grow() >= Animals[i]->Deathage())
			{
				std::cout  << Animals[i]->GetName()  << " was died at age " <<  Animals[i]->GetAge() << std::endl;
				Animals[i]->Dec();
				Animals[i] = nullptr;
				CountOfDeath++;
			}
		}
	}
		for (size_t i = 0; i < NumAnimals; i++)
		{
			if (Animals[i] == nullptr)
			{
				Animals[i] = Animals[i + 1];
				Animals[i + 1] = nullptr;
			}
		}

	for (size_t i = NumAnimals - CountOfDeath; i < NumAnimals; ++i)
	{
		delete Animals[i];
	}
	NumAnimals = NumAnimals - CountOfDeath;
	std::cout << "NumAnimals: " << NumAnimals << " | Death: " << CountOfDeath << std::endl;
	return CountOfDeath;
}
void TZoo::More() 
{
	TLeo a;
	std::cout << "TLeo: " << a.Count() << std::endl;
	TTigris b;
	std::cout << "TTigris: " << b.Count() << std::endl;
	if (a.Count() >= 2)
	{
		TAnimal *newAn = *a.Born();
		AddNewAnimal(&newAn);
	}
	if (b.Count() >= 2)
	{
		TAnimal *newAn = *b.Born();
		AddNewAnimal(&newAn);
	}
}
void TZoo::Work()
{
	std::cout << "Time: " << Time << std::endl << "----------------" <<std::endl;
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		if (Animals[i] != nullptr)
		{
			Animals[i]->Live(Time);
		}
	}
	Time += STEP;
	if (Time > 24.f)
	{
		Time -= 28.f;
		Delete();
		More();
		system("pause");
	}

}

TZoo::~TZoo()
{
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		delete Animals[i];
	}
	delete[] Animals;
}