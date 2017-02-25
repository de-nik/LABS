#include "TCar.h"
class TBus : public TCar
{
public:
	int MaxPass;
	TBus() : TCar()
	{
		Title = "BUS";
		Max = 45;
		MaxPass = 30;
	}
	virtual void Print()
	{
		std::cout << Title << " : " << Max << " : " << MaxPass << std::endl;
	}
};