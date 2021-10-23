#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "../utils/type_traits.hpp"
# include "../utils/iterator/random_access_iterator.hpp"
# include "../utils/iterator/reverse_iterator.hpp"
# include <memory> // std::allocator<T>
# include <stdexcept> // std::out_of_range


namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		/****************************/
		/*		Member types		*/
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
		pointer _arr;
		size_type _size;
		size_type _capacity;
		allocator_type _alloc;
	public:
		/********************************/
		/*		Member functions		*/
		/********************************/

		//	Constuctors
		vector() : _alloc(allocator_type()), _arr(0), _size(0), _capacity(0) {}
		explicit vector(const allocator_type& alloc) : _alloc(alloc), _arr(0), _size(0), _capacity(0) {}

		explicit vector(size_type n, const value_type& value = value_type(),
						const allocator_type& alloc = allocator_type()) : _alloc(alloc), _arr(0), _size(0), _capacity(0) {
			reserve(n);
			for (size_t i = 0; i < n; ++i) {
				_alloc.construct(_arr + i, value);
			}
			this->_size = n;
		}

		template<class InputIt>
		vector(InputIt first, InputIt last,
				const allocator_type& alloc = allocator_type(),
				typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt >::type* = 0) : _alloc(alloc),
																								_arr(0),
																								_size(0),
																								_capacity(0) {
			reserve(std::distance(first, last));
			for (; first != last; ++first) {
				_alloc.construct(_arr + _size, *first);
				++_size;
			}
		}

		//	Copy Constuctors
		vector(const vector& other) : _alloc(other._alloc), _arr(0), _size(0), _capacity(0) {
			reserve(other._capacity);
			for (size_t i = 0; i < other._size; ++i) {
				this->_alloc.construct(this->_arr + i, other._arr[i]);
			}
			this->_size = other._size;
		}

		// Destructors
		virtual ~vector(void) {
			clear();
			if (_capacity) {
				_alloc.deallocate(_arr, _capacity);
			}
		}

		// Assigns
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

		void assign(size_type count, const value_type& value) {
			clear();
			for (size_t i = 0; i < count; ++i) {
				push_back(value);
			}
		}

		template<class inputIt>
		void assign(inputIt first, inputIt last,
					typename ft::enable_if<!ft::is_integral<inputIt>::value, inputIt>::type* = 0) {
			clear();
			for (; first != last; ++first) {
				push_back(*first);
			}
		}
		// Other
		allocator_type get_allocator(void) const {
			return this->_alloc;
		}

		// === Element access ===
		reference at(size_type pos) {
			if (pos >= _size) {
				throw std::out_of_range("Out of range")
			}
			return *(_arr + pos);
		}

		const_reference at(size_type pos) const {
			if (pos >= _size) {
				throw std::out_of_range("Out of range")
			}
			return *(_arr + pos);
		}

		reference operator[](size_type pos) {
			return *(_arr + pos);
		}

		const_reference operator[](size_type pos) const {
			return *(_arr + pos);
		}

		reference front(void) {
			return *_arr;
		}

		const_reference front(void) const {
			return *_arr;
		}

		reference back(void) {
			return *(_arr + (_size - 1));
		}

		const_reference back(void) const {
			return *(_arr + (_size - 1));
		}

		pointer data(void) {
			return _arr;
		}

		const pointer data(void) const {
			return _arr;
		}

		// ==== Iterators ====

		iterator begin(void) {
			return iterator(_arr);
		}

		const_iterator begin(void) const {
			return const_iterator(_arr);
		}

		iterator end(void) {
			return iterator(_arr + _size);
		}

		const_iterator end(void) const {
			return const_iterator(_arr + _size);
		}

		reverse_iterator rbegin(void) {
			if (!_size) {
				return reverse_iterator(_arr);
			}
			return reverse_iterator(_arr + (_size - 1));
		}

		const_reverse_iterator rbegin(void) const {
			if (!_size) {
				return const_reverse_iterator(_arr);
			}
			return const_reverse_iterator(_arr + (_size - 1));
		}

		reverse_iterator rend(void) {
			if (!_size) {
				return reverse_iterator(_arr);
			}
			return reverse_iterator(_arr - 1);
		}

		const_reverse_iterator rend(void) const {
			if (!_size) {
				return const_reverse_iterator(_arr);
			}
			return const_reverse_iterator(_arr - 1);
		}

		// ==== Capacity ====

		bool empty() const {
			return size() == 0;
		}

		size_type size(void) const {
			return this->_size;
		}

		size_type max_size() const {
			return _alloc.max_size();
		}

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

		size_type capacity(void) const {
			return this->_capacity;
		}

		// ==== Modifiers ====

		void clear(void) {
			if (_arr) {
				for (size_t i = 0; i < _size; ++i) {
					_alloc.destroy(_arr + i);
				}
			}
			this->_size = 0;
		}

		iterator insert(iterator pos, const value_type& value) {
			difference_type posInsert = std::distance(this->begin(), pos);
			this->insert(pos, 1, value);
			return iterator(_arr + posInsert);
		}

		void insert(iterator pos, size_type count, const value_type& value) {
			vector tmp(pos, this->end());
			iterator tmpIt(tmp.begin());

			while (this->end() != pos) {
				this->pop_back();
			}
			for (size_t i = count; i > 0; --i) {
				this->push_back(value);
			}
			while (tmpIt != tmp.end()) {
				this->push_back(*tmpIt);
				++tmpIt;
			}
		}

		template<class InputIt>
		void insert(iterator pos, InputIt first, InputIt last,
					typename ft::enable_if< !ft::is_integral< InputIt >::value, InputIt >::type* = 0) {
			vector tmp(pos, this->end());
			iterator tmpIt(tmp.begin());

			while (this->end() != pos) {
				this->pop_back();
			}
			while (first != last) {
				this->push_back(*first);
				++first;
			}
			while (tmpIt != tmp.end()) {
				this->push_back(*tmpIt);
				++tmpIt;
			}
		}

		iterator erase(iteartor pos) {
			vector tmp(pos + 1, this->end());
			iterator tmpIt(tmp.begin());

			while (this->end() != pos) {
				this->pop_back();
			}
			this->pop_back();
			while (tmpIt != tmp.end()) {
				this->push_back(*tmpIt);
				++tmpIt;
			}
			return pos;

		}

		iterator erase(iterator first, iterator last) {
			iterator ret(first);

			while (first != last) {
				this->erase(first);
				++first;
			}
			return ret;
		}

		void push_back(const T& value) {
			if (_capacity == _size) {
				reserve(2 * _size);
			}
			_alloc.construct(_arr + _size, value);
			++_size;
		}
	};
}


#endif