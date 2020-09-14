#include "../../vector.hpp"
#include <vector>
#include <iostream>

/*
bool single_digit(const int& value)
{
	return (value<10);
}

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

struct is_near {
	bool operator() (int first, int second)
	{
		if (first + 2 > second && first - 2 < second)
			return (true);
		return (false);
	}
};

bool	my_comp(int first, int second)
{
	return (first < second);
}
class Truc: public std::string
{
	public:
	virtual ~Truc()
    {
        std::cout<<"I AM DESTROYED"<<std::endl;
    }
};
*/

template <typename Vec>
void	print_vec(Vec &list)
{
	typename Vec::iterator current = list.begin();
	typename Vec::iterator end = list.end();

	std::cout << list.size() << " = size\n";
	std::cout << list.capacity() << " = capacity\n";
	std::cout << list.empty() << " = empty()\n";
	while (current != end)
	{
		std::cout << *current << ", ";
		++current;
	}
	std::cout << "\n";
}

int		main(void)
{
	std::vector<int>			test_int({1, 2, 3, 4, 5, 6, 7, 8});
	std::vector<std::string>	test_str({"salut", "je", "suis", "mayeul", "hihi"});

	std::vector<std::string>	empty;
	std::vector<int>			range_int(test_int.begin(), test_int.end());
	std::vector<std::string>	range_str(test_str.begin(), test_str.end());

	std::cout << "---------------------\n\n";
	std::cout << "CONSTRUCTORS / CAPACITY\n\n";
	
	std::cout << "\n vector[] \n\n";

	std::cout << range_str[0] << range_str[1] << range_str[range_str.size() - 1] << "\n";
	std::cout << range_int[0] << range_int[1] << range_int[range_int.size() - 1] << "\n";

	std::cout << "\n vector.at() \n\n";

	try
	{
		empty.at(0);
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "catch: index out of range" << '\n';
	}
	try
	{
		range_str.at(range_str.size());
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "catch: index out of range" << '\n';
	}
	try
	{
		range_str.at(-1);
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "catch: index out of range" << '\n';
	}

	const std::string	const_str = range_str[0];
	std::cout << const_str << "\n";
	

	std::cout << "\n vector.front() \n\n";
	
	std::cout << range_int.front() << ", ";
	std::cout << range_str.front() << "\n";

	std::cout << "\n vector.back() \n\n";
	
	std::cout << range_int.back() << ", ";
	std::cout << range_str.back() << "\n";

	return (0);
}
