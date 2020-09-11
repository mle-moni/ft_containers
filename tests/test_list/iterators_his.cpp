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
	std::cout << "ITERATORS\n";

	std::list<std::string> list1(str_begin, str_end);
	std::list<int> list3;

	std::cout << "simple iterator\n";
	{
		std::list<std::string>::iterator	current = list1.begin();
		std::list<std::string>::iterator	end = list1.end();
		current++;
		--current;
		++current;
		end--;
		--end;
		++end;
		end++;
		while (current != end)
		{
			std::cout << *current << ", ";
			++current;
		}
		if (list3.begin() == list3.end())
			std::cout << "list is empty\n";
		std::cout << "\n";
	}
	std::cout << "reverse iterator\n";
	{
		std::list<std::string>::reverse_iterator	current = list1.rbegin();
		std::list<std::string>::reverse_iterator	end = list1.rend();
		current++;
		--current;
		++current;
		end--;
		--end;
		++end;
		end++;
		while (current != end)
		{
			std::cout << *current << ", ";
			++current;
		}
		std::cout << "\n";
	}
	std::cout << "const iterator\n";
	{
		std::list<std::string>::const_iterator	current = list1.begin();
		std::list<std::string>::const_iterator	end = list1.end();
		current++;
		--current;
		++current;
		end--;
		--end;
		++end;
		end++;
		while (current != end)
		{
			std::cout << *current << ", ";
			++current;
		}
		std::cout << "\n";
	}
	std::cout << "const reverse iterator\n";
	{
		std::list<std::string>::const_reverse_iterator	current = list1.rbegin();
		std::list<std::string>::const_reverse_iterator	end = list1.rend();
		current++;
		--current;
		++current;
		end--;
		--end;
		++end;
		end++;
		while (current != end)
		{
			std::cout << *current << ", ";
			++current;
		}
		std::cout << "\n";
	}
	return (0);
}
