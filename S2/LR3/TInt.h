#pragma once
#include <iostream>
class TInt
{
	int Int;
public:
	TInt();
	TInt(const int iNt);
	TInt operator =(const TInt &rhs);
	operator int();
	friend TInt operator +(const TInt &lhs, const TInt &rhs);
	friend TInt &operator +=(TInt &lhs, const TInt &rhs);
	friend TInt operator -(const TInt &lhs, const TInt &rhs);
	friend TInt &operator -=(TInt &lhs, const TInt &rhs);
	friend TInt operator /(TInt &lhs, TInt &rhs);
	friend TInt operator *(TInt &lhs, TInt &rhs);
	friend TInt &operator /=(TInt &lhs, const TInt &rhs);
	friend TInt &operator *=(TInt &lhs, const TInt &rhs);
	friend bool operator==(const TInt &lhs, const TInt &rhs);
	friend bool operator >(const TInt &lhs, const TInt &rhs);
	friend bool operator >=(const TInt &lhs, const TInt &rhs);
	friend bool operator <(const TInt &lhs, const TInt &rhs);
	friend bool operator <=(const TInt &lhs, const TInt &rhs);
	friend const TInt& operator++(TInt& i);
	friend const TInt operator++(TInt& i, int);
	friend const TInt& operator--(TInt& i);
	friend const TInt operator--(TInt& i, int);
	friend std::ostream & operator <<(std::ostream &out, TInt &str);
};
class CastException : public std::exception
{
};
class OverFlow : public  CastException {
};