#include "../../stack.hpp"
#include "../../vector.hpp"
#include <stack>
#include <vector>
#include <iostream>

int		main(void)
{
	std::vector<int> vectorOfInt({4, -11, 12, -552, 2111});
	std::vector<int> orderedInts({1, 2, 3, 5});
	std::vector<int>::iterator ordered_begin = orderedInts.begin();
	std::vector<int>::iterator ordered_end = orderedInts.end();
	std::vector<int>::iterator vector_begin = vectorOfInt.begin();
	std::vector<int>::iterator vector_end = vectorOfInt.end();

	std::vector<int> vector1(ordered_begin, ordered_end);
	std::vector<int> vector2(vector_begin, vector_end);
	
	// actual stack constructors xd

	std::cout << "---------------------\n\n";
	std::cout << "CONSTRUCTORS / MEMBER METHODS\n\n";

	std::cout << "\n constructors \n\n";

	std::stack<int, std::vector<int> >	stack1(vector1);
	std::stack<int, std::vector<int> >	stack2(vector1);
	std::stack<int, std::vector<int> >	stack3(vector2);
	std::stack<int, std::vector<int> >	stack4;

	stack4.push(42);

	std::cout << "---------------------\n\n";
	std::cout << "COMPARAISON OPERATORS\n";

	std::cout << "test operator==\n";
	std::cout << "stack1 == stack2 -> " << (stack1 == stack2) << "\n";
	std::cout << "stack2 == stack1 -> " << (stack2 == stack1) << "\n";
	std::cout << "stack2 == stack3 -> " << (stack2 == stack3) << "\n";
	std::cout << "stack3 == stack4 -> " << (stack3 == stack4) << "\n";
	std::cout << "stack4 == stack3 -> " << (stack4 == stack3) << "\n";

	std::cout << "\ntest operator!=\n";
	std::cout << "stack1 != stack2 -> " << (stack1 != stack2) << "\n";
	std::cout << "stack2 != stack1 -> " << (stack2 != stack1) << "\n";
	std::cout << "stack2 != stack3 -> " << (stack2 != stack3) << "\n";
	std::cout << "stack3 != stack4 -> " << (stack3 != stack4) << "\n";
	std::cout << "stack4 != stack3 -> " << (stack4 != stack3) << "\n";

	std::cout << "\ntest operator <\n";
	std::cout << "stack1 < stack2 -> " << (stack1 < stack2) << "\n";
	std::cout << "stack2 < stack1 -> " << (stack2 < stack1) << "\n";
	std::cout << "stack2 < stack3 -> " << (stack2 < stack3) << "\n";
	std::cout << "stack3 < stack4 -> " << (stack3 < stack4) << "\n";
	std::cout << "stack4 < stack3 -> " << (stack4 < stack3) << "\n";

	std::cout << "\ntest operator <=\n";
	std::cout << "stack1 <= stack2 -> " << (stack1 <= stack2) << "\n";
	std::cout << "stack2 <= stack1 -> " << (stack2 <= stack1) << "\n";
	std::cout << "stack2 <= stack3 -> " << (stack2 <= stack3) << "\n";
	std::cout << "stack3 <= stack4 -> " << (stack3 <= stack4) << "\n";
	std::cout << "stack4 <= stack3 -> " << (stack4 <= stack3) << "\n";

	std::cout << "\ntest operator >\n";
	std::cout << "stack1 > stack2 -> " << (stack1 > stack2) << "\n";
	std::cout << "stack2 > stack1 -> " << (stack2 > stack1) << "\n";
	std::cout << "stack2 > stack3 -> " << (stack2 > stack3) << "\n";
	std::cout << "stack3 > stack4 -> " << (stack3 > stack4) << "\n";
	std::cout << "stack4 > stack3 -> " << (stack4 > stack3) << "\n";

	std::cout << "\ntest operator >=\n";
	std::cout << "stack1 >= stack2 -> " << (stack1 >= stack2) << "\n";
	std::cout << "stack2 >= stack1 -> " << (stack2 >= stack1) << "\n";
	std::cout << "stack2 >= stack3 -> " << (stack2 >= stack3) << "\n";
	std::cout << "stack3 >= stack4 -> " << (stack3 >= stack4) << "\n";
	std::cout << "stack4 >= stack3 -> " << (stack4 >= stack3) << "\n";
	std::cout << "\n";
	
	return (0);
}
