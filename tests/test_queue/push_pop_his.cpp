#include "../../queue.hpp"
#include "../../list.hpp"
#include <queue>
#include <list>
#include <iostream>
#include <string>

template <class Stack>
void	print_queue_infos(Stack &queue)
{
	std::cout << queue.empty() << " = empty()\n";
	std::cout << queue.size() << " = size()\n";
	if (queue.size())
	{
		std::cout << queue.front() << " = front()\n";
		std::cout << queue.back() << " = back()\n";
	}
}

int		main(void)
{
	std::list<std::string> listOfStr({"salut", "je", "suis", "mayeul", "hihi"});
	std::list<int> orderedInts({1, 2, 3, 5});
	std::list<int>::iterator ordered_begin = orderedInts.begin();
	std::list<int>::iterator ordered_end = orderedInts.end();
	std::list<std::string>::iterator list_begin = listOfStr.begin();
	std::list<std::string>::iterator list_end = listOfStr.end();

	std::list<int> list1(ordered_begin, ordered_end);
	std::list<std::string> list2(list_begin, list_end);
	
	// actual queue constructors xd

	std::cout << "---------------------\n\n";
	std::cout << "PUSH / POP\n\n";

	std::cout << "\n push / pop \n\n";

	std::queue<std::string, std::list<std::string> >	queue1(list2);
	std::queue<int, std::list<int> >					queue3(list1);

	print_queue_infos(queue1);
	print_queue_infos(queue3);
	queue3.push(42);
	queue1.pop();
	print_queue_infos(queue1);
	print_queue_infos(queue3);
	queue3.push(663);
	queue3.pop();
	queue1.push(":))");
	print_queue_infos(queue1);
	print_queue_infos(queue3);
	queue1.pop();
	queue3.push(-4);
	print_queue_infos(queue1);
	print_queue_infos(queue3);

	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	queue3.push(42);
	print_queue_infos(queue3);
	return (0);
}
