#include "shared_functions.hpp"

namespace ft
{
	template <typename T>
	class list;

	template <typename T>
	class _list_iterator {
		template<typename> friend class list;
		private:
			typedef typename list<T>::Elem			Elem;
		public:
			typedef T								value_type;
			typedef T								&reference;
			typedef const T							&const_reference;
			typedef T								*pointer;
			typedef const T							*const_pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;
			
			_list_iterator(): ptr(nullptr) {}
			_list_iterator(const _list_iterator<T> &copy): ptr(copy.ptr) {}
			~_list_iterator() {}

			_list_iterator<T> &operator=(const _list_iterator<T> &other)
			{
				ptr = other.ptr;
				return (*this);
			}

			reference		operator*()
			{
				return (ptr->data);
			}
			const_reference	operator*() const
			{
				return (ptr->data);
			}
			pointer			operator->()
			{
				return (&(ptr->data));
			}
			const pointer	operator->() const
			{
				return (&(ptr->data));
			}
			_list_iterator<T>	&operator++()
			{
				ptr = ptr->next;
				return (*this);
			}
			_list_iterator<T>	&operator--()
			{
				ptr = ptr->prev;
				return (*this);
			}
			_list_iterator<T>	operator++(int)
			{
				_list_iterator<T>	tmp(*this);
				ptr = ptr->next;
				return (tmp);
			}
			_list_iterator<T>	operator--(int)
			{
				_list_iterator<T>	tmp(*this);
				ptr = ptr->prev;
				return (tmp);
			}
			bool operator!=(const _list_iterator<T> &r) const
			{
				return (ptr != r.ptr);
			}
			bool operator==(const _list_iterator<T> &r) const
			{
				return (ptr == r.ptr);
			}
		private:
			_list_iterator(Elem *elem): ptr(elem) {}
			Elem	*ptr;
	};	
}
