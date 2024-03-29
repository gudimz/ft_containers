#ifndef RBT_BIDERECTIONAL_ITERATOR_HPP
# define RBT_BIDERECTIONAL_ITERATOR_HPP

# include <cstddef> // ptrdiff_t
# include <iterator> //std::random_access_iterator_tag
# include "reverse_iterator.hpp"

namespace ft
{
	template<class Node>
	class rbt_bidirectional_iterator {
	public:

		/****************************/
		/*      Member types        */
		/****************************/

		typedef Node								value_type;
		typedef value_type*							node_ptr;
		typedef std::ptrdiff_t						difference_type;
		typedef typename Node::value_type const		data_type;
		typedef data_type*							pointer;
		typedef data_type const*					const_pointer;
		typedef data_type&							reference;
		typedef data_type const&					const_reference;
		typedef std::bidirectional_iterator_tag		iterator_category;

		/********************************/
		/*        Member object         */
		/********************************/

		node_ptr									_ptr;
	private:
		node_ptr									_root;
		node_ptr									_nil;
	public:

		/********************************/
		/*       Member function        */
		/********************************/

		/*
		** Default constructor.
		** Constructor for empty iterator, points to NULL.
		*/
		rbt_bidirectional_iterator() : _ptr(0), _root(0), _nil(0) {}

		/*
		** Constructor for iterator, having one element and points to ptr.
		*/
		rbt_bidirectional_iterator(node_ptr ptr, node_ptr root, node_ptr nil) : _ptr(ptr),
																				_root(root),
																				_nil(nil)
																				{}

		/*
		** Copy constructor.
		** The iterator is initialized with that of other
		*/
		rbt_bidirectional_iterator(const rbt_bidirectional_iterator& other) :	_ptr(other._ptr),
																				_root(other._root),
																				_nil(other._nil)
																				{}

		/*
		** Destructor.
		** Destroy iterator.
		*/
		virtual ~rbt_bidirectional_iterator() {}

		/*
		** Overload operator "=".
		** The iterator is assigned the value
		** of the iterator of other.
		*/
		rbt_bidirectional_iterator& operator=(const rbt_bidirectional_iterator& other) {
			if (this == &other) {
				return *this;
			}
			this->_ptr = other._ptr;
			this->_root = other._root;
			this->_nil = other._nil;
			return *this;
		}

		/*
		** Overload called when an iterator is converted to a const iterator.
		*/
		operator rbt_bidirectional_iterator<const value_type>() const {
			return rbt_bidirectional_iterator<const value_type>(_ptr, _root, _nil);
		}

		// === Element access ===

		/*
		** Returns a reference to the data of the node,
		** pointed to by the iterator
		*/
		reference operator*() {
			return _ptr->data;
		}

		/*
		** Returns a const reference to the data of the node,
		** pointed to by the iterator
		*/
		const_reference operator*() const {
			return _ptr->data;
		}

		/*
		** Returns a pointer to the data of the node,
		** pointed to by the iterator
		*/
		pointer operator->() {
			return &(operator*());
		}

		/*
		** Returns a pointer to the data of the node,
		** pointed to by the iterator
		*/
		const_pointer operator->() const {
			return &(operator*());
		}

		// === Increments and Decrements ===

		/*
		** Prefix increment.
		** ++iter
		*/
		rbt_bidirectional_iterator& operator++() {
			if (_ptr != _nil) {
				_ptr = _next_node(_ptr);
			}
			return *this;
		}

		/*
		** Prefix decrement.
		** --iter
		*/
		rbt_bidirectional_iterator& operator--() {
			if (_ptr == _nil) {
				_ptr = _root;
				while (_ptr->right != _nil && _ptr != _nil) {
					_ptr = _ptr->right;
				}
			} else {
				_ptr = _prev_node(_ptr);
			}
			return *this;
		}

		/*
		** Postfix increment.
		** iter++
		*/
		rbt_bidirectional_iterator operator++(int) {
			rbt_bidirectional_iterator copy = *this;
			_ptr = _next_node(_ptr);
			return copy;
		}

		/*
		** Postfix decrement.
		** iter--
		*/
		rbt_bidirectional_iterator operator--(int) {
			rbt_bidirectional_iterator copy = *this;
			operator--();
			return copy;
		}

		// === Compares ===

		bool operator==(const rbt_bidirectional_iterator& other) const {
			return _ptr == other._ptr;
		}

		bool operator!=(const rbt_bidirectional_iterator& other) const {
			return _ptr != other._ptr;
		}

	// Helpers
	private:
		/*
		** Returns the value of the previous leaf, starting at the current node.
		*/
		node_ptr _prev_node(node_ptr node) {
			node_ptr tmp = node;
			if (tmp->left != _nil) {
				tmp = tmp->left;
				while (tmp->right != _nil) {
					tmp = tmp->right;
				}
				return tmp;
			} else {
				node_ptr prev_tmp = tmp->parent;
				while (prev_tmp && tmp == prev_tmp->left) {
					tmp = prev_tmp;
					prev_tmp = prev_tmp->parent;
				}
				if (!prev_tmp) {
					return _nil;
				} else {
					return prev_tmp;
				}
			}
		}

		/*
		** Returns the value of the next leaf, starting at the current node.
		*/
		node_ptr _next_node(node_ptr node) {
			node_ptr tmp = node;
			if (tmp == _nil) {
				return _nil;
			}
			if (tmp->right != _nil) {
				tmp = tmp->right;
				while (tmp->left != _nil && tmp != _nil) {
					tmp = tmp->left;
				}
				return tmp;
			} else {
				node_ptr next_tmp = tmp->parent;
				while (next_tmp != _nil && tmp == next_tmp->right) {
					tmp = next_tmp;
					next_tmp = next_tmp->parent;
				}
				if (!next_tmp) {
					return _nil;
				} else {
					return next_tmp;
				}
			}
		}
	};
}

#endif
