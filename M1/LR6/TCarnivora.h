#pragma once
#include <string>
#include <iostream>
#include "TAnimal.h"
class TCarnivora
	: public TAnimal
{
public:
	TCarnivora();
	TCarnivora(const std::string & name, const size_t age, const size_t deathage, const size_t bornage);
	virtual void Live(float time) override;
};

class TLeo
	: public TCarnivora
{
	size_t count;
public:
	TLeo();
	void Dec();
	TAnimal** Born();
	size_t &Count();
	size_t &AgeBorn();
	TLeo(const std::string & name, const size_t age);
	virtual void Live(float time) override;
};

class TTigris
	: public TCarnivora
{
	size_t count;
public:
	TTigris();
	void Dec();
	TAnimal** Born();
	size_t &Count();
	size_t &AgeBorn();
	TTigris(const std::string & name, const size_t age);
	virtual void Live(float time) override;
};
