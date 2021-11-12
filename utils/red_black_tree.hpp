#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <cstddef> // ptrdiff_t
# include <functional> // std::less<Key>
# include <iostream>
# include "../utils/pair.hpp"
# include "../utils/iterator/rbt_bidirectional_iterator.hpp"
# include "../utils/iterator/reverse_iterator.hpp"

namespace ft
{
	enum color {red, black};

	template<class T>
	struct rbt_node {
		typedef T									value_type;
		typedef value_type*							pointer;
		typedef value_type&							reference;

		value_type		data;
		rbt_node*		parent;
		rbt_node*		left;
		rbt_node*		right;
		color			color;

		rbt_node(value_type data) : data(data) {}
	};

	template<class Key, class T, class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
	class red_black_tree {
	public:

		/****************************/
		/*      Member types        */
		/****************************/

		typedef Key														key_type;
		typedef	T														value_type;
		typedef Compare													key_compare;
		typedef	value_type*												pointer;
		typedef	const value_type*										const_pointer;
		typedef	value_type&												reference;
		typedef	const value_type&										const_reference;
		typedef	red_black_tree<value_type>								node_type;
		typedef node_type*												node_ptr;
		typedef Allocator												allocator_type;
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
		key_type		_comp;
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
			_alloc.consruct(_nil, node_type(value_type()));
			_nil->color = black;
			_root = _nill;
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
			_root = _nill;
			insert(first, last);
		}

		/*
		** Copy constructor.
		** Each element is copied from "other".
		*/
		red_black_tree(const red_black_tree& other) :	_root(0), _nil(0), _comp(comp),
																					_size(0), _alloc(alloc) {
			_nil = _alloc.allocate(1);
			_alloc.consruct(_nil, node_type(value_type()));
			_nil->color = black;
			_root = _nill;
			insert(other.begin(), other.end());
		}

		/*
		** Destructor.
		** Destroy the tree object.
		*/
		virtual ~red_black_tree(void) {
			clear();
			_alloc.destroy(_nil);
			_alloc.deallocate(_nill, 1);
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

	private:

		/********************************/
		/* Helpers for public function  */
		/********************************/

		// ==== for Modifiers ====

		/*
		** Destroy all elements of the tree using recursion
		*/
		void _clear_help(node_ptr node) {
			if (node == _nil) {
				return ;
			}
			_clear_help(node->left);
			_clear_help(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			--_size;
		}


	};
}



#endif