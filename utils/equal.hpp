#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{
	/*
	**	Default
	**	Compare elements in the range first1 to last1 and first2.
	**	If elements in range equal elemnts in first2,
	**	return true
	**	The elements are compared using operator==
	*/
	template<class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
		while (first1 != last1) {
			if (*first1 != *first2) {
				return false;
			}
			++first1;
			++first2;
		}
		return true;
	}

	/*
	**	With binary predicate.
	**	Compare elements in the range first1 to last1 and first2.
	**	If elements in range equal elemnts in first2,
	**	return true
	**	The elements are compared using binary predicate
	*/
	template<class InputIt1, class InputIt2, class BinaryPredicate>
	bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, BinaryPredicate p) {
		while (first1 != last1) {
			if (!p(*first1, *first2)) {
				return false;
			}
			++first1;
			++first2;
		}
		return true;
	}
}

#endif