#ifndef SHARED_FUNCTIONS_H
#define SHARED_FUNCTIONS_H

#include <cstddef>
#include <limits>

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

#endif