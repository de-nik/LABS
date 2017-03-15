#pragma once
#include "TCarnivora.h"
const float STEP = 4;
class TZoo
{
	typedef TAnimal * TPtrAnimal;
	TPtrAnimal * Animals;
	size_t Capacity;
	size_t NumAnimals;
	float Time;
public:
	TZoo(size_t capacity);
	bool AddNewAnimal(TAnimal ** newAnimal);
	void Work();
	void More();
	void ReLive(TZoo& place, int n, int m);
	size_t Delete();
	~TZoo();
};
