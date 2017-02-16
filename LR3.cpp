#include <iostream>
class TFlat {
private:
	size_t *Count,  // Количество комнат
		   *Value;  // Стоимость квартиры
public:
	TFlat(size_t Number) {
		Count = new size_t[Number];
		Value = new size_t[Number];
	}
	void Enter(size_t c_count, size_t c_value, size_t i) { // Заполнение массивов данными
		Count[i] = c_count;
		Value[i] = c_value;
	}
	void AverageValue(size_t Number, size_t Limit) { // Расчет средней стоимости одной комнаты и вывод всех данных на экран
		std::cout << std::endl << "The parameters of all flats: " << std::endl;
		for (int i = 0; i < Number; i++)
			std::cout << "[" << i + 1 << "] " << "Count = " << Count[i] << " | " << "Value = " << Value[i] << " | " << "Av. Value = " << Value[i] / Count[i] << std::endl;
		std::cout << "------------------------------------------------------" << std::endl << "below the limit ->" << std::endl;
		for (int i = 0; i < Number; i++)
			if (Value[i] / Count[i] < Limit)
				std::cout << "[" << i + 1 << "] " << "Count = " << Count[i] << " | " << "Value = " << Value[i] << " | " << "Av. Value = " << Value[i] / Count[i] << std::endl;
	}
	~TFlat() {
		delete []Count;
		delete []Value;
	}
};
int main() {
	size_t Value, Count, Number, Limit;
	std::cout << "Enter the number of the flats and the sorting limit: " << std::endl;
	std::cin >> Number >> Limit;
	TFlat obj(Number);
	std::cout << "Enter count of rooms and the value of the flats: " << std::endl;
	for (int i = 0; i < Number; ++i) {
		std::cin >> Count >> Value;
		obj.Enter(Count, Value, i);
	}
	obj.AverageValue(Number, Limit);
	system("pause");
}
