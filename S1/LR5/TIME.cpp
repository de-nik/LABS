#include "TIME.h"
TIME::TIME() {
	Hour = 0;
	Minute = 0;
	Minute = 0;
}
TIME::TIME(int a, int b, int c)
{
	Hour = a;
	Minute = b;
	Minute = c;
}
TIME TIME::operator +(TIME &obj) 
{
	int hour = Hour + obj.Hour;
	int minute = Minute + obj.Minute;
	int second = Minute + obj.Minute;
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
	int second = Minute - obj.Minute;
	if (second < 0)
	{
		int i = 0;
		i = second / 60;
		minute += i - 1;
		second = 60 - (60 * i - second);
	}
	else if (second > 60)
	{
		int i = 0;
		i = second / 60;
		second -= i * 60;
		minute += i;
	}
	if (minute < 0) 
	{
		int i = 0;
		i = minute / 60;
		hour += i - 1;
		minute = 60 - (60 * i - minute);
	}
	else if (minute > 60) {
		int i = 0;
		i = minute / 60;
		minute -= i * 60;
		hour += i;
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
	if (Hour == obj.Hour && Minute == obj.Minute && Minute == obj.Minute)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TIME::operator >(TIME &obj)
{
	if (3600 * Hour + 60 * Minute + Second > 3600 * obj.Hour + 60 * obj.Minute + obj.Second)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool TIME::operator <(TIME &obj)
{
	if (3600 * Hour + 60 * Minute + Second < 3600 * obj.Hour + 60 * obj.Minute + obj.Second)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void TIME::operator =(TIME &obj)
{
	Hour = obj.Hour;
	Minute = obj.Minute;
	Second = obj.Second;
}
void TIME::Print() {
	std::cout << Hour << " hours " << Minute << " minutes " << Minute << "seconds" << std::endl;
}
