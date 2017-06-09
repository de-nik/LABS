#include <iostream>
#include <thread>
#include "InfInt.h"


void factorial(int& n, InfInt& res)
{
	res = 1;
	for (int i = 1; i <= n; ++i)
	{
		res *= i;
	}
}

InfInt fc(int n, int k)
{
	if (k == n || k == 0)
		return 1;
	InfInt nf;
	InfInt kf;
	InfInt df;
	int dif = n - k;
	std::thread first(factorial, std::ref(n), std::ref(nf));
	std::thread second(factorial, std::ref(k), std::ref(kf));
	std::thread third(factorial, std::ref(dif), std::ref(df));
	first.join();
	second.join();
	third.join();
	InfInt res = nf / (kf*df);
	return res;
}
