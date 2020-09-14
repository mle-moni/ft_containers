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
	std::vector<int>			fill_int((size_t)5, 42);
	std::vector<std::string>	fill_str((size_t)5, "yoooo");
	std::vector<int>			range_int(test_int.begin(), test_int.end());
	std::vector<std::string>	range_str(test_str.begin(), test_str.end());
	std::vector<int>			copy_int(range_int.begin(), range_int.end());
	std::vector<std::string>	copy_str(range_str.begin(), range_str.end());

	std::cout << "---------------------\n\n";
	std::cout << "CONSTRUCTORS / CAPACITY\n\n";
	
	std::cout << "\n Constructors \n\n";
	print_vec(empty);
	print_vec(fill_int);
	print_vec(fill_str);
	print_vec(range_int);
	print_vec(range_str);
	print_vec(copy_int);
	print_vec(copy_str);

	std::cout << "\n Operator= \n\n";

	copy_int = fill_int;
	copy_str = fill_str;
	print_vec(copy_int);
	print_vec(copy_str);

	std::cout << "\n resize \n\n";
	
	copy_str.resize(20);
	print_vec(copy_str);
	copy_str.resize(10, "super");
	print_vec(copy_str);
	copy_str.resize(20, "genial");
	print_vec(copy_str);
	copy_str.resize(0);
	print_vec(copy_str);

	std::cout << "\n reserve \n\n";

	fill_str.reserve(0);
	print_vec(fill_str);
	fill_str.reserve(10);
	print_vec(fill_str);
	fill_str.reserve(30);
	print_vec(fill_str);
	fill_str.reserve(40);
	print_vec(fill_str);
	
	empty.reserve(0);
	print_vec(empty);
	empty.reserve(10);
	print_vec(empty);
	empty.reserve(30);
	print_vec(empty);
	empty.reserve(40);
	print_vec(empty);
	return (0);
}