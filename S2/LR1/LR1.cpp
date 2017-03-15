#include "LR1.h"
int intFromString(const char* data)
{
	std::cout << std::endl << "Welcome to <intFromString>(" << data << ")!" << std::endl;
	int Int = 0, CountOfInt = 0;
	std::vector <int> Arr(0);
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (isalpha(data[i]) || ispunct(data[i]) || isspace(data[i])) {
			throw Symbol();
		}
		else
		{
			char buf = data[i];
			Arr.insert(Arr.end(), buf - '0');
			CountOfInt++;
		}
	}
	int i, j;
	try
	{
		if (CountOfInt > 10)
		{
			throw OverFlow();
		}
		else
		{
			for (i = 0, j = CountOfInt - 1; i < CountOfInt; i++, j--)
			{
				int k = Int;
				Int = Arr[i] * pow(10, j) + Int;
				if (k > 0 && Int < 0)
				{
					throw OverFlow();
					break;
				}
				else if (k < 0 && Int > 0) {
					throw OverFlow();
					break;
				}
			}
		}
	}
	catch (OverFlow &exc)
	{
		std::cout << "	Error! " << std::endl;
		return false;
	}
	return Int;
}

bool boolFromString(const char * data)
{
	std::cout << std::endl << "Welcome to <boolFromString>(" << data << ")!" << std::endl;
	int Int = 0, CountOfInt = 0;
	std::vector <int> Arr(0);
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (isalpha(data[i]) || ispunct(data[i]) || isspace(data[i]) || data[i] == '0') {
			throw Symbol();
		}
		else
		{
			char buf = data[i];
			Arr.insert(Arr.end(), buf - '0');
			CountOfInt++;
		}
	}
	return true;
}

float floatFromString(const char * data)
{
	std::cout << std::endl << "Welcome to <floatFromString>(" << data << ")!" << std::endl;
	float Int = 0;
	int CountOfInt = 0, t = 0;
	std::vector <float> Arr(0);
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (isalpha(data[i]) || ispunct(data[i]) || isspace(data[i])) {
			if (data[i] != ',' && data[i] != '.')
			{
				throw Symbol();
			}
			else
			{
				t = CountOfInt;
			}
		}
		else
		{
			char buf = data[i];
			Arr.insert(Arr.end(), buf - '0');
			CountOfInt++;
		}
	}
	int i, j;
	try
	{
		if (CountOfInt <= 10)
		{
			for (i = 0, j = t - 1; i < t; i++, j--)
			{
				Int = Arr[i] * pow(10, j) + Int;
			}
			float b = 0;
			for (i = t, j = CountOfInt - t; i < CountOfInt; i++, j--)
			{
				b = Arr[i] * pow(10, j) + b;
			}
			b = b / pow(10, CountOfInt - t + 1);
			Int += b;
		}
		else throw OverFlow();
	}
	catch (OverFlow &exc)
	{
		std::cout << "Error! " << std::endl;
		return false;
	}
	return Int;
}

int main()
{
	try {
		std::cout << "FinalResult: " << intFromString("456") << std::endl;
		std::cout << "FinalResult: " << intFromString("456fjsd 6-7b8,s") << std::endl;
	} catch (Symbol &exc)
	{
		std::cout << "	Error!" << std::endl;
	}

	try
	{
		std::cout << "FinalResult: " << boolFromString("11111") << std::endl;
		std::cout << "FinalResult: " << boolFromString("11fgmvhm1101") << std::endl;
	} catch (Symbol &exc)
	{
		std::cout << "	Error!" << std::endl;
	}

	try
	{
		std::cout << "FinalResult: " << floatFromString("1.89") << std::endl;
		std::cout << "FinalResult: " << floatFromString("1fdgh.89dfg") << std::endl;
	} catch (Symbol &exc)
	{
		std::cout << "	Error!" << std::endl;
	}
}
