#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../utils/type_traits.hpp"
# include "../utils/iterator/random_access_iterator.hpp"
# include "../utils/iterator/reverse_iterator.hpp"
# include "../utils/equal.hpp"
# include "../utils/lexicographical_compare.hpp"
# include <memory> // std::allocator<T>
# include <stdexcept> // std::out_of_range


namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector {
	public:

		/****************************/
		/*       Member types       */
		/****************************/

		typedef T																		value_type;
		typedef Allocator																allocator_type;

		typedef typename allocator_type::reference										reference;
		typedef typename allocator_type::const_reference								const_reference;
		typedef typename allocator_type::size_type										size_type;
		typedef typename allocator_type::difference_type								difference_type;
		typedef typename allocator_type::pointer										pointer;
		typedef typename allocator_type::const_pointer									const_pointer;

		typedef ft::random_access_iterator<value_type>									iterator;
		typedef ft::random_access_iterator<const value_type>							const_iterator;
		typedef ft::reverse_iterator<iterator>											reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;
	private:

		/********************************/
		/*        Member object         */
		/********************************/

		pointer			_arr;
		size_type 		_size;
		size_type 		_capacity;
		allocator_type	_alloc;
	public:

		/********************************/
		/*       Member functions       */
		/********************************/

		/*
		** Default constructor.
		** Constructor for an empty vector.
		*/
		vector() : _arr(0), _size(0), _capacity(0), _alloc(allocator_type()) {}
		explicit vector(const allocator_type& alloc) : _arr(0), _size(0), _capacity(0), _alloc(alloc) {}

		/*
		** Fill constructor.
		** Vector with n elements. Each element has a value n.
		*/
		explicit vector(size_type n, const value_type& value = value_type(),
						const allocator_type& alloc = allocator_type()) : _arr(0), _size(0), _capacity(0), _alloc(alloc) {
			if (n) {
				reserve(n);
				for (size_t i = 0; i < n; ++i) {
					_alloc.construct(_arr + i, value);
				}
			}
			this->_size = n;
		}

		/*
		** Range constructor.
		** Vector with elements from range first and last.
		** Each element has value from that range.
		*/
		template<class InputIt>
		vector(InputIt first, InputIt last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0) :	_arr(0),
																								_size(0),
																								_capacity(0),
																								_alloc(alloc) {
			reserve(std::distance(first, last));
			for (iterator it = first; it != last; ++it) {
				_alloc.construct(_arr + _size, *it);
				++_size;
			}
		}

		/*
		** Copy constructor.
		** Each element is copied from "other".
		*/
		vector(const vector& other) : _arr(0), _size(0), _capacity(0), _alloc(other._alloc) {
			reserve(other._capacity);
			for (size_t i = 0; i < other._size; ++i) {
				this->_alloc.construct(this->_arr + i, other._arr[i]);
			}
			this->_size = other._size;
		}

		/*
		** Destructor.
		** Destructors of the elements are called and
		** the used storage is deallocated.
		*/
		virtual ~vector(void) {
			clear();
			if (_capacity) {
				_alloc.deallocate(_arr, _capacity);
			}
		}

		/*
		** Copy assignment operator.
		** Replaces the contents with a copy of the contents of other
		*/
		vector& operator=(const vector& other) {
			if (this == &other) {
				return *this;
			}
			this->~vector();
			reserve(other._capacity);
			for (size_t i = 0; i < other._size; ++i) {
				this->_alloc.construct(this->_arr + i, other._arr[i]);
			this->_size = other._size;
			}
			return *this;
		}

		/*
		** Fill assign.
		** Replaces the contents with count copies of value value.
		*/
		void assign(size_type count, const value_type& value) {
			clear();
			for (size_t i = 0; i < count; ++i) {
				push_back(value);
			}
		}

		/*
		** Range assign.
		** Replaces the contents with copies of those in the range [first, last].
		*/
		template<class inputIt>
		void assign(inputIt first, inputIt last,
					typename ft::enable_if<!ft::is_integral<inputIt>::value, inputIt>::type* = 0) {
			clear();
			for (; first != last; ++first) {
				push_back(*first);
			}
		}

		/*
		** Returns the allocator associated with the container.
		*/
		allocator_type get_allocator(void) const {
			return this->_alloc;
		}

		// === Element access ===

		/*
		** Returns a reference to the element at specified location pos, with bounds checking.
		** If pos is not within the range of the container,
		** an exception of type std::out_of_range is thrown.
		*/
		reference at(size_type pos) {
			if (pos >= _size) {
				throw std::out_of_range("Out of range");
			}
			return *(_arr + pos);
		}

		/*
		** Returns a const reference to the element at specified location pos, with bounds checking.
		** If pos is not within the range of the container,
		** an exception of type std::out_of_range is thrown.
		*/
		const_reference at(size_type pos) const {
			if (pos >= _size) {
				throw std::out_of_range("Out of range");
			}
			return *(_arr + pos);
		}

		/*
		** Returns a reference to the element at specified location pos.
		** No bounds checking is performed.
		*/
		reference operator[](size_type pos) {
			return *(_arr + pos);
		}

		/*
		** Returns a const reference to the element at specified location pos.
		** No bounds checking is performed.
		*/
		const_reference operator[](size_type pos) const {
			return *(_arr + pos);
		}

		/*
		** Returns a reference to the first element in the container.
		** Calling front on an empty container is undefined.
		*/
		reference front(void) {
			return *_arr;
		}

		/*
		** Returns a const reference to the first element in the container.
		** Calling front on an empty container is undefined.
		*/
		const_reference front(void) const {
			return *_arr;
		}

		/*
		** Returns a reference to the last element in the container.
		** Calling back on an empty container causes undefined behavior.
		*/
		reference back(void) {
			return *(_arr + (_size - 1));
		}

		/*
		** Returns a const reference to the last element in the container.
		** Calling back on an empty container causes undefined behavior.
		*/
		const_reference back(void) const {
			return *(_arr + (_size - 1));
		}

		/*
		** Returns pointer to the underlying array serving as element storage.
		*/
		pointer data(void) {
			return _arr;
		}

		/*
		** Returns const pointer to the underlying array serving as element storage.
		*/
		const pointer data(void) const {
			return _arr;
		}

		// ==== Iterators ====

		/*
		** Returns an iterator to the first element of the vector.
		** If the vector is empty, the returned iterator will be equal to end().
		*/
		iterator begin(void) {
			return iterator(_arr);
		}

		/*
		** Returns a const iterator to the first element of the vector.
		** If the vector is empty, the returned iterator will be equal to end().
		*/
		const_iterator begin(void) const {
			return const_iterator(_arr);
		}

		/*
		** Returns an iterator to the element following the last element of the vector.
		** This element acts as a placeholder; attempting to access it results in undefined behavior.
		*/
		iterator end(void) {
			return iterator(_arr + _size);
		}

		/*
		** Returns an const iterator to the element following the last element of the vector.
		** This element acts as a placeholder; attempting to access it results in undefined behavior.
		*/
		const_iterator end(void) const {
			return const_iterator(_arr + _size);
		}

		/*
		** Returns a reverse iterator to the first element of the reversed vector.
		** It corresponds to the last element of the non-reversed vector.
		** If the vector is empty, the returned iterator is equal to rend().
		*/
		reverse_iterator rbegin(void) {
			return reverse_iterator(end());
		}

		/*
		** Returns a const reverse iterator to the first element of the reversed vector.
		** It corresponds to the last element of the non-reversed vector.
		** If the vector is empty, the returned iterator is equal to rend().
		*/
		const_reverse_iterator rbegin(void) const {
			return const_reverse_iterator(end());
		}

		/*
		** Returns a reverse iterator to the element following the last element of the reversed vector.
		** It corresponds to the element preceding the first element of the non-reversed vector.
		** This element acts as a placeholder, attempting to access it results in undefined behavior.
		*/
		reverse_iterator rend(void) {
			return reverse_iterator(begin());
		}

		/*
		** Returns a const reverse iterator to the element following the last element of the reversed vector.
		** It corresponds to the element preceding the first element of the non-reversed vector.
		** This element acts as a placeholder, attempting to access it results in undefined behavior.
		*/
		const_reverse_iterator rend(void) const {
			return const_reverse_iterator(begin());
		}

		// ==== Capacity ====

		/*
		** Checks if the container has no elements.
		*/
		bool empty() const {
			return size() == 0;
		}

		/*
		** Returns the number of elements in the container.
		*/
		size_type size(void) const {
			return _size;
		}

		/*
		** Returns the maximum number of elements the container is able to hold due to system or
		** library implementation limitations
		*/
		size_type max_size() const {
			return _alloc.max_size();
		}

		/*
		** Increase the capacity of the vector to a value that's greater or equal to new_cap.
		** If new_cap is greater than the current capacity(), new storage is allocated,
		** otherwise the function does nothing.
		** Reserve does not change the size of the vector.
		*/
		void reserve(size_type n) {
			if (n <= _capacity) return;
			pointer newArr = _alloc.allocate(n);
			for (size_t i = 0; i < _size; ++i) {
				_alloc.construct(newArr + i, _arr[i]);
				_alloc.destroy(_arr + i);
			}
			_alloc.deallocate(_arr, _capacity);
			this->_arr = newArr;
			this->_capacity = n;
		}

		/*
		** Returns the number of elements that the container has currently allocated space for.
		*/
		size_type capacity(void) const {
			return _capacity;
		}

		// ==== Modifiers ====

		/*
		** Erases all elements from the container. After this call, size() returns zero.
		*/
		void clear(void) {
			if (_arr) {
				for (size_t i = 0; i < _size; ++i) {
					_alloc.destroy(_arr + i);
				}
			}
			_size = 0;
		}

		/*
		** Single element.
		** Inserts element in the container before pos.
		*/
		iterator insert(iterator pos, const value_type& value) {
			difference_type posInsert = std::distance(this->begin(), pos);
			this->insert(pos, 1, value);
			return iterator(_arr + posInsert);
		}

		/*
		** Fill
		** inserts count copies of the value before pos
		*/
		void insert(iterator pos, size_type count, const value_type& value) {
			vector tmp(pos, this->end());
			iterator tmp_it(tmp.begin());

			while (this->end() != pos) {
				pop_back();
			}
			for (size_t i = count; i > 0; --i) {
				push_back(value);
			}
			while (tmp_it != tmp.end()) {
				push_back(*tmp_it);
				++tmp_it;
			}
		}

		/*
		** Range
		** inserts elements from range [first, last) before pos.
		*/
		template<class InputIt>
		void insert(iterator pos, InputIt first, InputIt last,
					typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt >::type* = 0) {
			vector tmp(pos, this->end());
			iterator tmp_it(tmp.begin());

			while (this->end() != pos) {
				pop_back();
			}
			while (first != last) {
				push_back(*first);
				++first;
			}
			while (tmp_it != tmp.end()) {
				push_back(*tmp_it);
				++tmp_it;
			}
		}

		/*
		** Single element.
		** Removes the element at pos from the container.
		*/
		iterator erase(iterator pos) {
			vector tmp(pos + 1, this->end());
			iterator tmp_it(tmp.begin());

			for (size_t i = 0; i < tmp.size(); ++i) {
				pop_back();
			}
			pop_back();
			while (tmp_it != tmp.end()) {
				push_back(*tmp_it);
				++tmp_it;
			}
			return pos;

		}

		/*
		** Range.
		** Removes the elements at range from the container.
		*/
		iterator erase(iterator first, iterator last) {
			iterator ret(first);

			while (ret != last) {
				erase(first);
				++ret;
			}
			return first;
		}

		/*
		** Appends the given element value to the end of the container.
		** The new element is initialized as a copy of value.
		*/
		void push_back(const T& value) {
			if (_capacity == _size && _capacity) {
				reserve(2 * _size);
			} else {
				reserve(1);
			}
			_alloc.construct(_arr + _size, value);
			++_size;
		}

		/*
		** Removes the last element of the container.
		** Calling pop_back on an empty container results in undefined behavior.
		*/
		void pop_back() {
			if (!_size) {
				return;
			}
			_alloc.destroy(_arr + (_size - 1));
			--_size;
		}

		/*
		** Resizes the container to contain count elements.
		** If the current size is greater than count, the container is reduced to its first count elements.
		** If the current size is less than count, additional default-inserted elements are appended.
		*/
		void resize(size_type count, value_type value = value_type()) {
			if (count < _size) {
				while (_size > count) {
					pop_back();
				}
			} else if (count > _size) {
				while (_size < count) {
					push_back(value);
				}
			}
		}

		/*
		** Exchanges the contents of the container with those of other.
		** Does not invoke any move, copy, or swap operations on individual elements.
		*/
		void swap(vector& other) {
			pointer tmp_arr = _arr;
			_arr = other._arr;
			other._arr = tmp_arr;

			size_type tmp_size = _size;
			_size = other._size;
			other._size = tmp_size;

			size_type tmp_capacity = _capacity;
			_capacity = other._capacity;
			other._capacity = tmp_capacity;
		}
	};

	/********************************/
	/*      Non-member functions    */
	/********************************/

	template<class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return rhs < lhs;
	}

	template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs) {
		return !(lhs < rhs);
	}

	template<class T, class Alloc>
	void swap(ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs) {
		lhs.swap(rhs);
	}
}


#endif