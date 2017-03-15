#include "TInt.h"
TInt::TInt() {
	Int = 0;
}
TInt::TInt(int iNt)
{
	Int = iNt;
}
void TInt::operator =(const TInt &rhs)
{
	Int = rhs.Int;
}
TInt TInt::operator +(const TInt &rhs)
{
	TInt a = rhs.Int + Int;
	return a;
}
TInt &TInt::operator +=(const TInt &rhs)
{
	Int += rhs.Int;
	return *this;
}
TInt TInt::operator -(TInt &rhs)
{
	TInt a = rhs.Int + Int;
	return a;
}
TInt &TInt::operator -=(const TInt &rhs)
{
	Int -= rhs.Int;
	return *this;
}
int TInt::out() {
	return Int;
}

