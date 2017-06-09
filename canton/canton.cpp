#include <iostream>
#include <string>
#include <vector>
#include <iterator>


class canton_compound //Список солдат контейнером
{
protected:
	std::vector <std::string> ini;
	std::vector <size_t> age;
	size_t amount;
public:
	canton_compound() = default;

	canton_compound(size_t _amount)
		: amount(_amount)
	{ }

	size_t get_amount()
	{
		return amount;
	}
	void set()
	{
		for (size_t i = 0; i < amount; ++i)
		{
			std::cout << "Ini >> age" << std::endl;
			std::istream_iterator<std::string> input(std::cin);
			ini.push_back(*input);
			std::istream_iterator<size_t> in(std::cin);
			age.push_back(*in);
		}
	}

	std::string get_ini(size_t i)
	{
		return ini[i];
	}

	std::size_t get_age(size_t i)
	{
		return age[i];
	}

};


class canton // Военная часть
{
protected:
	std::string code_name;
	size_t supply;
	canton_compound* ref;
public:
	canton()
		: code_name("empty canton"),
		supply(0)
	{ }

	canton(const std::string& code, canton_compound* _ref, size_t _supply)
		: code_name(code),
		supply(_supply),
		ref(_ref)
	{ }

	size_t get_supply()
	{
		return supply;
	}

	friend std::ostream & operator<<(std::ostream &out, canton & rhs);
};

std::ostream & operator<<(std::ostream &out, canton & rhs)
{
	out << rhs.code_name << ": " << std::endl;
	out << rhs.supply << std::endl;

	out <<  "compound: " << std::endl;
	for (size_t i = 0; i < (*rhs.ref).get_amount(); ++i)
		out << (*rhs.ref).get_ini(i) << " | " << (*rhs.ref).get_age(i) << std::endl;

	return out;
}

template <typename N>
class tech //список мех. армии путем добавления объектов
{
protected:
	std::string title;
	size_t amount_tech;
	std::vector<N> cont;
	canton* _canton;
public:
	tech() = default;

	tech(const std::string &_title, canton* ref)
		: title(_title)
		, amount_tech(0)
		, _canton(ref)
	{ }

	void add(N &tech_class_unit)
	{
		if ((*_canton).get_supply() <= amount_tech)
		{
			cont.push_back(tech_class_unit);
			++amount_tech;
		}
		else
		{
			std::cout << "Not enough supply" << std::endl;
		}
	}

	template <typename N>
	friend std::ostream & operator<<(std::ostream &out, tech<N> & rhs);
};

template <typename N>
std::ostream & operator<<(std::ostream &out, tech<N> & rhs)
{
	out << rhs.title << ": " << std::endl;
	for (size_t i = 0; i < rhs.amount_tech; ++i)
		out << rhs.cont[i].get_serial() << std::endl;
	return out;
}

class tank
{
protected:
	size_t serial;
public:
	tank(size_t _serial)
		: serial(_serial)
	{ }
	size_t get_serial()
	{
		return serial;
	}
	void set_serial(size_t _serial)
	{
		serial = _serial;
	}

	size_t get_serial(size_t _serial)
	{
		return serial;
	}

	virtual void manual_set()
	{
			std::cout << "Enter tank serial: " << std::endl;
			std::cin >> serial;
	}
};

class armoured_tank : public tank
{
protected:
	size_t armor;
public:
	armoured_tank(size_t _serial, size_t _armor)
		: tank(serial),
		  armor(_armor)
	{ }
	size_t get_serial()
	{
		return serial;
	}
	void set_serial(size_t _serial)
	{
		serial = _serial;
	}

	size_t get_serial(size_t _serial)
	{
		return serial;
	}

	void manual_set()
	{
		std::cout << "Enter armoured tank serial and armor: " << std::endl;
		std::cin >> serial >> armor;
	}
};
int main()
{
	canton_compound b(2);
	b.set();
	canton a("alpha", &b, 1);

	std::cout << a;
	std::cout << std::endl;

	tech<tank> alpha_1("alpha_1", &a);
	tank tank1(16574);
	tank tank2(1634);

	alpha_1.add(tank1);
	alpha_1.add(tank2);

	std::cout << alpha_1 << std::endl;

	armoured_tank tank3(12345, 5);
	tank *tank4;
	tank4 = &tank1;
	tank4->manual_set();
	tank4 = &tank3;
	tank3.manual_set();

}
