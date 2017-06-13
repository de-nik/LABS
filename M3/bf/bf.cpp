#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <exception>

class boolean_function
{
public:
	using value_type = bool;
	using size_type = size_t;
	using reference = std::vector<value_type>::reference;
	using const_reference = std::vector<value_type>::const_reference;

	using iterator = typename std::vector<value_type>::iterator;
	using const_iterator = typename std::vector<value_type>::const_iterator;

private:
	std::vector<value_type> func;

	bool xor(bool a, bool b) const
	{
		if (a == b)
			return 0;
		else return 1;
	}

	bool checkLength(size_t len)
	{
		size_t i = 0;
		while (len)
		{
			i += len % 2;
			len = len / 2;
		}
		if (i != 1)
			throw std::exception("Wrong length");
		else return true;
	}

	bool comp(const boolean_function & larger, const boolean_function & smaller) const
	{
		auto it = larger.func.begin();
		while (it != larger.func.end())
		{
			auto beg = it;
			for (size_t i = 0; i < smaller.size(); ++i)
				++it;
			if (!std::equal(beg, it, smaller.func.begin()))
				return false;
		}
		return true;
	}
public:

	static boolean_function var(size_t n, size_t dimension)
	{
		boolean_function f(dimension);
		for (size_t i = 0; i + pow(2, n) < f.size(); ++i)
		{
			if (f[i] != 1 && f[i + pow(2, n)] <= f[f.size() - 1])
				f[i + pow(2, n)] = 1;
		}
		return f;
	}

	static boolean_function one(size_t dimension)
	{
		boolean_function on(dimension);
		~on;
		return on;
	}

	static boolean_function from_anf(std::vector<value_type> v)
	{
		std::vector<value_type> temp;
		std::vector<value_type> tria = v;
		for (size_t i = 0; i < v.size(); ++i)
		{
			temp.push_back(tria[0]);
			for (size_t k = 0; k < tria.size() - 1; ++k)
			{
				if (tria[k] == tria[k + 1])
					tria[k] = 0;
				else tria[k] = 1;
			}
			tria.pop_back();
		}
		boolean_function t(temp);
		return t;
	}

	boolean_function() = default;

	boolean_function(size_t n)
	{
		func.resize(pow(2, n));
		std::fill(func.begin(), func.end(), 0);
	}

	boolean_function(unsigned long long value, size_type n)
	{
		while (value)
		{
			func.insert(func.begin(), (value % 2));
			value = value / 2;
		}
		while (func.size() < pow(2, n))
		{
			func.insert(func.begin(), 0);
		}
		std::reverse(func.begin(), func.end());
	}

	boolean_function(const std::string& table)
	{
		if (checkLength(table.size()))
			for (size_t i = 0; i < table.size(); ++i)
				func.push_back(table[i] - 48);
	}

	boolean_function(const std::vector<value_type>& table)
	{
		if (checkLength(table.size()))
			func = table;
	}

	boolean_function(const std::initializer_list<bool> vars)
	{
		if (checkLength(vars.size()))
			func = vars;
	}

	boolean_function(const boolean_function& table) : func(table.func)
	{}

	static boolean_function zero(size_t dimension)
	{
		boolean_function z(dimension);
		return z;
	}

	boolean_function& operator=(const boolean_function& rhs)
	{
		func = rhs.func;
		return *this;
	}

	boolean_function& operator += (const boolean_function& rhs)
	{
		if (this->size() != rhs.size())
			throw std::exception("Not equal");
		for (size_t i = 0; i < func.size(); ++i)
		{
			func[i] = xor (func[i], rhs.func[i]);
		}
		return *this;
	}

	boolean_function& operator *= (const boolean_function& rhs)
	{
		if (this->size() != rhs.size())
			throw std::exception("Not equal");
		for (size_t i = 0; i < func.size(); ++i)
		{
			if (func[i] == 1 && rhs.func[i] == 1)
				func[i] = 1;
			else func[i] = 0;
		}
		return *this;
	}

	boolean_function& operator |= (const boolean_function& rhs)
	{
		if (this->size() != rhs.size())
			throw std::exception("Not equal");
		for (size_t i = 0; i < func.size(); ++i)
		{
			if (func[i] == 1 || rhs.func[i] == 1)
				func[i] = 1;
			else func[i] = 0;
		}
		return *this;
	}

	boolean_function operator ~ ()
	{
		func.flip();
		return *this;
	}

	bool operator == (const boolean_function& rhs) const
	{
		if (this->size() == rhs.size())
			return func == rhs.func;
		if (this->size() > rhs.size())
			return comp(*this, rhs);
		else return comp(rhs, *this);

	}


	bool operator >= (const boolean_function& rhs) const
	{
		if (this->size() == rhs.size())
		{
			size_t t = 0;
			for (size_t i = 0; i < func.size(); ++i)
			{
				if (func[i] >= rhs.func[i])
					++t;
			}
			if (t == func.size())
				return true;
			else
			{
				t = 0;
				for (size_t i = 0; i < func.size(); ++i)
				{
					if (func[i] <= rhs.func[i])
						++t;
				}
			}
			if (t == func.size())
				return false;
		}
		throw std::exception("logic error");
	}

	reference operator[](size_type ind)
	{
		return func[ind];
	}
	const_reference operator[](size_type ind) const
	{
		return func[ind];
	}

	reference at(size_type ind)
	{
		return func.at(ind);
	}
	const_reference at(size_type ind) const
	{
		return func.at(ind);
	}

	iterator begin()
	{
		return func.begin();
	}
	iterator end()
	{
		return func.end();
	}

	const_iterator cbegin() const
	{
		return func.cbegin();
	}
	const_iterator cend() const
	{
		return func.cend();
	}

	size_type size() const throw()
	{
		return func.size();
	}


	size_type dimension() const throw()
	{
		size_t t = func.size();
		if (t == 0)
			return 0;
		if (t == 1)
			return 1;
		size_t dim = 0;
		while (t != 1)
		{
			t = t / 2;
			++dim;
		}
		return dim;

	}


	bool operator()(const std::vector<bool>& vars) const
	{
		int t = 0;
		for (size_t i = 0; i < vars.size(); ++i)
		{
			t += pow(2, i)*vars[i];
		}
		return this->at(t);

	}

	bool operator()(const std::initializer_list<bool> vars) const
	{
		int t = 0;
		int i = 0;
		for (auto &it : vars)
		{
			t += pow(2, i)*it;
			++i;
		}
		return this->at(t);
	}


	boolean_function operator()(const std::vector<boolean_function>& fs) const
	{
		std::vector<boolean_function> tmp = fs;
		std::vector<size_t> sizes;
		for (auto it = fs.begin(); it != fs.end(); ++it)
		{
			sizes.push_back(it->size());
		}
		size_t max = *std::max_element(sizes.begin(), sizes.end(), [](size_t a, size_t b) {return a < b; });
		for (size_t i = 0; i < sizes.size(); ++i)
		{
			while (sizes[i] != max)
			{
				tmp[i].func.resize(2 * sizes[i]);
				for (size_t k = 0; k < sizes[i]; ++k)
					tmp[i].func[k + sizes[i]] = tmp[i].func[k];
				sizes[i] = tmp[i].size();
			}

		}
		std::vector<value_type> g;

		for (size_t j = 0; j < max; ++j)
		{
			std::vector<value_type> temp;
			for (size_t i = 0; i < tmp.size(); ++i)
			{
				temp.push_back(tmp.at(i).at(j));
			}
			g.push_back((*this)(temp));
		}
		boolean_function G(g);
		return G;
	}

	boolean_function operator()(const std::initializer_list<boolean_function> vars) const
	{
		std::vector<boolean_function> fs = vars;
		return (*this)(fs);
	}

	std::string get_polynom(const boolean_function & function) {

		auto buf = function.anf();

		std::string result("");

		if (buf[0])
			result = "1";

		for (size_t i = 1; i < buf.size(); ++i) {
			if (buf[i]) {
				if (result.size())
					result += " + ";
				std::vector<size_t> nums;
				for (size_t j = 0; j < function.dimension(); ++j)
					if ((i % static_cast<size_t>(pow(2, j + 1))) >= pow(2, j + 1) / 2)
						nums.push_back(j);

				for (size_t j = 0; j < nums.size(); ++j) {
					result += "x";
					result += std::to_string(nums[j]);
				}
			}
		}

		return result;

	}

	bool is_monotone() const
	{
		if (func.size() == 0)
			throw std::exception("Empty");
		for (size_t i = 0; i < func.size() - 1; ++i)
			if (func[i] > func[i + 1])
				return false;
		return true;
	}
	bool is_symmetric() const
	{
		std::vector<value_type> rev(func.size());
		std::reverse_copy(func.begin(), func.end(), rev.begin());
		rev.flip();
		return (func == rev);
	}
	bool is_linear() const
	{
		std::vector<value_type> a = this->anf();
		size_t t = 0;
		for (size_t i = 1; i < a.size(); ++i)
		{
			if (i == pow(2, t))
				++t;
			else if (a[i] == 1)
				return false;
		}
		return true;
	}
	bool is_T1() const
	{
		auto it = func.end();
		--it;
		return (*it == 1);
	}
	bool is_T0() const
	{
		return (*(func.begin()) == 0);
	}
	bool is_balanced() const
	{
		return this->weight() == this->size() / 2;
	}

	size_t weight() const
	{
		return std::count_if(func.begin(), func.end(),
			[](const bool a)
		{
			return a == 1;
		}
		);

	}

	bool is_functionally_complete_system() const
	{
		return (!this->is_monotone() && !this->is_symmetric() && !this->is_linear()
			&& !this->is_T0() && !this->is_T1());
	}


	std::vector<value_type> anf() const
	{
		std::vector<value_type> temp;
		std::vector<value_type> tria = func;
		for (size_t i = 0; i < func.size(); ++i)
		{
			temp.push_back(tria[0]);
			for (size_t k = 0; k < tria.size() - 1; ++k)
			{
				tria[k] = xor (tria[k], tria[k + 1]);
			}
			tria.pop_back();
		}
		return temp;
	}
};


boolean_function operator + (const boolean_function& a, const boolean_function& b)
{
	return boolean_function(a) += boolean_function(b);
}

boolean_function operator * (const boolean_function& a, const boolean_function& b)
{
	return boolean_function(a) *= boolean_function(b);
}

boolean_function operator | (const boolean_function& a, const boolean_function& b)
{
	return boolean_function(a) |= boolean_function(b);
}

bool operator != (const boolean_function& a, const boolean_function& b)
{
	return !(a == b);
}
