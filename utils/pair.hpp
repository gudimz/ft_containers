#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
	template<class T1, class T2>
	struct pair {

		/****************************/
		/*      Member types        */
		/****************************/
		typedef T1 			first_type;
		typedef T2 			second_type;

		/********************************/
		/*        Member object         */
		/********************************/

		first_type	first;
		second_type	second;

		/********************************/
		/*       Member function        */
		/********************************/

		/*
		** Default constructor.
		** Value-initializes both elements of the pair, first and second.
		*/
		pair() : first(first_type()), second(second_type()) {}

		/*
		** Initializes first with x and second with y.
		*/
		pair(const first_type& x, const second_type& y) : first(x), second(y) {}

		/*
		** Copy constructor.
		** Initializes first with p.first and second with p.second.
		*/
		template<class U1, class U2>
		pair(const pair<U1, U2>& other) : first(other.first), second(other.second) {}

		/*
		** Assigns contents from pair object "other".
		** Initializes first with other.first and second with other.second.
		*/
		pair& operator=(const pair& other) {
			first = other.first;
			second = other.second;
			return *this;
		}
	};

	/********************************/
	/*     Non-member functions     */
	/********************************/

	template<class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u) {
		return ft::pair<T1, T2>(t, u);
	}

	template<class T1, class T2>
	bool operator==(const ft::pair<T1, T2>& lhs, ft::pair<T1, T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template<class T1, class T2>
	bool operator!=(const ft::pair<T1, T2>& lhs, ft::pair<T1, T2>& rhs) {
		return !(lhs==rhs);
	}

	template<class T1, class T2>
	bool operator<(const ft::pair<T1, T2>& lhs, ft::pair<T1, T2>& rhs) {
		return lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second);
	}

	template<class T1, class T2>
	bool operator<=(const ft::pair<T1, T2>& lhs, ft::pair<T1, T2>& rhs) {
		return !(rhs < lhs);
	}

	template<class T1, class T2>
	bool operator>(const ft::pair<T1, T2>& lhs, ft::pair<T1, T2>& rhs) {
		return rhs < lhs;
	}

	template<class T1, class T2>
	bool operator>=(const ft::pair<T1, T2>& lhs, ft::pair<T1, T2>& rhs) {
		return !(lhs < rhs);
	}
}

#endif