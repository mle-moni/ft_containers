#include "shared_functions.hpp"

namespace ft
{
	template <typename T>
	class vector;

	template <typename T>
	class _vector_iterator
	{
		template<typename> friend class vector;
		private:
			vector<T>*  _vector;
			size_t      _index;
			_vector_iterator(vector<T> *vector, size_t index): _vector(vector), _index(index) {}
		public:
			typedef T								value_type;
			typedef T								&reference;
			typedef const T							&const_reference;
			typedef T								*pointer;
			typedef const T							*const_pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

			_vector_iterator(): _vector(nullptr), _index(0) {}
			_vector_iterator(const _vector_iterator<T> &copy): _vector(copy._vector), _index(copy._index) {}
			~_vector_iterator() {}

			_vector_iterator<T> &operator=(const _vector_iterator<T> &other)
			{
				_vector = other._vector;
				_index = other._index;
				return (*this);
			}

			_vector_iterator&	operator++()
			{
				++_index;
				return (*this);
			}
			_vector_iterator&	operator--()
			{
				--_index;
				return (*this);
			}
			_vector_iterator	operator++(int)
			{
				_vector_iterator	tmp(*this);
				++_index;
				return (tmp);
			}
			_vector_iterator	operator--(int)
			{
				_vector_iterator	tmp(*this);
				--_index;
				return (tmp);
			}
			reference		operator*()
			{
				return (*_vector)[_index];
			}
			const_reference	operator*() const
			{
				return (*_vector)[_index];
			}
			reference		operator[](int index_diff)
			{
				return (*_vector)[_index + index_diff];
			}
			const_reference	operator[](int index_diff) const
			{
				return (*_vector)[_index + index_diff];
			}
			pointer			operator->()
			{
				return &((*_vector)[_index]);
			}
			const pointer	operator->() const
			{
				return &((*_vector)[_index]);
			}
			
			_vector_iterator	&operator-=(int index_diff)
			{
				_index -= index_diff;
				return (*this);
			}
			_vector_iterator	&operator+=(int index_diff)
			{
				_index += index_diff;
				return (*this);
			}

			_vector_iterator	operator-(int index_diff) const
			{
				_vector_iterator r(*this);
				return r -= index_diff;
			}
			_vector_iterator	operator+(int index_diff) const
			{
				_vector_iterator r(*this);
				return r += index_diff;
			}
			difference_type		operator-(_vector_iterator const& other) const
			{
				return (_index - other._index);
			}

			bool				operator==(const _vector_iterator &other) const
			{
				return (_index == other._index);
			}
			bool				operator!=(const _vector_iterator &other) const
			{
				return (_index != other._index);
			}
			bool				operator<(_vector_iterator const& other) const
			{
				return (_index <  other._index);
			}
			bool				operator>(_vector_iterator const& other) const
			{
				return (_index >  other._index);
			}
			bool				operator<=(_vector_iterator const& other) const
			{
				return (_index <= other._index);
			}
			bool				operator>=(_vector_iterator const& other) const
			{
				return (_index >= other._index);
			}
	};
}


