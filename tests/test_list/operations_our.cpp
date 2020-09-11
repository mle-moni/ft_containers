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

struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

struct start_with_i {
	bool operator() (const std::string& value) { return (value[0] == 'i'); }
};

bool	is_near(const int& value, const int& value2)
{
	return (value - 2 < value2 && value + 2 > value2);
}

bool	my_comp(int first, int second)
{
	return (first < second);
}

bool	is_more(int first, int second)
{
	return (first > second);
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
	std::cout << "OPERATIONS\n";

	std::cout << "splice\n";
	ft::list<std::string>	str_lst1(str_begin, str_end);
	ft::list<std::string>	str_lst2(str_begin, str_end);
	ft::list<std::string>	str_lst3;
	ft::list<int> 			int_lst1(ordered_begin, ordered_end);
	ft::list<int> 			int_lst2(ordered_begin, ordered_end);
	ft::list<int> 			int_lst3;

	str_lst1.splice(str_lst1.begin(), str_lst3);
	str_lst1.splice(str_lst1.end(), str_lst2, --str_lst2.end());
	str_lst1.splice(str_lst1.end(), str_lst2, ++str_lst2.begin(), str_lst2.end());
	str_lst1.splice(str_lst1.begin(), str_lst2);
	str_lst3.splice(str_lst3.begin(), str_lst1);

	int_lst1.splice(int_lst1.begin(), int_lst3);
	int_lst1.splice(int_lst1.end(), int_lst2, --int_lst2.end());
	int_lst1.splice(int_lst1.end(), int_lst2, ++int_lst2.begin(), int_lst2.end());
	int_lst1.splice(int_lst1.begin(), int_lst2);
	int_lst3.splice(int_lst3.begin(), int_lst1);

	print_list(str_lst1);
	print_list(str_lst2);
	print_list(str_lst3);
	print_list(int_lst1);
	print_list(int_lst2);
	print_list(int_lst3);

	std::cout << "remove\n";

	str_lst1.remove("Hey");
	str_lst2.remove("Hey");
	str_lst3.remove("Hey");
	str_lst1.remove("am");
	str_lst2.remove("am");
	str_lst3.remove("am");
	int_lst1.remove(1);
	int_lst2.remove(1);
	int_lst3.remove(1);
	int_lst1.remove(3);
	int_lst2.remove(3);
	int_lst3.remove(3);
	print_list(str_lst1);
	print_list(str_lst2);
	print_list(str_lst3);
	print_list(int_lst1);
	print_list(int_lst2);
	print_list(int_lst3);
	
	std::cout << "remove_if\n";
	
	str_lst1.remove_if(start_with_i());
	str_lst2.remove_if(start_with_i());
	str_lst3.remove_if(start_with_i());
	int_lst1.remove_if(is_odd());
	int_lst2.remove_if(is_odd());
	int_lst3.remove_if(is_odd());
	print_list(str_lst1);
	print_list(str_lst2);
	print_list(str_lst3);
	print_list(int_lst1);
	print_list(int_lst2);
	print_list(int_lst3);

	std::cout << "unique\n";

	std::list<std::string> non_unique_str({"Hey", "i", "am", "mayeul", "Hey", "am", "super", "am", "am"});
	std::list<int> non_unique_int({-2, 1, 1, 2, 50, 1, 3, 5, 50, -2});

	ft::list<std::string>	str1(non_unique_str.begin(), non_unique_str.end());
	ft::list<int>	int1(non_unique_int.begin(), non_unique_int.end());

	str1.unique();
	int1.unique();
	int1.unique(is_near);
	print_list(str1);
	print_list(int1);

	std::cout << "merge\n";

	std::list<std::string> str_ordered({"aaah", "abriter", "balle", "boule", "garage", "girouette", "madame", "route", "surement"});
	std::list<std::string> str_ordered2({"abriter", "balle", "crayon", "raton", "route", "zebre"});
	std::list<std::string> str_ordered3({"mayeul"});
	std::list<int> int_ordered({-2, 1, 1, 2, 50, 50, 200});
	std::list<int> int_ordered2({-20, 2, 3, 5, 51, 88});
	std::list<int> int_ordered3({44});

	str_ordered.merge(str_ordered2);
	str_ordered.merge(str_ordered3);

	int_ordered.merge(int_ordered2, my_comp);
	int_ordered.merge(int_ordered3, my_comp);
	print_list(str_ordered);
	print_list(str_ordered2);
	print_list(str_ordered3);
	print_list(int_ordered);
	print_list(int_ordered2);
	print_list(int_ordered3);

	std::cout << "reverse\n";

	str_ordered.reverse();
	int_ordered.reverse();
	int_ordered.reverse();
	int_ordered3.reverse();
	print_list(int_ordered3);
	print_list(str_ordered);
	print_list(int_ordered);
	int_ordered.reverse();
	print_list(int_ordered);

	std::cout << "sort\n";

	str_ordered.sort();
	str_ordered.push_back("criquet");
	str_ordered.sort();
	int_ordered.sort(my_comp);
	print_list(str_ordered);
	print_list(int_ordered);
	int_ordered.sort(is_more);
	print_list(int_ordered);

	return (0);
}
