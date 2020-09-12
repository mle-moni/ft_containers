#ifndef SHARED_FUNCTIONS_H
#define SHARED_FUNCTIONS_H

#include <cstddef>
#include <limits>
#include <iostream>
#include <stdexcept>

template <class container>
bool	container_cmp_equal(container &a, container &b)
{
	typename container::iterator	current_a = a.begin();
	typename container::iterator	current_b = b.begin();
	typename container::iterator	end_a = a.end();
	typename container::iterator	end_b = b.end();
	while (current_a != end_a && current_b != end_b)
	{
		if (*current_a != *current_b)
			return (false);
		++current_a;
		++current_b;
	}
	return (current_a == end_a && current_b == end_b);
}

template <class container>
bool	container_cmp_less(container &a, container &b)
{
	typename container::iterator	current_a = a.begin();
	typename container::iterator	current_b = b.begin();
	typename container::iterator	end_a = a.end();
	typename container::iterator	end_b = b.end();
	while (current_a != end_a && current_b != end_b)
	{
		if (*current_a != *current_b)
			return (*current_a < *current_b);
		++current_a;
		++current_b;
	}
	if (current_a == end_a && current_b == end_b)
		return (false);
	if (current_a == end_a)
		return (true);
	return (false);
}

template <class container>
bool	container_cmp_less_eq(container &a, container &b)
{
	typename container::iterator	current_a = a.begin();
	typename container::iterator	current_b = b.begin();
	typename container::iterator	end_a = a.end();
	typename container::iterator	end_b = b.end();
	while (current_a != end_a && current_b != end_b)
	{
		if (*current_a != *current_b)
			return (*current_a <= *current_b);
		++current_a;
		++current_b;
	}
	if (current_a == end_a && current_b == end_b)
		return (true);
	if (current_a == end_a)
		return (true);
	return (false);
}

template <class container>
bool	container_cmp_more(container &a, container &b)
{
	typename container::iterator	current_a = a.begin();
	typename container::iterator	current_b = b.begin();
	typename container::iterator	end_a = a.end();
	typename container::iterator	end_b = b.end();
	while (current_a != end_a && current_b != end_b)
	{
		if (*current_a != *current_b)
			return (*current_a > *current_b);
		++current_a;
		++current_b;
	}
	if (current_a == end_a && current_b == end_b)
		return (false);
	if (current_a == end_a)
		return (false);
	return (true);
}

template <class container>
bool	container_cmp_more_eq(container &a, container &b)
{
	typename container::iterator	current_a = a.begin();
	typename container::iterator	current_b = b.begin();
	typename container::iterator	end_a = a.end();
	typename container::iterator	end_b = b.end();
	while (current_a != end_a && current_b != end_b)
	{
		if (*current_a != *current_b)
			return (*current_a >= *current_b);
		++current_a;
		++current_b;
	}
	if (current_a == end_a && current_b == end_b)
		return (true);
	if (current_a == end_a)
		return (false);
	return (true);
}

// namespace ft
// {
// 	template<typename IteratorType>
// 	class reverse_iterator: public IteratorType
// 	{
// 		public:
// 			typedef IteratorType::value_type		value_type;
// 			typedef IteratorType::reference			reference;
// 			typedef IteratorType::pointer			pointer;
// 			typedef IteratorType::difference_type	difference_type;
// 		public:
// 			reverse_iterator(): IteratorType()
// 			{}
// 			reverse_iterator(reverse_iterator const &other): IteratorType(other)
// 			{}
// 			reverse_iterator(IteratorType const &iterator): IteratorType(iterator)
// 			{}
// 			reverse_iterator	&operator=(reverse_iterator const &other)
// 			{
// 				*this = IteratorType::operator=(other);
// 				return (*this);
// 			}

// 			reverse_iterator	operator++(int) {
// 				reverse_iterator	tmp(*this);
// 				operator++();
// 				return (tmp);
// 			}
// 			IteratorType		&operator++() {
// 				return (this->IteratorType::operator--());
// 			}
// 			reverse_iterator operator--(int) {
// 				reverse_iterator tmp(*this);
// 				operator--();
// 				return (tmp);
// 			}
// 			IteratorType &operator--() {
// 				return (this->IteratorType::operator++());
// 			}

// 			reference operator*()
// 			{
// 				IteratorType	tmp(*this);
// 				--tmp;
// 				return (*tmp);
// 			}
// 			const_reference operator*() const
// 			{
// 				IteratorType tmp(*this);
// 				return (*--tmp);
// 			}
// 			pointer operator->() {
// 				IteratorType tmp(*this);
// 				return (&*--tmp);
// 			}
// 			const_pointer operator->() const {
// 				IteratorType tmp(*this);
// 				return (&*--tmp);
// 			}
// 	};
// }

#endif