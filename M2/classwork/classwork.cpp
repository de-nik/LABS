#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

enum Grade
{
	F = 1,
	D,
	C,
	B,
	A
};

struct Student
{
	std::string FIO;
	std::string Group;
	std::map<std::string, Grade> Grades;
};

std::vector<Student> LoadStudents()
{
	return{
		{
			"Anna", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::A },
				{ "english", Grade::A },
				{ "dutch", Grade::B },

			}
		},
		{
			"Petr", "G7",
			{
				{ "math", Grade::A },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },

			}
		},
		{
			"Vova", "G1",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },

			}
		},
		{
			"Vasya", "G3",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "cs", Grade::B },
				{ "dutch", Grade::C },

			}
		},
		{
			"Anton", "G4",
			{
				{ "math", Grade::F },
				{ "english", Grade::F },
				{ "dutch", Grade::C },
				{ "cs", Grade::C },

			}
		},
		{
			"Masha", "G2",
			{
				{ "math", Grade::A },

			}
		},
		{
			"Sasha", "G6",
			{
				{ "english", Grade::F },
				{ "russian", Grade::F },
				{ "dutch", Grade::F },

			}
		},
		{
			"Jeka", "G2",
			{
				{ "english", Grade::A },

			}
		},
		{
			"Sveta", "G3",
			{

			}
		}
	};
}

struct NewSubj
{
	void operator() (Student& a)
	{
		float Mark_Lit = 0;
		for (auto itLit = a.Grades.begin(); itLit != a.Grades.end(); ++itLit)
		{
			Mark_Lit += itLit->second;
		}
		Mark_Lit /= a.Grades.size();
		Grade Mark_Lit2 = (Grade)(int)ceil(Mark_Lit);
		a.Grades.insert(std::pair<std::string, Grade>("Russian Literature", Mark_Lit2));
	}
};

struct ba
{
	Grade math_grade = Grade::A;
	Grade cs_grade = Grade::B;
	void operator()(const Student& s) const
	{
		if (s.Grades.count("math") && s.Grades.count("cs") && s.Grades.find("math")->second == math_grade && s.Grades.find("cs")->second == cs_grade)
		{
			std::cout << s.FIO << " : Math = A, Cs = B " << std::endl;
		}
	}
};

struct group
{
	std::string neededGroup;
	void operator()(const Student& s) const
	{
		if (s.Group == neededGroup)
		{
			std::cout << s.FIO << " studies in " << s.Group << std::endl;
		}
	}
};

struct dutch_
{
	void operator()(const Student& s) const
	{
		if (s.Grades.count("dutch"))
		{
			std::cout << s.FIO << " - dutch" << std::endl;
		}
		else
		{
			std::cout << s.FIO << " - !dutch" << std::endl;
		}
	}
};

struct sub
{
	bool operator()(const Student &a, const Student &b)
	{
		return (a.Grades.size() < b.Grades.size());
	}
};
struct mat
{
	bool operator()(const Student &a, const Student &b)
	{
		if (a.Grades.count("math") && b.Grades.count("math"))
		{
			return (a.Grades.find("math")->second < b.Grades.find("math")->second);
		}
		else return 0;
	}
};
struct score
{
	bool operator()(const Student &a, const Student &b)
	{
		float Mark_A = 0;
		float Mark_B = 0;
		for (auto ita = a.Grades.begin(); ita != a.Grades.end(); ++ita)
		{
			Mark_A += ita->second;
		}
		Mark_A /= a.Grades.size();

		for (auto itb = b.Grades.begin(); itb != b.Grades.end(); ++itb)
		{
			Mark_B += itb->second;
		}
		Mark_B /= b.Grades.size();
		return Mark_A < Mark_B;
	}
};
int main()
{
	std::vector<Student> students = LoadStudents();
	std::for_each(students.begin(), students.end(), ba());
	std::for_each(students.begin(), students.end(), group{ "G7" });
	auto it = std::max_element(students.begin(), students.end(), sub());
	std::cout << "More subjects : " << it->FIO << std::endl;
	auto it2 = std::max_element(students.begin(), students.end(), mat());
	std::cout << "Best math : " << it2->FIO << " ; Mark = " << it2->Grades.find("math")->second << std::endl;
	auto it3 = std::min_element(students.begin(), students.end(), score());
	std::cout << "Worst mark : " << it3->FIO << std::endl;
	std::for_each(students.begin(), students.end(), dutch_());
	std::for_each(students.begin(), students.end(), NewSubj());
}
