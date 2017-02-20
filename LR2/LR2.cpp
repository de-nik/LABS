#include <iostream>
#include <string>
class TExh {
private:
	int *Value,
		*Time;
	std::string Title;
	TExh *a;
public:
	TExh() {

	}
	TExh(const int Number) {
		Value = new int[Number];
		Time = new int[Number];
		a = new TExh[Number];
	}
	void Enter(const std::string c_title, const int c_value, const int c_time, int i) {
		a[i].Title = c_title;
		Value[i] = c_value;
		Time[i] = c_time;
	}
	void AverageValue(const int Number, const int Buf) {
		std::cout << std::endl << "The parameters of all exhibits: " << std::endl;
		for (int i = 0; i < Number; i++)
			std::cout << "[" << i + 1 << "] " << "Title = " << a[i].Title << " | " << "Value = " << Value[i] << " | " << "Av. Value = " << Value[i] * Time[i] << std::endl;
		std::cout << "------------------------------------------------------" << std::endl << "max ->" << std::endl;
		std::cout << "[" << Buf + 1 << "] " << "Title = " << a[Buf].Title << " | " << "Value = " << Value[Buf] << " | " << "Av. Value = " << Value[Buf] * Time[Buf] << std::endl;
	}
	~TExh() {
		delete[]Value;
		delete[]Time;
	}
};
int main() {
	int Value, Number, Time, Buf, Max = 0;
	std::string Title;
	std::cout << "Enter the number of exhibits: " << std::endl;
	std::cin >> Number;
	TExh obj(Number);
	std::cout << "Enter title, value of exhibits and time of exposure: " << std::endl;
	for (int i = 0; i < Number; ++i) {
		std::cout << "[" << i + 1 << "]" << std::endl;
		std::cin >> Title >> Value >> Time;
		obj.Enter(Title, Value, Time, i);
		if (Value * Time > Max) {
			Max = Value * Time;
			Buf = i;
		}
	}
	obj.AverageValue(Number, Buf);
	system("pause");
}
