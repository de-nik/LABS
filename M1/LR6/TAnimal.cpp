#include "TAnimal.h"
TAnimal::TAnimal()
	: Name()
	, Age(0)
	, DeathAge(0)
	, BornAge(0)
{ }

TAnimal::TAnimal(const std::string & name, const size_t age, const size_t deathage, const size_t bornage)
	: Name(name)
	, Age(age)
	, DeathAge(deathage)
	, BornAge(bornage)
{ }

std::string TAnimal::GetName() const
{
	return Name;
}

size_t TAnimal::GetAge() const
{
	return Age;
}
size_t TAnimal::Grow()
{
	Age++;
	if (Age >= Deathage()) --this->AgeBorn();
	if (Age >= Bornage()) ++this->AgeBorn();
	return Age;
}
size_t TAnimal::Deathage() {
	return DeathAge;
}
size_t TAnimal::Bornage() {
	return BornAge;
}
