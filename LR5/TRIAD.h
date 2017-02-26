#include <iostream>
#include <string>
class TRIAD
{
private:
	int First, Second, Third;
public:
	TRIAD();
	TRIAD(int a, int b, int c);
	virtual bool operator == (TRIAD &obj);
	virtual bool operator >(TRIAD &obj);
	virtual bool operator <(TRIAD &obj);
	virtual void operator =(TRIAD &obj);
	void Change(int a, int b, int c);
};
