//http://algolist.ru/ds/rbtree.php

#ifndef RB_TREE_MAP_HPP
# define RB_TREE_MAP_HPP

# include <cstddef> // ptrdiff_t
# include <iostream>
# include <stdexcept>
# include "map.hpp"
# include "../../utils/pair.hpp"
# include "../../iterators/rbt_bidirectional_iterator.hpp"
# include "../../utils/functional.hpp"
# include "../../utils/type_traits.hpp"


namespace ft
{
	enum color {RED, BLACK};

	template<class T>
	struct rbt_node {
		typedef T							value_type;
		value_type							data;
		rbt_node*							parent;
		rbt_node*							left;
		rbt_node*							right;
		color								color;

		rbt_node(value_type data) : data(data), parent(0), left(0), right(0), color(BLACK) {}
	};

	template<class T, class Compare = less<typename T::first_type>,
			class Allocator = std::allocator<T> >
	class red_black_tree {
	public:

		/****************************/
		/*      Member types        */
		/****************************/

		typedef T														value_type;
		typedef typename T::first_type									key_type;
		typedef typename T::second_type									mapped_type;
		typedef Compare													key_compare;
		typedef	rbt_node<value_type>									node_type;
		typedef	node_type*												pointer;
		typedef	const node_type*										const_pointer;
		typedef	node_type&												reference;
		typedef	const node_type&										const_reference;
		typedef typename Allocator::template rebind<node_type>::other	allocator_type;
		typedef std::size_t												size_type;
		typedef std::ptrdiff_t											difference_type;
		typedef ft::rbt_bidirectional_iterator<node_type>				iterator;
		typedef ft::rbt_bidirectional_iterator<const node_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;
	private:

		/********************************/
		/*        Member object         */
		/********************************/

		pointer			_root;
		pointer			_nil;
		key_compare		_comp;
		size_type		_size;
		allocator_type	_alloc;
	public:

		/********************************/
		/*       Member function        */
		/********************************/

		/*
		** Default constructor.
		** Constructor for an empty tree.
		** Root empty tree points to a _nil(black color).
		*/
		explicit red_black_tree(const key_compare& comp = key_compare(),
								const allocator_type& alloc = allocator_type()) :	_root(0), _nil(0), _comp(comp),
																					_size(0), _alloc(alloc) {
			_nil = _alloc.allocate(1);
			_alloc.construct(_nil, node_type(value_type()));
			_nil->color = BLACK;
			_root = _nil;
		}

		/*
		** Range constructor
		** Сonstructor for a set of elements from a span of iterators(first and last)
		** Root empty tree points to a _nil(black color).
		*/
		template<class InputIt>
		red_black_tree(InputIt first, InputIt last, const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) :	_root(0), _nil(0), _comp(comp),
																			_size(0), _alloc(alloc) {
			_nil = _alloc.allocate(1);
			_alloc.consruct(_nil, node_type(value_type()));
			_nil->color = BLACK;
			_root = _nil;
			insert(first, last);
		}

		/*
		** Copy constructor.
		** Each element is copied from "other".
		*/
		red_black_tree(const red_black_tree& other) :	_root(0), _nil(0), _comp(other._comp),
																					_size(0), _alloc(other._alloc) {
			_nil = _alloc.allocate(1);
			_alloc.construct(_nil, node_type(value_type()));
			_nil->color = BLACK;
			_root = _nil;
			insert(other.begin(), other.end());
		}

		/*
		** Destructor.
		** Destroy the tree object.
		*/
		virtual ~red_black_tree(void) {
			clear();
			_delete_node(_nil);
		}

		/*
		** Assigns contents.
		** The current content replace from "other"
		*/
		red_black_tree& operator=(const red_black_tree& other) {
			if (this == &other) {
				return *this;
			}
			clear();
			_alloc = other._alloc;
			_comp = other._comp;
			insert(other.begin(), other.end());
			return *this;
		}

		/*
		** Returns copy of the allocator
		*/
		allocator_type get_allocator(void) const {
			return _alloc;
		}

		// === Element access ===

		/*
		** Returns a reference to the mapped value of the element with key equivalent to key.
		** If no such element exists, an exception of type std::out_of_range is thrown
		*/
		mapped_type& at(key_type& key) {
			pointer pos = _search_key(key, _root);
			if (pos) {
				return pos->data.second;
			} else {
				throw std::out_of_range("Out of range");
			}
		}

		/*
		** Returns a const reference to the element at specified location pos, with bounds checking.
		** If pos is not within the range of the container,
		** an exception of type std::out_of_range is thrown.
		*/
		const mapped_type& at(key_type& key) const {
			pointer pos = _search_key(key);
			if (pos) {
				return pos->data.second;
			} else {
				throw std::out_of_range("Out of range");
			}
		}

		/*
		** Returns a reference to the value that is mapped to a key equivalent to key,
		** performing an insertion if such key does not already exist.
		*/
		mapped_type& operator[](key_type& key) {
			pointer pos = _search_key(key, _root);
			if (!pos) {
				insert(ft::make_pair<key_type, mapped_type>(key, mapped_type()));
				pos = _search_key(key, _root);
			}
			return pos->data.second;
		}

		// ==== Iterators ====

		/*
		** Returns an iterator to the first element tree
		*/
		iterator begin(void) {
			pointer tmp = _root;
			while (tmp->left != _nil && tmp != _nil) {
				tmp = tmp->left;
			}
			return iterator(tmp, _root, _nil);
		}

		/*
		** Returns a const iterator to the first element tree
		*/
		const_iterator begin(void) const {
			pointer tmp = _root;
			while (tmp->left != _nil && tmp != _nil) {
				tmp = tmp->left;
			}
			return const_iterator(tmp, _root, _nil);
		}

		/*
		** Returns an iterator to the last element tree
		*/
		iterator end(void) {
			return iterator(_nil, _root, _nil);
		}

		/*
		** Returns a const iterator to the last element tree
		*/
		const_iterator end(void) const {
			return const_iterator(_nil, _root, _nil);
		}

		/*
		** Returns an revere iterator to the last element tree
		*/
		reverse_iterator rbegin(void) {
			return reverse_iterator(end());
		}

		/*
		** Returns an const revere iterator to the last element tree
		*/
		const_reverse_iterator rbegin(void) const {
			return const_reverse_iterator(end());
		}

		/*
		** Returns an revere iterator to the first element tree
		*/
		reverse_iterator rend(void) {
			return reverse_iterator(begin());
		}

		/*
		** Returns an const revere iterator to the first element tree
		*/
		const_reverse_iterator rend(void) const {
			return const_reverse_iterator(begin());
		}

		// ==== Capacity ====

		/*
		** Checks if the tree has no elements.
		** If the tree is empty, return true.
		*/
		bool empty(void) const {
			return _size == 0;
		}

		/*
		** Return number of elemnts the tree.
		*/
		size_type size(void) const {
			return _size;
		}

		/*
		** Return the max number of elemnts the tree is able to hold.
		*/
		size_type max_size(void) const {
			return _alloc.max_size();
		}

		// ==== Modifiers ====

		/*
		** Erases all elements from the tree.
		** After this call, _size = 0.
		*/
		void clear(void) {
			_clear_help(_root);
			_root = _nil;
		}

		/*
		** Single element.
		** Inserts element into the tree,
		** if the tree doesn't already contain an element with an equivalent key.
		*/
		ft::pair<iterator, bool> insert(const value_type& value) {
			// Check that the key is a duplicate.
			iterator it = find(value.first);
			if (it != end()) {
				return ft::make_pair(it, false);
			}
			pointer new_node = _create_node(node_type(value));
			if (_root == _nil) {
				new_node->color = BLACK;
				_root = new_node;
			} else {
				_insert_helper(new_node, _root);
			}
			it = iterator(new_node, _root, _nil);
			++_size;
			return ft::make_pair(it, true);
		}

		/*
		** Single element
		** Inserts value in the position as close as possible to hint
		*/
		iterator insert(iterator hint, const value_type& value) {
			(void)hint;
			return insert(value).first;
		}

		/*
		** Range.
		** Inserts elements from range [first, last).
		** If multiple elements in the range have keys that compare equivalent,
		** it is unspecified which element is inserted.
		*/
		template<class InputIt>
		void insert(InputIt first, InputIt last,
					typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = 0) {
			while (first != last) {
				insert(*first);
				++first;
			}
		}

		/*
		** Single element.
		** Removes the element at pos.
		*/
		void erase(iterator pos) {
			if (pos != end()) {
				_erase_helper(pos._ptr);
				--_size;
			}
		}

		/*
		** Range.
		** Removes the elements in the range [first; last),
		** which must be a valid range in *this.
		*/
		void erase(iterator first, iterator last) {
			while (first != last) {
				erase(first);
				++first;
			}
		}


		/*
		** Single element.
		** Removes the element (if one exists) with the key equivalent to key.
		*/
		size_type erase(const key_type& key) {
			iterator it = find(key);
			// Key not found.
			if (it == end()) {
				return 0;
			}
			erase(it);
			return 1;
		}


		// ==== Lookup ====

		/*
		** Returns the number of elements with key key,
		** which is either 1 or 0 since this container does not allow duplicates.
		*/
		size_type count(const key_type& key) {
			if (find(key) != end()) {
				return 1;
			}
			return 0;
		}

		/*
		** Finds an element with key equivalent to key and returns a iterator to it, if found.
		*/
		iterator find(const key_type& key) {
			pointer node = _search_key(key, _root);
			if (!node) {
				return end();
			}
			return iterator(node, _root, _nil);
		}

		/*
		** Finds an element with key equivalent to key and returns a const iterator to it, if found.
		*/
		const_iterator find(const key_type& key) const {
			pointer node = _search_key(key, _root);
			if (!node) {
				return end();
			}
			return const_iterator(node, _root, _nil);
		}

		/*
		** Returns a range containing all elements with the given key in the container.
		** The range is defined by two iterators, one pointing to the first element that is not less than key
		** and another pointing to the first element greater than key.
		*/
		ft::pair<iterator, iterator> equal_range(const key_type& key) {
			return ft::make_pair<iterator, iterator> (lower_bound(key), upper_bound(key));
		}

		/*
		** Returns a range containing all elements with the given key in the container.
		** The range is defined by two const iterators, one pointing to the first element that is not less than key
		** and another pointing to the first element greater than key.
		*/
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
			return ft::make_pair<const_iterator, const_iterator> (lower_bound(key), upper_bound(key));
		}

		/*
		** Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
		*/
		iterator lower_bound(const key_type& key) {
			for (iterator it = begin(); it != end(); ++it) {
				if (!_comp(it._ptr->data.first, key)) {
					return it;
				}
			}
			return end();
		}

		/*
		** Returns an const iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
		*/
		const_iterator lower_bound(const key_type& key) const {
			for (const_iterator it = begin(); it != end(); ++it) {
				if (!_comp(it._ptr->data.first, key)) {
					return it;
				}
			}
			return end();
		}

		/*
		** Returns an iterator pointing to the first element that is greater than key.
		*/
		iterator upper_bound(const key_type& key) {
			for (iterator it = begin(); it != end(); ++it) {
				if (_comp(key, it._ptr->data.first)) {
					return it;
				}
			}
			return end();
		}

		/*
		** Returns an const iterator pointing to the first element that is greater than key.
		*/
		const_iterator upper_bound(const key_type& key) const {
			for (const_iterator it = begin(); it != end(); ++it) {
				if (_comp(key, it._ptr->data.first)) {
					return it;
				}
			}
			return end();
		}

		// ==== Observers ====

		/*
		** Returns the function object that compares the keys,
		** which is a copy of this container's constructor argument comp.
		*/
		key_compare key_comp(void) const {
			return key_compare();
		}

	private:

		/********************************/
		/* Helpers for public function  */
		/********************************/

		/*
		** This is the helper func for public clear func.
		** Destroy all elements of the tree using recursion
		*/
		void _clear_help(pointer node) {
			//for recursion
			if (node == _nil) {
				return ;
			}
			_clear_help(node->left);
			_clear_help(node->right);
			_delete_node(node);
			--_size;
		}

		/*
		** This is the helper func for public find func.
		** Finds an element with key in the tree using recursion
		*/
		pointer _search_key(const key_type& key, const pointer& node) const {
			// Base case of recursion
			if (node == _nil) {
				return 0;
			} else if (node->data.first == key) {
				return node;
			}
			if (_comp(key, node->data.first)) {
				return _search_key(key, node->left);
			} else {
				return _search_key(key, node->right);
			}
		}

		/*
		** Create new node. New nodes are necessarily red.
		*/
		pointer _create_node(const_reference value) {
			pointer node = _alloc.allocate(1);
			_alloc.construct(node, value);
			node->color = RED;
			node->parent = _nil;
			node->left = _nil;
			node->right = _nil;
			return node;
		}

		void _delete_node(pointer node) {
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}

		/*
		** Rotate node x to left.
		*/
		void _rotate_left(pointer x) {
			pointer y = x->right;
			x->right = y->left;
			if (y->left != _nil) {
				y->left->parent = x;
			}
			if (y != _nil) {
				y->parent = x->parent;
			}
			if (x->parent != _nil) {
				if (x == x->parent->left) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
			} else {
				_root = y;
			}
			y->left = x;
			if (x != _nil) {
				x->parent = y;
			}
		}

		/*
		** Rotate node x to right.
		*/
		void _rotate_right(pointer x) {
			pointer y = x->left;
			x->left = y->right;
			if (y->right != _nil) {
				y->right->parent = x;
			}
			if (y != _nil) {
				y->parent = x->parent;
			}
			if (x->parent != _nil) {
				if (x == x->parent->right) {
					x->parent->right = y;
				} else {
					x->parent->left = y;
				}
			} else {
				_root = y;
			}
			y->right = x;
			if (x != _nil) {
				x->parent = y;
			}
		}

		/*
		** This is the helper func for public insert func.
		** Find position in the tree and insert new_node.
		** Call the insert_fix_up to recolor and rotate nodes in leaf.
		*/
		void _insert_helper(pointer new_node, pointer node) {
			pointer current = node;
			pointer parent = 0;
			while (current != _nil) {
				parent = current;
				if (_comp(new_node->data.first, current->data.first)) {
					current = current->left;
				} else {
					current = current->right;
				}
			}
			new_node->parent = parent;
			if (_comp(new_node->data.first, parent->data.first)) {
				parent->left = new_node;
			} else {
				parent->right = new_node;
			}
			if (new_node->parent != _root) {
				_insert_fix_up(new_node);
			}
		}

		/*
		** Maintain red black tree baance after inserting new node.
		*/
		void _insert_fix_up(pointer node) {
			pointer uncle = 0;
			pointer parent = node->parent;
			pointer grandparent = node->parent->parent;
			while (node != _root && parent->color == RED) {
				// parent of the node is a left leaf:
				if (parent == grandparent->left) {
					uncle = grandparent->right;
					// uncle is RED:
					if (uncle->color == RED) {
						parent->color = BLACK;
						uncle->color = BLACK;
						grandparent->color = RED;
						node = grandparent;
					// uncle is BLACK:
					} else {
						// node is right leaf:
						if (node == parent->right) {
							// make node a left child:
							node = parent;
							_rotate_left(node);
						}
						// recolor and rotate
						parent->color = BLACK;
						grandparent->color = RED;
						_rotate_right(grandparent);
					}
				// parent of the node is a right leaf:
				} else {
					uncle = grandparent->left;
					// uncle is RED:
					if (uncle->color == RED) {
						parent->color = BLACK;
						uncle->color = BLACK;
						grandparent->color = RED;
						node = grandparent;
					// uncle is BLACK:
					} else {
						// node is left leaf:
						if (node == parent->left) {
							// make node a left child:
							node = parent;
							_rotate_right(node);
						}
						// recolor and rotate
						parent->color = BLACK;
						grandparent->color = RED;
						_rotate_left(grandparent);
					}
				}
			}
			_root->color = BLACK;
		}

		void _delete_fix_up(pointer node) {
			pointer tmp;
			while (node != _root && node->color == BLACK) {
				if (node == node->parent->left) {
					tmp = node->parent->right;
					if (tmp->color == RED) {
						tmp->color = BLACK;
						node->parent->color = RED;
						_rotate_left(node->parent);
						tmp = node->parent->right;
					}
					if (tmp->left->color == BLACK && tmp->right->color == BLACK) {
						tmp->color = RED;
						node = node->parent;
					} else {
						if (tmp->right->color == BLACK) {
							tmp->left->color = BLACK;
							tmp->color = RED;
							_rotate_right(tmp);
							tmp = node->parent->right;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK;
						tmp->right->color = BLACK;
						_rotate_left(node->parent);
						node = _root;
					}
				} else {
					tmp = node->parent->left;
					if (tmp->color == RED) {
						tmp->color = BLACK;
						node->parent->color = RED;
						_rotate_right(node->parent);
						tmp = node->parent->left;
					}
					if (tmp->right->color == BLACK && tmp->left->color == BLACK) {
						tmp->color = RED;
						node = node->parent;
					} else {
						if (tmp->left->color == BLACK) {
							tmp->right->color = BLACK;
							tmp->color = RED;
							_rotate_left(tmp);
							tmp = node->parent->left;
						}
						tmp->color = node->parent->color;
						node->parent->color = BLACK;
						tmp->left->color = BLACK;
						_rotate_right(node->parent);
						node = _root;
					}
				}
			}
			node->color = BLACK;
		}

		/*
		** This is the helper func for public erase func.
		** Delete node from tree.
		*/
		void _erase_helper(pointer node) {
			pointer x = 0;
			pointer y = 0;
			if (!node || node == _nil) {
				return;
			}
			if (node->left == _nil || node->right == _nil) {
				// y has f _nil node as a child
				y = node;
			} else {
				// find tree successor with a _nil node as a child
				y = node->right;
				while (y->left != _nil) {
					y = y->left;
				}
			}
			// x is y's only child
			if (y->left != _nil) {
				x = y->left;
			} else {
				x = y->right;
			}
			// remove y from the parent chain
			x->parent = y->parent;
			if (y->parent) {
				if (y == y->parent->left) {
					y->parent->left = x;
				} else {
					y->parent->right = x;
				}
			} else {
				_root = x;
			}
			if (y != node) {
				node = y;
			}
			if (y->color == BLACK) {
				_delete_fix_up(x);
			}
			_delete_node(y);
		}
	};
}

#endif