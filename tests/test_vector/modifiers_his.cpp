#include "../../vector.hpp"
#include <vector>
#include <iostream>

template <typename List>
void	print_vector(List &vector)
{
	typename List::iterator current = vector.begin();
	typename List::iterator end = vector.end();

	std::cout << "size = " << vector.size() << "\n";
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
	std::vector<int> orderedInts({1, 2, 3, 5});
	std::vector<int>::iterator ordered_begin = orderedInts.begin();
	std::vector<int>::iterator ordered_end = orderedInts.end();

	std::cout << "---------------------\n\n";
	std::cout << "MODIFIERS\n";

	std::cout << "\n assign \n\n";

	std::vector<std::string> vector1;
	std::vector<int> vector3;

	vector1.assign((size_t)5, "Bonjour");
	vector3.assign((size_t)5, 77);
	print_vector(vector1);
	print_vector(vector3);
	++str_begin;
	vector1.assign(str_begin, str_end);
	ordered_end--;
	vector3.assign(ordered_begin, ordered_end);
	print_vector(vector1);
	print_vector(vector3);

	std::cout << "\n insert \n\n";

	vector3.insert(vector3.begin(), 345);
	print_vector(vector3);
	vector3.insert(vector3.end(), 123);
	vector3.insert(++(vector3.begin()), 4598);
	std::cout << "new element = " << *(vector1.insert(vector1.begin(), "345")) << "\n";
	vector1.insert(vector1.end(), "123");
	vector1.insert(++(vector1.begin()), "4598");
	print_vector(vector1);
	print_vector(vector3);
	vector3.insert(vector3.begin(), (size_t)10, 345);
	vector3.insert(vector3.end(), (size_t)10, 123);
	vector3.insert(++(vector3.begin()), (size_t)10, 4598);
	vector1.insert(vector1.begin(), (size_t)10, "345");
	vector1.insert(vector1.end(), (size_t)10, "123");
	vector1.insert(++(vector1.begin()), (size_t)10, "4598");
	print_vector(vector1);
	print_vector(vector3);
	vector3.insert(vector3.begin(), ordered_begin, ordered_end);
	vector3.insert(vector3.end(), ordered_begin, ordered_end);
	vector3.insert(++(vector3.begin()), ordered_begin, ordered_end);
	vector1.insert(vector1.begin(), str_begin, str_end);
	vector1.insert(vector1.end(), str_begin, str_end);
	vector1.insert(++(vector1.begin()), str_begin, str_end);
	print_vector(vector1);
	print_vector(vector3);

	std::cout << "\n erase \n\n";

	vector1.erase(++vector1.begin());
	vector1.erase(--vector1.end());
	vector3.erase(++vector3.begin());
	vector3.erase(--vector3.end());
	print_vector(vector1);
	print_vector(vector3);

	std::vector<std::string>::iterator	str_del_end = vector1.begin();
	++str_del_end;
	++str_del_end;
	++str_del_end;
	vector1.erase(vector1.begin(), str_del_end);
	std::vector<int>::iterator	int_del_end = vector3.begin();
	++int_del_end;
	++int_del_end;
	++int_del_end;
	vector3.erase(vector3.begin(), int_del_end);
	print_vector(vector1);
	print_vector(vector3);

	std::cout << "\n swap / non member swap \n\n";

	std::vector<std::string>	empty_str;
	std::vector<int>			empty_int;

	vector1.swap(empty_str);
	vector3.swap(empty_int);
	print_vector(vector1);
	print_vector(vector3);
	print_vector(empty_str);
	print_vector(empty_int);

	swap(empty_str, vector1);
	swap(empty_int, vector3);
	print_vector(vector1);
	print_vector(vector3);
	print_vector(empty_str);
	print_vector(empty_int);

	std::cout << "clear\n";

	vector1.clear();
	vector1.clear();
	vector3.clear();
	vector3.clear();
	print_vector(vector1);
	print_vector(vector3);

	return (0);
}
