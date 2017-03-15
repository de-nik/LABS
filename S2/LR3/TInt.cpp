#include "TInt.h"
TInt::TInt() {
	Int = 0;
}
TInt::TInt(const int iNt)
{
	long double m = iNt;
	if (m > 2147483648.0L || m < -2147483647.0L)
	{
		throw OverFlow();
	}
	Int = iNt;
}
TInt::operator int() {
	return Int;
}
TInt TInt::operator =(const TInt &rhs)
{
	if (this == &rhs)
	{
		return Int;
	}
	else return Int = rhs.Int;
}
TInt operator +(const TInt &lhs, const TInt &rhs)
{
	long double m = (lhs.Int + rhs.Int);
	if (m > 2147483648.0L || m < -2147483647.0L)
	{
		throw OverFlow();
	}
	else return TInt(lhs.Int + rhs.Int);
}
TInt &operator +=(TInt &lhs, const TInt &rhs)
{
	long double m = (lhs.Int += rhs.Int);
	if (m > 2147483648.0L || m < -2147483647.0L)
	{
		throw OverFlow();
	}
	else return lhs;
}
TInt operator -(const TInt &lhs, const TInt &rhs)
{
	long double m = (lhs.Int - rhs.Int);
	if (m > 2147483648.0L || m < -2147483647.0L)
	{
		throw OverFlow();
	}
	else return TInt(lhs.Int + lhs.Int);
}
TInt &operator -=(TInt &lhs, const TInt &rhs)
{
	long double m = (lhs.Int -= rhs.Int);
	if (m > 2147483648.0L || m < -2147483647.0L)
	{
		throw OverFlow();
	}
	else return lhs;
}
TInt operator /(TInt &lhs, TInt &rhs)
{
	return TInt(lhs.Int / rhs.Int);
}
TInt operator *(TInt &lhs, TInt &rhs)
{
	long double m = (lhs.Int * rhs.Int);
	if (m > 2147483648.0L || m < -2147483647.0L)
	{
		throw OverFlow();
	}
	else return TInt(lhs.Int * rhs.Int);
}
TInt &operator /=(TInt &lhs, const TInt &rhs)
{
	lhs.Int /= rhs.Int;
	return lhs;
}
TInt &operator *=(TInt &lhs, const TInt &rhs)
{
	long double m = (lhs.Int *= rhs.Int);
	if (m > 2147483648.0L || m < -2147483647.0L)
	{
		throw OverFlow();
	}
	else return lhs;
}
bool operator==(const TInt &rhs, const TInt &lhs) {
	return lhs.Int == rhs.Int;
}
const TInt& operator++(TInt& obj) {
	obj.Int++;
	return obj;
}
const TInt operator++(TInt& obj, int) {
	TInt old(obj.Int);
	obj.Int++;
	return old;
}
const TInt& operator--(TInt& obj) {
	obj.Int--;
	return obj;
}
const TInt operator--(TInt& obj, int) {
	TInt old(obj.Int);
	obj.Int--;
	return old;
}
bool operator >(const TInt &lhs, const TInt &rhs)
{
	return lhs.Int > rhs.Int;
}
bool operator >=(const TInt &lhs, const TInt &rhs)
{
	return lhs.Int >= rhs.Int;
}
bool operator <(const TInt &lhs, const TInt &rhs)
{
	return lhs.Int < rhs.Int;
}
bool operator <=(const TInt &lhs, const TInt &rhs)
{
	return lhs.Int <= rhs.Int;
}
std::ostream & operator <<(std::ostream &out, TInt & str) {
	out << str.Int;
	return out;
}