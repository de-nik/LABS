#include "TInt.h"
int main()
{
	TInt a(5), b(7);
	int c(5), d(6);
	a += b;
	a -= b;
	a *= b;
	a /= b;
	c = c&d;
	a = a;
	a++;
	a--;
	std::cout << a << (a == b) << std::endl;
}