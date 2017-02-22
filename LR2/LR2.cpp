#include <iostream>
#include <string>
class TExh
{
private:
	int *Value, *Time, Numb;
	std::string Title;
	TExh *a;
public:
	TExh()
	{
		Value = nullptr;
		Time = nullptr;
		a = nullptr;
		Numb = 0;
		Title = "\0";
	}
	TExh(const int Number)
	{
		Numb = Number;
		Value = new int[Numb];
		Time = new int[Numb];
		a = new TExh[Numb];
	}
	void Enter(const std::string *c_title, const int c_value, const int c_time, const int i)
	{
		a[i].Title = *c_title;
		Value[i] = c_value;
		Time[i] = c_time;
	}
	void AverageValue(int n) const
	{
		std::cout << std::endl << "The parameters of all exhibits: " << std::endl;
		for (int i = 0; i < Numb; i++)
		{
			std::cout << "[" << i + 1 << "] " << "Title = " << a[i].Title << " | " << "Value = " << Value[i] << " | " << "Av. Value = " << Value[i] * Time[i] << std::endl;
		}
		std::cout << "------------------------------------------------------" << std::endl << "max ->" << std::endl;
		std::cout << "[" << n + 1 << "] " << "Title = " << a[n].Title << " | " << "Value = " << Value[n] << " | " << "Av. Value = " << Value[n] * Time[n] << std::endl;
	}
	~TExh()
	{
		delete[]Value;
		delete[]Time;
	}
};
int MAX(const int *T_V, const int Numb){
	int max = T_V[0], n = 0;
	for (int i = 0; i < Numb; ++i)
	{
		if (T_V[i] > max)
		{
			max = T_V[i];
			n = i;
		}
	}
	return n;
}
int main()
{
	int Value;
	std::cout << "Enter the number of exhibits: " << std::endl;
	int Number;
	std::cin >> Number;
	TExh obj(Number);
	std::cout << "Enter title, value of exhibits and time of exposure: " << std::endl;
	int Time;
	int *T_V = new int[Number];
	std::string Title;
	for (int i = 0; i < Number; ++i)
	{
		std::cout << "[" << i + 1 << "]" << std::endl;
		std::cin >> Title >> Value >> Time;
		obj.Enter(&Title, Value, Time, i);
		T_V[i] = Value * Time;
	}
	obj.AverageValue(MAX(T_V, Number));
	delete[]T_V;
	system("pause");
}
