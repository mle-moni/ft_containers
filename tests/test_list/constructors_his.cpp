#include "../../list.hpp"
#include <list>
#include <iostream>

template <typename List>
void	print_list(List &list)
{
	typename List::iterator current = list.begin();
	typename List::iterator end = list.end();

	while (current != end)
	{
		std::cout << *current << ", ";
		++current;
	}
	std::cout << "\n";
}

int		main(void)
{
	std::list<int> orderedInts({1, 2, 3, 5});
	std::list<int>::iterator ordered_begin = orderedInts.begin();
	std::list<int>::iterator ordered_end = orderedInts.end();

	std::cout << "---------------------\n\n";
	std::cout << "CONSTRUCTORS / OPERATOR=\n";

	std::cout << "default constructor\n";
	std::list<int> list1;
	print_list(list1);
	std::cout << "range constructor\n";
	std::list<int> list2(ordered_begin, ordered_end);
	print_list(list2);
	std::cout << "copy constructor\n";
	std::list<int> list3(list2);
	print_list(list3);
	std::cout << "fill constructor\n";
	std::list<std::string> list4(5, "Salut");
	print_list(list4);
	std::cout << "operator=\n";
	list1 = list3;
	print_list(list1);
	std::cout << "\n";
	return (0);
}
