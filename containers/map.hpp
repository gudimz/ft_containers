#ifndef MAP_HPP
# define MAP_HPP

#include <memory> // std::allocator<ft::pair<const Key, T> >
#include "../utils/functional.hpp"
#include "../utils/pair.hpp"
#include "../utils/rb_tree_map.hpp"
#include "../utils/iterator/rbt_bidirectional_iterator.hpp"

namespace ft
{
	template<class Key, class T, class Compare = ft::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {
	public:

		/****************************/
		/*        Member types      */
		/****************************/

		typedef Key																				key_type;
		typedef T																				mapped_type;
		typedef ft::pair<const key_type, mapped_type>											value_type;
		typedef Compare																			key_compare;
		typedef Allocator																		allocator_type;
		typedef typename ft::red_black_tree<key_type, mapped_type, key_compare, allocator_type>	tree_type;
		typedef typename allocator_type::reference												reference;
		typedef typename allocator_type::const_reference										const_reference;
		typedef typename allocator_type::size_type												size_type;
		typedef typename allocator_type::difference_type										difference_type;
		typedef typename allocator_type::pointer												pointer;
		typedef typename allocator_type::const_pointer											const_pointer;
		typedef typename tree_type::iterator													iterator;
		typedef typename tree_type::const_iterator												const_iterator;
		typedef typename tree_type::reverse_iterator											reverse_iterator;
		typedef typename tree_type::const_reverse_iterator										const_reverse_iterator;

		/****************************/
		/*      Member classes      */
		/****************************/

		/*
		**  Function object that compares objects of type ft::map::value_type (key-value pairs)
		** by comparing of the first components of the pairs.
		*/
		class value_compare : public ft::binary_function<value_type, value_type, bool> {
			friend class map;
		protected:
			key_compare _comp;
			value_compare(key_compare c) : _comp(c) {}
		public:
			bool operator()(const value_type& lhs, const value_type& rhs) const {
				return _comp(lhs.first, rhs.first);
			}
		};

	private:

		/********************************/
		/*        Member object         */
		/********************************/

		tree_type _tree;

	public:

		/********************************/
		/*       Member functions       */
		/********************************/

		/*
		** Default constructor.
		** Constructor for an empty map.
		*/
		explicit map(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, allocator_type(alloc)) {}

		/*
		** Range constructor.
		** Constructs the container with the contents of the range [first, last).
		** If multiple elements in the range have keys that compare equivalent,
		** it is unspecified which element is inserted
		*/
		template<class InputIt>
		map(InputIt first, InputIt last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, allocator_type(alloc)) {
			_tree.insert(first, last);
		}





		/*
		** Copy constructor.
		** Each element is copied from "other".
		*/
		map(const map& other) : _tree(other._tree) {}

		/*
		** Destructor.
		** Destructors of the elements are called and
		** the used storage is deallocated.
		*/
		~map() {}

		// ==== Iterators ====

		/*
		** Returns an iterator to the first element container.
		*/
		iterator begin(void) {
			return _tree.begin();
		}

		/*
		** Returns a const iterator to the first element container.
		*/
		const_iterator begin(void) const {
			return _tree.begin();
		}

		/*
		** Returns an iterator to the last element container
		*/
		iterator end(void) {
			return _tree.end();
		}

		/*
		** Returns a const iterator to the last element container
		*/
		const_iterator end(void) const {
			return _tree.end();
		}

		/*
		** Returns an revere iterator to the last element container
		*/
		reverse_iterator rbegin(void) {
			return _tree.rbegin();
		}

		/*
		** Returns an const revere iterator to the last element container
		*/
		const_reverse_iterator rbegin(void) const {
			return _tree.rbegin();
		}

		/*
		** Returns an revere iterator to the first element container
		*/
		reverse_iterator rend(void) {
			return _tree.rend();
		}

		/*
		** Returns an const revere iterator to the first element container
		*/
		const_reverse_iterator rend(void) const {
			return _tree.rend();
		}

		// ==== Capacity ====

		/*
		** Checks if the map has no elements.
		** If the map is empty, return true.
		*/
		bool empty(void) const {
			return _tree.empty();
		}

		/*
		** Return number of elemnts the map.
		*/
		size_type size(void) const {
			return _tree.size();
		}

		/*
		** Return the max number of elemnts the map is able to hold.
		*/
		size_type max_size(void) const {
			return _tree.max_size();
		}




	};

}
#endif