#pragma once
#include <iostream>      
#include <string>         
#include <bitset>         

class cast_exception : public std::exception
{ };
class out_of_range : public  cast_exception
{ };
class overflow : public  cast_exception
{ };
class invalid_char : public  cast_exception
{ };

//

template <size_t N>
class Bitset
{
	const size_t n = N / 8 + 1;
	unsigned char *ptr = new unsigned char[n];
public:

	Bitset()
	{
		for (size_t i = 0; i < n; ++i)
			ptr[i] = 0;
	}

	Bitset(unsigned long long value)
	{
		unsigned long long t = value;
		size_t k = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= 7; ++j)
			{
				if (t % 2)
					ptr[i] |= 1 << j;

				else
					ptr[i] &= ~(1 << j);

				t = t / 2;
				if (k++ == N) break;
			}
		}
	}

	Bitset(const std::string &str)
	{
		size_t k = 1, i = 0, d = str.size() - 1;
		for (; i < n && k != N && d != 0; ++i)
		{
			for (int j = 0; j <= 7 && k != N && d != 0; ++j, --d, ++k)
			{
				if ((str[d] - '0') == 1)
					ptr[i] |= 1 << j;

				else if ((str[d] - '0') == 0)
					ptr[i] &= ~(1 << j);

				else
					throw invalid_char();
			}
		}

		for (; i < n && k != N; ++i)
		{
			for (int e = 7 - ((8*(n - i) - 1) - str.size()); e <= 7 && k != N; ++e, ++k)
			{
				ptr[i] &= ~(1 << e);
			}

			for (int q = 0; q <= 7 && k != N; ++q, ++k)
			{
				ptr[i] &= ~(1 << q);
			}


		}
	}

	Bitset(const std::string &str, size_t number)
	{
		if (number <= str.size())
		{
			for (size_t k = 0; k < n; ++k)
			{
				for (int i = 0, j = 0; j < number; ++i, ++j)
				{
					if ((str[j] - '0') == 1)
						ptr[k] |= 1 << i;

					else if ((str[j] - '0') == 0)
						ptr[k] &= ~(1 << i);

					else
						throw invalid_char();
				}
				for (int i = number; i < N; i++)
					ptr[k] &= ~(1 << i);
			}
		}
		else
		{
			throw out_of_range();
		}
	}

	Bitset(const std::string &str, size_t number, char x, char y)
	{
		if (number <= str.size())
		{
			for (size_t k = 0; k < n; ++k)
			{
				for (int i = 0, j = 0; j < number; ++i, ++j)
				{
					if (str[j] == x)
						ptr[k] |= 1 << i;

					else if (str[j] == y)
						ptr[k] &= ~(1 << i);

					else
						throw invalid_char();
				}
				for (int i = number; i < N; i++)
					ptr[k] &= ~(1 << i);
			}
		}
		else
		{
			throw out_of_range();
		}
	}

	Bitset(const Bitset<N> &rhs)
	{

		memcpy(ptr, rhs.ptr, N * sizeof(bool));
	}

	//

	size_t size()
	{
		return N;
	}

	size_t count()
	{
		size_t temp_w = 0;
		for (size_t i = 0; i < n; ++i)
		{
			for (int j = N - 1; j >= 0; --j)
			{
				if (ptr[i] & (1 << j))
					++temp_w;
			}
		}
		return temp_w;
	}

	Bitset<N>& set(size_t pos, bool val = true)
	{
		if (pos > N - 1 || pos < 0)
		{
			throw out_of_range();
		}
		else
		{
			size_t k = 0;
			for (size_t i = 0; i < n; ++i)
			{
				if (k - 1 == pos)
				{
					ptr[i] |= 1 << (8 * i - 1 - k);
				}
				k++;

			}
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
		if (pos > N - 1 || pos < 0)
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
		if (pos > N - 1 || pos < 0)
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

	void out()
	{
		size_t k = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= 7; ++j)
			{
				if (ptr[i] & (1 << j))
					std::cout << 1;
				else
					std::cout << 0;
				if (k++ == 14) break;
			}
		}
		std::cout << std::endl;
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
		if (pos > N - 1 || pos < 0)
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
				if (i <= 30)
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
		if (pos > N - 1 || pos < 0)
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
		if (pos > N - 1 || pos < 0)
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

	//

	template <size_t N> friend Bitset<N>& operator&=(Bitset<N>& lhs, const Bitset<N>& other);

	template <size_t N> friend Bitset<N> operator&(const Bitset<N>& rhs);

	template <size_t N> friend Bitset<N>& operator|=(Bitset<N>& lhs, const Bitset<N>& other);

	template <size_t N> friend Bitset<N> operator|(Bitset<N>& lhs, const Bitset<N>& other);

	template <size_t N> friend Bitset<N>& operator^=(Bitset<N>& lhs, const Bitset<N>& other);

	template <size_t N> friend Bitset<N> operator^(Bitset<N>& lhs, const Bitset<N>& other);

	template <size_t N> friend Bitset<N> operator~(Bitset<N>& lhs);

	template <size_t N> friend bool operator==(const Bitset<N>& lhs, const Bitset<N>& other);

	template <size_t N> friend bool operator!=(const Bitset<N>& lhs, const Bitset<N>& other);
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
		if (lhs.ptr[i] != other.ptr[i])
			return false;
	}
	return true;
}

template <size_t N>
bool operator!=(const Bitset<N>& lhs, const Bitset<N>& other)
{
	for (int i = N - 1; i >= 0; i--)
	{
		if (lhs.ptr[i] != other.ptr[i])
			return true;
	}
	return false;
}
