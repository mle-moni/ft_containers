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
			typedef std::reverse_iterator<iterator>	reverse_iterator;
			typedef _vector_iterator<T>						const_iterator;
			typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
		private:
			size_type		_length;
			size_type		_capacity;
			value_type		*_arr;

			template<typename A>
			void	_swap(A& ref1, A& ref2) {
				A	tmp(ref1);
				ref1 = ref2;
				ref2 = tmp;
			}
		public:
			// constructors
			vector (): _arr(nullptr), _length(0), _capacity(0) {}
			vector (size_type n, const value_type& val = value_type()): _arr(nullptr), _length(n), _capacity(n)
			{
				_arr = (pointer)::operator new(sizeof(value_type) * n);
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
				_arr = (pointer)::operator new(sizeof(value_type) * size_of_vector);
				while (first != last) {
					_arr[index] = value_type(*first);
					++index;
					++first;
				}
			}
			vector (const vector& x): _arr(nullptr), _length(x._length), _capacity(x._capacity)
			{
				_arr = (pointer)::operator new(sizeof(value_type) * _capacity);
				std::memcpy((void*)(_arr), (void*)(x._arr), x._length * sizeof(value_type));
			}

			// destructor
			~vector()
			{
				clear();
				if (_arr)
					::operator delete(_arr);
			}

			// operator=
			vector& operator= (const vector& x)
			{
				clear();
				if (_arr)
					::operator delete(_arr);
				_arr = nullptr;
				_length = x._length;
				_capacity = x._capacity;
				_arr = (pointer)::operator new(sizeof(value_type) * _capacity);
				std::memcpy((void*)(_arr), (void*)(x._arr), x._length * sizeof(value_type));
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
					size_type	i = _length;
					while (i > n)
					{
						_arr[i].value_type::~value_type();
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
				if (n == _capacity + 1)
					n = _capacity * 2;
				_arr = ::operator new(sizeof(value_type) * n);
				_capacity = n;
				std::memcpy((void*)(_arr), (void*)(old_arr), _length * sizeof(value_type));
				::operator delete(old_arr);
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
				size_type	val_size = sizeof(value_type);
				pointer		pos = _arr + (position._index * val_size);
				size_type	number_of_bytes = (_length - position._index) * val_size;
				if (number_of_bytes)
					std::memmove(pos + val_size, pos, number_of_bytes);
				_arr[position._index - 1] = value_type(val);
				++_length;
				return (iterator(this, position._index - 1));
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
				size_type	val_size = sizeof(value_type);
				pointer		pos = _arr + ((position._index + 1) * val_size);
				size_type	number_of_bytes = (_length - (position._index + 1)) * val_size;
				if (number_of_bytes)
					std::memmove(pos, pos + val_size, number_of_bytes);
				--_length;
				return (position);
			}
			iterator erase (iterator first, iterator last)
			{
				if (empty())
					return (last);
				size_type	val_size = sizeof(value_type);
				size_type	number_to_del = last._index - first._index;

				pointer		pos = _arr + ((first._index + number_to_del) * val_size);
				size_type	number_of_bytes = (_length - (first._index + number_to_del)) * val_size;
				if (number_of_bytes)
					std::memmove(pos - (number_to_del * val_size), pos, number_of_bytes);
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
		if (lhs.size() != rhs.size())
			return (false);
		return (container_cmp_equal(lhs, rhs));
	}
	template <class T>
	bool operator!= (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T>
	bool operator<  (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (container_cmp_less(lhs, rhs));
	}
	template <class T>
	bool operator<= (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (container_cmp_less_eq(lhs, rhs));
	}
	template <class T>
	bool operator>  (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (container_cmp_more(lhs, rhs));
	}
	template <class T>
	bool operator>= (const vector<T>& lhs, const vector<T>& rhs)
	{
		return (container_cmp_more_eq(lhs, rhs));
	}
	template <class T>
	void swap (vector<T>& x, vector<T>& y)
	{
		x.swap(y);
	}
}

#endif