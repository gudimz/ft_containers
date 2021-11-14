#ifndef FUNCTIONAL_HPP
# define FUNCTIONAL_HPP

namespace ft
{
	/*
	** Base class for creating function objects with two arguments.
	*/
	template<class Arg1, class Arg2, class Result>
	struct binary_function {

		/****************************/
		/*      Member types        */
		/****************************/

		typedef Arg1 			first__argument_type;
		typedef Arg2 			second_argument_type;
		typedef Result 			result_type;
	};

	/*
	** Function object for performing comparisons. Unless specialized, invokes operator< on type T.
	*/
	template<class T>
	struct less : binary_function<T, T, bool> {
		bool operator()(const T& lhs, const T& rhs) const {
			return lhs < rhs;
		}

	};
}

#endif