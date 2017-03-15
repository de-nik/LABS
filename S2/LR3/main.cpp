#include "TInt.h"
int main()
{
	TInt a(5), b(6);
	a += b;
	a -= b;
	std::cout << a << std::endl;
}