#ifndef FT_REVERSE_ITERATOR
# define FT_REVERSE_ITERATOR

# include "ft_iterator_traits.hpp"

namespace ft
{
	template<class Iter>
	class reverse_iterator {
	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_trait<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_trait<Iter>::value_type			value_type;
		typedef typename ft::iterator_trait<Iter>::pointer				pointer;
		typedef typename ft::iterator_trait<Iter>::iterator_category	iterator_category;

	private:
		iterator_type _it;
	};
}

#endif