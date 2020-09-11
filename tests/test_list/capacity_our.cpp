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
	std::cout << "CAPACITY / ELEMENT ACCES\n";

	std::cout << "empty\n";
	{
		ft::list<std::string> list1(str_begin, str_end);
		ft::list<int> list3;

		std::cout << list3.empty() << list1.empty() << "\n";
		list3.push_front(1);
		list1.clear();
		std::cout << list3.empty() << list1.empty() << "\n";
		list3.pop_back();
		list1.push_back("yooo");
		std::cout << list3.empty() << list1.empty() << "\n";
	}
	
	std::cout << "size\n";
	{
		ft::list<std::string> list1(str_begin, str_end);
		ft::list<int> list3;

		std::cout << list3.size() << list1.size() << "\n";
		list3.push_front(1);
		list1.clear();
		std::cout << list3.size() << list1.size() << "\n";
		list3.pop_back();
		list1.push_back("yooo");
		std::cout << list3.size() << list1.size() << "\n";
	}

	std::cout << "max_size\n";
	{
		ft::list<std::string> list1(str_begin, str_end);
		ft::list<int> list3;

		list3.max_size();
		list1.max_size();
		list3.push_front(1);
		list1.clear();
		list3.max_size();
		list1.max_size();
		list3.pop_back();
		list1.push_back("yooo");
		list3.max_size();
		list1.max_size();
	}

	std::cout << "front / back\n";
	{
		ft::list<std::string> list1(str_begin, str_end);
		ft::list<int> list3;

		list3.push_back(42);
		std::cout << list3.front() << list1.front() << "\n";
		std::cout << list3.back() << list1.back() << "\n";
		list3.push_front(1);
		list1.clear();
		list1.push_front("tadam");
		std::cout << list3.front() << list1.front() << "\n";
		std::cout << list3.back() << list1.back() << "\n";
		list3.pop_back();
		list1.push_back("yooo");
		list1.push_front(":)");
		list3.push_front(1);
		list3.push_back(12);
		std::cout << list3.front() << list1.front() << "\n";
		std::cout << list3.back() << list1.back() << "\n";
	}
	
	return (0);
}
