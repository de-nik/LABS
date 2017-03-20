#include "TInt.h"
#include <limits>
int main()
{
	try
	{
		TInt a(1073741824), b(1073741824), e(7);
		a -= b;
		std::cout << a << std::endl;
	}
	catch (OverFlow &exc)
	{
		std::cout << "Error" << std::endl;
	}

}