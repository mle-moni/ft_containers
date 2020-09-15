#include "../../queue.hpp"
#include "../../list.hpp"
#include <queue>
#include <list>
#include <iostream>

int		main(void)
{
	std::list<int> listOfInt({4, -11, 12, -552, 2111});
	std::list<int> orderedInts({1, 2, 3, 5});
	std::list<int>::iterator ordered_begin = orderedInts.begin();
	std::list<int>::iterator ordered_end = orderedInts.end();
	std::list<int>::iterator list_begin = listOfInt.begin();
	std::list<int>::iterator list_end = listOfInt.end();

	ft::list<int> list1(ordered_begin, ordered_end);
	ft::list<int> list2(list_begin, list_end);
	
	// actual queue constructors xd

	std::cout << "---------------------\n\n";
	std::cout << "COMP OPERATORS\n\n";

	ft::queue<int, ft::list<int> >	queue1(list1);
	ft::queue<int, ft::list<int> >	queue2(list1);
	ft::queue<int>						queue3(list2);
	ft::queue<int>						queue4;

	queue4.push(42);

	std::cout << "---------------------\n\n";
	std::cout << "COMPARAISON OPERATORS\n";

	std::cout << "test operator==\n";
	std::cout << "queue1 == queue2 -> " << (queue1 == queue2) << "\n";
	std::cout << "queue2 == queue1 -> " << (queue2 == queue1) << "\n";
	std::cout << "queue2 == queue3 -> " << (queue2 == queue3) << "\n";
	std::cout << "queue3 == queue4 -> " << (queue3 == queue4) << "\n";
	std::cout << "queue4 == queue3 -> " << (queue4 == queue3) << "\n";

	std::cout << "\ntest operator!=\n";
	std::cout << "queue1 != queue2 -> " << (queue1 != queue2) << "\n";
	std::cout << "queue2 != queue1 -> " << (queue2 != queue1) << "\n";
	std::cout << "queue2 != queue3 -> " << (queue2 != queue3) << "\n";
	std::cout << "queue3 != queue4 -> " << (queue3 != queue4) << "\n";
	std::cout << "queue4 != queue3 -> " << (queue4 != queue3) << "\n";

	std::cout << "\ntest operator <\n";
	std::cout << "queue1 < queue2 -> " << (queue1 < queue2) << "\n";
	std::cout << "queue2 < queue1 -> " << (queue2 < queue1) << "\n";
	std::cout << "queue2 < queue3 -> " << (queue2 < queue3) << "\n";
	std::cout << "queue3 < queue4 -> " << (queue3 < queue4) << "\n";
	std::cout << "queue4 < queue3 -> " << (queue4 < queue3) << "\n";

	std::cout << "\ntest operator <=\n";
	std::cout << "queue1 <= queue2 -> " << (queue1 <= queue2) << "\n";
	std::cout << "queue2 <= queue1 -> " << (queue2 <= queue1) << "\n";
	std::cout << "queue2 <= queue3 -> " << (queue2 <= queue3) << "\n";
	std::cout << "queue3 <= queue4 -> " << (queue3 <= queue4) << "\n";
	std::cout << "queue4 <= queue3 -> " << (queue4 <= queue3) << "\n";

	std::cout << "\ntest operator >\n";
	std::cout << "queue1 > queue2 -> " << (queue1 > queue2) << "\n";
	std::cout << "queue2 > queue1 -> " << (queue2 > queue1) << "\n";
	std::cout << "queue2 > queue3 -> " << (queue2 > queue3) << "\n";
	std::cout << "queue3 > queue4 -> " << (queue3 > queue4) << "\n";
	std::cout << "queue4 > queue3 -> " << (queue4 > queue3) << "\n";

	std::cout << "\ntest operator >=\n";
	std::cout << "queue1 >= queue2 -> " << (queue1 >= queue2) << "\n";
	std::cout << "queue2 >= queue1 -> " << (queue2 >= queue1) << "\n";
	std::cout << "queue2 >= queue3 -> " << (queue2 >= queue3) << "\n";
	std::cout << "queue3 >= queue4 -> " << (queue3 >= queue4) << "\n";
	std::cout << "queue4 >= queue3 -> " << (queue4 >= queue3) << "\n";
	std::cout << "\n";
	
	return (0);
}
