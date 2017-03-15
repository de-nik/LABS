#pragma once
#include <iostream>
class TInt
{
	int Int;
public:
	TInt();
	TInt(int iNt);
	TInt operator =(const TInt &rhs);
	friend TInt operator +(const TInt &rhs, const TInt &lhs);
	friend TInt &operator +=(TInt &rhs, const TInt &lhs);
	friend TInt operator -(const TInt &rhs, const TInt &lhs);
	friend TInt &operator -=(TInt &rhs, const TInt &lhs);
	TInt operator /(TInt &rhs);
	TInt operator *(TInt &rhs);
	TInt operator /=(const TInt &rhs);
	TInt operator *=(const TInt &rhs);
	bool operator==(const TInt &rhs);
	const TInt &operator--(int);
	const TInt operator--();
	const TInt &operator++(int);
	const TInt operator++();
	int out();
};
std::ostream & operator <<(std::ostream &out, TInt & str);