#ifndef FT_RANDOM_ACCESS_ITERATOR
# define FT_RANDOM_ACCESS_ITERATOR

# include <cstddef> // ptrdiff_t
# include <iterator> //std::random_access_iterator_tag

namespace ft
{
	template<class T, class Pointer, class Reference, class Category = std::random_access_iterator_tag>
	class random_access_iterator {
	public:
		typedef std::ptrdiff_t						difference_type;
		typedef T									value_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;

		typedef random_access_iterator<T, T*, T&>	iterator_type;
		typedef random_access_iterator<T, const T*, const T&>	const_iterator_type;
	private:
		pointer _ptr;
	};



}

#endif