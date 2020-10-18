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
		std::make_pair('z', 262),
		std::make_pair('d', 12)
	});

	ft::map<char, int>			map1(test_int.begin(), test_int.end());

	std::cout << "---------------------\n\n";
	std::cout << "OPERATIONS\n\n";
	
	std::cout << "find\n";
	{
		ft::map<char, int>::iterator	ite;
		ite = map1.find('2');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		ite = map1.find('3');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		ite = map1.find('z');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		ite = map1.find('a');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		std::cout << "\n";
	}

	std::cout << "count\n";
	{
		std::cout << "'2' matches " << map1.count('2') << " times\n";
		std::cout << "'3' matches " << map1.count('3') << " times\n";
		std::cout << "'z' matches " << map1.count('z') << " times\n";
		std::cout << "'a' matches " << map1.count('a') << " times\n";
		std::cout << "\n";
	}

	std::cout << "lower_bound\n";
	{
		ft::map<char, int>::iterator	ite;
		ite = map1.lower_bound('2');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		ite = map1.lower_bound('3');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		ite = map1.lower_bound('z');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		ite = map1.lower_bound('a');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		std::cout << "\n";
	}

	std::cout << "upper_bound\n";
	{
		ft::map<char, int>::iterator	ite;
		ite = map1.upper_bound('2');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		ite = map1.upper_bound('3');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		ite = map1.upper_bound('z');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		ite = map1.upper_bound('a');
		if (ite != map1.end())
			std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
		std::cout << "\n";
	}

	std::cout << "equal_range\n";
	{
		ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator>	range;
		ft::map<char, int>::iterator	ite;

		range = map1.equal_range('2');
		ite = range.first;
		while (ite != range.second) {
			if (ite != map1.end())
				std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
			++ite;
		}
		range = map1.equal_range('3');
		ite = range.first;
		while (ite != range.second) {
			if (ite != map1.end())
				std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
			++ite;
		}
		range = map1.equal_range('z');
		ite = range.first;
		while (ite != range.second) {
			if (ite != map1.end())
				std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
			++ite;
		}
		range = map1.equal_range('a');
		ite = range.first;
		while (ite != range.second) {
			if (ite != map1.end())
				std::cout << "key = " << ite->first << " val = " << ite->second << "\n";
			++ite;
		}
		
		std::cout << "\n";
	}

	return (0);
}