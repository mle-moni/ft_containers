#include "../../map.hpp"
#include <map>
#include <iostream>

int		main(void)
{
	std::map<std::string, char>	test_1({
		std::make_pair("super", 'a'),
		std::make_pair("ouais", 'g'),
		std::make_pair("^^", '2'),
		std::make_pair("mayeul", 'b'),
		std::make_pair("paprika", 'g'),
		std::make_pair("nuage", 'a'),
		std::make_pair("raton-laveur", 'd')
	});
	std::map<std::string, char>	test_2({
		std::make_pair("super", 'a'),
		std::make_pair("ouais", 'g'),
		std::make_pair("^^", '2'),
		std::make_pair("mayeul", 'b'),
		std::make_pair("paprika", 'g'),
		std::make_pair("nuage", 'a'),
		std::make_pair("raton-laveur", 'd')
	});

	std::map<std::string, char>	map1(test_1.begin(), test_1.end());
	std::map<std::string, char>	map2(test_2.begin(), test_2.end());
	std::map<std::string, char>	map3(map2);
	std::map<std::string, char>	map4(map2);

	map4["haha"] = 'V';

	std::cout << "---------------------\n\n";
	std::cout << "COMPARAISON OPERATORS\n";

	std::cout << "test operator==\n";
	std::cout << "map1 == map2 -> " << (map1 == map2) << "\n";
	std::cout << "map2 == map1 -> " << (map2 == map1) << "\n";
	std::cout << "map2 == map3 -> " << (map2 == map3) << "\n";
	std::cout << "map3 == map4 -> " << (map3 == map4) << "\n";
	std::cout << "map4 == map3 -> " << (map4 == map3) << "\n";

	std::cout << "\ntest operator!=\n";
	std::cout << "map1 != map2 -> " << (map1 != map2) << "\n";
	std::cout << "map2 != map1 -> " << (map2 != map1) << "\n";
	std::cout << "map2 != map3 -> " << (map2 != map3) << "\n";
	std::cout << "map3 != map4 -> " << (map3 != map4) << "\n";
	std::cout << "map4 != map3 -> " << (map4 != map3) << "\n";

	std::cout << "\ntest operator <\n";
	std::cout << "map1 < map2 -> " << (map1 < map2) << "\n";
	std::cout << "map2 < map1 -> " << (map2 < map1) << "\n";
	std::cout << "map2 < map3 -> " << (map2 < map3) << "\n";
	std::cout << "map3 < map4 -> " << (map3 < map4) << "\n";
	std::cout << "map4 < map3 -> " << (map4 < map3) << "\n";

	std::cout << "\ntest operator <=\n";
	std::cout << "map1 <= map2 -> " << (map1 <= map2) << "\n";
	std::cout << "map2 <= map1 -> " << (map2 <= map1) << "\n";
	std::cout << "map2 <= map3 -> " << (map2 <= map3) << "\n";
	std::cout << "map3 <= map4 -> " << (map3 <= map4) << "\n";
	std::cout << "map4 <= map3 -> " << (map4 <= map3) << "\n";

	std::cout << "\ntest operator >\n";
	std::cout << "map1 > map2 -> " << (map1 > map2) << "\n";
	std::cout << "map2 > map1 -> " << (map2 > map1) << "\n";
	std::cout << "map2 > map3 -> " << (map2 > map3) << "\n";
	std::cout << "map3 > map4 -> " << (map3 > map4) << "\n";
	std::cout << "map4 > map3 -> " << (map4 > map3) << "\n";

	std::cout << "\ntest operator >=\n";
	std::cout << "map1 >= map2 -> " << (map1 >= map2) << "\n";
	std::cout << "map2 >= map1 -> " << (map2 >= map1) << "\n";
	std::cout << "map2 >= map3 -> " << (map2 >= map3) << "\n";
	std::cout << "map3 >= map4 -> " << (map3 >= map4) << "\n";
	std::cout << "map4 >= map3 -> " << (map4 >= map3) << "\n";
	std::cout << "\n";
	
	return (0);
}
