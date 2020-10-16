#include "../../map.hpp"
#include <map>
#include <iostream>

int		main(void)
{
	std::map<char, int>			test_int({
		std::make_pair('a', 22),
		std::make_pair('g', 61),
		std::make_pair('2', 1),
		std::make_pair('b', 6),
		std::make_pair('g', 71),
		std::make_pair('a', 42),
		std::make_pair('d', 12)
	});
	std::map<std::string, char>	test_str({
		std::make_pair("super", 'a'),
		std::make_pair("ouais", 'g'),
		std::make_pair("^^", '2'),
		std::make_pair("mayeul", 'b'),
		std::make_pair("paprika", 'g'),
		std::make_pair("nuage", 'a'),
		std::make_pair("raton-laveur", 'd')
	});


	std::cout << "---------------------\n\n";
	std::cout << "ITERATORS\n";

	ft::map<char, int>			map1(test_int.begin(), test_int.end());
	ft::map<std::string, char>	map2(test_str.begin(), test_str.end());
	ft::map<std::string, char>	map3;

	std::cout << "iterator with empty map\n";
	{
		ft::map<std::string, char>::iterator	current = map3.begin();
		ft::map<std::string, char>::iterator	end = map3.end();
		while (current != end)
		{
			std::cout << "map[ " << current->first << " ] = " << current->second << "\n";
			current++;
		}
		std::cout << "\n";
	}

	std::cout << "simple iterator\n";
	{
		ft::map<char, int>::iterator	current = map1.begin();
		ft::map<char, int>::iterator	end = map1.end();
		current++;
		--current;
		++current;
		end--;
		--end;
		++end;
		end++;
		while (current != end)
		{
			std::cout << "map[ " << current->first << " ] = " << current->second << "\n";
			++current;
		}
		if (map3.begin() == map3.end())
			std::cout << "list is empty\n";
		std::cout << "\n";
	}
	std::cout << "reverse iterator\n";
	{
		ft::map<std::string, char>::reverse_iterator	current = map2.rbegin();
		ft::map<std::string, char>::reverse_iterator	end = map2.rend();
		current++;
		--current;
		++current;
		end--;
		--end;
		++end;
		end++;
		while (current != end)
		{
			std::cout << "map[ " << current->first << " ] = " << current->second << "\n";
			++current;
		}
		std::cout << "\n";
	}
	std::cout << "const iterator\n";
	{
		ft::map<char, int>::const_iterator	current = map1.begin();
		ft::map<char, int>::const_iterator	end = map1.end();
		current++;
		--current;
		++current;
		end--;
		--end;
		++end;
		end++;
		while (current != end)
		{
			std::cout << "map[ " << current->first << " ] = " << current->second << "\n";
			++current;
		}
		std::cout << "\n";
	}
	std::cout << "const reverse iterator\n";
	{
		ft::map<std::string, char>::const_reverse_iterator	current = map2.rbegin();
		ft::map<std::string, char>::const_reverse_iterator	end = map2.rend();
		current++;
		--current;
		++current;
		end--;
		--end;
		++end;
		end++;
		while (current != end)
		{
			std::cout << "map[ " << current->first << " ] = " << current->second << "\n";
			++current;
		}
		std::cout << "\n";
	}

	return (0);
}
