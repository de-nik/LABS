#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
template <typename T, typename U>
T meta_print(T vec, U variable)
{
	(*vec).insert((*vec).end(), ++variable);
	if (variable < 100)
		meta_print(vec, variable);
	else return vec;
}

int main() 
{
	std::vector <int> vec;
	meta_print(&vec, -1);
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
+}

