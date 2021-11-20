//http://algolist.ru/ds/rbtree.php

#ifndef RB_TREE_MAP_HPP
# define RB_TREE_MAP_HPP

# include <cstddef> // ptrdiff_t
# include <iostream>
# include "../containers/map.hpp"
# include "../utils/pair.hpp"
# include "../utils/iterator/rbt_bidirectional_iterator.hpp"
# include "../utils/functional.hpp"
# include "../utils/type_traits.hpp"


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

		rbt_node(value_type data) : data(data) {}
	};

	template<class T, class Compare = ft::less<typename T::first_type>,
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
		red_black_tree(red_black_tree const& other) :	_root(0), _nil(0), _comp(other._comp),
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
			_alloc.destroy(_nil);
			_alloc.deallocate(_nil, 1);
		}

		/*
		** Assigns contents.
		** The current content replace from "other"
		*/
		red_black_tree& operator=(red_black_tree const& other) {
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
		reference at(key_type& key) {
			iterator it = find(key);
			if (it) {
				return it->_ptr->data.second;
			} else {
				throw std::out_of_range("Out of range");
			}
		}

		/*
		** Returns a const reference to the element at specified location pos, with bounds checking.
		** If pos is not within the range of the container,
		** an exception of type std::out_of_range is thrown.
		*/
		const_reference at(key_type& key) const {
			iterator it = find(key);
			if (it) {
				return it->_ptr->data.second;
			} else
				throw std::out_of_range("Out of range");
		}

		/*
		** Returns a reference to the value that is mapped to a key equivalent to key,
		** performing an insertion if such key does not already exist.
		*/
		reference operator[](key_type& key) {
			iterator it = find(key);
			if (it) {
				return it->_ptr->data.second;
			} else {
				insert(ft::make_pair<key_type, value_type>(key, value_type()));
				it = find(key);
				return it->_ptr->data.second;
			}
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
		ft::pair<iterator, bool> insert(value_type const& value) {
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

		void erase(iterator pos) {
			if (pos != end()) {
				_erase_helper(pos._ptr);
				--_size;
			}
		}

		// ==== Lookup ====

		/*
		** Returns the number of elements with key key,
		** which is either 1 or 0 since this container does not allow duplicates.
		*/
		size_type count(key_type const& key) {
			iterator it = find(key);
			return !it ? 0 : 1;
		}

		/*
		** Finds an element with key equivalent to key and returns a iterator to it, if found.
		*/
		iterator find(key_type const& key) {
			pointer node = _search_key(key);
			// if (!node) {
			// 	return end();
			// }
			return iterator(node, _root, _nil);
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
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			--_size;
		}

		/*
		** This is the helper func for public find func.
		** Finds an element with key in the tree using recursion
		*/
		pointer _search_key(key_type const key) const {
			pointer tmp = _root;
			pointer search_key = _nil;
			while (tmp != _nil) {
				if (_comp(key, tmp->data.first)) {
					if (tmp->left != _nil) {
						tmp = tmp->left;
					} else {
						break;
					}
				} else if (key == tmp->data.first) {
					search_key = tmp;
					break;
				} else {
					if (tmp->right != _nil) {
						tmp = tmp->right;
					} else {
						break;
					}
				}
			}
			return search_key;
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
				insert_fix_up(new_node);
			}
		}

		/*
		** Maintain red black tree baance after inserting new node.
		*/
		void insert_fix_up(pointer node) {
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

		void _erase_helper(pointer node) {
			
		}
	};
}





#endif