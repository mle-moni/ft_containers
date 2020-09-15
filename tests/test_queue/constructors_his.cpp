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
	std::cout << "CONSTRUCTORS / MEMBER METHODS\n\n";

	std::cout << "\n constructors \n\n";

	std::queue<int, std::list<int> >	queue1(list1);
	std::queue<int, std::list<int> >	queue2(list1);
	std::queue<std::string, std::list<std::string> >	queue3(list2);
	std::queue<std::string, std::list<std::string> >	queue4;

	print_queue_infos(queue1);
	print_queue_infos(queue2);
	print_queue_infos(queue3);
	print_queue_infos(queue4);

	queue4 = queue3;

	print_queue_infos(queue3);
	print_queue_infos(queue4);

	std::cout << "\n member methods (called in print_queue_infos) \n\n";

	int	i = 0;
	while (i < 12)
	{
		queue1.push(i);
		queue2.push(i);
		queue3.push(std::string(std::to_string(i)));
		queue4.push(std::string(std::to_string(i)));
		++i;
	}
	print_queue_infos(queue1);
	print_queue_infos(queue2);
	print_queue_infos(queue3);
	print_queue_infos(queue4);

	return (0);
}
