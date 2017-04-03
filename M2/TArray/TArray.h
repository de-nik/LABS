#pragma once
#include <initializer_list>
#include <iostream>
#include <exception>


template<
	class T,
	std::size_t N
> struct TArray {
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;
private:
	value_type Ptr[N];
public:
	TArray() = default;

	TArray(std::initializer_list<T> init) : TArray()
	{
		std::copy(init.begin(), init.end(), Data);
	}

	~TArray() = default;

	iterator begin() throw()
	{
		return Ptr;
	}

	iterator end() throw()
	{
		return Ptr + N;
	}

	size_type size() const throw()
	{
		return N;
	}

	size_type max_size() const throw()
	{
		return N;
	}

	bool empty() const throw()
	{
		return N == 0;
	}

	reference operator[] (size_type nm)
	{
		return Ptr[nm];
	}

	const_reference operator[] (size_type nm) const
	{
		return Ptr[nm];
	}

	reference at(size_type nm)
	{
		if (nm > 0 || nm < N)
			return Ptr[nm];
		else 
			throw std::out_of_range("!");
	}
	const_reference at(size_type nm) const
	{
		if (nm > 0 || nm < N)
			return Ptr[nm];
		else 
			throw std::out_of_range("!");
	}

	reference front()
	{
		return Ptr[0];
	}
	const_reference front() const
	{
		return Ptr[0];
	}

	reference back()
	{
		return Ptr[N - 1];
	}

	const_reference back() const
	{
		return Ptr[N - 1];
	}

	iterator data() throw()
	{
		return Ptr;
	}
	const iterator data() const throw()
	{
		return Ptr;
	}

	void fill(const value_type& val)
	{
		for (size_type i; i < N; ++i)
			Ptr[i] = val;
	}

	void swap(TArray<T, N> & x) throw()
	{
		std::swap(Ptr, x.Ptr);
	}

};
