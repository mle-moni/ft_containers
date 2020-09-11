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
	std::list<std::string> orderedStr({"Hey", "i", "am", "mayeul"});
	std::list<std::string>::iterator str_begin = orderedStr.begin();
	std::list<std::string>::iterator str_end = orderedStr.end();

	std::cout << "---------------------\n\n";
	std::cout << "PUSH / POP\n";

	std::cout << "push / pop\n";

	ft::list<std::string> list1(str_begin, str_end);
	ft::list<int> list3;

	print_list(list1);
	print_list(list3);
	list3.push_back(42);
	list1.pop_back();
	print_list(list1);
	print_list(list3);
	list3.push_back(663);
	list3.pop_front();
	list3.pop_back();
	list1.push_front(":))");
	list1.push_front("sldkfj");
	print_list(list1);
	print_list(list3);
	list1.pop_back();
	list3.push_front(-4);
	print_list(list1);
	print_list(list3);
	return (0);
}
