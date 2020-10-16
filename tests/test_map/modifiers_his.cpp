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

	std::map<char, int>			map1(test_int.begin(), test_int.end());
	std::map<char, int>	map2;

	std::cout << "---------------------\n\n";
	std::cout << "MODIFIERS\n";

	std::cout << "\n insert \n\n";

	print_map(map1);
	map2.insert(std::make_pair('G', 133));
	print_map(map2);
	map2.insert(map2.end(), std::make_pair('Q', 123));
	map2.insert(++(map2.begin()), std::make_pair('G', 555));
	print_map(map2);
	std::cout << "new element mapped value = " << map1.insert(map1.begin(), std::make_pair('G', 11))->second << "\n";
	map1.insert(map1.end(), std::make_pair('g', 12));
	print_map(map1);
	map1.insert(++(map1.begin()), std::make_pair('A', 112));
	print_map(map1);
	print_map(map2);
	map2.insert(map1.begin(), --map1.end());
	map2.insert(map1.begin(), map1.end());
	print_map(map1);
	print_map(map2);

	std::cout << "\n erase \n\n";

	if (map1.size() >= 2) {
		map1.erase(++map1.begin());
		map1.erase(--map1.end());
	}
	if (map2.size() >= 2) {
		map2.erase(++map2.begin());
		map2.erase(--map2.end());
	}
	print_map(map1);
	print_map(map2);

	map1.insert(std::make_pair('r', 1234));
	map1.insert(std::make_pair('4', 234));
	std::map<char, int>::iterator	del_end = map1.begin();
	++del_end;
	++del_end;
	std::cout << "moment before chaos\n\n";
	print_map(map1);
	std::cout << "o no moment\n";
	map1.erase(map1.begin(), del_end);
	print_map(map1);
	map2.insert(std::make_pair('t', 14));
	map2.insert(std::make_pair('q', 34));
	std::cout << "deleted: " << map2.erase('t');
	std::cout << ", deleted: " << map2.erase('0') << "\n";
	print_map(map2);

	std::cout << "\n swap / non member swap \n\n";

	std::map<char, int>	empty_map1;
	std::map<char, int>	empty_map2;

	map1.swap(empty_map1);
	map2.swap(empty_map2);
	print_map(map1);
	print_map(map2);
	print_map(empty_map1);
	print_map(empty_map2);

	swap(empty_map1, map1);
	swap(empty_map2, map2);
	print_map(map1);
	print_map(map2);
	print_map(empty_map1);
	print_map(empty_map2);

	std::cout << "clear\n";

	map1.clear();
	std::cout << "deuxieme\n";
	map1.clear();
	map2.clear();
	map2.clear();
	print_map(map1);
	print_map(map2);

	return (0);
}
