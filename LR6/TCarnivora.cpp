#include "TCarnivora.h"
TCarnivora::TCarnivora(){ }
TCarnivora::TCarnivora(const std::string & name, const size_t age, const size_t deathage, const size_t bornage)
	: TAnimal(name, age, deathage, bornage)
{ }
void TCarnivora::Live(float time)
{
	if (time >= 6.f && time <= 7.f)
		std::cout << GetName() << " is eating" << std::endl;
	else
		std::cout << GetName() << " is sleeping" << std::endl;
}

TLeo::TLeo()
{ }

TLeo::TLeo(const std::string & name, const size_t age)
	: TCarnivora(name, age, 5, 2)
{
	++Count();
}

void TLeo::Live(float time)
{
	if (time >= 0.f && time <= 7.f)
		std::cout << GetName() << " " << GetAge() << " is killing" << std::endl;
	else if (time >= 8.f && time <= 15.f)
		std::cout << GetName() << " " << GetAge() << " is eating" << std::endl;
	else if (time >= 16.f && time <= 20.f)
		std::cout << GetName() << " " << GetAge() << " is sleeping" << std::endl;
	else
		std::cout << GetName() << " " << GetAge() << " is running" << std::endl;
}

TAnimal** TLeo::Born() {
	std::cout << "And the name of the new our prisoner(TLeo) is ";
	std::string name;
	std::cin >> name;
	TAnimal *Leo = new TLeo(name, 0);
	return &Leo;
}

size_t& TLeo::Count() 
{ 
	static size_t c = 0; 
	return c; 
}

void TLeo::Dec() 
{
	--Count();
}

TTigris::TTigris(){ }

TTigris::TTigris(const std::string & name, const size_t age)
	: TCarnivora(name, age, 7, 3)
{ 
	++Count();
}

void TTigris::Live(float time)
{
	if (time >= 8.f && time <= 15.f)
		std::cout << GetName() << " " << GetAge() << " is eating" << std::endl;
	else if (time >= 16.f && time <= 20.f)
		std::cout << GetName() << " " << GetAge() << " is sleeping" << std::endl;
	else if (time >= 21.f && time <= 24.f)
		std::cout << GetName() << " " << GetAge() << " is killing" << std::endl;
	else
		std::cout << GetName() << " " << GetAge() << " is running" << std::endl;
}

TAnimal** TTigris::Born() {
	std::cout << "And the name of the new our prisoner(TTigris) is ";
	std::string name;
	std::cin >> name;
	TAnimal *Tigris = new TLeo(name, 0);
	return &Tigris;
}

size_t& TTigris::Count() 
{ 
	static size_t c = 0; 
	return c; 
}

void TTigris::Dec() 
{
	--Count();
}