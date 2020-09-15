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

	ft::vector<int> vector1(ordered_begin, ordered_end);
	ft::vector<std::string> vector2(vector_begin, vector_end);
	
	// actual stack constructors xd

	std::cout << "---------------------\n\n";
	std::cout << "PUSH / POP\n\n";

	std::cout << "\n push / pop \n\n";

	ft::stack<std::string>				stack1(vector2);
	ft::stack<int, ft::vector<int> >	stack3(vector1);

	print_stack_infos(stack1);
	print_stack_infos(stack3);
	stack3.push(42);
	stack1.pop();
	print_stack_infos(stack1);
	print_stack_infos(stack3);
	stack3.push(663);
	stack3.pop();
	stack1.push(":))");
	print_stack_infos(stack1);
	print_stack_infos(stack3);
	stack1.pop();
	stack3.push(-4);
	print_stack_infos(stack1);
	print_stack_infos(stack3);

	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	stack3.push(42);
	print_stack_infos(stack3);
	return (0);
}
