#include <iostream>
#include <string>
class TCar
{
protected:
	std::string Title;
	int Max;
public:
	TCar()
	{
		Title = "CAR";
		Max = 60;
	}
	virtual void Print() {
		std::cout << Title << " : " << Max  << std::endl;
	}
};