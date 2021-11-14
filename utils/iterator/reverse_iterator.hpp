#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
# include <memory> //std::addressof()

namespace ft
{
	template<class Iter>
	class reverse_iterator {
	public:

		/****************************/
		/*      Member types        */
		/****************************/

		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;

	private:

		/********************************/
		/*        Member object         */
		/********************************/

		iterator_type _it;
	public:

		/********************************/
		/*       Member function        */
		/********************************/

		/*
		** Default constructor.
		** The underlying iterator is value-initialized
		*/
		reverse_iterator() : _it(0) {}

		/*
		** The underlying iterator is initialized with it.
		*/
		explicit reverse_iterator(iterator_type it) : _it(it) {}

		/*
		** Copy constructor
		** The underlying iterator is initialized with that of other
		*/
		template<class U>
		reverse_iterator(const reverse_iterator<U>& other) : _it(other.base()) {}

		/*
		** Destructor.
		** Destroy iterator.
		*/
		virtual ~reverse_iterator() {}

		/*
		** Overload operator "=".
		** The underlying iterator is assigned the value
		** of the underlying iterator of other.
		*/
		reverse_iterator& operator=(const reverse_iterator& other) {
			if (this == &other) {
				return *this;
			}
			this->_it = other._it;
			return *this;
		}
		// === Element access ===


		/*
		** Returns the underlying base iterator.
		*/
		iterator_type base() const {
			return _it;
		}

		/*
		** Returns a reference to the element previous to current
		*/
		reference operator*() const {
			iterator_type tmp = _it;
			return *--tmp;
		}

		/*
		** Returns a pointer to the element previous to current
		*/
		pointer operator->() const {
			return std::addressof(operator*());
		}

		/*
		** Returns a reference to the element at specified relative location.
		** If such an element does not exist, it causes undefined behavior.
		*/
		reference operator[](difference_type n) const {
			return base()[-n - 1];
		}
		// === Increments and Decrements ===

		/*
		** Prefix increment.
		** ++iter
		*/
		reverse_iterator& operator++() {
			--_it;
			return *this;
		}

		/*
		** Prefix decrement.
		** --iter
		*/
		reverse_iterator& operator--() {
			++_it;
			return *this;
		}

		/*
		** Postfix increment.
		** iter++
		*/
		reverse_iterator operator++(int) {
			reverse_iterator copy = *this;
			--_it;
			return copy;
		}

		/*
		** Postfix decrement.
		** iter--
		*/
		reverse_iterator operator--(int) {
			reverse_iterator copy = *this;
			++_it;
			return copy;
		}

		/*
		** Advances the iterator by n positions respectively.
		*/
		reverse_iterator& operator+=(difference_type n) {
			_it -= n;
			return *this;
		}
		/*
		** Advances the iterator by -n positions respectively.
		*/
		reverse_iterator& operator-=(difference_type n) {
			_it += n;
			return *this;
		}

		/*
		** Returns an iterator which is advanced by n positions respectively.
		*/
		reverse_iterator operator+(difference_type n) const {
			for (difference_type i = 0; i < n; ++i) {
				--reverse_iterator<Iter>(base());
			}
			return reverse_iterator<Iter>(base());
		}

		/*
		** Returns an iterator which is advanced by -n positions respectively.
		*/
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
	/*     Non-member functions     */
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

	/*
	** Returns the iterator other incremented by n.
	*/
	template<class Iterator>
	reverse_iterator<Iterator> operator+(typename ft::reverse_iterator<Iterator>::difference_type n,
															const reverse_iterator<Iterator>& other) {
		return n + other;
	}

	/*
	** Returns the iterator other decremented by n.
	*/
	template<class Iterator>
	reverse_iterator<Iterator> operator-(typename ft::reverse_iterator<Iterator>::difference_type n,
															const reverse_iterator<Iterator>& other) {
		return n - other;
	}

	/*
	** Returns the difference between two reverse iterators.
	*/
	template<class IteratorL, class IteratorR>
	typename reverse_iterator<IteratorL>::difference_type operator-(reverse_iterator<IteratorL>& lhs, reverse_iterator<IteratorR>& rhs) {
		return rhs.base() - lhs._base();
	}
}

#endif