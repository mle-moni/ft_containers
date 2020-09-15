
#ifndef STACK_H
#define STACK_H

#include "vector.hpp"
#include "shared_functions.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef	T			value_type;
			typedef	Container	container_type;
			typedef	size_t		size_type;
		protected:
			Container		c;
		public:
			// constructors
			stack (const container_type& ctnr = container_type()): c(ctnr) {}
			stack (const stack& other): c(other.c) {}
			virtual ~stack() {}

			// operator=
			stack& operator= (const stack& other)
			{
				c = other.c;
				return (*this);
			}

			// member functions
			bool empty() const
			{
				return (c.empty());
			}
			size_type size() const
			{
				return (c.size());
			}
			value_type& top()
			{
				return (c.back());
			}
			const value_type& top() const
			{
				return (c.back());
			}
			void push (const value_type& val)
			{
				c.push_back(val);
			}
			void pop()
			{
				c.pop_back();
			}

			// Non-member (but friend) function overloads
			template <class Tp, class Cntnr>
			friend bool operator== (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs);
			template <class Tp, class Cntnr>
			friend bool operator!= (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs);
			template <class Tp, class Cntnr>
			friend bool operator< (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs);
			template <class Tp, class Cntnr>
			friend bool operator<= (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs);
			template <class Tp, class Cntnr>
			friend bool operator> (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs);
			template <class Tp, class Cntnr>
			friend bool operator>= (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs);
	};
	// Non-member (but friend) function overloads
	template <class Tp, class Cntnr>
	bool operator== (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	template <class Tp, class Cntnr>
	bool operator!= (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs)
	{
		return (lhs.c != rhs.c);
	}
	template <class Tp, class Cntnr>
	bool operator< (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs)
	{
		return (lhs.c < rhs.c);
	}
	template <class Tp, class Cntnr>
	bool operator<= (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs)
	{
		return (lhs.c <= rhs.c);
	}
	template <class Tp, class Cntnr>
	bool operator> (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs)
	{
		return (lhs.c > rhs.c);
	}
	template <class Tp, class Cntnr>
	bool operator>= (const stack<Tp,Cntnr>& lhs, const stack<Tp,Cntnr>& rhs)
	{
		return (lhs.c >= rhs.c);
	}
}

#endif