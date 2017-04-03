#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__
#include <iostream>
#include <limits>
template <typename T>
class TVector
{
public:
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;
public:
	TVector()
		: Ptr(nullptr)
		, Count(0)
		, InternalCapacity(0)
	{ }

	TVector(size_type capacity)
		: Count(0)
		, InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
	}

	TVector(const TVector & obj)
	{
		Count = obj.Count;
		InternalCapacity = obj.InternalCapacity;
		Ptr = new value_type[InternalCapacity];
		for (size_type i = 0; i < Count; ++i)
			memcpy(Ptr, obj.Ptr, Count * sizeof(value_type));
	}

	~TVector()
	{
		delete[] Ptr;
	}

	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type capacity() const throw()
	{
		return InternalCapacity;
	}

	iterator begin() const throw()
	{
		return Ptr;
	}

	iterator end() const throw()
	{
		return Ptr + Count;
	}

	void reserve(size_type size)
	{
		InternalCapacity = size;
		iterator buf = Ptr;
		Ptr = new value_type[size];
		if (size < Count)
		{
			Count = size;
		}
		memcpy(Ptr, buf, Count * sizeof(value_type));
		if (buf != nullptr)
		{
			delete[] buf;
		}
	}

	TVector & operator = (const TVector & vector)
	{
		Count = vector.Count;
		InternalCapacity = vector.InternalCapacity;
		if (Ptr != nullptr) delete[] Ptr;
		Ptr = new value_type[InternalCapacity];
		memcpy(Ptr, vector.Ptr, Count * sizeof(value_type));
		return *this;
	}

	void push_back(const value_type& value)
	{
		if (Count == InternalCapacity)
		{
			reserve(InternalCapacity + 1);
		}
		Ptr[Count] = value;
		Count++;
	}

	reference at(size_type index)
	{
		if (index < Count)
		{
			return Ptr[index];
		}
		throw(std::exception("Error"));
	}

	value_type at(size_type index) const
	{
		if (index < Count)
		{
			return Ptr[index];
		}
		throw(std::exception("Error"));
	}

	reference operator [] (size_type index)
	{
		return Ptr[index];
	}

	const_reference operator [] (size_type index) const
	{

		return Ptr[index];
	}

	reference front()
	{
		return *this->begin();
	}

	const_reference front() const
	{
		return *this->begin();
	}

	reference back()
	{
		return *(this->end() - 1);
	}

	const_reference back() const
	{
		return *(this->end() - 1);
	}

	void clear()
	{
		Count = 0;
	}

	void pop_back()
	{
		--Count;
	}

	void swap(TVector & other) throw()
	{
		std::swap(Ptr, other.Ptr);
		std::swap(InternalCapacity, other.InternalCapacity);
		std::swap(Count, other.Count);
	}

	void resize(size_type count, value_type value = value_type())
	{
		if (count >= std::numeric_limits<size_type>::max())
		{
			throw(std::exception("Error"));
		}
		size_type buf(Count);
		count <= InternalCapacity ? Count = count : Count = InternalCapacity;
		if (buf <= Count)
		{
			insert((this->begin() + buf), Count - buf, 0);
		}
	}

	iterator insert(iterator pos, const value_type & value)
	{
		if (pos < this->end())
		{
			*pos = value;
			if (pos == this->end())
			{
				++Count;
			}
			return pos;
		}
	}

	void insert(iterator pos, size_type count, const value_type & value)
	{
		if (*pos > Count)
		{
			throw(std::exception("Error"));
		}
		Count += count;
		reserve(Count);
		for (int i = Count - 1; i >= *pos + count; i--)
		{
			Ptr[i] = Ptr[i - count];
		}
		for (int i = 0; i < count; i++)
		{
			Ptr[*pos + i] = value;
		}
	}

	iterator erase(iterator pos)
	{
		if (pos >= this->end() || pos < this->begin())
		{
			return this->begin();
		}
		for (iterator i = pos; i + 1 < this->end(); ++i)
		{
			*i = *(i + 1);
		}
		--Count;
		return this->begin();
	}

	iterator erase(iterator first, iterator last)
	{
		if (last > Ptr + Count || first >= Ptr + Count)
		{
			throw(std::exception("Error"));
		}
		for (int i = 0; i + last < Ptr + Count; ++i)
		{
			*(i + first) = *(last + i);
		}
		Count -= (last - first);
		return first;
	}
};


#endif // __TVECTOR_INCLUDED__
