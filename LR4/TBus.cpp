#include "TBus.h"
TBus :: TBus() : TCar()
{
	Title = "BUS";
	Max = 45;
	MaxPass = 30;
}
void TBus ::  Print()
{
	std::cout << Title << " : " << Max << " : " << MaxPass << std::endl;
}