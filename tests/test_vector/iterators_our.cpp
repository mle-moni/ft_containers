#include "../../vector.hpp"
#include <vector>
#include <iostream>

int		main(void)
{
	std::vector<std::string> orderedStr({"Hey", "i", "am", "mayeul"});
	std::vector<std::string>::iterator str_begin = orderedStr.begin();
	std::vector<std::string>::iterator str_end = orderedStr.end();

	std::cout << "---------------------\n\n";
	std::cout << "ITERATORS\n";

	ft::vector<std::string> list1(str_begin, str_end);
	ft::vector<int> list3;

	std::cout << "simple iterator\n";
	{
		ft::vector<std::string>::iterator	current = list1.begin();
		ft::vector<std::string>::iterator	end = list1.end();
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
		ft::vector<std::string>::reverse_iterator	current = list1.rbegin();
		ft::vector<std::string>::reverse_iterator	end = list1.rend();
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
		ft::vector<std::string>::const_iterator	current = list1.begin();
		ft::vector<std::string>::const_iterator	end = list1.end();
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
		ft::vector<std::string>::const_reverse_iterator	current = list1.rbegin();
		ft::vector<std::string>::const_reverse_iterator	end = list1.rend();
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
	std::cout << "\n random acces things \n\n";
	{
		ft::vector<std::string>::iterator	current = list1.begin();
		ft::vector<std::string>::iterator	end = list1.end();
		
		std::cout << "\n iterator-> \n\n";
		while (current != end)
		{
			std::cout << current->size() << ", ";
			++current;
		}
		std::cout << "\n";
		std::cout << "\n iterator[] \n\n";
		size_t	i = 0;
		current = list1.begin();
		while (i < list1.size())
		{
			std::cout << current[i] << ", ";
			++i;
		}
		std::cout << "\n";
		std::cout << "\n iterator < iterator\n\n";
		std::cout << (list1.begin() < list1.end()) << "\n";
		std::cout << "\n iterator > iterator\n\n";
		std::cout << (list1.begin() > list1.end()) << "\n";
		std::cout << "\n iterator == iterator\n\n";
		std::cout << (list1.begin() == list1.end()) << "\n";
		std::cout << "\n iterator <= iterator\n\n";
		std::cout << (list1.begin() <= list1.end()) << "\n";
		std::cout << "\n iterator >= iterator\n\n";
		std::cout << (list1.begin() >= list1.end()) << "\n";
		
		std::cout << "\n iterator + \n\n";
		std::cout << ((list1.begin() + 2) - (list1.begin() + 1)) << "\n";
		std::cout << "\n iterator - \n\n";
		std::cout << ((list1.end() - 2) - (list1.end() - 1)) << "\n";
		std::cout << "\n iterator += \n\n";
		current = list1.begin();
		while (current != end)
		{
			std::cout << *current << ", ";
			current += 1;
		}
		std::cout << "\n";
	}
	return (0);
}
