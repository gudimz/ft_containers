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

		typedef Key																		key_type;
		typedef T																		mapped_type;
		typedef ft::pair<const key_type, mapped_type>									value_type;
		typedef Compare																	key_compare;
		typedef Allocator																allocator_type;
		typedef typename ft::red_black_tree<value_type, key_compare, allocator_type>	tree_type;
		typedef value_type&																reference;
		typedef const value_type&														const_reference;
		typedef value_type*																pointer;
		typedef const value_type*														const_pointer;
		typedef std::size_t																size_type;
		typedef std::ptrdiff_t															difference_type;
		typedef typename tree_type::iterator											iterator;
		typedef typename tree_type::const_iterator										const_iterator;
		typedef typename tree_type::reverse_iterator									reverse_iterator;
		typedef typename tree_type::const_reverse_iterator								const_reverse_iterator;

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

		/*
		** Returns the allocator associated with the container.
		*/
		allocator_type get_allocator(void) const {
			return allocator_type(_tree.get_allocator());
		}

		// === Element access ===

		/*
		** Returns a reference to the mapped value of the element with key equivalent to key.
		** If no such element exists, an exception of type std::out_of_range is thrown
		*/
		mapped_type& at(const key_type& key) {
			return _tree.at(key);
		}

		/*
		** Returns a const reference to the element at specified location pos, with bounds checking.
		** If pos is not within the range of the container,
		** an exception of type std::out_of_range is thrown.
		*/
		mapped_type& at(const key_type& key) const {
			return _tree.at(key);
		}

		/*
		** Returns a reference to the value that is mapped to a key equivalent to key,
		** performing an insertion if such key does not already exist.
		*/
		mapped_type& operator[](const key_type& key) {
			return _tree[key];
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
			_tree.clear();
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
			_tree(first, last);
		}

		/*
		** Single element.
		** Removes the element at pos.
		*/
		void erase(iterator pos) {
			_tree.erase(pos);
		}

		/*
		** Range.
		** Removes the elements in the range [first; last),
		** which must be a valid range in *this.
		*/
		void erase(iterator first, iterator last) {
			_tree.erase(first, last);
		}


		/*
		** Single element.
		** Removes the element (if one exists) with the key equivalent to key.
		*/
		size_type erase(const key_type& key) {
			return _tree.erase(key);
		}

		/*
		** Exchanges the contents of the container with those of other.
		** Does not invoke any move, copy, or swap operations on individual elements.
		** All iterators and references remain valid.
		** The past-the-end iterator is invalidated.
		*/
		void swap(map& other) {
			map tmp = *this;
			*this = other;
			other = tmp;
		}

		// ==== Lookup ====

		/*
		** Returns the number of elements with key key,
		** which is either 1 or 0 since this container does not allow duplicates.
		*/
		size_type count(const key_type& key) {
			return _tree.count(key);
		}

		/*
		** Finds an element with key equivalent to key and returns a iterator to it, if found.
		*/
		iterator find(const key_type& key) {
			return _tree.find(key);
		}

		/*
		** Finds an element with key equivalent to key and returns a const iterator to it, if found.
		*/
		const_iterator find(const key_type& key) const {
			return _tree.find(key);
		}

		/*
		** Returns a range containing all elements with the given key in the container.
		** The range is defined by two iterators, one pointing to the first element that is not less than key
		** and another pointing to the first element greater than key.
		*/
		ft::pair<iterator, iterator> equal_range(const key_type& key) {
			return _tree.equal_range(key);
		}

		/*
		** Returns a range containing all elements with the given key in the container.
		** The range is defined by two const iterators, one pointing to the first element that is not less than key
		** and another pointing to the first element greater than key.
		*/
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& key) const {
			return _tree.equal_range(key);
		}

		/*
		** Returns an iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
		*/
		iterator lower_bound(const key_type& key) {
			_tree.lower_bound(key);
		}

		/*
		** Returns an const iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
		*/
		const_iterator lower_bound(const key_type& key) const {
			_tree.lower_bound(key);
		}

		/*
		** Returns an iterator pointing to the first element that is greater than key.
		*/
		iterator upper_bound(const key_type& key) {
			_tree.upper_bound(key);
		}

		/*
		** Returns an const iterator pointing to the first element that is greater than key.
		*/
		const_iterator upper_bound(const key_type& key) const {
			_tree.upper_bound(key);
		}

		// ==== Observers ====

		/*
		** Returns the function object that compares the keys,
		** which is a copy of this container's constructor argument comp.
		*/
		key_compare key_comp(void) const {
			return _tree.key_comp();
		}

		/*
		** Returns a function object that compares objects of type std::map::value_type (key-value pairs)
		** by using key_comp to compare the first components of the pairs.
		*/
		value_compare value_comp(void) const {
			return value_compare(key_comp);
		}
	};

	/********************************/
	/*      Non-member functions    */
	/********************************/



}
#endif