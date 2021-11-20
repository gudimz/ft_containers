#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef> // ptrdiff_t
# include <iterator> //std::random_access_iterator_tag

namespace ft
{
	template<class T>
	class random_access_iterator {
	public:

		/****************************/
		/*      Member types        */
		/****************************/

		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef value_type*							pointer;
		typedef const value_type*					const_pointer;
		typedef value_type&							reference;
		typedef const value_type&					const_reference;
		typedef std::random_access_iterator_tag		iterator_category;

	private:

		/********************************/
		/*        Member object         */
		/********************************/

		pointer _ptr;
	public:

		/********************************/
		/*       Member function        */
		/********************************/

		/*
		** Default constructor.
		** The iterator is value-initialized
		*/
		random_access_iterator() : _ptr(0) {}

		/*
		** The iterator is initialized with ptr
		*/
		explicit random_access_iterator(pointer ptr) : _ptr(ptr) {}

		/*
		** Copy constructor
		** The iterator is initialized with that of other
		*/
		random_access_iterator(const random_access_iterator& other) : _ptr(other._ptr) {}

		/*
		** Destructor.
		** Destroy iterator.
		*/
		virtual ~random_access_iterator() {}

		/*
		** Overload operator "=".
		** The iterator is assigned the value
		** of the iterator of other.
		*/
		random_access_iterator& operator=(const random_access_iterator& other) {
			if (this == &other) {
				return *this;
			}
			this->_ptr = other._ptr;
			return *this;
		}

		/*
		** Overload called when an iterator is converted to a const iterator.
		*/
		operator random_access_iterator<const value_type>() const {
			return random_access_iterator<const value_type>(_ptr);
		}

		// === Element access ===

		/*
		** Returns a reference to the element pointed to by the iterator
		*/
		reference operator*() {
			return *_ptr;
		}

		/*
		** Returns a const reference to the element pointed to by the iterator
		*/
		const_reference operator*() const {
			return *_ptr;
		}

		/*
		** Returns a pointer to the element pointed to by the iterator
		*/
		pointer operator->() {
			return _ptr;
		}

		/*
		** Returns a const pointer to the element pointed to by the iterator
		*/
		const_pointer operator->() const {
			return _ptr;
		}

		/*
		** Returns a reference to the element at specified relative location.
		** If such an element does not exist, it causes undefined behavior.
		*/
		const_reference operator[](difference_type n) const {
			return *(_ptr + n);
		}

		/*
		** Setter.
		** Return copy of poiner _ptr.
		*/
		pointer base(void) const {
			return _ptr;
		}

		// === Increments and Decrements ===

		/*
		** Prefix increment.
		** ++iter
		*/
		random_access_iterator& operator++() {
			++_ptr;
			return *this;
		}

		/*
		** Prefix decrement.
		** --iter
		*/
		random_access_iterator& operator--() {
			--_ptr;
			return *this;
		}

		/*
		** Postfix increment.
		** iter++
		*/
		random_access_iterator operator++(int) {
			random_access_iterator copy = *this;
			++_ptr;
			return copy;
		}

		/*
		** Postfix decrement.
		** iter--
		*/
		random_access_iterator operator--(int) {
			random_access_iterator copy = *this;
			--_ptr;
			return copy;
		}

		/*
		** Advances the iterator by n positions respectively.
		*/
		random_access_iterator& operator+=(difference_type n) {
			_ptr += n;
			return *this;
		}

		/*
		** Advances the iterator by -n positions respectively.
		*/
		random_access_iterator& operator-=(difference_type n) {
			_ptr -= n;
			return *this;
		}

		/*
		** Returns an iterator which is advanced by n positions respectively.
		*/
		random_access_iterator operator+(difference_type n) const {
			return random_access_iterator<T>(_ptr + n);
		}

		/*
		** Returns an iterator which is advanced by -n positions respectively.
		*/
		random_access_iterator operator-(difference_type n) const {
			return random_access_iterator<T>(_ptr - n);
		}

		/*
		** Returns the sum between iterators.
		*/
		difference_type operator+(const random_access_iterator& other) const {
			return base() + other.base();
		}

		/*
		** Returns the difference between iterators.
		*/
		difference_type operator-(const random_access_iterator& other) const {
			return base() - other.base();
		}

		// === Compares ===
		bool operator==(const random_access_iterator& other) const {
			return base() == other.base();
		}

		bool operator!=(const random_access_iterator& other) const {
			return base() != other.base();
		}

		bool operator<(const random_access_iterator& other) const {
			return base() < other.base();
		}

		bool operator<=(const random_access_iterator& other) const {
			return base() <= other.base();
		}

		bool operator>(const random_access_iterator& other) const {
			return base() > other.base();
		}

		bool operator>=(const random_access_iterator& other) const {
			return base() >= other.base();
		}
	};

	/********************************/
	/*     Non-member functions     */
	/********************************/

	template<class T, class U>
	bool operator==(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.base() == rhs.base();
	}

	template<class T, class U>
	bool operator!=(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.base() != rhs.base();
	}

	template<class T, class U>
	bool operator<(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.base() < rhs.base();
	}

	template<class T, class U>
	bool operator<=(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.base() <= rhs.base();
	}

	template<class T, class U>
	bool operator>(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.base() > rhs.base();
	}

	template<class T, class U>
	bool operator>=(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.base() >= rhs.base();
	}

	/*
	** Returns the iterator other incremented by n.
	*/
	template<class T>
	random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n,
															const random_access_iterator<T>& other) {
		return n + other;
	}
}

#endif