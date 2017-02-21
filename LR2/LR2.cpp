#include <iostream>
#include <string>
class TExh 
{
private:
	int *Value, *Time, *T_V, Numb;
	std::string Title;
	TExh *a;
public:
	TExh() 
	{
		Value = nullptr;
		Time = nullptr;
		a = nullptr;
		Title = "\0";
	}
	TExh(const int Number) 
	{
		Numb = Number;
		Value = new int[Numb];
		T_V = new int[Numb];
		Time = new int[Numb];
		a = new TExh[Numb];
	}
	void Enter(std::string *c_title, int c_value, int c_time, int i) const
	{
		a[i].Title = *c_title;
		Value[i] = c_value;
		Time[i] = c_time;
		T_V[i] = Time[i] * Value[i];
	}
	int MAX(){
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
	void AverageValue(int n) const
	{
		std::cout << std::endl << "The parameters of all exhibits: " << std::endl;
		for (int i = 0; i < Numb; i++)
		{
			std::cout << "[" << i + 1 << "] " << "Title = " << a[i].Title << " | " << "Value = " << Value[i] << " | " << "Av. Value = " << Value[i] * Time[i] << std::endl;
		}
		std::cout << "------------------------------------------------------" << std::endl << "max ->" << std::endl;
		std::cout << "[" <<  n + 1 << "] " << "Title = " << a[n].Title << " | " << "Value = " << Value[n] << " | " << "Av. Value = " << T_V[n] << std::endl;
	}
	~TExh() 
	{
		delete[]Value;
		delete[]Time;
		delete[]T_V;
	}
};
int main() 
{
	int Value, Number, Time;
	std::string Title;
	std::cout << "Enter the number of exhibits: " << std::endl;
	std::cin >> Number;
	TExh obj(Number);
	std::cout << "Enter title, value of exhibits and time of exposure: " << std::endl;
	for (int i = 0; i < Number; ++i) 
	{
		std::cout << "[" << i + 1 << "]" << std::endl;
		std::cin >> Title >> Value >> Time;
		obj.Enter(&Title, Value, Time, i);
	}
	obj.AverageValue(obj.MAX());
	system("pause");
}
