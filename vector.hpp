#ifndef VECTOR_H
#define VECTOR_H

#include "shared_functions.hpp"
#include <cstring>
#include "vector_iterator.hpp"

namespace ft
{
	template <typename T>
	class vector {
		public:
			typedef T					value_type;
			typedef value_type			&reference;
			typedef const value_type	&const_reference;
			typedef value_type			*pointer;
			typedef const value_type	*const_pointer;
			typedef std::ptrdiff_t		difference_type;
			typedef size_t				size_type;
			// Iterator types
			typedef _vector_iterator<T>				iterator;
			typedef ft::reverse_iterator<iterator>	reverse_iterator;
			typedef _vector_iterator<T>						const_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		private:
			value_type		*_arr;
			size_type		_length;
			size_type		_capacity;

			template<typename A>
			void	_swap(A& ref1, A& ref2) {
				A	tmp(ref1);
				ref1 = ref2;
				ref2 = tmp;
			}
			void	_move_elems(size_type dest, size_type src, size_type len)
			{
				size_type	dest_index;
				size_type	src_index = 0;
				if (src < dest)
				{
					dest_index = dest + len - 1;
					while (src_index < len)
					{
						_arr[dest_index] = _arr[src + (len - 1) - src_index];
						--dest_index;
						++src_index;
					}
				}
				else
				{
					dest_index = dest;
					while (src_index < len)
					{
						_arr[dest_index] = _arr[src_index + src];
						++dest_index;
						++src_index;
					}
				}
			}
		public:
			// constructors
			vector (): _arr(nullptr), _length(0), _capacity(0) {}
			vector (size_type n, const value_type& val = value_type()): _arr(nullptr), _length(0), _capacity(0)
			{
				_length = n;
				_capacity = n;
				_arr = new value_type[n];
				for (size_type i = 0; i < n; i++) {
					_arr[i] = value_type(val);
				}
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last): _arr(nullptr)
			{
				size_type		size_of_vector = 0;
				size_type		index = 0;
				InputIterator	tmp = first;
				while (tmp != last)
				{
					++size_of_vector;
					++tmp;
				}
				_length = size_of_vector;
				_capacity = size_of_vector;
				_arr = new value_type[size_of_vector];
				while (first != last) {
					_arr[index] = value_type(*first);
					++index;
					++first;
				}
			}
			vector (const vector& x): _arr(nullptr), _length(x._length), _capacity(x._capacity)
			{
				_arr = new value_type[_capacity];
				for (size_type i = 0; i < x._length; i++) {
					_arr[i] = value_type(x._arr[i]);
				}
			}

			// destructor
			~vector()
			{
				clear();
				if (_arr)
					delete [] _arr;
			}

			// operator=
			vector& operator= (const vector& x)
			{
				clear();
				reserve(x._capacity);
				_length = x._length;
				for (size_type i = 0; i < x._length; i++) {
					_arr[i] = value_type(x._arr[i]);
				}
				return (*this);
			}

			// iterators
			iterator begin()
			{
				return (iterator(this, 0));
			}
			const_iterator begin() const
			{
				return (const_iterator(this, 0));
			}
			iterator end()
			{
				return (iterator(this, _length));
			}
			const_iterator end() const
			{
				return (iterator(this, _length));
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
				return (const_reverse_iterator(begin()));
			}
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(begin()));
			}

			// capacity
			size_type size() const
			{
				return (_length);
			}
			size_type max_size() const
			{
				return (std::numeric_limits<difference_type>::max() / sizeof(value_type));
			}
			void resize (size_type n, value_type val = value_type())
			{
				if (n > _length)
				{
					reserve(n);
					size_type	i = _length;
					while (i < n)
					{
						_arr[i] = value_type(val);
						++i;
					}
				}
				else
				{
					size_type	i = _length - 1;
					while (i >= n)
					{
						_arr[i].value_type::~value_type();
						if (i == n)
							break ; // prevent overflow
						--i;
					}
				}
				_length = n;
			}
			size_type capacity() const
			{
				return (_capacity);
			}
			bool empty() const
			{
				return (_length == 0);
			}
			void reserve (size_type n)
			{
				value_type	*old_arr = nullptr;
				if (n <= _capacity || n == 0)
					return ;
				old_arr = _arr;
				if (_capacity && n == _capacity + 1)
					n = _capacity * 2;
				_arr = new value_type[n];
				_capacity = n;
				for (size_type i = 0; i < _length; i++) {
					_arr[i] = value_type(old_arr[i]);
				}
				delete [] old_arr;
				old_arr = nullptr;
			}

			// Element access
			reference operator[] (size_type n)
			{
				return (_arr[n]);
			}
			const_reference operator[] (size_type n) const
			{
				return (_arr[n]);
			}
			reference at (size_type n)
			{
				if (n >= _length)
					throw std::out_of_range("index is out of bounds");
				return ((*this)[n]);
			}
			const_reference at (size_type n) const
			{
				if (n >= _length)
					throw std::out_of_range("index is out of bounds");
				return ((*this)[n]);
			}
			reference front()
			{
				return ((*this)[0]);
			}
			const_reference front() const
			{
				return ((*this)[0]);
			}
			reference back()
			{
				return ((*this)[_length - 1]);
			}
			const_reference back() const
			{
				return ((*this)[_length - 1]);
			}

			// modifiers

			template <class InputIterator>
  			void assign (InputIterator first, InputIterator last)
			{
				clear();
				size_type		size_of_vector = 0;
				size_type		index = 0;
				InputIterator	tmp = first;
				while (tmp != last)
				{
					++size_of_vector;
					++tmp;
				}
				reserve(size_of_vector);
				_length = size_of_vector;
				while (first != last) {
					_arr[index] = value_type(*first);
					++index;
					++first;
				}
			}
			void assign (size_type n, const value_type& val)
			{
				clear();
				reserve(n);
				_length = n;
				for (size_type i = 0; i < n; i++) {
					_arr[i] = value_type(val);
				}
			}
			void push_back (const value_type& val)
			{
				reserve(_length + 1);
				_arr[_length] = value_type(val);
				++_length;
			}
			void pop_back()
			{
				--_length;
				_arr[_length].value_type::~value_type();
			}
			iterator insert (iterator position, const value_type& val)
			{
				reserve(_length + 1);
				size_type	number_of_elems = _length - position._index;
				if (number_of_elems)
					_move_elems(position._index + 1, position._index, number_of_elems);
				_arr[position._index] = value_type(val);
				++_length;
				return (position);
			}
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type	i = 0;
				while (i < n)
				{
					position = insert(position, val);
					++i;
				}
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				iterator	new_pos = position;
				while (first != last)
				{
					const	value_type& val = *first;
					position = insert(position, val);
					++position;
					++first;
				}
			}
			iterator erase (iterator position)
			{
				if (empty())
					return (position);
				_arr[position._index].value_type::~value_type();
				size_type	number_of_elems = _length - (position._index + 1);
				if (number_of_elems)
					_move_elems(position._index, position._index + 1, number_of_elems);
				--_length;
				return (position);
			}
			iterator erase (iterator first, iterator last)
			{
				if (empty())
					return (last);
				size_type	number_to_del = last._index - first._index;
				size_type	elems_to_move = _length - last._index;
				for (size_type i = first._index; i < last._index; i++) {
					_arr[i].value_type::~value_type();
				}
				if (elems_to_move)
					_move_elems(first._index, last._index, elems_to_move);
				_length -= number_to_del;
				return (first);
			}
			void swap (vector& x)
			{
				_swap(_arr, x._arr);
				_swap(_capacity, x._capacity);
				_swap(_length, x._length);
			}
			void	clear()
			{
				size_type	i = 0;
				while (i < _length)
				{
					_arr[i].value_type::~value_type();
					++i;
				}
				_length = 0;
			}

	};
	
	// Non-member function overloads
	template <class T>
  	bool operator== (const vector<T>& lhs, const vector<T>& rhs)
	{
		ft::vector<T>	cpy_l(lhs);
		ft::vector<T>	cpy_r(rhs);
		if (lhs.size() != rhs.size())
			return (false);
		return (container_cmp_equal(cpy_l, cpy_r));
	}
	template <class T>
	bool operator!= (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T>
	bool operator<  (const vector<T>& lhs, const vector<T>& rhs)
	{
		ft::vector<T>	cpy_l(lhs);
		ft::vector<T>	cpy_r(rhs);
		return (container_cmp_less(cpy_l, cpy_r));
	}
	template <class T>
	bool operator<= (const vector<T>& lhs, const vector<T>& rhs)
	{
		ft::vector<T>	cpy_l(lhs);
		ft::vector<T>	cpy_r(rhs);
		return (container_cmp_less_eq(cpy_l, cpy_r));
	}
	template <class T>
	bool operator>  (const vector<T>& lhs, const vector<T>& rhs)
	{
		ft::vector<T>	cpy_l(lhs);
		ft::vector<T>	cpy_r(rhs);
		return (container_cmp_more(cpy_l, cpy_r));
	}
	template <class T>
	bool operator>= (const vector<T>& lhs, const vector<T>& rhs)
	{
		ft::vector<T>	cpy_l(lhs);
		ft::vector<T>	cpy_r(rhs);
		return (container_cmp_more_eq(cpy_l, cpy_r));
	}
	template <class T>
	void swap (vector<T>& x, vector<T>& y)
	{
		x.swap(y);
	}
}

#endif