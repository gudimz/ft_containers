#ifndef RBT_BIDERECTIONAL_ITERATOR_HPP
# define RBT_BIDERECTIONAL_ITERATOR_HPP

# include <cstddef> // ptrdiff_t
# include <iterator> //std::random_access_iterator_tag
# include "../red_black_tree.hpp"

namespace ft
{
	template<class Node>
	class rbt_bidirectional_iterator {
	public:
		/****************************/
		/*		Member types		*/
		/****************************/
		typedef Node								value_type;
		typedef value_type*							node_ptr;
		typedef std::ptrdiff_t						difference_type;
		typedef typename Node::value_type			data_type;
		typedef typename Node::pointer				pointer;
		typedef typename Node::reference			reference;
		typedef typename Node::const_reference		const_reference;
		typedef std::random_access_iterator_tag		iterator_category;
		/********************************/
		/*		Member object			*/
		/********************************/
		node_ptr									_ptr;
	private:
		node_ptr									_root;
		node_ptr									_nil;
	public:
		/********************************/
		/*		Member functions		*/
		/********************************/
		//	Constuctors
		rbt_bidirectional_iterator() : ptr(0) _root(0) _nil(0) {}

		rbt_bidirectional_iterator(node_ptr ptr, node_ptr root, node_ptr nil) : _ptr(ptr)
																							_root(_root)
																							_nil(nil)
																							{}

		//	Copy Constuctors
		rbt_bidirectional_iterator(const rbt_bidirectional_iterator& other) :	_ptr(other._ptr)
																				_root(other._root)
																				_nil(other._nil)
																				{}

		// Destructor
		virtual ~rbt_bidirectional_iterator() {}

		// Assign
		rbt_bidirectional_iterator& operator=(const rbt_bidirectional_iterator& other) {
			if (this == &other) {
				return *this;
			}
			this->_ptr = other._ptr;
			this->_root = other._root;
			this->_nil = other._nil;
			return *this;
		}

		operator rbt_bidirectional_iterator<const value_type>() const {
			return rbt_bidirectional_iterator<const value_type>(_ptr);
		}

		// === Element access ===
		node_ptr base() const {
			return _ptr;
		}

		reference operator*() {
			return _ptr->data;
		}

		const_reference operator*() const {
			return _ptr->data;
		}

		pointer operator->() {
			return &_ptr->data;
		}

		// === Increments and Decrements ===
		// Prefix increment
		rbt_bidirectional_iterator& operator++() {
			_ptr = _next_node(_ptr);
			return *this;
		}

		// Prefix decrement
		rbt_bidirectional_iterator& operator--() {
			_ptr = _prev_node(_ptr);
			return *this;
		}

		// Postfix increment
		rbt_bidirectional_iterator operator++(int) {
			rbt_bidirectional_iterator = *this;
			_ptr = _next_node(_ptr);
			return copy;
		}

		// Postfix decrement
		rbt_bidirectional_iterator operator--(int) {
			rbt_bidirectional_iterator copy = *this;
			_ptr = _prev_node(_ptr);
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
		node_ptr _prev_node(node_ptr node) {
			node_ptr tmp;
			if (node->left != _nil) {
				tmp = node->left;
				while (tmp->right && tmp->right != _nill) {
					tmp = tmp->right;
				}
			} else {
				node_ptr prev_tmp = node->parent;
				while (prev_tmp && prev_tmp != _nil && tmp == prev_tmp->left) {
					tmp = prev_tmp;
					prev_tmp = prev_tmp->parent;
				}
			}
			if (!tmp) {
				return _nil
			} else {
				return tmp;
			}
		}

		node_ptr _next_node(node_ptr node) {
			node_ptr tmp;
			if (node->right != _nil) {
				tmp = node->right;
				while (tmp->left && tmp->left != _nill) {
					tmp = tmp->left;
				}
			} else {
				node_ptr prev_tmp = node->parent;
				while (prev_tmp && prev_tmp != _nil && tmp == prev_tmp->right) {
					tmp = prev_tmp;
					prev_tmp = prev_tmp->parent;
				}
			}
			if (!tmp) {
				return _nil
			} else {
				return tmp;
			}
		}
	};
}

#endif
