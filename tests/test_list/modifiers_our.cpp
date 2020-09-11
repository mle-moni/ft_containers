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
	std::list<int> orderedInts({1, 2, 3, 5});
	std::list<int>::iterator ordered_begin = orderedInts.begin();
	std::list<int>::iterator ordered_end = orderedInts.end();

	std::cout << "---------------------\n\n";
	std::cout << "MODIFIERS\n";

	std::cout << "assign\n";

	ft::list<std::string> list1;
	ft::list<int> list3;

	list1.assign((size_t)5, "Bonjour");
	list3.assign((size_t)5, 77);
	print_list(list1);
	print_list(list3);
	++str_begin;
	list1.assign(str_begin, str_end);
	ordered_end--;
	list3.assign(ordered_begin, ordered_end);
	print_list(list1);
	print_list(list3);

	std::cout << "insert\n";

	list3.insert(list3.begin(), 345);
	print_list(list3);
	list3.insert(list3.end(), 123);
	list3.insert(++(list3.begin()), 4598);
	list1.insert(list1.begin(), "345");
	list1.insert(list1.end(), "123");
	list1.insert(++(list1.begin()), "4598");
	print_list(list1);
	print_list(list3);
	list3.insert(list3.begin(), (size_t)10, 345);
	list3.insert(list3.end(), (size_t)10, 123);
	list3.insert(++(list3.begin()), (size_t)10, 4598);
	list1.insert(list1.begin(), (size_t)10, "345");
	list1.insert(list1.end(), (size_t)10, "123");
	list1.insert(++(list1.begin()), (size_t)10, "4598");
	print_list(list1);
	print_list(list3);
	list3.insert(list3.begin(), ordered_begin, ordered_end);
	list3.insert(list3.end(), ordered_begin, ordered_end);
	list3.insert(++(list3.begin()), ordered_begin, ordered_end);
	list1.insert(list1.begin(), str_begin, str_end);
	list1.insert(list1.end(), str_begin, str_end);
	list1.insert(++(list1.begin()), str_begin, str_end);
	print_list(list1);
	print_list(list3);

	std::cout << "erase\n";

	list1.erase(++list1.begin());
	list1.erase(--list1.end());
	list3.erase(++list3.begin());
	list3.erase(--list3.end());
	print_list(list1);
	print_list(list3);

	ft::list<std::string>::iterator	str_del_end = list1.begin();
	++str_del_end;
	++str_del_end;
	++str_del_end;
	list1.erase(list1.begin(), str_del_end);
	ft::list<int>::iterator	int_del_end = list3.begin();
	++int_del_end;
	++int_del_end;
	++int_del_end;
	list3.erase(list3.begin(), int_del_end);
	print_list(list1);
	print_list(list3);

	std::cout << "swap / non member swap\n";

	ft::list<std::string>	empty_str;
	ft::list<int>			empty_int;

	list1.swap(empty_str);
	list3.swap(empty_int);
	print_list(list1);
	print_list(list3);
	print_list(empty_str);
	print_list(empty_int);

	swap(empty_str, list1);
	swap(empty_int, list3);
	print_list(list1);
	print_list(list3);
	print_list(empty_str);
	print_list(empty_int);

	std::cout << "resize\n";

	list1.resize((size_t)100, "Coucou");
	list1.resize((size_t)120, "hey !!");
	list3.resize((size_t)10, 123);
	list3.resize((size_t)20, 321);
	print_list(list1);
	print_list(list3);
	std::cout << "resize with 0 length, then filling again\n";
	list1.resize((size_t)0);
	list1.resize((size_t)40, "hey !!");
	list3.resize((size_t)0);
	list3.resize((size_t)40, 321);
	print_list(list1);
	print_list(list3);

	std::cout << "clear\n";

	list1.clear();
	list1.clear();
	list3.clear();
	list3.clear();
	print_list(list1);
	print_list(list3);

	return (0);
}
