#include <iostream>      
#include <string>         
#include <bitset>         
#include <vector>
template <size_t N>
class Bitset {	
	bool *Ptr;
	size_t Size, my_pos, Count;
public:
	Bitset()
		: Size(N)
		, my_pos(0)
		, Count(0)
	{
		Ptr = new bool[Size];
		for (size_t i(0); i < Size; ++i)
			Ptr[i] = 0;
	}

	Bitset(unsigned long long value)
		: Size(N)
		, my_pos(0)
		, Count(0)
	{ 
		Ptr = new bool[Size];
		unsigned long long t = value;
		for (int i = Size-1; i >= 0; i--)
		{
			if (t % 2)
			{
				Ptr[i] = true;
				++Count;
			}
			else
				Ptr[i] = false;
			t = t / 2;
		}
	}	

	Bitset(std::string str)
		: Size(N)
		, my_pos(0)
		, Count(0)
	{
		Ptr = new bool[Size];
		for (int i = Size - 1, j = str.Size() - 1; 
			 i >= Size - str.Size(); 
			 --i, --j)
		{
			if ((str[j] - '0') == 1)
			{
				Ptr[i] = true;
				++Count;
			}
			else
			{
				Ptr[i] = false;
			}
		}
		for (int i = Size - str.Size() - 1; i >= 0; i--)
			Ptr[i] = 0;
	}

	Bitset(const Bitset<N> &rhs)
		: Size(N)
		, my_pos(0)
		, Count(0)
	{
		Ptr = rhs.Ptr;
		Size = rhs.Size;
		Count = rhs.Count;
		my_pos = rhs.my_pos;
	}

	Bitset operator[](size_t pos)
	{
		my_pos = Size - 1 - pos;
		return *this;
	}

	bool operator==(const Bitset<N>& rhs) const
	{
		for (int i = Size - 1; i >= 0; i--)
		{
			if (Ptr[i] != rhs.Ptr[i])
				return false;
		}
			return true;
	}

	bool operator!=(const Bitset<N>& rhs) const
	{
		for (int i = Size - 1; i >= 0; i--)
		{
			if (Ptr[i] != rhs.Ptr[i])
				return true;
		}
		return false;
	}

	size_t size()
	{
		return Size;
	}

	size_t count()
	{
		return Count;
	}
	
	Bitset<N>& set(size_t pos)
	{	
		Ptr[Size - 1 - pos] = true;
		++Count;
		return *this;
	}

	Bitset<N>& set()
	{
		for (size_t i(0); i < Size; ++i)
		{
			if (Ptr[i])
			{
				Ptr[i] = true;
				++Count;
			}
		}
		return *this;
	}

	Bitset<N>& reset(size_t pos)
	{
		Ptr[Size - 1 - pos] = false;
		--Count;
		return *this;
	}

	Bitset<N>& reset()
	{
		for (size_t i(0); i < Size; ++i)
		{
			Ptr[i] = false;
			--Count;
		}
		return *this;
	}

	Bitset<N>& flip(size_t pos)
	{
		if (Ptr[Size - 1 - pos])
		{
			Ptr[Size - 1 - pos] = false;
			--Count;
		}
		else
		{
			Ptr[Size - 1 - pos] = true;
			++Count;
		}
		return *this;
	}

	Bitset<N>& flip()
	{
		for (size_t i(0); i < Size; ++i)
		{
			if (Ptr[i])
			{
				Ptr[i] = false;
				--Count;
			}
			else
			{
				Ptr[i] = true;
				++Count;
			}
		}
		return *this;
	}

	void out()
	{
		for (size_t i(0); i < Size; ++i)
		{
			std::cout << Ptr[i];
		}
		std::cout << std::endl;
	}

	Bitset& operator =(Bitset<N> &rhs)
	{
		Ptr = rhs.Ptr;
		Size = rhs.Size;
		Count = rhs.Count;
		return *this;
	}

	Bitset& operator =(bool x)
	{
		if (x)
		{
			Ptr[my_pos] = true;
			++Count;
		}
		else
		{
			Ptr[my_pos] = false;
			--Count;
		}
		return *this;
	}

	bool all() const
	{
		for (size_t i(0); i < Size; ++i)
		{
			if (!Ptr[i])
				return false;
		}
		return true;
	}

	bool any() const
	{
		for (size_t i(0); i < Size; ++i)
		{
			if (Ptr[i])
				return true;
		}
		return false;
	}

	bool none() const
	{
		for (size_t i(0); i < Size; ++i)
		{
			if (Ptr[i])
				return false;
		}
		return true;
	}

	Bitset<N>& operator&=(const Bitset<N>& other)
	{
		for (size_t i(0); i < Size; ++i)
			Ptr[i] = Ptr[i] & other.Ptr[i];
		return *this;
	}

	Bitset<N> operator&(const Bitset<N>& rhs) 
	{
		return Bitset<N>(lhs) &= rhs;
	}

	Bitset<N>& operator|=(const Bitset<N>& other)
	{
		for (size_t i(0); i < Size; ++i)
			Ptr[i] = Ptr[i] | other.Ptr[i];
		return *this;
	}

	Bitset<N> operator|(const Bitset<N>& rhs)
	{
		return Bitset<N>(lhs) |= rhs;
	}

	Bitset<N>& operator^=(const Bitset<N>& other)
	{
		for (size_t i(0); i < Size; ++i)
			Ptr[i] = Ptr[i] ^ other.Ptr[i];
		return *this;
	}

	Bitset<N> operator^(const Bitset<N>& rhs)
	{
		return Bitset<N>(lhs) ^= rhs;
	}

	Bitset<N> operator~() const
	{
		Bitset<N> a(*this);
		return a.flip();
	}

	std::string to_string() const
	{
		std::string data;
		for (size_t i(0); i < Size; ++i)
		{
			if (Ptr[i] == 1)
				data.push_back('1');
			else
				data.push_back('0');
		}
				return data;
	}

	~Bitset()
	{
		delete[] Ptr;
	}
};
