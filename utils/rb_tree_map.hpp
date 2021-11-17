#ifndef RB_TREE_MAP_HPP
# define RB_TREE_MAP_HPP

# include <cstddef> // ptrdiff_t
# include <iostream>
# include "../containers/map.hpp"
# include "../utils/pair.hpp"
# include "../utils/iterator/rbt_bidirectional_iterator.hpp"
# include "../utils/functional.hpp"


namespace ft
{
	enum color {red, black};

	template<class Key, class T>
	struct rbt_node {
		typedef ft::pair<Key, T>			value_type;
		value_type							data;
		rbt_node*							parent;
		rbt_node*							left;
		rbt_node*							right;
		color								color;

		rbt_node(value_type data) : data(data) {}
	};

	template<class Key, class T, class Compare = ft::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
	class red_black_tree {
	public:

		/****************************/
		/*      Member types        */
		/****************************/

		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<const key_type, mapped_type>					value_type;
		typedef Compare													key_compare;
		typedef	value_type*												pointer;
		typedef	const value_type*										const_pointer;
		typedef	value_type&												reference;
		typedef	const value_type&										const_reference;
		typedef	rbt_node<key_type, mapped_type>					node_type;
		typedef node_type*												node_ptr;
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

		node_ptr		_root;
		node_ptr		_nil;
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
			_nil->color = black;
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
			_nil->color = black;
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
			_alloc.consruct(_nil, node_type(value_type()));
			_nil->color = black;
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
			node_ptr tmp = _root;
			while (tmp && tmp->left != _nil) {
				tmp = tmp->left;
			}
			return iterator(tmp, _root, _nil);
		}

		/*
		** Returns a const iterator to the first element tree
		*/
		const_iterator begin(void) const {
			node_ptr tmp = _root;
			while (tmp && tmp->left != _nil) {
				tmp = tmp->left;
			}
			return const_iterator(tmp, _root, _nil);
		}

		/*
		** Returns an iterator to the last element tree
		*/
		iterator end(void) {
			if (empty()) {
				return begin();
			}
			return iterator(_nil, _root, _nil);
		}

		/*
		** Returns a const iterator to the last element tree
		*/
		const_iterator end(void) const {
				if (empty()) {
				return begin();
			}
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
		** Inserts element into the container,
		** if the container doesn't already contain an element with an equivalent key.
		*/
		ft::pair<iterator, bool> insert(const value_type& value) {
			// Check that the key is a duplicate.
			iterator it = find(value);
			if (it != end()) {
				return ft::pair<it, false>;
			}
			node_ptr new_node = _create_node(value);
			if (_root == _nil) {
				new_node->color = black;
				_root = new_node;
				++_size;
			} else {
//???????????????????????????????????????????????????????
			}
			return ft::make_pair(it, true);
		}

		// ==== Lookup ====

		/*
		** Returns the number of elements with key key,
		** which is either 1 or 0 since this container does not allow duplicates.
		*/
		size_type count(const key_type& key) {
			iterator it = find(key);
			return !it ? 0 : 1;
		}

		/*
		** Finds an element with key equivalent to key and returns a iterator to it, if found.
		*/
		iterator find(const key_type& key) {
			node_ptr node = _search_key(key, _root);
			if (!node) {
				return end();
			}
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
		void _clear_help(node_ptr node) {
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
		node_ptr _serach_key(const key_type key, node_ptr node) const {
			if (!node) {
				return 0;
			}
			if (key < node->data.first) {
				return _serach_key(key, node->left);
			} else if (key > node->data.first) {
				return _serach_key(key, node->right);
			} else if (key == node->data.first) {
				return node;
			}
			return 0;
		}

		/*
		** Create new node. new node. New nodes are necessarily red.
		*/
		node_ptr _create_node(const key_type& value) {
			node_ptr node = _alloc.allocate(1);
			_alloc.construct(node, node_type(value_type()));
			node->color = red;
			node->parent = _nil;
			node->left = _nil;
			node->right = _nil;
		}

		/*
		** Rotate node x to left.
		*/
		void _rotate_left(node_ptr x) {
			node_ptr y = x->right;
			x->right = y->left;
			if (y->left != _nil) {
				y->left->parent = x;
			}
			if (y != _nil) {
				y->parent = x->parent;
			}
			if (x->parent) {
				if (x == x->parent->left) {
					x->parent->left = y;
				} else {
					x->parent->right = y;
				}
			} else {
				root = y;
			}
			y->left = x;
			if (x != _nil) {
				x->parent = y;
			}
		}

		/*
		** Rotate node x to right.
		*/
		void _rotate_left(node_ptr x) {
			node_ptr y = x->left;
			x->left = y->right;
			if (y->right != _nil) {
				y->right->parent = x;
			}
			if (y != _nil) {
				y->parent = x->parent;
			}
			if (x->parent) {
				if (x == x->parent->right) {
					x->parent->right = y;
				} else {
					x->parent->left = y;
				}
			} else {
				root = y;
			}
			y->right = x;
			if (x != _nil) {
				x->parent = y;
			}

		}
	};
}





#endif