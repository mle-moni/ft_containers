#ifndef LIST_H
#define LIST_H

#include "shared_functions.hpp"
#include "list_iterator.hpp"

namespace ft
{
	template <typename T>
	class list {
		template<typename> friend class _list_iterator;
		public:
			// Tpypes:
			typedef T					value_type;
			typedef value_type			&reference;
			typedef const value_type	&const_reference;
			typedef value_type			*pointer;
			typedef const value_type	*const_pointer;
			typedef std::ptrdiff_t		difference_type;
			typedef size_t				size_type;
			// Iterator types
			typedef _list_iterator<T>					iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef _list_iterator<T>							const_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			struct Elem {
				value_type	data;
				Elem		*next;
				Elem		*prev;
				bool		is_last;
				Elem(): next(nullptr), prev(nullptr), is_last(false) {}
			};
			size_type		_length;
			Elem			*_first;
			Elem			*_last;
			
			void			_create_last_elem(void)
			{
				Elem	*last_elem = new Elem();
				last_elem->is_last = true;
				last_elem->data = value_type();
				if (!_first)
					_first = last_elem;
				if (_last)
				{
					last_elem->prev = _last;
					_last->next = last_elem;
				}
				_last = last_elem;
			}
			void			_clear_list(void)
			{
				Elem	*current = _first;
				Elem	*prev = nullptr;
				while (current)
				{
					prev = current;
					current = current->next;
					delete prev;
				}
				_length = 0;
				_first = nullptr;
				_last = nullptr;
			}
			template<typename A>
			void	_swap(A& ref1, A& ref2) {
				A	tmp(ref1);
				ref1 = ref2;
				ref2 = tmp;
			}
			void			_insert_after(Elem *elem, const value_type& val)
			{
				Elem	*new_el = new Elem();
				new_el->data = value_type(val);
				_insert_ptr_after(elem, new_el);
			}
			void			_insert_ptr_after(Elem *elem, Elem *new_el)
			{
				if (empty())
				{
					new_el->prev = nullptr;
					new_el->next = _last;
					_last->prev = new_el;
					_first = new_el;
				}
				else if (elem == _last)
				{
					new_el->next = _last;
					new_el->prev = _last->prev;
					new_el->prev->next = new_el;
					_last->prev = new_el;
				}
				else
				{
					new_el->next = elem->next;
					new_el->prev = elem;
					new_el->prev->next = new_el;
					new_el->next->prev = new_el;
				}
				_length += 1;
			}
			void			_insert_ptr_before(Elem *elem, Elem *new_el)
			{
				if (!elem->prev)
				{
					new_el->prev = nullptr;
					_first->prev = new_el;
					new_el->next = _first;
					_first = new_el;
				}
				else
				{
					new_el->prev = elem->prev;
					new_el->next = elem;
					new_el->prev->next = new_el;
					elem->prev = new_el;
				}
				_length += 1;
			}
			iterator		_unlink(iterator position)
			{
				Elem	*to_del = position.ptr;
				++position;
				if (to_del->prev)
					to_del->prev->next = to_del->next;
				else
				{
					_first = to_del->next;
					_first->prev = nullptr;
				}
				to_del->next->prev = to_del->prev;
				_length -= 1;
				return (position);
			}
			void		_swap_elems(Elem *first, Elem *second)
			{
				Elem	*tmp_next = second->next;
				if (first->next == second)
				{
					second->next = first;
					second->prev = first->prev;
					first->prev = second;
					first->next = tmp_next;

					if (second->prev)
						second->prev->next = second;
					else
						_first = second;
					first->next->prev = first;
					return ;
				}
				Elem	*tmp_prev = second->prev;
				second->next = first->next;
				second->prev = first->prev;
				first->prev = tmp_prev;
				first->next = tmp_next;
				if (second->prev)
					second->prev->next = second;
				else
					_first = second;
				second->next->prev = second;
				first->next->prev = first;
				first->prev->next = first;
			}
		public:
			// Constructors:
			list (): _length(0), _first(nullptr), _last(nullptr)
			{
				_create_last_elem();
			}

			list (size_type n, const value_type& val = value_type()): _length(n)
			{
				Elem	*prev_elem = nullptr;
				for (size_t i = 0; i < n; i++) {
					Elem	*new_el = new Elem();
					new_el->data = value_type(val);
					if (i == 0) {
						_first = new_el;
					} else {
						new_el->prev = prev_elem;
						if (prev_elem)
							prev_elem->next = new_el;
					}
					prev_elem = new_el;
					_last = new_el;
				}
				_create_last_elem();
			}

			template <class InputIterator>
			list (InputIterator first, InputIterator last): _length(0)
			{
				size_type	len = 0;
				Elem		*prev_elem = nullptr;
				while (first != last)
				{
					Elem	*new_el = new Elem();
					new_el->data = value_type(*first);
					if (len == 0) {
						_first = new_el;
					} else {
						new_el->prev = prev_elem;
						if (prev_elem)
							prev_elem->next = new_el;
					}
					prev_elem = new_el;
					_last = new_el;
					len++;
					first++;
				}
				_length = len;
				_create_last_elem();
			}

			list (const list& x): _length(x._length)
			{
				Elem		*current = x._first;
				Elem		*prev_elem = nullptr;
				while (current)
				{
					Elem	*new_el = new Elem();
					new_el->data = value_type(current->data);
					new_el->is_last = current->is_last;
					if (current == x._first) {
						_first = new_el;
					} else {
						new_el->prev = prev_elem;
						if (prev_elem)
							prev_elem->next = new_el;
					}
					prev_elem = new_el;
					_last = new_el;
					current = current->next;
				}
			}

			// Destructor:
			~list()
			{
				_clear_list();
			}

			// Copy operator
			list& operator= (const list& x)
			{
				_clear_list();
				_length = x._length;
				Elem		*current = x._first;
				Elem		*prev_elem = nullptr;
				while (current)
				{
					Elem	*new_el = new Elem();
					new_el->data = value_type(current->data);
					if (current == x._first) {
						_first = new_el;
					} else {
						new_el->prev = prev_elem;
						if (prev_elem)
							prev_elem->next = new_el;
					}
					prev_elem = new_el;
					_last = new_el;
					current = current->next;
				}
				return (*this);
			}

			// Iterators:
			iterator begin()
			{
				return (iterator(_first));
			}
			const_iterator begin() const
			{
				return (const_iterator(_first));
			}
			iterator end()
			{
				return (iterator(_last));
			}
			const_iterator end() const
			{
				return (const_iterator(_last));
			}
			reverse_iterator rbegin()
			{
				return (reverse_iterator(end()));
			}
			const_reverse_iterator rbegin() const
			{
				return (reverse_iterator((const_iterator)end()));
			}
			reverse_iterator rend()
			{
				return (reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const
			{
				return (reverse_iterator((const_iterator)begin()));
			}

			// Capacity:
			bool		empty() const
			{
				return (_first->is_last);
			}
			size_type	size() const
			{
				return (_length);
			}
			size_type	max_size() const
			{
				return (std::numeric_limits<difference_type>::max() / sizeof(Elem));
			}

			// Element access:
			reference		front()
			{
				return (_first->data);
			}
			const_reference	front() const
			{
				return (_first->data);
			}
			reference		back()
			{
				if (_first->is_last == false)
					return (_last->prev->data);
				else
					return (_last->data);
			}
			const_reference	back() const
			{
				if (_first->is_last == false)
					return (_last->prev->data);
				else
					return (_last->data);
			}

			// Modifiers:
			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last)
			{
				_clear_list();
				_length = 0;
				_first = nullptr;
				_last = nullptr;
				_create_last_elem();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}
			void assign (size_type n, const value_type& val)
			{
				_clear_list();
				_length = 0;
				_first = nullptr;
				_last = nullptr;
				_create_last_elem();
				
				size_type i = 0;
				while (i < n)
				{
					push_back(val);
					i++;
				}
			}
			void push_front (const value_type& val)
			{
				Elem	*new_el = new Elem();
				new_el->data = value_type(val);
				_first->prev = new_el;
				new_el->next = _first;
				_first = new_el;
				_length += 1;
			}
			void pop_front()
			{
				if (empty())
					return ;
				Elem	*to_del = _first;
				_first = _first->next;
				_first->prev = nullptr;
				delete to_del;
				_length -= 1;
			}
			void push_back (const value_type& val)
			{
				_insert_after(_last->prev, val);
			}
			void pop_back()
			{
				if (empty())
					return ;
				Elem	*to_del = _last->prev;
				if (_length == 1)
				{
					delete to_del;
					_last->prev = nullptr;
					_first = _last;
					_length -= 1;
					return ;
				}
				_last->prev = to_del->prev;
				to_del->prev->next = _last;
				delete to_del;
				_length -= 1;
			}
			iterator insert (iterator position, const value_type& val)
			{
				if (position == end())
					push_back(val);
				else if (position.ptr->prev == nullptr)
					push_front(val);
				else
					_insert_after(position.ptr->prev, val);
				return (position);
			}
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type	i = 0;
				while (i < n)
				{
					position = insert(position, val);
					i++;
				}
			}
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					position = insert(position, *first);
					first++;
				}
			}
			iterator erase (iterator position)
			{
				Elem	*to_del = position.ptr;
				position = _unlink(position);
				delete to_del;
				return (position);
			}
			iterator erase (iterator first, iterator last)
			{
				while (first != last)
					first = erase(first);
				return (first);
			}
			void swap (list& x)
			{
				_swap(_first, x._first);
				_swap(_last, x._last);
				_swap(_length, x._length);
			}
			void resize (size_type n, value_type val = value_type())
			{
				while (n > _length)
					push_back(val);
				while (n < _length)
					pop_back();
			}
			void clear()
			{
				_clear_list();
				_create_last_elem();
			}

			// Operations:
			void splice (iterator position, list& x)
			{
				iterator	current;
				iterator	end = x.end();
				Elem		*pos_ptr = position.ptr;
				while ((current = x.begin()) != end)
				{
					Elem	*new_el = current.ptr;
					x._unlink(current);
					_insert_ptr_after(pos_ptr, new_el);
					pos_ptr = new_el;
				}
			}
			void splice (iterator position, list& x, iterator i)
			{
				Elem	*new_el = i.ptr;
				x._unlink(i);
				_insert_ptr_after(position.ptr, new_el);
			}
			void splice (iterator position, list& x, iterator first, iterator last)
			{
				iterator	next = first;
				while (next != last)
				{
					first = next;
					++next;
					splice(position, x, first);
				}
			}
			void remove (const value_type& val)
			{
				iterator	first = begin();
				iterator	next = first;
				iterator	it_end = end();
				while (next != it_end)
				{
					first = next;
					++next;
					if (*first == val)
						erase(first);
				}
			}
			template <class Predicate>
  			void remove_if (Predicate pred)
			{
				iterator	first = begin();
				iterator	next = first;
				iterator	it_end = end();
				while (next != it_end)
				{
					first = next;
					++next;
					if (pred(*first))
						erase(first);
				}
			}
			void unique()
			{
				iterator	first = begin();
				iterator	next = first;
				iterator	it_end = end();
				while (next != it_end)
				{
					first = next;
					++next;
					if (next == it_end)
						return ;
					if (*first == *next)
						erase(first);
				}
			}
			template <class BinaryPredicate>
  			void unique (BinaryPredicate binary_pred)
			{
				iterator	first = begin();
				iterator	next = first;
				iterator	it_end = end();
				while (next != it_end)
				{
					first = next;
					++next;
					if (next == it_end)
						return ;
					if (binary_pred(*first, *next))
					{
						erase(next);
						next = first;
					}
				}
			}
			void merge (list& x)
			{
				iterator	current = begin();
				iterator	it_end = end();
				iterator	first_el;
				iterator	x_end = x.end();
				Elem		*el;
				while (1)
				{
					bool stop = false;
					while (!stop)
					{
						first_el = x.begin();
						if (first_el == x_end)
							return ;
						if (*first_el < *current || current == it_end)
						{
							el = first_el.ptr;
							x._unlink(first_el);
							_insert_ptr_before(current.ptr, el);
						}
						else
							stop = true;
					}
					if (current == it_end)
						return ;
					++current;
				}
			}
			template <class Compare>
			void merge (list& x, Compare comp)
			{
				iterator	current = begin();
				iterator	it_end = end();
				iterator	first_el;
				iterator	x_end = x.end();
				Elem		*el;
				while (1)
				{
					bool stop = false;
					while (!stop)
					{
						first_el = x.begin();
						if (first_el == x_end)
							return ;
						if (comp(*first_el, *current) || current == it_end)
						{
							el = first_el.ptr;
							x._unlink(first_el);
							_insert_ptr_before(current.ptr, el);
						}
						else
							stop = true;
					}
					if (current == it_end)
						return ;
					++current;
				}
			}
			void sort()
			{
				bool		changes = false;
				iterator	current = begin();
				iterator	it_end = end();
				iterator	next;
				if (_length < 2)
					return ;
				while (current != it_end)
				{
					next = current;
					++next;
					if (next == it_end)
						break ;
					if (*current > *next)
					{
						_swap_elems(current.ptr, next.ptr);
						changes = true;
					}
					else
						++current;
				}
				if (changes)
					sort();
			}
			template <class Compare>
  			void sort (Compare comp)
			{
				bool		changes = false;
				iterator	current = begin();
				iterator	it_end = end();
				iterator	next;
				if (_length < 2)
					return ;
				while (current != it_end)
				{
					next = current;
					++next;
					if (next == it_end)
						break ;
					if (!comp(*current, *next) && comp(*next, *current))
					{
						_swap_elems(current.ptr, next.ptr);
						changes = true;
					}
					else
						++current;
				}
				if (changes)
					sort();
			}
			void reverse()
			{
				if (_length < 2)
					return ;
				iterator	current = begin();
				iterator	current_end = end();
				--current_end;
				iterator	next = current;
				iterator	next_end = current_end;
				size_type	i = 0;
				size_type	threshold = _length / 2;
				while (i < threshold)
				{
					current = next;
					current_end = next_end;
					++next;
					--next_end;
					_swap_elems(current.ptr, current_end.ptr);
					++i;
				}
			}
	};

	// Non-member function overloads:
	template <class Tp>
	bool operator== (const list<Tp>& lhs, const list<Tp>& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (container_cmp_equal(lhs, rhs));
	}
	template <class Tp>
	bool operator!= (const list<Tp>& lhs, const list<Tp>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class Tp>
	bool operator<  (const list<Tp>& lhs, const list<Tp>& rhs)
	{
		return (container_cmp_less(lhs, rhs));
	}
	template <class Tp>
	bool operator<= (const list<Tp>& lhs, const list<Tp>& rhs)
	{
		return (container_cmp_less_eq(lhs, rhs));
	}
	template <class Tp>
	bool operator>  (const list<Tp>& lhs, const list<Tp>& rhs)
	{
		return (container_cmp_more(lhs, rhs));
	}
	template <class Tp>
	bool operator>= (const list<Tp>& lhs, const list<Tp>& rhs)
	{
		return (container_cmp_more_eq(lhs, rhs));
	}
	template <class Tp>
	void swap (list<Tp>& x, list<Tp>& y)
	{
		x.swap(y);
	}
};

#endif