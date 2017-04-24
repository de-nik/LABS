#include <iostream>
#include <algorithm>
#include <vector>
template<typename T>
void swap(T &Left, T &Right)
{
	T Tmp = Left;
	Left = Right;
	Right = Tmp;
}

template <typename IT>
void Sort(IT a, IT b)
{
	for (IT i = a; i != b; ++i) 
	{
		for (IT j = a; j != b; ++j) 
		{
			if ((*i) < (*j))
				swap((*i), (*j));
		}
	}
}

int main()
{

	int arr[] = { 123, 3, 0, 13212, -100 };
	Sort(arr, arr + 3);
	for (int i = 0; i < 5; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::vector<double> vec = { 123.0, 3.0, 0.0, 13212.0, -100.0 };
	Sort(vec.begin(), vec.end());
	for (int i = 0; i < 5; ++i)
	{
		std::cout << std::fixed << vec[i] << " ";
	}
	std::cout << std::endl;

}
