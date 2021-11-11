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
		typedef value_type*							node_pointer;
		typedef std::ptrdiff_t						difference_type;
		typedef typename Node::value_type			data_type;
		typedef typename Node::pointer				pointer;
		typedef typename Node::reference			reference;
		typedef typename Node::const_reference		const_reference;
		typedef std::random_access_iterator_tag		iterator_category;
		/********************************/
		/*		Member object			*/
		/********************************/
		node_pointer								_ptr;
	private:
		node_pointer								_root;
		node_pointer								_nil;
	public:
		/********************************/
		/*		Member functions		*/
		/********************************/
		//	Constuctors
		rbt_bidirectional_iterator() : ptr(NULL) _root(NULL) _nil(NULL) {}

		rbt_bidirectional_iterator(node_pointer ptr, node_pointer root, node_pointer nil) : _ptr(ptr)
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
		node_pointer base() const {
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
			_ptr = next_node(_ptr);
			return *this;
		}

		// Prefix decrement
		rbt_bidirectional_iterator& operator--() {
			_ptr = next_node(_ptr);
			return *this;
		}

		// Postfix increment
		rbt_bidirectional_iterator operator++(int) {
			rbt_bidirectional_iterator = *this;
			_ptr = next_node(_ptr);
			return copy;
		}

		// Postfix decrement
		random_access_iterator operator--(int) {
			random_access_iterator copy = *this;
			--_ptr;
			return copy;
		}



	// Helpers
	private:
		node_pointer prev_node(node_pointer node) {
			node_pointer tmp;
			if (node->left != _nil) {
				tmp = node->left;
				while (tmp->right && tmp->right != _nill) {
					tmp = tmp->right;
				}
			} else {
				node_pointer prev_tmp = node->parent;
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

		node_pointer next_node(node_pointer node) {
			node_pointer tmp;
			if (node->right != _nil) {
				tmp = node->right;
				while (tmp->left && tmp->left != _nill) {
					tmp = tmp->left;
				}
			} else {
				node_pointer prev_tmp = node->parent;
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
