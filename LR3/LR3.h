#include <iostream>
class TVector{
private:
	int* Vector;
	int Size;
public:
	TVector();
	~TVector();
	TVector(int* arr, int n);
	int operator [](int index);
	TVector & operator = (TVector & rhs);
	int TVector::Length() const;
};
TVector operator ^(TVector a, int * arr);
