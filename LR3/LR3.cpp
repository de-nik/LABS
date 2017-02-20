#include "LR3.h"
TVector::TVector() { // Стандартный конструктор
	Vector = new int[0];
	Size = 0;
}
TVector::~TVector() { // Деструктор
	delete[] Vector;
}

TVector::TVector(int* arr, int size) { // Пользовательский конструктор
	Size = size;
	Vector = new int[size];
	memcpy(Vector, arr, Size * sizeof(int));
}

int TVector::operator [](int index) {
	if (index > Size) return 0;
	return Vector[index];
}

TVector & TVector::operator = (TVector& rhs) {
	Vector = new int[Size];
	Size = rhs.Size;
	memcpy(Vector, rhs.Vector, Size * sizeof(int));
	return *this;
}
int TVector::Length() const { //Возврат размера массива
	return Size;
}
TVector operator ^ (TVector Vector, int* arr) { // Побитовый оператор ^
	int *result = new int[Vector.Length()];
	for (int i = 0; i < Vector.Length(); i++)
		result[i] = Vector[i] ^ arr[i];
	TVector obj(result, Vector.Length());
	delete[] result;
	return obj;
}
