#ifndef FT_RANDOM_ACCESS_ITERATOR
# define FT_RANDOM_ACCESS_ITERATOR

# include <cstddef> // ptrdiff_t
# include <iterator> //std::random_access_iterator_tag

namespace ft
{
	template<class T, class Pointer, class Reference, class Category = std::random_access_iterator_tag>
	class random_access_iterator {
	public:
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;

		typedef random_access_iterator<T, T*, T&>	iterator_type;
		typedef random_access_iterator<T, const T*, const T&>	const_iterator_type;
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

		// === Element access ===
		random_access_iterator base() const {
			return _ptr;
		}

		reference operator*() const {
			return *_ptr;
		}

		pointer operator->() const {
			return _ptr;
		}

		reference operator[](difference_type n) const {
			return *(_ptr + n);
		}

		// === Increments and Decrements ===
		// Pre increment
		random_access_iterator& operator++() {
			_ptr++;
			return *this;
		}

	};



}

#endif