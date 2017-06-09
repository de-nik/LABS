#include<iostream>
#include<string>




template < int N >
class sup_bit {
	unsigned char *bit_num;
	int len;
public:
	sup_bit()
	{
		bit_num = new unsigned char[N / 8];
		len = (N / 8) + ((N % 8) > 0);
		for (int i = 0; i < len; ++i)
			bit_num[i] = 0;
		len = N;
	}

	class TChangeBit : public sup_bit
	{
	public:
		int index;
		sup_bit point;

		TChangeBit(int ind, sup_bit&  p) 
		{
			index = ind;
			point = p;
		}

		TChangeBit operator=(bool val) 
		{
			point.setbit(index, val);
			return *this;
		}

		operator bool()
		{
			return point.getbit(index);
		}

	};

	const bool operator[](int index) const 
	{
		int cur = len - 1 - index;
		bool ret;
		int num = (cur / 8);
		int num_in = cur % 8;
		unsigned char current = bit_num[num];
		for (int i = 0; i <= num_in; ++i)
		{
			b = current % 2;
			current /= 2;
		}
		return ret;

	}

	bool getbit(int index) const 
	{
		int cur = len - 1 - index;
		size_t ret;
		int num = (cur / 8);
		int num_in = cur % 8;
		unsigned char current = bit_num[num];
		for (int i = 0; i <= num_in; ++i)
		{
			ret = current % 2;
			current /= 2;
		}
		return ret;
	}

	TChangeBit operator[](int index) 
	{
		TChangeBit ret(index, *this);
		return ret;
	}

	TChangeBit change(int index)
	{
		TChangeBit ret(index, *this);
		return ret;
	}

	void setbit(int index, size_t newval) 
	{
		int cur = len - 1 - index;
		int num = (cur / 8);
		int num_in = cur % 8;

		size_t curr_bit;
		unsigned char current = bit_num[num];
		for (int i = 0; i <= num_in; ++i)
		{
			curr_bit = current % 2;
			current /= 2;
		}
		if (curr_bit == 0 && newval == 1)
			bit_num[num] += pow(2, num_in);
		else if (curr_bit == 1 && newval == 0)
			bit_num[num] -= pow(2, num_in);
	}
};



template < size_t N >
class Bitset
{
private:
	sup_bit<N> sup;
public:

	Bitset() = default;

	Bitset(unsigned long val)
	{
		for (int i = N - 1; i >= 0; --i)
		{
			sup.setbit(i, val % 2);
			val = val / 2;
		}
	}

	Bitset(const std::string& str, size_t pos, size_t n)
	{
		size_t j = 0;
		if (pos >= str.size())
			throw std::out_of_range("Error!");
		for (size_t i = pos; i < n; ++i)
		{
			if (j >= N)
				return;
			if (str[i] == '0')
				sup.setbit(j, 0);
			else if (str[i] == '1')
				sup.setbit(j, 1);
			else
			{
				~Bitset();
				throw std::exception();
			}
			j++;
		}
	}

	~Bitset() = default;

	Bitset& set() 
	{
		for (size_t i = 0; i < N; ++i)
			sup.setbit(i, 1);
		return *this;
	};

	Bitset& set(size_t index, bool value = true) 
	{
		if (index >= N || index < 0)
			throw std::exception();
		sup.setbit(index, value);
		return *this;
	}

	Bitset& reset()
	{
		for (size_t i = 0; i < N; ++i)
		{
			sup.setbit(i, 0);
		}
		return *this;
	}

	Bitset& reset(size_t index)
	{
		sup.setbit(index, 0);
		return *this;
	}

	Bitset& flip()
	{

		for (size_t i = 0; i < N; i++)
		{
			sup.setbit(i, sup.getbit(i) ^ 1);
		}
		return *this;
	}

	Bitset& flip(size_t index)
	{
		if (index >= N || index < 0)
			throw std::exception();
		sup.setbit(index, sup.getbit(index) ^ 1);
		return *this;
	}

	typename sup_bit<N>::TChangeBit operator[](size_t index)
	{

		typename sup_bit<N>::TChangeBit tmp = sup.change(index);
		return tmp;
	}

	size_t count() const 
	{
		size_t count = 0;
		for (size_t i = 0; i < N; ++i)
		{
			count += sup.getbit(i);
		}
		return count;
	}

	size_t size() const
	{
		return N;
	}

	bool test(size_t index) const 
	{
		if (index >= N || index < 0)
			throw std::out_of_range("Error");
		return sup.getbit(index);
	}

	bool any() 
	{
		for (size_t i = 0; i < N; ++i)
		{
			if ((*this).operator[](i) == 1)
				return true;
		}
		return false;
	}

	bool none() 
	{
		return !(any());
	}

	bool all() const
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (sup.getbit(i) == 0)
				return false;
		}
		return true;
	}

	Bitset& operator&= (const Bitset& rhs)
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (sup.getbit(i) == 0 || rhs.sup.getbit(i) == 0)
			{
				sup.setbit(i, 0);
			}
			else
				sup.setbit(i, 1);
		}
		return *this;
	}

	Bitset& operator|= (const Bitset& rhs) 
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (sup.getbit(i) == 1 || rhs.sup.getbit(i) == 1)
			{
				sup.setbit(i, 1);
			}
			else
				sup.setbit(i, 0);
		}
		return *this;
	}

	Bitset& operator^= (const Bitset& rhs)
	{
		for (size_t i = 0; i < N; ++i)
		{
			sup.setbit(i, !(sup.getbit(i) == rhs.sup.getbit(i)));
		}
		return *this;
	}

	Bitset& operator<<= (size_t pos)
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (i + pos < N)
				sup.setbit(i, sup.getbit(i + pos));
			else
				sup.setbit(i, 0);
		}
		return *this;
	}

	Bitset& operator>>= (size_t pos)
	{
		for (size_t i = N - 1; i > 0; --i)
		{
			if (i - pos >= 0)
				sup.setbit(i, sup.getbit(i - pos));
			else
				sup.setbit(i, 0);
		}
		return *this;
	}

	Bitset operator~()
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (sup.getbit(i) == 0)
				sup.setbit(i, 1);
			else
				sup.setbit(i, 0);
		}
		return *this;
	}

	Bitset operator<<(size_t pos)
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (i + pos < N)
				sup.setbit(i, sup.getbit(i + pos));
			else
				sup.setbit(i, 0);
		}
		return *this;
	}

	Bitset operator >> (size_t pos)
	{
		for (int i = N - 1; i >= 0; --i)
		{
			if (i - pos >= 0) {
				int a = sup.getbit(i - pos);
				sup.setbit(i, sup.getbit(i - pos));
			}
			else
				sup.setbit(i, 0);
		}
		return *this;
	}

	bool operator== (const Bitset& rhs)
	{
		if (N != rhs.size())
			return false;
		for (int i = 0; i < N; ++i)
		{
			if (sup.getbit(i) != rhs.sup.getbit(i))
				return false;
		}
		return true;
	}

	std::string to_string()  
	{
		char* str = new char[N + 1];
		for (size_t i = 0; i < N; ++i)
		{
			str[i] = 48 + sup.getbit(i);
		}
		str[N] = '\0';
		std::string stri;
		stri.reserve(N);
		stri = str;
		delete[] str;
		return stri;
	}

	unsigned long to_ulong()
	{
		double tolong = 0;
		int two = 1;
		for (int i = N - 1; i >= 0; --i)
		{
			if (tolong + sup.getbit(i) * two > 4294967295)
				throw std::overflow_error("Overflow");
			tolong += sup.getbit(i) * two;
			two *= 2;
		}
		return tolong;
	}
};

template<size_t N>
std::ostream & operator<<(std::ostream &out, Bitset<N> &rhs)
{
	for (int i = 0; i < N; ++i)
		out << rhs[i];
	return out;
}

template<size_t N>
Bitset<N> operator& (const Bitset<N>& lhs, const Bitset<N>& rhs)
{
	Bitset<N> tmp = lhs;
	tmp &= rhs;
	return tmp;
}

template<size_t N>
Bitset<N> operator| (const Bitset<N>& lhs, const Bitset<N>& rhs)
{

	Bitset<N> tmp = lhs;
	tmp |= rhs;
	return tmp;
}

template<size_t N>
Bitset<N> operator^ (const Bitset<N>& lhs, const Bitset<N>& rhs)
{
	Bitset<N> tmp = lhs;
	tmp ^= rhs;
	return tmp;
}

int main()
{
	Bitset <8> a(5);
	std::cout << a << std::endl;
	a.reset();
	std::cout << a;

}
