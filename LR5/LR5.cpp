#include "TIME.h"
int main() 
{
	TRIAD obj(3, 5, 7);
	TRIAD obj2(8, 7, 9);
	obj = obj2;
	TRIAD obj3(6, 7, 9);
	std::cout << (obj == obj2) << " | " << (obj2 < obj3) << std::endl;
	TIME tm(4, 5, 23);
	TIME tm2(3, 8, 45);
	TIME tm3, tm4;
	tm3 = (tm - tm2);
	tm4 = (tm + tm2);
	tm3.Print();
	tm4.Print();
	std::cout << " == ? "<< (tm3 == tm4) << " < ? "<< (tm3 < tm4 ) << std::endl;

}
