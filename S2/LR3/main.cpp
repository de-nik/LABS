#include "TInt.h"
int main()
{
	try
	{
		TInt a(500000000000), b(500000000000), e(7);
		a *= b;
		std::cout << a << "|" << b << std::endl;
	}
	catch (OverFlow &exc)
	{
		std::cout << "Error" << std::endl;
	}

}