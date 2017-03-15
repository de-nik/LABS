#pragma once
#include <string>
#include <iostream>
class TAnimal
{
	std::string Name;
	size_t Age;
	size_t DeathAge;
	size_t BornAge;

public:
	TAnimal();
	TAnimal(const std::string & name, const size_t age, const size_t deathage, const size_t bornage);
	virtual ~TAnimal() = default;
	virtual void Live(float time) = 0;
	virtual void Dec() = 0;
	virtual size_t &AgeBorn() = 0;
	std::string GetName() const;
	size_t GetAge() const;
	size_t Grow();
	size_t Deathage();
	size_t Bornage();
};

