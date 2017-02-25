#include "TBus.h"
int main() 
{
	TCar obj1;
	obj1.Print();
	TBus obj;
	obj.Print();
	TCar* obj2 = &obj;
	obj2->Print();
}
