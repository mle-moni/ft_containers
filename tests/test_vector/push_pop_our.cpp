#include "../../vector.hpp"
#include <vector>
#include <iostream>

template <typename List>
void	print_vector(List &vector)
{
	typename List::iterator current = vector.begin();
	typename List::iterator end = vector.end();

	std::cout << vector.size() << " = size\n";
	std::cout << vector.capacity() << " = capacity\n";
	while (current != end)
	{
		std::cout << *current << ", ";
		++current;
	}
	std::cout << "\n";
}

int		main(void)
{
	std::vector<std::string> orderedStr({"Hey", "i", "am", "mayeul"});
	std::vector<std::string>::iterator str_begin = orderedStr.begin();
	std::vector<std::string>::iterator str_end = orderedStr.end();

	std::cout << "---------------------\n\n";
	std::cout << "PUSH / POP\n\n";

	ft::vector<std::string> vector1(str_begin, str_end);
	ft::vector<int> vector3;

	print_vector(vector1);
	print_vector(vector3);
	vector3.push_back(42);
	vector1.pop_back();
	print_vector(vector1);
	print_vector(vector3);
	vector3.push_back(663);
	vector3.pop_back();
	vector1.push_back(":))");
	print_vector(vector1);
	print_vector(vector3);
	vector1.pop_back();
	vector3.push_back(-4);
	print_vector(vector1);
	print_vector(vector3);

	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	vector3.push_back(42);
	print_vector(vector3);
	return (0);
}
