#include "../../map.hpp"
#include <map>
#include <iostream>

template <typename MyMap>
void	print_map(MyMap &theMap)
{
	typename MyMap::iterator current = theMap.begin();
	typename MyMap::iterator end = theMap.end();

	std::cout << theMap.size() << " = size\n";
	std::cout << theMap.empty() << " = empty()\n\nlistbegin\n";
	while (current != end)
	{
		std::cout << "map[ " << current->first << " ] = " << current->second << "\n";
		++current;
	}
	std::cout << "endoflist\n\n";
}

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

	ft::map<std::string, char>	empty;
	ft::map<char, int>			range_int(test_int.begin(), test_int.end());
	ft::map<std::string, char>	range_str(test_str.begin(), test_str.end());
	ft::map<char, int>			copy_int(range_int.begin(), range_int.end());
	ft::map<std::string, char>	copy_str(range_str.begin(), range_str.end());

	std::cout << "---------------------\n\n";
	std::cout << "CONSTRUCTORS / CAPACITY\n\n";
	
	std::cout << "\n Constructors \n\n";
	print_map(empty);
	print_map(range_int);
	print_map(range_str);
	print_map(copy_int);
	print_map(copy_str);

	std::cout << "\n Operator= \n\n";

	empty["coucou"] = 25;

	copy_str = empty;
	print_map(copy_str);

	return (0);
}