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
		if (size < InternalCapacity) return;
		value_type * ptr = new value_type[size];
		std::copy(this->begin(), this->end(), ptr);
		delete[] Ptr;
		Ptr = ptr;
		InternalCapacity = size;
	}

	TVector& operator=(const TVector& rhs)
	{
		if (this == &rhs) return *this;
		this->reserve(rhs.InternalCapacity);
		Count = rhs.Count;
		std::copy(rhs.begin(), rhs.end(), this->begin());
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
		size_type i = Pos(pos);
		Allot(Count);
		Count++;
		for (size_type k = Count - 1; k >= i; k--)
			Ptr[k] = Ptr[k - 1];
		Ptr[i - 1] = value;
		return pos;
	}

	void insert(iterator pos, size_type count, const value_type & value)
	{
		Count += count;
		size_type i = Pos(pos);
		Allot(Count);
		for (size_type k = Count - 1; k >= i + count - 1; k--)
			Ptr[k] = Ptr[k - count];
		for (size_t k = 0; k < count; k++)
			Ptr[i + k] = value;
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
