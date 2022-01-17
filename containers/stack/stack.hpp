#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack {
	public:

		/****************************/
		/*       Member types       */
		/****************************/

		typedef Container																	container_type;
		typedef typename container_type::value_type											value_type;
		typedef typename container_type::size_type											size_type;
		typedef typename container_type::reference											reference;
		typedef typename container_type::const_reference 									const_reference;
	protected:

		/********************************/
		/*         Member object        */
		/********************************/
		container_type	_c;

	public:

		/********************************/
		/*        Member functions      */
		/********************************/

		/*
		** Constructs new underlying container of the container adaptor from a variety of data sources.
		*/
		explicit stack(const container_type& cont = container_type()) : _c(cont) {}

		/*
		** Copy constructs the underlying container c with the contents of container.
		*/
		stack(const stack& other) : _c(other._c) {}

		/*
		** Destructor.
		** The destructors of the elements are called and the used storage is deallocated.
		** Note, that if the elements are pointers, the pointed-to objects are not destroyed.
		*/
		~stack(void) {}

		/*
		** Copy assignment operator.
		** Replaces the contents of the container adaptor with those of other.
		*/
		stack& operator=(const stack& other) {
			if (this == &other) {
				return *this;
			}
			_c = other._c;
			return *this;
		}
		// === Element access ===

		/*
		** Returns reference to the top element in the stack.
		** This is the most recently pushed element.
		*/
		reference top(void) {
			return _c.back();
		}

		/*
		** Returns const reference to the top element in the stack.
		** This is the most recently pushed element.
		*/
		const_reference top(void) const {
			return _c.back();
		}
		// ==== Capacity ====

		/*
		** Checks if the underlying container has no elements
		*/
		bool empty(void) const {
			return _c.empty();
		}

		/*
		** Returns the number of elements in the underlying container
		*/
		size_type size(void) const {
			return _c.size();
		}
		// ==== Modifiers ====

		/*
		** Pushes the given element value to the top of the stack.
		*/
		void push(const value_type& value) {
			return _c.push_back(value);
		}

		/*
		** Removes the top element from the stack
		*/
		void pop(void) {
			return _c.pop_back();
		}

		template<class U, class Cont>
		friend bool operator==(const ft::stack<U, Cont>& lhs, const ft::stack<U, Cont>& rhs);

		template<class U, class Cont>
		friend bool operator!=(const ft::stack<U, Cont>& lhs, const ft::stack<U, Cont>& rhs);

		template<class U, class Cont>
		friend bool operator<(const ft::stack<U, Cont>& lhs, const ft::stack<U, Cont>& rhs);

		template<class U, class Cont>
		friend bool operator<=(const ft::stack<U, Cont>& lhs, const ft::stack<U, Cont>& rhs);

		template<class U, class Cont>
		friend bool operator>(const ft::stack<U, Cont>& lhs, const ft::stack<U, Cont>& rhs);

		template<class U, class Cont>
		friend bool operator>=(const ft::stack<U, Cont>& lhs, const ft::stack<U, Cont>& rhs);
	};

	/********************************/
	/*     Non-member functions     */
	/********************************/

	template<class T, class Container>
	bool operator==(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
		return lhs._c == rhs._c;
	}

	template<class T, class Container>
	bool operator!=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
		return lhs._c != rhs._c;
	}

	template<class T, class Container>
	bool operator<(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
		return lhs._c < rhs._c;
	}

	template<class T, class Container>
	bool operator<=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
		return lhs._c <= rhs._c;
	}

	template<class T, class Container>
	bool operator>(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
		return lhs._c > rhs._c;
	}

	template<class T, class Container>
	bool operator>=(const ft::stack<T, Container>& lhs, const ft::stack<T, Container>& rhs) {
		return lhs._c >= rhs._c;
	}
}

#endif