#ifndef QUEUE_H
#define QUEUE_H

#include "shared_functions.hpp"
#include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue {
		public:
			typedef	T			value_type;
			typedef	Container	container_type;
			typedef	size_t		size_type;
		protected:
			Container	c;
		public:
			// constructors
			queue(const container_type& ctnr = container_type()): c(ctnr) {}
			queue (const queue& other): c(other.c) {}
			virtual ~queue() {}

			// operator= 
			queue& operator= (const queue& other)
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
			value_type& front()
			{
				return (c.front());
			}
			const value_type& front() const
			{
				return (c.front());
			}
			value_type& back()
			{
				return (c.back());
			}
			const value_type& back() const
			{
				return (c.back());
			}
			void push (const value_type& val)
			{
				c.push_back(val);
			}
			void pop()
			{
				c.pop_front();
			}
			// Non-member (but friend) function overloads
			template <class Tp, class Cntnr>
			friend bool operator== (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs);
			template <class Tp, class Cntnr>
			friend bool operator!= (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs);
			template <class Tp, class Cntnr>
			friend bool operator< (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs);
			template <class Tp, class Cntnr>
			friend bool operator<= (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs);
			template <class Tp, class Cntnr>
			friend bool operator> (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs);
			template <class Tp, class Cntnr>
			friend bool operator>= (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs);
	};

	// Non-member (but friend) function overloads
	template <class Tp, class Cntnr>
	bool operator== (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	template <class Tp, class Cntnr>
	bool operator!= (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs)
	{
		return (lhs.c != rhs.c);
	}
	template <class Tp, class Cntnr>
	bool operator< (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs)
	{
		return (lhs.c < rhs.c);
	}
	template <class Tp, class Cntnr>
	bool operator<= (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs)
	{
		return (lhs.c <= rhs.c);
	}
	template <class Tp, class Cntnr>
	bool operator> (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs)
	{
		return (lhs.c > rhs.c);
	}
	template <class Tp, class Cntnr>
	bool operator>= (const queue<Tp,Cntnr>& lhs, const queue<Tp,Cntnr>& rhs)
	{
		return (lhs.c >= rhs.c);
	}
}

#endif