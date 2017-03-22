#include <iostream>
#include <algorithm>
#include <vector>
template<typename T> 
void swap(T *Left, T *Right)
{	
	T Tmp = *Left;
	*Left = *Right;
	*Right = Tmp;
}

template <typename IT>
void sort(IT* a, IT* b)
{
	for (IT* i = a; i < b-2; ++i)
	{
		for (IT* j = a; j < b-2; j++)
		{
			if (*(j+1) < *j) swap(j+1, j); 
		}
	}
}

int main()
{

	int arr[] = { 9, 8, 7, 6, 5 };
	sort(arr, arr + 3);
	for (int i = 0; i < 5; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	std::vector<double> vec = { 123.0, 3.0, 0.0, 13212.0, -100.0 };
	sort(vec.begin(), vec.end());
	for (int i = 0; i < 5; ++i)
	{
		std::cout << std::fixed << vec[i] << " ";
	}
	std::cout << std::endl;

}

