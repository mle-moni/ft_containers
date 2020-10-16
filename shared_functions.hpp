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

namespace ft
{
	struct input_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template<typename IteratorType>
	class reverse_iterator
	{
		public:
			typedef typename IteratorType::value_type		value_type;
			typedef typename IteratorType::reference			reference;
			typedef typename IteratorType::const_reference	const_reference;
			typedef typename IteratorType::pointer			pointer;
			typedef typename IteratorType::const_pointer		const_pointer;
			typedef typename IteratorType::difference_type	difference_type;
			typedef typename IteratorType::iterator_category	iterator_category;
		private:
			IteratorType	_ite;
		public:
			reverse_iterator(): _ite(IteratorType())
			{}
			reverse_iterator(IteratorType const &iterator): _ite(iterator)
			{}
			reverse_iterator(reverse_iterator const &other): _ite(other._ite)
			{}
			reverse_iterator	&operator=(reverse_iterator const &other)
			{
				_ite = other._ite;
				return (*this);
			}

			reverse_iterator	operator++(int) {
				reverse_iterator	tmp(*this);
				_ite--;
				return (tmp);
			}
			reverse_iterator	&operator++() {
				--_ite;
				return (*this);
			}
			reverse_iterator operator--(int) {
				reverse_iterator	tmp(*this);
				_ite++;
				return (tmp);
			}
			reverse_iterator	&operator--() {
				++_ite;
				return (*this);
			}
			reference operator*()
			{
				IteratorType	tmp(_ite);
				--tmp;
				return (*tmp);
			}
			const_reference operator*() const
			{
				IteratorType	tmp(_ite);
				--tmp;
				return (*tmp);
			}
			reference		operator[](int index_diff)
			{
				return (_ite[index_diff]);
			}
			const_reference	operator[](int index_diff) const
			{
				return (_ite[index_diff]);
			}
			pointer operator->() {
				IteratorType	tmp(_ite);
				--tmp;
				return (&(*tmp));
			}
			const_pointer operator->() const {
				IteratorType	tmp(_ite);
				--tmp;
				return (&(*tmp));
			}

			reverse_iterator	&operator-=(int index_diff)
			{
				_ite -= index_diff;
				return (*this);
			}
			reverse_iterator	&operator+=(int index_diff)
			{
				_ite += index_diff;
				return (*this);
			}

			reverse_iterator	operator-(int index_diff) const
			{
				reverse_iterator	tmp(*this);
				tmp._ite -= index_diff;
				return (tmp);
			}
			reverse_iterator	operator+(int index_diff) const
			{
				reverse_iterator	tmp(*this);
				tmp._ite += index_diff;
				return (tmp);
			}
			difference_type		operator-(reverse_iterator const& other) const
			{
				return (_ite - other._ite);
			}
			
			bool				operator==(const reverse_iterator &other) const
			{
				return (_ite == other._ite);
			}
			bool				operator!=(const reverse_iterator &other) const
			{
				return (_ite != other._ite);
			}
			bool				operator<(const reverse_iterator &other) const
			{
				return (_ite <  other._ite);
			}
			bool				operator>(const reverse_iterator &other) const
			{
				return (_ite >  other._ite);
			}
			bool				operator<=(const reverse_iterator &other) const
			{
				return (_ite <= other._ite);
			}
			bool				operator>=(const reverse_iterator &other) const
			{
				return (_ite >= other._ite);
			}
	};

	template<class T1, class T2>
	struct pair {
		typedef	T1	first_type;
		typedef	T2	second_type;

		first_type	first;
		second_type	second;
		
		pair(): first(), second() {}
		template<class U, class V>
		pair (const pair<U, V> &o): first(o.first), second(o.second) {}
		pair (const first_type &a, const second_type &b): first(a), second(b) {}
		pair	&operator=(const pair &o)
		{
			first = o.first;
			second = o.second;
			return (*this);
		}
	};
	template <class type1, class type2>
	bool operator==(const pair<type1, type2> &lhs, const pair<type1, type2> &rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template <class type1, class type2>
	bool operator!=(const pair<type1, type2> &lhs, const pair<type1, type2> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class type1, class type2>
	bool operator<(const pair<type1, type2> &lhs, const pair<type1, type2> &rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}
	template <class type1, class type2>
	bool operator<=(const pair<type1, type2> &lhs, const pair<type1, type2> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <class type1, class type2>
	bool operator>(const pair<type1, type2> &lhs, const pair<type1, type2> &rhs)
	{
		return (rhs < lhs);
	}
	template <class type1, class type2>
	bool operator>=(const pair<type1, type2> &lhs, const pair<type1, type2> &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class type1, class type2>
	pair<type1, type2> make_pair (type1 x, type2 y)
	{
		return (pair<type1, type2>(x, y));
	}

	template<typename Tp>
	struct less {
		bool operator()(const Tp& x, const Tp& y) const
		{
			return (x < y);
		}
	};
}

#endif