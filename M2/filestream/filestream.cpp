#include <exception>
#include <string>
#include <vector>
#include <iostream>

class filestream
{
	FILE * filep;

public:

	~filestream() {
		close();
	}

	filestream()
		: filep(nullptr)
	{ }

	void read(char* s, std::streamsize n) 
	{
		if (filep == nullptr)
		{
			throw std::exception("can't_read");
		}
		else fgets(s, n + 1, filep);
	}

	void write(const char* s, std::streamsize n)
	{
		if (filep == nullptr)
		{
			throw std::exception("can't write");
		}
		else fwrite(s, sizeof(char), n, filep);
	}

	void open(const std::string& filename, char * mode) 
	{
		if (filep != nullptr)
		{
			throw std::exception("opened");
		}

		std::string mod[] = { "r", "w", "a", "r+", "w+", "a+", "rb", "wb", "ab",
			"r+b", "w+b", "a+b", "rb+", "wb+", "ab+", "wx", "wbx", "w+x", "wb+x", "w+bx" };	

		for (size_t i = 0; i < 20; ++i)
		{
			if (mod[i] == mode)
			{
				filep = fopen(filename.c_str(), mode);
			}
		}
		
		if (filep == nullptr)
		{
			throw std::exception("incorect_mode");
		}
	}

	void close() throw()
	{
		if (filep != nullptr)
		{
			fclose(filep);
			filep = nullptr;
		}
	}

	bool is_open() 
	{
		if (filep != nullptr)
			return true;
		else return false;
	}

	char * getline(char* s)
	{
		if (!(this->is_open()))
		{
			throw std::exception("Error");
		}
		std::vector<char> vec;
		while (!feof(filep))
		{
			vec.push_back(fgetc(filep));
		}
		s = new char[vec.size() + 1];
		std::copy(vec.begin(), vec.end(), s);
		s[vec.size()] = '\0';
		return s;
	}

};
