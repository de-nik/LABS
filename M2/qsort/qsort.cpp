
#include <vector>
#include <iostream>
#include <iterator>
#include <functional>  
template<class It, class Cmp>
void qsort(It beg, It end, Cmp cmp)
{
	if (beg != end)
	{
		It choose = beg;
		It start = beg;
		while(start != end)
		{
			if (cmp(*start, *choose))
			{
				for (It j = start; j != choose;)
				{
					It k = j;
					std::iter_swap(k, --j);
				}
				++choose;
			}
			++start;
		}
			qsort(beg, choose, cmp);
			qsort(++choose, end, cmp);
	}
}


int main()
{
	std::vector<int> vec = { 44, 7, 99, 56, 0, 3, 8 };
	std::less<int> g;
	qsort(vec.begin(), vec.end(), g);
	std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "));
	system("pause");
	return 0;
}
