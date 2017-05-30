#include <exception>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>

class CastException : public std::exception
{
};
class OverFlow : public  CastException {
};

class Symbol : public  CastException {
};



int intFromString(const char* data)
{
	int Int = 0, CountOfInt = 0;
	std::vector <int> Arr(0);
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (ispunct(data[i]) || isspace(data[i]) || isalpha(data[i])) {
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

	if (CountOfInt > 10)
	{
		throw OverFlow();
	}

	else
	{
		for (i = 0, j = CountOfInt - 1; i < CountOfInt; i++, j--)
		{
			long double m = Arr[i] * pow(10, j) + Int;
			if (m > 2147483648.0L || m < -2147483647.0L)
			{
				throw OverFlow();
			}
			else Int = Arr[i] * pow(10, j) + Int;
		}
	}

	return Int;
}


bool boolFromString(const char* data) {
	if (data == "true")
	{
		return true;
	}
	else if (data == "false")
	{
		return false;
	}
	else throw Symbol();
}


float floatFromString(const char * data)
{
	double Int = 0;
	int CountOfInt = 0, t = 0;
	std::vector <float> Arr(0);
	for (int i = 0; data[i] != '\0'; i++)
	{
		if (ispunct(data[i]) || isspace(data[i]) || isalpha(data[i]))
		{
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
	if (t == 0) t = CountOfInt;
		for (i = 0, j = t - 1; i < t; i++, j--)
		{
			long double m = Arr[i] * pow(10, j) + Int;
			if (m > 2147483648.0L || m < -2147483647.0L)
			{
				throw OverFlow();
			}
			else Int = Arr[i] * pow(10, j) + Int;
			std::cout << Int << std::endl;
		}
		double b = 0;
		for (i = t, j = CountOfInt - t; i < CountOfInt; i++, j--)
		{
			b = Arr[i] * pow(10, j) + b;
		}
		b = b / pow(10, CountOfInt - t + 1);
		Int += b;
	return (float)Int;
}
