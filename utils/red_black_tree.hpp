#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include <cstddef> // ptrdiff_t
# include <iostream>
# include "../utils/pair.hpp"
# include "../utils/iterator/rbt_bidirectional_iterator.hpp"
# include "../utils/iterator/reverse_iterator.hpp"

namespace ft
{
	enum color {red, black};

	template<class T>
	struct rbt_node {
		typedef T		value_type;

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
		/*		Member types		*/
		/****************************/
		typedef Key													key_type;
		typedef	T													value_type;
		typedef	value_type*											pointer;
		typedef	const value_type*									const_pointer;
		typedef	value_type&											reference;
		typedef	const value_type&									const_reference;
		typedef	red_black_tree<value_type>							node_type;
		typedef Allocator											allocator_type;
		typedef std::size_t											size_type;
		typedef std::ptrdiff_t										difference_type;
		typedef ft::rbt_bidirectional_iterator<node_type>				iterator;
		typedef ft::rbt_bidirectional_iterator<const node_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

	};
}



#endif