#ifndef MAP_H
#define MAP_H

#include "shared_functions.hpp"
#include "tree.hpp"
#include "debug/tree_visualizer.hpp"
#include "map_iterator.hpp"


namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key> >
	class map {
		protected:
			Compare comp;
		public:
			template <class compKey, class compT, class compCompare>
			class value_compare_class
			{
				friend class map;
				protected:
					compCompare comp;
					value_compare_class (compCompare c) : comp(c) {}
					value_compare_class () {}
					value_compare_class (const value_compare_class& other): comp(other.comp) {}
					~value_compare_class() {}
					value_compare_class	&operator=(const value_compare_class& other)
					{
						comp = other.comp;
						return (*this);
					}
				public:
					typedef	ft::pair<const Key, T>	value_type;
					
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return (comp(x.first, y.first));
					}
			};

			typedef	Key			key_type;
			typedef	T			mapped_type;
			typedef	ft::pair<const Key, T>	value_type;
			typedef	Compare		key_compare;
			typedef	value_compare_class<Key, T, Compare>	value_compare;
			typedef	value_type			&reference;
			typedef const value_type	&const_reference;
			typedef value_type			*pointer;
			typedef const value_type	*const_pointer;
			typedef _map_iterator<Key, T, Compare>	iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef _map_iterator<Key, T, Compare>			const_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef ptrdiff_t			difference_type;
			typedef	size_t				size_type;
		private:
			typedef	tree_node<Key, T, Compare>	_node_type;
			_node_type	*_root;
			size_type	_size;
		public:
			// constructors
			map (const key_compare& p_comp = key_compare()) : comp(p_comp), _root(nullptr), _size(0)
			{
				_root  = _node_type::create_last_elem(true);
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& p_comp = key_compare())
			: comp(p_comp), _root(nullptr), _size(0)
			{
				_root  = _node_type::create_last_elem(true);
				while (first != last)
				{
					value_type	new_pair(first->first, first->second);
					_node_type	*new_el = new _node_type(new_pair.first, new_pair.second);
					if (_node_type::insert(_root, new_el) != new_el)
						delete new_el; // there is already a pair with this Key
					else
						++_size;
					_root = _node_type::get_root_node(_root);
					++first;
				}
			}
			~map()
			{
				_node_type::free_tree(_root);
			}
			map (const map& x): comp(x.comp), _root(nullptr), _size(x._size)
			{
				_root = _node_type::deep_copy(x._root);
			}
			map	&operator=(const map& other)
			{
				comp = other.comp;
				_node_type::free_tree(_root);
				_root = _node_type::deep_copy(other._root);
				_size = other._size;
				return (*this);
			}

			// iterators
			iterator		begin()
			{
				return (iterator(_node_type::find_leftmost_node(_root)));
			}
			const_iterator	begin() const
			{
				return (const_iterator(_node_type::find_leftmost_node(_root)));
			}
			iterator end()
			{
				return (iterator(_node_type::find_rightmost_node(_root)));
			}
			const_iterator end() const
			{
				return (const_iterator(_node_type::find_rightmost_node(_root)));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(end()));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			// capacity
			bool empty() const
			{
				return (_size == 0);
			}
			size_type size() const
			{
				return (_size);
			}
			size_type max_size() const
			{
				return (std::numeric_limits<difference_type>::max() / sizeof(_node_type));
			}

			// element acces
			mapped_type& operator[] (const key_type& k)
			{
				_node_type	*new_el = new _node_type(k, mapped_type());
				_node_type	*elem = _node_type::insert(_root, new_el);
				if (elem != new_el)
					delete new_el; // there is already a pair with this Key
				else
				{
					++_size;
					_root = _node_type::get_root_node(_root);
				}
				return (elem->key_val.second);
			}

			// Modifiers
			pair<iterator,bool> insert (const value_type& val)
			{
				bool		insert_succes = false;
				_node_type	*new_el = new _node_type(val.first, val.second);
				_node_type	*elem = _node_type::insert(_root, new_el);
				if (elem != new_el)
					delete new_el; // there is already a pair with this Key
				else
				{
					++_size;
					_root = _node_type::get_root_node(_root);
					insert_succes = true;
				}
				return (pair<iterator, bool>(iterator(elem), insert_succes));
			}
			iterator insert (iterator position, const value_type& val)
			{
				iterator	beg = begin();
				_node_type	*insert_node;
				if (position == end())
					position = begin();
				while (1)
				{
					if (position == beg)
					{
						insert_node = _root;
						break ;
					}
					if (comp((*position).first, val.first))
					{
						insert_node = position.ptr;
						break ;
					}
					--position;
				}
				_node_type	*new_el = new _node_type(val.first, val.second);
				_node_type	*elem = _node_type::insert(insert_node, new_el);
				if (elem != new_el)
					delete new_el; // there is already a pair with this Key
				else
				{
					++_size;
					_root = _node_type::get_root_node(_root);
				}
				return (elem);
			}
			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					value_type	new_pair(*first);
					_node_type	*new_el = new _node_type(new_pair.first, new_pair.second);
					if (_node_type::insert(_root, new_el) != new_el)
						delete new_el; // there is already a pair with this Key
					else
						++_size;
					_root = _node_type::get_root_node(_root);
					++first;
				}
			}
			void erase (iterator position)
			{
				int	removedCount = 0;
				_root = _node_type::remove(position.ptr, &removedCount);
				if (removedCount)
					--_size;
			}
			size_type erase (const key_type& k)
			{
				int	removedCount = 0;
				_root = _node_type::remove(_root, k, &removedCount);
				if (!removedCount)
					return (0);
				--_size;
				return (1);
			}
			void erase (iterator first, iterator last)
			{
				iterator	tmp;
				while (first != last)
				{
					tmp = first;
					++first;
					erase(tmp);
				}
			}
			void swap (map& x)
			{
				size_type	size_tmp = _size;
				_node_type	*root_tmp = _root;
				_root = x._root;
				_size = x._size;
				x._root = root_tmp;
				x._size = size_tmp;
			}
			void clear()
			{
				if (_size == 0)
					return ;
				_size = 0;
				_node_type::free_tree(_root);
				_root = nullptr;
			}

			// Observers
			key_compare key_comp() const
			{
				return (_node_type::comp);
			}

			value_compare value_comp() const
			{
				value_compare	comp_function;
				return (comp_function);
			}

			// Operations
			iterator find (const key_type& k)
			{
				_node_type	*obj_found = _node_type::find(_root, k);
				if (!obj_found)
					return (end());
				return (iterator(obj_found));
			}
			const_iterator find (const key_type& k) const
			{
				return (const_iterator(find(k)));
			}

			size_type count (const key_type& k) const
			{
				_node_type	*obj_found = _node_type::find(_root, k);
				if (!obj_found)
					return (0);
				return (1);
			}

			iterator lower_bound (const key_type& k)
			{
				iterator	current = begin();
				iterator	map_end = end();
				key_compare	comp_function;
				while (current != map_end)
				{
					if ((*current).first == k)
						return (current);
					if (comp_function(k, (*current).first))
						return (current);
					++current;
				}
				return (map_end);
			}
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator	current = begin();
				const_iterator	map_end = end();
				key_compare		comp_function;
				while (current != map_end)
				{
					if ((*current).first == k)
						return (current);
					if (comp_function(k, (*current).first))
						return (current);
					++current;
				}
				return (map_end);
			}

			iterator upper_bound (const key_type& k)
			{
				iterator	current = begin();
				iterator	map_end = end();
				key_compare	comp_function;
				while (current != map_end)
				{
					if (comp_function(k, (*current).first))
						return (current);
					++current;
				}
				return (map_end);
			}
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator	current = begin();
				const_iterator	map_end = end();
				key_compare		comp_function;
				while (current != map_end)
				{
					if (comp_function(k, (*current).first))
						return (current);
					++current;
				}
				return (map_end);
			}

			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				pair<iterator, iterator>	ret;
				ret.first = lower_bound(k);
				ret.second = upper_bound(k);
				return (ret);
			}
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				pair<const_iterator, const_iterator>	ret;
				ret.first = lower_bound(k);
				ret.second = upper_bound(k);
				return (ret);
			}

			// void	print_it(void)
			// {
			// 	showTree(_root, "tree.png");
			// }
	};

	// non member overloads 
	template <class Key, class T, class Compare>
	bool operator== (const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (container_cmp_equal(lhs, rhs));
	}

	template <class Key, class T, class Compare>
	bool operator!= (const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class Key, class T, class Compare>
	bool operator<  (const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
	{
		return (container_cmp_less(lhs, rhs));
	}
	template <class Key, class T, class Compare>
	bool operator<= (const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
	{
		return (container_cmp_less_eq(lhs, rhs));
	}
	template <class Key, class T, class Compare>
	bool operator>  (const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
	{
		return (container_cmp_more(lhs, rhs));
	}
	template <class Key, class T, class Compare>
	bool operator>= (const map<Key,T,Compare>& lhs, const map<Key,T,Compare>& rhs)
	{
		return (container_cmp_more_eq(lhs, rhs));
	}

	template <class Key, class T, class Compare>
	void swap (map<Key,T,Compare>& x, map<Key,T,Compare>& y)
	{
		x.swap(y);
	}
}

#endif