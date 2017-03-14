#pragma once
#include <exception>
#include <ctype.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>
class CastException : public std::exception
{
};
class OverFlow : public  CastException {
};

class Symbol : public  CastException {
};
int StrLen(const char* Data) {
	int size = 0;
	for (; Data[size] != 0; size++);
	return size;
}
