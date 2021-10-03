#ifndef FT_TYPE_TRAITS_HPP
# define FT_TYPE_TRAITS_HPP

# include <limits>

namespace ft
{
	template <bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if <true, T> {
		typedef T type;
	};

	template <class T, T v>
	struct integral_constant {
	/****************************/
	/*		Member types		*/
	/****************************/
	typedef T value_type;
	typedef integral_constant <T, v> type;
	/****************************/
	/*		Member constants	*/
	/****************************/
	static const value_type value = v;
	/****************************/
	/*		Member functions	*/
	/****************************/
	operator value_type() const {
		return value;
	}
	};

	typedef integral_constant <bool, true> true_type;
	typedef integral_constant <bool, true> false_type;

	template <class T> struct is_integral : ft::false_type {};
	template <> struct is_integral<bool> : ft::true_type {};
	template <> struct is_integral<char> : ft::true_type {};
	template <> struct is_integral<char16_t> : ft::true_type {};
	template <> struct is_integral<char32_t> : ft::true_type {};
	template <> struct is_integral<wchar_t> : ft::true_type {};
	template <> struct is_integral<short> : ft::true_type {};
	template <> struct is_integral<int> : ft::true_type {};
	template <> struct is_integral<long> : ft::true_type {};
	template <> struct is_integral<long long> : ft::true_type {};
	template <> struct is_integral<unsigned char> : ft::true_type {};
	template <> struct is_integral<unsigned short> : ft::true_type {};
	template <> struct is_integral<unsigned int> : ft::true_type {};
	template <> struct is_integral<unsigned long> : ft::true_type {};
	template <> struct is_integral<unsigned long long> : ft::true_type {};
}


#endif