#include "TInt.h"
TInt::TInt() {
	Int = 0;
}
TInt::TInt(const long long int iNt)
{
	if (iNt >= std::numeric_limits<int>::max() || iNt < std::numeric_limits<int>::min())
	{
		throw OverFlow();
	}
	else Int = iNt;
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
	if (rhs.Int != 0)
	{
		if ((lhs.Int * rhs.Int) / rhs.Int != lhs.Int)
		{
			throw OverFlow();
		}
		else return TInt(lhs.Int + rhs.Int);
	}
	else return TInt(lhs.Int + rhs.Int);
}
TInt &TInt::operator +=(const TInt &rhs)
{
	if (rhs.Int != 0)
	{
		if ((Int * rhs.Int) / rhs.Int != Int)
		{
			throw OverFlow();
		}
		else return *this;
	}
	else return *this;
}
TInt operator -(const TInt &lhs, const TInt &rhs)
{
	if (rhs.Int != 0)
	{
		if ((lhs.Int * rhs.Int) / rhs.Int != lhs.Int)
		{
			throw OverFlow();
		}
		else return TInt(lhs.Int + lhs.Int);
	}
	else return TInt(lhs.Int + lhs.Int);

}
TInt &TInt::operator -=(const TInt &rhs)
{
	if (rhs.Int != 0)
	{
		if ((Int * rhs.Int) / rhs.Int != Int)
		{
			throw OverFlow();
		}
		else return *this;
	}
	else return *this;
}
TInt operator /(TInt &lhs, TInt &rhs)
{
	return TInt(lhs.Int / rhs.Int);
}
TInt operator *(TInt &lhs, TInt &rhs)
{
	if (rhs.Int != 0)
	{
		if ((lhs.Int * rhs.Int) / rhs.Int != lhs.Int)
		{
			throw OverFlow();
		}
		else return TInt(lhs.Int * rhs.Int);
	}
	else return TInt(lhs.Int * rhs.Int);
}
TInt &TInt::operator /=(const TInt &rhs)
{
	Int /= rhs.Int;
	return *this;
}
TInt &TInt::operator *=(const TInt &rhs)
{
	if (rhs.Int != 0)
	{
		if ((Int * rhs.Int) / rhs.Int != Int)
		{
			throw OverFlow();
		}
		else {
			Int = Int * rhs.Int;
			return *this;
		}
	}
	else {
		Int = Int * rhs.Int;
		return *this;
	}
}
bool operator==(const TInt &rhs, const TInt &lhs) {
	return lhs.Int == rhs.Int;
}
TInt &TInt::operator++() {
	++Int;
	return *this;
}
TInt TInt::operator++(int) {
	TInt old(Int);
	Int++;
	return old;
}
TInt &TInt::operator--() {
	--Int;
	return *this;
}
TInt TInt::operator--(int) {
	TInt old(Int);
	Int--;
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
TInt TInt::operator & (const TInt & rhs) const {
	return TInt(Int & rhs.Int);
}
TInt TInt::operator ^ (const TInt & rhs) const {
	return TInt(Int ^ rhs.Int);
}
TInt TInt::operator | (const TInt & rhs) const {
	return TInt(Int | rhs.Int);
}
TInt TInt::operator << (const TInt & rhs) const {
	return TInt(Int << rhs.Int);
}
TInt TInt::operator >> (const TInt & rhs) const {
	return TInt(Int >> rhs.Int);
}