#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include <cstddef> // ptrdiff_t
# include <iterator> //std::random_access_iterator_tag

namespace ft
{
	template<class T>
	class random_access_iterator {
	public:
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef value_type*							pointer;
		typedef const value_type*					const_pointer;
		typedef value_type&							reference;
		typedef const value_type&					const_reference;
		typedef std::random_access_iterator_tag		iterator_category;

	private:
		pointer _ptr;
	public:
		/********************************/
		/*		Member functions		*/
		/********************************/

		//	Constuctors
		random_access_iterator() : _ptr(0) {}

		explicit random_access_iterator(pointer ptr) : _ptr(ptr) {}

		//	Copy Constuctors
		random_access_iterator(const random_access_iterator& other) : _ptr(other._ptr) {}

		// Destructor
		virtual ~random_access_iterator() {}

		// Assign
		random_access_iterator& operator=(const random_access_iterator& other) {
			if (this == &other) {
				return *this;
			}
			this->_ptr = other._ptr;
			return *this;
		}

		operator random_access_iterator<const value_type>() const {
			return random_access_iterator<const value_type>(_ptr);
		}

		// === Element access ===
		random_access_iterator base() const {
			return _ptr;
		}

		reference operator*() {
			return *_ptr;
		}

		const_reference operator*() const {
			return *_ptr;
		}

		pointer operator->() {
			return _ptr;
		}

		const_pointer operator->() const {
			return _ptr;
		}

		reference operator[](difference_type n) {
			return *(_ptr + n);
		}

		const_reference operator[](difference_type n) const {
			return *(_ptr + n);
		}

		// === Increments and Decrements ===
		// Prefix increment
		random_access_iterator& operator++() {
			++_ptr;
			return *this;
		}

		// Prefix decrement
		random_access_iterator& operator--() {
			--_ptr;
			return *this;
		}

		// Postfix increment
		random_access_iterator operator++(int) {
			random_access_iterator copy = *this;
			++_ptr;
			return copy;
		}

		// Postfix decrement
		random_access_iterator operator--(int) {
			random_access_iterator copy = *this;
			--_ptr;
			return copy;
		}

		random_access_iterator& operator+=(difference_type n) {
			_ptr += n;
			return *this;
		}

		random_access_iterator& operator-=(difference_type n) {
			_ptr -= n;
			return *this;
		}

		random_access_iterator operator+(difference_type n) const {
			return random_access_iterator<T>(_ptr + n);
		}

		random_access_iterator operator-(difference_type n) const {
			return random_access_iterator<T>(_ptr - n);
		}

		difference_type operator+(const random_access_iterator& other) const {
			return _ptr + other._ptr;
		}

		difference_type operator-(const random_access_iterator& other) const {
			return _ptr - other._ptr;
		}

		// === Compares ===
		bool operator==(const random_access_iterator& other) const {
			return _ptr == other._ptr;
		}

		bool operator!=(const random_access_iterator& other) const {
			return _ptr != other._ptr;
		}

		bool operator<(const random_access_iterator& other) const {
			return _ptr < other._ptr;
		}

		bool operator<=(const random_access_iterator& other) const {
			return _ptr <= other._ptr;
		}

		bool operator>(const random_access_iterator& other) const {
			return _ptr > other._ptr;
		}

		bool operator>=(const random_access_iterator& other) const {
			return _ptr >= other._ptr;
		}

		pointer& get_poiner(void) {
			return _ptr;
		}
	};
	/********************************/
	/*		Non-member functions	*/
	/********************************/

	template<class T, class U>
	bool operator==(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.get_poiner() == rhs.get_poiner();
	}

	template<class T, class U>
	bool operator!=(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.get_poiner() != rhs.get_poiner();
	}

	template<class T, class U>
	bool operator<(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.get_poiner() < rhs.get_poiner();
	}

	template<class T, class U>
	bool operator<=(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.get_poiner() <= rhs.get_poiner();
	}

	template<class T, class U>
	bool operator>(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.get_poiner() > rhs.get_poiner();
	}

	template<class T, class U>
	bool operator>=(random_access_iterator<T>& lhs, random_access_iterator<U>& rhs) {
		return lhs.get_poiner() >= rhs.get_poiner();
	}

	template<class T>
	random_access_iterator<T> operator+(typename ft::random_access_iterator<T>::difference_type n,
															const random_access_iterator<T>& other) {
		return n + other;
	}
}

#endif