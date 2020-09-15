#include "../../stack.hpp"
#include "../../vector.hpp"
#include <stack>
#include <vector>
#include <iostream>
#include <string>


template <class Stack>
void	print_stack_infos(Stack &stack)
{
	std::cout << stack.empty() << " = empty()\n";
	std::cout << stack.size() << " = size()\n";
	if (stack.size())
		std::cout << stack.top() << " = top()\n";
}

int		main(void)
{
	std::vector<std::string> vectorOfStr({"salut", "je", "suis", "mayeul", "hihi"});
	std::vector<int> orderedInts({1, 2, 3, 5});
	std::vector<int>::iterator ordered_begin = orderedInts.begin();
	std::vector<int>::iterator ordered_end = orderedInts.end();
	std::vector<std::string>::iterator vector_begin = vectorOfStr.begin();
	std::vector<std::string>::iterator vector_end = vectorOfStr.end();

	std::vector<int> vector1(ordered_begin, ordered_end);
	std::vector<std::string> vector2(vector_begin, vector_end);
	
	// actual stack constructors xd

	std::cout << "---------------------\n\n";
	std::cout << "CONSTRUCTORS / MEMBER METHODS\n\n";

	std::cout << "\n constructors \n\n";

	std::stack<int, std::vector<int> >	stack1(vector1);
	std::stack<int, std::vector<int> >	stack2(vector1);
	std::stack<std::string, std::vector<std::string> >	stack3(vector2);
	std::stack<std::string, std::vector<std::string> >	stack4;

	print_stack_infos(stack1);
	print_stack_infos(stack2);
	print_stack_infos(stack3);
	print_stack_infos(stack4);

	stack4 = stack3;

	print_stack_infos(stack3);
	print_stack_infos(stack4);

	std::cout << "\n member methods (called in print_stack_infos) \n\n";

	int	i = 0;
	while (i < 12)
	{
		stack1.push(i);
		stack2.push(i);
		stack3.push(std::string(std::to_string(i)));
		stack4.push(std::string(std::to_string(i)));
		++i;
	}
	print_stack_infos(stack1);
	print_stack_infos(stack2);
	print_stack_infos(stack3);
	print_stack_infos(stack4);

	return (0);
}
