#include "TRIAD.h"
class TIME : public TRIAD
{
private:
	int Hour, Minute, Second;
public:
	TIME();
	TIME(int a, int b, int c);
	TIME operator +(TIME &obj);
	TIME operator -(TIME &obj);
	bool operator ==(TIME &obj);
	bool operator >(TIME &obj);
	bool operator <(TIME &obj);
	void operator =(TIME &obj);
	void Print();
};
