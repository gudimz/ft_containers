#ifndef SET_HPP
# define SET_HPP

#include <memory> // std::allocator<T>
#include "../../utils/functional.hpp"
#include "../../utils/pair.hpp"
#include "rb_tree_set.hpp"
#include "../../iterators/rbt_bidirectional_iterator.hpp"
#include "../../utils/equal.hpp"
#include "../../utils/lexicographical_compare.hpp"

namespace ft
{
	template<class Key, class Compare = ft::less<Key>,
			class Allocator = std::allocator<Key> >
	class set {
	public:

		/****************************/
		/*        Member types      */
		/****************************/

		typedef Key																		key_type;
		typedef Key																		value_type;
		typedef std::size_t																size_type;
		typedef std::ptrdiff_t															difference_type;
		typedef Compare																	key_compare;
		typedef Compare																	value_compare;
		typedef Allocator																allocator_type;
		typedef typename ft::red_black_tree<value_type, key_compare, allocator_type>	tree_type;
		typedef value_type&																reference;
		typedef const value_type&														const_reference;
		typedef value_type*																pointer;
		typedef const value_type*														const_pointer;
		typedef typename tree_type::iterator											iterator;
		typedef typename tree_type::const_iterator										const_iterator;
		typedef typename tree_type::reverse_iterator									reverse_iterator;
		typedef typename tree_type::const_reverse_iterator								const_reverse_iterator;

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
		** Constructor for an empty set.
		*/
		explicit set(const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, allocator_type(alloc)) {}

		/*
		** Range constructor.
		** Constructs the container with the contents of the range [first, last).
		** If multiple elements in the range have keys that compare equivalent,
		** it is unspecified which element is inserted
		*/
		template<class InputIt>
		set(InputIt first, InputIt last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, allocator_type(alloc)) {
			_tree.insert(first, last);
		}

		/*
		** Copy constructor.
		** Each element is copied from "other".
		*/
		set(const set& other) : _tree(other._tree) {}

		/*
		** Destructor.
		** Destructors of the elements are called and
		** the used storage is deallocated.
		*/
		~set() {
			clear();
		}

		/*
		** Copy assignment operator.
		** Replaces the contents with a copy of the contents of other
		*/
		set& operator=(const set& other) {
			_tree = other._tree;
			return *this;
		}

		/*
		** Returns the allocator associated with the container.
		*/
		allocator_type get_allocator(void) const {
			return allocator_type(_tree.get_allocator());
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
		** Checks if the set has no elements.
		** If the set is empty, return true.
		*/
		bool empty(void) const {
			return _tree.empty();
		}

		/*
		** Return number of elemnts the set.
		*/
		size_type size(void) const {
			return _tree.size();
		}

		/*
		** Return the max number of elemnts the set is able to hold.
		*/
		size_type max_size(void) const {
			return _tree.max_size();
		}

		// ==== Modifiers ====

		/*
		** Erases all elements from the set.
		** After this call, _size = 0.
		*/
		void clear(void) {
			_tree.clear();
		}

		/*
		** Single element.
		** Inserts element into the set,
		** if the set doesn't already contain an element with an equivalent key.
		*/
		ft::pair<iterator, bool> insert(const value_type& value) {
			return _tree.insert(value);
		}

		/*
		** Single element with hint.
		** Inserts value in the position as close as possible.
		** if the set doesn't already contain an element with an equivalent key.
		*/
		iterator insert(iterator hint, const value_type& value) {
			return _tree.insert(hint, value);
		}

		/*
		** Range.
		** Inserts elements from range [first, last).
		** If multiple elements in the range have keys that compare equivalent,
		** it is unspecified which element is inserted.
		*/
		template<class InputIt>
		void insert(InputIt first, InputIt last) {
			_tree.insert(first, last);
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
		void swap(set& other) {
			set tmp = *this;
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
			return _tree.lower_bound(key);
		}

		/*
		** Returns an const iterator pointing to the first element that is not less than (i.e. greater or equal to) key.
		*/
		const_iterator lower_bound(const key_type& key) const {
			return _tree.lower_bound(key);
		}

		/*
		** Returns an iterator pointing to the first element that is greater than key.
		*/
		iterator upper_bound(const key_type& key) {
			return _tree.upper_bound(key);
		}

		/*
		** Returns an const iterator pointing to the first element that is greater than key.
		*/
		const_iterator upper_bound(const key_type& key) const {
			return _tree.upper_bound(key);
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
		** Returns the function object that compares the values. It is the same as key_comp.
		*/
		value_compare value_comp(void) const {
			return value_compare(key_comp());
		}
	};

	/********************************/
	/*      Non-member functions    */
	/********************************/

	template<class Key, class Compare, class Alloc>
	bool operator==(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin()) && lhs.size() == rhs.size();
	}

	template<class Key, class Compare, class Alloc>
	bool operator!=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return !(lhs == rhs);
	}

	template<class Key, class Compare, class Alloc>
	bool operator<(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class Key, class Compare, class Alloc>
	bool operator<=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return lhs < rhs || lhs == rhs;
	}

	template<class Key, class Compare, class Alloc>
	bool operator>(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return rhs < lhs;
	}

	template<class Key, class Compare, class Alloc>
	bool operator>=(const set<Key, Compare, Alloc>& lhs, const set<Key, Compare, Alloc>& rhs) {
		return rhs <= lhs;
	}

	/*
	** Specializes the std::swap algorithm for std::set.
	** Swaps the contents of lhs and rhs. Calls lhs.swap(rhs).
	*/
	template<class Key, class Compare, class Alloc>
	void swap(set<Key, Compare, Alloc>& lhs, set<Key, Compare, Alloc>& rhs) {
		lhs.swap(rhs);
	}
}

#endif