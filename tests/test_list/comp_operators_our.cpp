#include "../../list.hpp"
#include <list>
#include <iostream>

int		main(void)
{
	std::list<int> listOfInts({1, 2, 3, 4});
	std::list<int> orderedInts({1, 2, 3, 5});
	std::list<int>::iterator ordered_begin = orderedInts.begin();
	std::list<int>::iterator ordered_end = orderedInts.end();
	std::list<int>::iterator list_begin = listOfInts.begin();
	std::list<int>::iterator list_end = listOfInts.end();

	ft::list<int> list1(ordered_begin, ordered_end);
	ft::list<int> list2(list_begin, list_end);
	ft::list<int> list3(list2);
	ft::list<int> list4(list2);
	list4.push_back(42);

	std::cout << "---------------------\n\n";
	std::cout << "COMPARAISON OPERATORS\n";

	std::cout << "test operator==\n";
	std::cout << "list1 == list2 -> " << (list1 == list2) << "\n";
	std::cout << "list2 == list1 -> " << (list2 == list1) << "\n";
	std::cout << "list2 == list3 -> " << (list2 == list3) << "\n";
	std::cout << "list3 == list4 -> " << (list3 == list4) << "\n";
	std::cout << "list4 == list3 -> " << (list4 == list3) << "\n";

	std::cout << "\ntest operator!=\n";
	std::cout << "list1 != list2 -> " << (list1 != list2) << "\n";
	std::cout << "list2 != list1 -> " << (list2 != list1) << "\n";
	std::cout << "list2 != list3 -> " << (list2 != list3) << "\n";
	std::cout << "list3 != list4 -> " << (list3 != list4) << "\n";
	std::cout << "list4 != list3 -> " << (list4 != list3) << "\n";

	std::cout << "\ntest operator <\n";
	std::cout << "list1 < list2 -> " << (list1 < list2) << "\n";
	std::cout << "list2 < list1 -> " << (list2 < list1) << "\n";
	std::cout << "list2 < list3 -> " << (list2 < list3) << "\n";
	std::cout << "list3 < list4 -> " << (list3 < list4) << "\n";
	std::cout << "list4 < list3 -> " << (list4 < list3) << "\n";

	std::cout << "\ntest operator <=\n";
	std::cout << "list1 <= list2 -> " << (list1 <= list2) << "\n";
	std::cout << "list2 <= list1 -> " << (list2 <= list1) << "\n";
	std::cout << "list2 <= list3 -> " << (list2 <= list3) << "\n";
	std::cout << "list3 <= list4 -> " << (list3 <= list4) << "\n";
	std::cout << "list4 <= list3 -> " << (list4 <= list3) << "\n";

	std::cout << "\ntest operator >\n";
	std::cout << "list1 > list2 -> " << (list1 > list2) << "\n";
	std::cout << "list2 > list1 -> " << (list2 > list1) << "\n";
	std::cout << "list2 > list3 -> " << (list2 > list3) << "\n";
	std::cout << "list3 > list4 -> " << (list3 > list4) << "\n";
	std::cout << "list4 > list3 -> " << (list4 > list3) << "\n";

	std::cout << "\ntest operator >=\n";
	std::cout << "list1 >= list2 -> " << (list1 >= list2) << "\n";
	std::cout << "list2 >= list1 -> " << (list2 >= list1) << "\n";
	std::cout << "list2 >= list3 -> " << (list2 >= list3) << "\n";
	std::cout << "list3 >= list4 -> " << (list3 >= list4) << "\n";
	std::cout << "list4 >= list3 -> " << (list4 >= list3) << "\n";
	std::cout << "\n";
	return (0);
}
