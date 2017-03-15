#include "TInt.h"
int main()
{
	try
	{
		TInt a(5000000), b(5000000), e(7);
		a *= b;
		std::cout << a << "|" << b << std::endl;
	}
	catch (OverFlow &exc)
	{
		std::cout << "Error" << std::endl;
	}

}