#include "TCar.h"
TCar::TCar()
{
	Title = "CAR";
	Max = 60;
}
void TCar::Print() {
	std::cout << Title << " : " << Max << std::endl;
}
