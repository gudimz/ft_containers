#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include <memory> //std::addressof()

namespace ft
{
	template<class Iter>
	class reverse_iterator {
	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;

	private:
		iterator_type _it;
	public:
		/********************************/
		/*		Member functions		*/
		/********************************/

		//	Constuctors
		reverse_iterator() : _it(0) {}

		explicit reverse_iterator(iterator_type it) : _it(it) {}

		//	Copy Constuctors
		template<class U>
		reverse_iterator(const reverse_iterator<U>& other) : _it(other.base()) {}

		// Destructor
		virtual ~reverse_iterator() {}

		// Assign
		reverse_iterator& operator=(const reverse_iterator& other) {
			if (this == &other) {
				return *this;
			}
			this->_it = other._it;
			return *this;
		}
		// === Element access ===
		iterator_type base() const {
			return _it;
		}

		reference operator*() const {
			iterator_type tmp = _it;
			return *--tmp;
		}

		pointer operator->() const {
			return std::addressof(operator*());
		}

		reference operator[](difference_type n) const {
			return base()[-n - 1];
		}
		// === Increments and Decrements ===
		// Prefix increment
		reverse_iterator& operator++() {
			--_it;
			return *this;
		}

		// Prefix decrement
		reverse_iterator& operator--() {
			++_it;
			return *this;
		}

		// Postfix increment
		reverse_iterator operator++(int) {
			reverse_iterator copy = *this;
			--_it;
			return copy;
		}

		// Postfix decrement
		reverse_iterator operator--(int) {
			reverse_iterator copy = *this;
			++_it;
			return copy;
		}

		reverse_iterator& operator+=(difference_type n) {
			_it -= n;
			return *this;
		}

		reverse_iterator& operator-=(difference_type n) {
			_it += n;
			return *this;
		}

		reverse_iterator operator+(difference_type n) const {
			for (difference_type i = 0; i < n; ++i) {
				--reverse_iterator<Iter>(base());
			}
			return reverse_iterator<Iter>(base());
		}

		reverse_iterator operator-(difference_type n) const {
			for (difference_type i = 0; i < n; ++i) {
				++reverse_iterator<Iter>(base());
			}
			return reverse_iterator<Iter>(base());
		}

		// === Compares ===
		bool operator==(const reverse_iterator& other) const {
			return this->base() == other.base();
		}

		bool operator!=(const reverse_iterator& other) const {
			return this->base() != other.base();
		}

		bool operator<(const reverse_iterator& other) const {
			return this->base() > other.base();
		}

		bool operator<=(const reverse_iterator& other) const {
			return this->base() >= other.base();
		}

		bool operator>(const reverse_iterator& other) const {
			return this->base() < other.base();
		}

		bool operator>=(const reverse_iterator& other) const {
			return this->base() <= other.base();
		}
	};

	/********************************/
	/*		Non-member functions	*/
	/********************************/
	template<class IteratorL, class IteratorR>
	bool operator==(reverse_iterator<IteratorL>& lhs, reverse_iterator<IteratorR>& rhs) {
		return lhs.base() == rhs._base();
	}

	template<class IteratorL, class IteratorR>
	bool operator!=(reverse_iterator<IteratorL>& lhs, reverse_iterator<IteratorR>& rhs) {
		return lhs.base() != rhs._base();
	}

	template<class IteratorL, class IteratorR>
	bool operator<(reverse_iterator<IteratorL>& lhs, reverse_iterator<IteratorR>& rhs) {
		return lhs.base() > rhs._base();
	}

	template<class IteratorL, class IteratorR>
	bool operator<=(reverse_iterator<IteratorL>& lhs, reverse_iterator<IteratorR>& rhs) {
		return lhs.base() >= rhs._base();
	}

	template<class IteratorL, class IteratorR>
	bool operator>(reverse_iterator<IteratorL>& lhs, reverse_iterator<IteratorR>& rhs) {
		return lhs.base() < rhs._base();
	}

	template<class IteratorL, class IteratorR>
	bool operator>=(reverse_iterator<IteratorL>& lhs, reverse_iterator<IteratorR>& rhs) {
		return lhs.base() <= rhs._base();
	}

	template<class Iterator>
	reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n,
															const reverse_iterator<Iterator>& other) {
		return n + other;
	}

	template<class Iterator>
	reverse_iterator<Iterator> operator-(typename ft::reverse_iterator<Iterator>::difference_type n,
															const reverse_iterator<Iterator>& other) {
		return n - other;
	}

	template<class IteratorL, class IteratorR>
	typename reverse_iterator<IteratorL>::difference_type operator-(reverse_iterator<IteratorL>& lhs, reverse_iterator<IteratorR>& rhs) {
		return rhs.base() - lhs._base();
	}
}

#endif