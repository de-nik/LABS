#pragma once
#include <iostream>

class TInt
{
	int Int;
public:
	TInt();
	TInt(const long long int iNt);
	TInt operator =(const TInt &rhs);
	operator int();
	friend TInt operator +(const TInt &lhs, const TInt &rhs);
	TInt &operator +=(const TInt &rhs);
	friend TInt operator -(const TInt &lhs, const TInt &rhs);
	TInt &operator -=(const TInt &rhs);
	friend TInt operator /(TInt &lhs, TInt &rhs);
	TInt &operator /=(const TInt &rhs);
	friend TInt operator *(TInt &lhs, TInt &rhs);
	TInt &operator *=(const TInt &rhs);
	friend bool operator==(const TInt &lhs, const TInt &rhs);
	friend bool operator >(const TInt &lhs, const TInt &rhs);
	friend bool operator >=(const TInt &lhs, const TInt &rhs);
	friend bool operator <(const TInt &lhs, const TInt &rhs);
	friend bool operator <=(const TInt &lhs, const TInt &rhs);
	TInt& operator++();
	TInt operator++(int);
	TInt& operator--();
	TInt operator--(int);
	friend std::ostream & operator <<(std::ostream &out, TInt &str);
	TInt TInt::operator & (const TInt & rhs) const;
	TInt TInt:: operator ^ (const TInt & rhs) const;
	TInt TInt:: operator | (const TInt & rhs) const;
	TInt TInt:: operator << (const TInt & rhs) const;
	TInt TInt:: operator >> (const TInt & rhs) const;
};
class CastException : public std::exception
{
};
class OverFlow : public  CastException {
};