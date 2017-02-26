#include "TIME.h"
TIME::TIME() {
	Hour = 0;
	Minute = 0;
	Second = 0;
}
TIME::TIME(int a, int b, int c)
{
	Hour = a;
	Minute = b;
	Second = c;
}
TIME TIME::operator +(TIME &obj) 
{
	int hour = Hour + obj.Hour;
	int minute = Minute + obj.Minute;
	int second = Second + obj.Second;
	if (second > 60)
	{ 
		int i = 0;
		i = second / 60;
		second -= i * 60;
		minute += i;
	}
	if (minute > 60) {
		int i = 0;
		i = minute / 60;
		minute -= i * 60;
		hour += i;
	}
	TIME t(hour, minute, second);
	return t;
}
TIME TIME::operator -(TIME &obj)
{
	int hour = Hour - obj.Hour;
	int minute = Minute - obj.Minute;
	int second = Second - obj.Second;
	if (second < 0)
	{
		int i = 0;
		i = second / 60;
		second = 0;
		minute += i - 1;
	}
	if (minute < 0) 
	{
		int i = 0;
		i = minute / 60;
		
	}
	if (hour < 0)
	{
		hour = 0;
		minute = 0;
		second = 0;
	}
	TIME t(hour, minute, second);
	return t;
}
bool TIME::operator ==(TIME &obj)
{
	return 1;
}
void TIME::Print() {
	std::cout << Hour << " | " << Minute << " | " << Second << std::endl;
}