#ifndef MAP_HPP
# define MAP_HPP

#include <functional>
#include <memory>
#include "../utils/pair.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>,
			class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:
	};

}
#endif