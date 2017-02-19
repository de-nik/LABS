#include "Header.h"
TVector::TVector() {
	Vector = new int[0];
	Size = 0;
}
TVector::~TVector() {
	delete[] Vector;
}

TVector::TVector(int* arr, int n) {
	Size = n;
	Vector = new int[n];
	for (int i = 0; i < n; i++)
		Vector[i] = arr[i];
}

int TVector::operator [](int index) {
	if (index > Size) return 0;
	return Vector[index];
}

TVector & TVector::operator = (TVector& rhs) {
	Vector = new int[Size];
	Size = rhs.Size;
	for (int i = 0; i < Size; i++)
		Vector[i] = rhs.Vector[i];
	return *this;
}
int TVector::Length() const {
	return Size;
}
TVector operator ^ (TVector Vector, int* arr) {
	int *result = new int[Vector.Length()];
	for (int i = 0; i < Vector.Length(); i++)
		result[i] = Vector[i] ^ arr[i];
	TVector obj(result, Vector.Length());
	delete[] result;
	return obj;
}
