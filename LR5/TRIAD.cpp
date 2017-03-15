#include "TRIAD.h"
TRIAD::TRIAD()
{
	First = 0;
	Second = 0;
	Third = 0;
}
TRIAD::TRIAD(int a, int b, int c)
{
	First = a;
	Second = b;
	Third = c;
}
bool TRIAD::operator == (TRIAD &obj)
{
	if (First == obj.First && Second == obj.Second && Third == obj.Third)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TRIAD::operator >(TRIAD &obj) {
	if (First + Second + Third > obj.First + obj.Second + obj.Third)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TRIAD::operator <(TRIAD &obj) {
	if (First + Second + Third > obj.First + obj.Second + obj.Third)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void TRIAD::operator =(TRIAD &obj) {
	First = obj.First;
	Second = obj.Second;
	Third = obj.Third;
}
void TRIAD::Change(int a, int b, int c)
{
	First = a;
	Second = b;
	Third = c;
}
