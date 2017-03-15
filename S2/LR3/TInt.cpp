#include "TInt.h"
TInt::TInt() {
	Int = 0;
}
TInt::TInt(int iNt)
{
	Int = iNt;
}
TInt TInt::operator =(const TInt &rhs)
{
	if (this == &rhs)
	{
		return Int;
	}
	else return Int = rhs.Int;
}
TInt operator +(const TInt &rhs, const TInt &lhs)
{
	return (rhs.Int + lhs.Int);
}
TInt &operator +=(TInt &rhs, const TInt &lhs)
{
	rhs.Int += lhs.Int;
	return rhs;
}
TInt operator -(const TInt &rhs, const TInt &lhs)
{
	return rhs.Int + lhs.Int;
}
TInt &operator -=(TInt &rhs, const TInt &lhs)
{
	rhs.Int -= lhs.Int;
	return rhs;
}
TInt TInt::operator /(TInt &rhs)
{
	return rhs.Int / Int;
}
TInt TInt::operator *(TInt &rhs)
{
	return rhs.Int * Int;
}
TInt TInt::operator /=(const TInt &rhs)
{
	return Int /= rhs.Int;
}
TInt TInt::operator *=(const TInt &rhs)
{
	return Int *= rhs.Int;
}
bool TInt::operator==(const TInt& rhs) {
	return rhs.Int == Int;
}
const TInt& TInt::operator--(int) {
	Int--;
	return *this;
}
const TInt TInt::operator--() {
	TInt old(Int);
	Int--;
	return old;
}
const TInt& TInt::operator++(int) {
	Int++;
	return *this;
}
const TInt TInt::operator++() {
	TInt old(Int);
	Int++;
	return old;
}
int TInt::out() {
	return Int;
}

std::ostream & operator <<(std::ostream &out, TInt & str) {
	out << str.out();
	return out;
}