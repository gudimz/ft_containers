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
		typedef typename ft::red_black_tree<value_type, key_compare, allocator_type>			tree_type;
		typedef value_type&																		reference;
		typedef const value_type&																const_reference;
		typedef value_type*																		pointer;
		typedef const value_type*																const_pointer;
		typedef std::size_t																		size_type;
		typedef std::ptrdiff_t																	difference_type;
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
		~map() {
			clear();
		}

		/*
		** Copy assignment operator.
		** Replaces the contents with a copy of the contents of other
		*/
		map& operator=(const map& other) {
			_tree = other._tree;
			return *this;
		}

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

		// ==== Modifiers ====

		/*
		** Erases all elements from the map.
		** After this call, _size = 0.
		*/

		void clear(void) {
			return _tree.clear();
		}

		/*
		** Single element.
		** Inserts element into the map,
		** if the map doesn't already contain an element with an equivalent key.
		*/
		ft::pair<iterator, bool> insert(const value_type& value) {
			return _tree.insert(value);
		}

		/*
		** Single element with hint.
		** Inserts value in the position as close as possible.
		** if the map doesn't already contain an element with an equivalent key.
		*/
		iterator insert(iterator hint, const value_type& value) {
			(void)hint;
			return _tree.insert(value).first;
		}

		/*
		** Range.
		** Inserts elements from range [first, last).
		** If multiple elements in the range have keys that compare equivalent,
		** it is unspecified which element is inserted.
		*/
		template<class InputIt>
		void insert(InputIt first, InputIt last) {
			return _tree(first, last);
		}


	};

}
#endif