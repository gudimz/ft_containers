#ifndef FT_ITERATOR_TRAITS_HPP
# define FT_ITERATOR_TRAITS_HPP

# include <cstddef> // ptrdiff_t
# include <iterator> //std::random_access_iterator_tag

namespace ft
{
	template<class Iter>
	struct iterator_trait {
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type 			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template<class T>
	struct iterator_trait<T*> {
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef value_type*							pointer;
		typedef value_type&							reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};

	template<class T>
	struct iterator_trait<const T*> {
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef const value_type*					pointer;
		typedef const value_type&					reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};
}

#endif