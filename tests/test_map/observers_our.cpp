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

	ft::map<char, int>			map1(test_int.begin(), test_int.end());

	std::cout << "---------------------\n\n";
	std::cout << "OBSERVERS\n\n";
	
	std::cout << "key_comp\n";
	{
		ft::map<char,int>::key_compare mycomp = map1.key_comp();
		std::cout << "map1 contains:\n";
		char highest = map1.rbegin()->first;
		ft::map<char,int>::iterator it = map1.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );
		std::cout << '\n';
	}

	std::cout << "\nvalue_comp\n";
	{
		std::cout << "mymap contains:\n";
		ft::pair<char,int> highest = *map1.rbegin();

		ft::map<char,int>::iterator it = map1.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( map1.value_comp()(*it++, highest) );
	}

	return (0);
}