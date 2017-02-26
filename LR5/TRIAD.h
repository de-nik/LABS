#include <iostream>
#include <string>
class TRIAD
{
private:
	int First, Second, Third;
public:
	TRIAD();
	TRIAD(int a, int b, int c);
	bool operator == (TRIAD &obj);
	bool operator >(TRIAD &obj);
	bool operator <(TRIAD &obj);
	void operator =(TRIAD &obj);
	void Change(int a, int b, int c);
};