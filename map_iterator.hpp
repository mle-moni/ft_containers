#ifndef MAP_ITERATOR_H
#define MAP_ITERATOR_H

#include "shared_functions.hpp"
#include "tree.hpp"

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key> >
	class _map_iterator {
		template<class, class, class> friend class map;
		public:
			typedef	Key				key_type;
			typedef	T				mapped_type;
			typedef	ft::pair<const Key, T>	value_type;
			typedef	Compare			key_compare;
			typedef	Compare			value_compare;
			typedef	value_type			&reference;
			typedef const value_type	&const_reference;
			typedef value_type			*pointer;
			typedef const value_type	*const_pointer;
			typedef ptrdiff_t			difference_type;
			typedef	size_t				size_type;
			typedef ft::bidirectional_iterator_tag	iterator_category;
		private:
			typedef	tree_node<Key, T, value_compare>	_node_type;
		public:			
			_map_iterator(): ptr(nullptr) {}
			_map_iterator(const _map_iterator &copy): ptr(copy.ptr) {}
			~_map_iterator() {}

			_map_iterator &operator=(const _map_iterator &other)
			{
				ptr = other.ptr;
				return (*this);
			}

			reference		operator*()
			{
				return (ptr->key_val);
			}
			const_reference	operator*() const
			{
				return (ptr->key_val);
			}
			pointer			operator->()
			{
				return (&(ptr->key_val));
			}
			const pointer	operator->() const
			{
				return (&(ptr->key_val));
			}
			_map_iterator<Key, T, Compare>	&operator++()
			{
				ptr = _node_type::get_next(ptr);
				return (*this);
			}
			_map_iterator<Key, T, Compare>	&operator--()
			{
				ptr = _node_type::get_prev(ptr);
				return (*this);
			}
			_map_iterator<Key, T, Compare>	operator++(int)
			{
				_map_iterator<Key, T, Compare>	tmp(*this);
				ptr = _node_type::get_next(ptr);
				return (tmp);
			}
			_map_iterator<Key, T, Compare>	operator--(int)
			{
				_map_iterator<Key, T, Compare>	tmp(*this);
				ptr = _node_type::get_prev(ptr);
				return (tmp);
			}
			bool operator!=(const _map_iterator<Key, T, Compare> &r) const
			{
				return (ptr != r.ptr);
			}
			bool operator==(const _map_iterator<Key, T, Compare> &r) const
			{
				return (ptr == r.ptr);
			}
		private:
			_map_iterator(_node_type *elem): ptr(elem) {}
			_node_type	*ptr;
	};	
}

#endif