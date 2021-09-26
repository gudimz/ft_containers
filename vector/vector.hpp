#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory> // std::allocator<T>
//# include "iterator.hpp"


namespace ft
{
	template < class T, class Allocator = std::allocator<T> >
	class vector {
	public:
		/****************************/
		/*		Member types		*/
		/****************************/
		typedef T											value_type;
		typedef Allocator									allocator_type;

		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		/*****************/
		/*	my_ierators	 */
		/*****************/
		// typedef implementation-defined                   iterator;
		// typedef implementation-defined                   const_iterator;
		// typedef std::reverse_iterator<iterator>          reverse_iterator;
		// typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;
		/********************************/
		/*		Member functions		*/
		/********************************/

		//	Constuctors
		vector() : _alloc(allocator_type()), _arr(0), _size(0), _capacity(0) {}
		explicit vector(const allocator_type& alloc) : _alloc(alloc), _arr(0), _size(0), _capacity(0) {}
		explicit vector( size_type n, const value_type& value = value_type(),
						const allocator_type& alloc = allocator_type()) : _alloc(alloc), _arr(0), _size(0), _capacity(0) {
			reserve(n);
			for (size_t i = 0; i < n; ++i) {
				_alloc.construct(_arr + i, value);
			}
			this->_size = n;
		}
		// ==== Capacity ====

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

	private:
		pointer _arr;
		size_type _size;
		size_type _capacity;
		allocator_type _alloc;
	};
}


#endif