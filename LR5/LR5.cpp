#include "TIME.h"
int main() 
{
	TRIAD obj(3, 5, 7);
	TRIAD obj2(8, 7, 9);
	obj = obj2;
	TRIAD obj3(6, 7, 9);
	std::cout << (obj == obj2) << " | " << (obj2 < obj3) << std::endl;
	TIME tm(0, 2, 0);
	TIME tm2(0, 0, 70);
	TIME tm3;
	tm3 = (tm - tm2);
	tm3.Print();
	int i = -70 / 60;
	std::cout << i;

}