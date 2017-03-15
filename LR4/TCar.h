#include <iostream>
#include <string>
class TCar
{
protected:
	std::string Title;
	int Max;
public:
	TCar();
	virtual void Print();
};