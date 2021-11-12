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
		/********************************/
		/*		Member object			*/
		/********************************/
		pointer			_arr;
		size_type 		_size;
		size_type 		_capacity;
		allocator_type	_alloc;
	public:
		/********************************/
		/*		Member functions		*/
		/********************************/

		/*
		**	Default constructor.
		**	Constructor for an empty vector.
		*/
		vector() : _arr(0), _size(0), _capacity(0), _alloc(allocator_type()) {}
		explicit vector(const allocator_type& alloc) : _arr(0), _size(0), _capacity(0), _alloc(alloc) {}

		/*
		**	Fill constructor.
		**	Vector with n elements. Each element has a value n.
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

		//	Copy Constuctors
		vector(const vector& other) : _arr(0), _size(0), _capacity(0), _alloc(other._alloc) {
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
				throw std::out_of_range("Out of range");
			}
			return *(_arr + pos);
		}

		const_reference at(size_type pos) const {
			if (pos >= _size) {
				throw std::out_of_range("Out of range");
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
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin(void) const {
			return const_reverse_iterator(end());
		}

		reverse_iterator rend(void) {
			return reverse_iterator(begin());
		}

		const_reverse_iterator rend(void) const {
			return const_reverse_iterator(begin());
		}

		// ==== Capacity ====

		bool empty() const {
			return size() == 0;
		}

		size_type size(void) const {
			return _size;
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
			return _capacity;
		}

		// ==== Modifiers ====

		void clear(void) {
			if (_arr) {
				for (size_t i = 0; i < _size; ++i) {
					_alloc.destroy(_arr + i);
				}
			}
			_size = 0;
		}

		iterator insert(iterator pos, const value_type& value) {
			difference_type posInsert = std::distance(this->begin(), pos);
			this->insert(pos, 1, value);
			return iterator(_arr + posInsert);
		}

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

		iterator erase(iterator first, iterator last) {
			iterator ret(first);

			while (ret != last) {
				erase(first);
				++ret;
			}
			return first;
		}

		void push_back(const T& value) {
			if (_capacity == _size && _capacity) {
				reserve(2 * _size);
			} else {
				reserve(1);
			}
			_alloc.construct(_arr + _size, value);
			++_size;
		}

		void pop_back() {
			if (!_size) {
				return;
			}
			_alloc.destroy(_arr + (_size - 1));
			--_size;
		}

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
	/*		Non-member functions	*/
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