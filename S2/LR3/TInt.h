#pragma once
#include <iostream>
class TInt
{
	int Int;
public:
	TInt();
	TInt(int iNt);
	void operator =(const TInt &rhs);
	TInt operator +(const TInt &rhs);
	TInt &operator +=(const TInt &rhs);
	TInt operator -(TInt &rhs);
	TInt &operator -=(const TInt &rhs);
	int out();
};
std::ostream & operator <<(std::ostream &out, TInt & str) {
	out << str.out();
	return out;
}