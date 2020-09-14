#include "../../vector.hpp"
#include <vector>
#include <iostream>

int		main(void)
{
	std::vector<int> vectorOfInts({1, 2, 3, 4});
	std::vector<int> orderedInts({1, 2, 3, 5});
	std::vector<int>::iterator ordered_begin = orderedInts.begin();
	std::vector<int>::iterator ordered_end = orderedInts.end();
	std::vector<int>::iterator vector_begin = vectorOfInts.begin();
	std::vector<int>::iterator vector_end = vectorOfInts.end();

	std::vector<int> vector1(ordered_begin, ordered_end);
	std::vector<int> vector2(vector_begin, vector_end);
	std::vector<int> vector3(vector2);
	std::vector<int> vector4(vector2);
	vector4.push_back(42);

	std::cout << "---------------------\n\n";
	std::cout << "COMPARAISON OPERATORS\n";

	std::cout << "test operator==\n";
	std::cout << "vector1 == vector2 -> " << (vector1 == vector2) << "\n";
	std::cout << "vector2 == vector1 -> " << (vector2 == vector1) << "\n";
	std::cout << "vector2 == vector3 -> " << (vector2 == vector3) << "\n";
	std::cout << "vector3 == vector4 -> " << (vector3 == vector4) << "\n";
	std::cout << "vector4 == vector3 -> " << (vector4 == vector3) << "\n";

	std::cout << "\ntest operator!=\n";
	std::cout << "vector1 != vector2 -> " << (vector1 != vector2) << "\n";
	std::cout << "vector2 != vector1 -> " << (vector2 != vector1) << "\n";
	std::cout << "vector2 != vector3 -> " << (vector2 != vector3) << "\n";
	std::cout << "vector3 != vector4 -> " << (vector3 != vector4) << "\n";
	std::cout << "vector4 != vector3 -> " << (vector4 != vector3) << "\n";

	std::cout << "\ntest operator <\n";
	std::cout << "vector1 < vector2 -> " << (vector1 < vector2) << "\n";
	std::cout << "vector2 < vector1 -> " << (vector2 < vector1) << "\n";
	std::cout << "vector2 < vector3 -> " << (vector2 < vector3) << "\n";
	std::cout << "vector3 < vector4 -> " << (vector3 < vector4) << "\n";
	std::cout << "vector4 < vector3 -> " << (vector4 < vector3) << "\n";

	std::cout << "\ntest operator <=\n";
	std::cout << "vector1 <= vector2 -> " << (vector1 <= vector2) << "\n";
	std::cout << "vector2 <= vector1 -> " << (vector2 <= vector1) << "\n";
	std::cout << "vector2 <= vector3 -> " << (vector2 <= vector3) << "\n";
	std::cout << "vector3 <= vector4 -> " << (vector3 <= vector4) << "\n";
	std::cout << "vector4 <= vector3 -> " << (vector4 <= vector3) << "\n";

	std::cout << "\ntest operator >\n";
	std::cout << "vector1 > vector2 -> " << (vector1 > vector2) << "\n";
	std::cout << "vector2 > vector1 -> " << (vector2 > vector1) << "\n";
	std::cout << "vector2 > vector3 -> " << (vector2 > vector3) << "\n";
	std::cout << "vector3 > vector4 -> " << (vector3 > vector4) << "\n";
	std::cout << "vector4 > vector3 -> " << (vector4 > vector3) << "\n";

	std::cout << "\ntest operator >=\n";
	std::cout << "vector1 >= vector2 -> " << (vector1 >= vector2) << "\n";
	std::cout << "vector2 >= vector1 -> " << (vector2 >= vector1) << "\n";
	std::cout << "vector2 >= vector3 -> " << (vector2 >= vector3) << "\n";
	std::cout << "vector3 >= vector4 -> " << (vector3 >= vector4) << "\n";
	std::cout << "vector4 >= vector3 -> " << (vector4 >= vector3) << "\n";
	std::cout << "\n";
	
	return (0);
}
