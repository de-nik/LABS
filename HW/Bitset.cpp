#include <iostream>      
#include <string>         
#include <bitset>         

class cast_exception : public std::exception
{ };

class out_of_range : public  cast_exception
{ };

class overflow : public  cast_exception
{ };
template <size_t N>
class Bitset
{
	bool *ptr;
public:

	Bitset()
	{
		ptr = new bool[N];
		for (size_t i = 0; i < N; ++i)
			ptr[i] = false;
	}

	Bitset(unsigned long long value)
	{
		ptr = new bool[N];
		unsigned long long t = value;
		for (int i = N - 1; i >= 0; i--)
		{
			if (t % 2)
			{
				ptr[i] = true;
			}
			else
				ptr[i] = false;
			t = t / 2;
		}
	}

	Bitset(const std::string &str)
	{
		ptr = new bool[N];
		for (int i = N - 1, j = str.size() - 1;
			i >= N - str.size();
			--i, --j)
		{
			if ((str[j] - '0') == 1)
			{
				ptr[i] = true;
			}
			else
			{
				ptr[i] = false;
			}
		}
		for (int i = N - str.size() - 1; i >= 0; i--)
		{
			ptr[i] = 0;
		}
	}

	Bitset(const std::string &str, size_t number)
	{
		if (number <= str.size())
		{
			ptr = new bool[N];
			for (int i = N - 1, j = str.size() - 1;
				i >= N - number;
				--i, --j)
			{
				if ((str[j] - '0') == 1)
				{
					ptr[i] = true;
				}
				else
				{
					ptr[i] = false;
				}
			}
			for (int i = N - 1 - number; i >= 0; i--)
			{
				ptr[i] = 0;
			}
		}
		else
		{
			throw out_of_range();
		}
	}

	Bitset(const std::string &str, size_t number, char x)
	{
		if (number <= str.size())
		{
			ptr = new bool[N];
			for (int i = N - 1, j = str.size() - 1;
				i >= N - number;
				--i, --j)
			{
				if (str[j] == x || (str[j] - '0') == 1)
				{
					ptr[i] = true;
				}
				else
				{
					ptr[i] = false;
				}
			}
			for (int i = N - 1 - number; i >= 0; i--)
			{
				ptr[i] = 0;
			}
		}
		else
		{
			throw out_of_range();
		}
	}

	Bitset(const Bitset<N> &rhs)
	{
		ptr = new bool[N];
		for (size_t i = 0; i < N; ++i)
			memcpy(ptr, rhs.ptr, N * sizeof(bool));
	}

	size_t size()
	{
		return N;
	}

	size_t count()
	{
		size_t temp_w = 0;
		for (size_t i = 0; i < N; ++i)
		{
			if (ptr[i])
				++temp_w;
		}
		return temp_w;
	}

	Bitset<N>& set(size_t pos, bool val = true)
	{
		if (pos > N || pos < 0)
		{
			throw out_of_range();
		}
		else
		{
			ptr[N - 1 - pos] = val;
			return *this;
		}
	}

	Bitset<N>& set()
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (ptr[i])
			{
				ptr[i] = true;
			}
		}
		return *this;
	}

	Bitset<N>& reset(size_t pos)
	{
		if (pos > N || pos < 0)
		{
			throw out_of_range();
		}
		else
		{
			ptr[N - 1 - pos] = false;
			return *this;
		}
	}

	Bitset<N>& reset()
	{
		for (size_t i = 0; i < N; ++i)
		{
			ptr[i] = false;
		}
		return *this;
	}

	Bitset<N>& flip(size_t pos)
	{
		if (pos > N || pos < 0)
		{
			throw out_of_range();
		}
		else
		{
			if (ptr[N - 1 - pos])
			{
				ptr[N - 1 - pos] = false;
			}
			else
			{
				ptr[N - 1 - pos] = true;
			}
			return *this;
		}
	}

	Bitset<N>& flip()
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (ptr[i])
			{
				ptr[i] = false;
			}
			else
			{
				ptr[i] = true;
			}
		}
		return *this;
	}

	bool all() const
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (!ptr[i])
				return false;
		}
		return true;
	}

	bool any() const
	{
		for (size_t i = 0; i < N; ++i)
		{
			if (ptr[i])
				return true;
		}
		return false;
	}

	bool none() const
	{
		if (all())
			return false;
		else return true;
	}

	bool test(size_t pos) const
	{
		if (pos > N || pos < 0)
		{
			throw out_of_range();
		}
		else return true;
	}

	std::string to_string() const
	{
		std::string data;
		for (size_t i = 0; i < N; ++i)
		{
			if (ptr[i] == 1)
				data.push_back('1');
			else
				data.push_back('0');
		}
		return data;
	}

	unsigned long to_ulong() const
	{
		unsigned long a = 0;
		for (size_t i = 0; i < N; ++i)
		{
			if (ptr[N - 1 - i])
			{
				if (a + pow(2, i) - pow(2, i) == a)
				{
					a = pow(2, i) + a;
				}
				else
				{
					throw overflow();
				}
			}
		}
		return a;
	}

	constexpr bool operator[](std::size_t pos) const
	{
		if (pos > N || pos < 0)
		{
			throw out_of_range();
		}
		else
		{
			return ptr[N - pos - 1];
		}
	}

	bool& operator[](std::size_t pos)
	{
		if (pos > N || pos < 0)
		{
			throw out_of_range();
		}
		else
		{
			return ptr[N - pos - 1];
		}
	}

	Bitset& operator =(Bitset<N> &rhs)
	{
		if (*this != rhs)
		{
			ptr = rhs.ptr;
			N = rhs.N;
			return *this;
		}
		else
		{
			return *this;
		}
	}

	Bitset& operator =(bool x)
	{
		if (*this != true)
		{
			*this = true;
			return *this;
		}
		else
		{
			return *this;
		}
	}

	~Bitset()
	{
		delete[] ptr;
	}

};

template <size_t N>
Bitset<N>& operator&=(Bitset<N>& lhs, const Bitset<N>& other)
{
	for (size_t i = 0; i < N; ++i)
		lhs.ptr[i] = lhs.ptr[i] & other.ptr[i];
	return *this;
}

template <size_t N>
Bitset<N> operator&(const Bitset<N>& rhs)
{
	return Bitset<N>(lhs) &= rhs;
}

template <size_t N>
Bitset<N>& operator|=(Bitset<N>& lhs, const Bitset<N>& other)
{
	for (size_t i = 0; i < N; ++i)
		lhs.ptr[i] = lhs.ptr[i] | other.ptr[i];
	return *this;
}

template <size_t N>
Bitset<N> operator|(Bitset<N>& lhs, const Bitset<N>& other)
{
	return lhs |= rhs;
}

template <size_t N>
Bitset<N>& operator^=(Bitset<N>& lhs, const Bitset<N>& other)
{
	for (size_t i = 0; i < N; ++i)
		lhs.ptr[i] = lhs.ptr[i] ^ other.ptr[i];
	return *this;
}

template <size_t N>
Bitset<N> operator^(Bitset<N>& lhs, const Bitset<N>& other)
{
	return lhs ^= rhs;
}

template <size_t N>
Bitset<N> operator~(Bitset<N>& lhs)
{
	return lhs.flip();
}

template <size_t N>
bool operator==(const Bitset<N>& lhs, const Bitset<N>& other)
{
	for (int i = N - 1; i >= 0; i--)
	{
		if (lhs.ptr[i] != rhs.ptr[i])
			return false;
	}
	return true;
}

template <size_t N>
bool operator!=(const Bitset<N>& lhs, const Bitset<N>& other)
{
	for (int i = N - 1; i >= 0; i--)
	{
		if (lhs.ptr[i] != rhs.ptr[i])
			return true;
	}
	return false;
}
