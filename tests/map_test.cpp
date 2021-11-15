#include "../containers/map.hpp"
#include "../utils/iterator/rbt_bidirectional_iterator.hpp"
#include "../utils/pair.hpp"
#include "../utils/rb_tree_map.hpp"
#include "../utils/functional.hpp"
#include <map>

#define GREEN "\x1b[1;32m"
#define WHITE "\x1b[37m"
#define RED "\x1b[1;31m"
#define YEL "\x1b[1;33m"
#define MAG "\x1b[1;35m"
#define CYAN "\x1b[1;36m"
#define REST "\x1b[0m"
#define CLEAR "\e[1;1H\e[2J"


template<class T>
void map_print(const T& map, int num) {
	if (num == 1) {
		std::cout << CYAN "ft::map<T>  " REST << "[ ";
	} else {
		std::cout << YEL "std::map<T> " REST << "[ ";
	}
	for (typename T::const_iterator it = map.begin(); it != map.end(); ++it) {
		std::cout << it->first << "=" << it->second << " ";
	}
	std::cout << "]" <<std::endl;
}

template<class Key, class T>
void map_compare(const ft::map<Key, T>& ft_map, const std::map<Key, T>& std_map) {
	std::cout << std::endl << MAG "compare: " REST << std::endl;
	map_print(ft_map, 1);
	map_print(std_map, 2);
	bool flag = true;
	typename ft::map<Key, T>::const_iterator ft_it = ft_map.begin();
	typename std::map<Key, T>::const_iterator std_it = std_map.begin();
	for (; std_it != std_map.end() && ft_it != ft_map.end(); ++std_it, ++ft_it) {
		if (std_it->first != ft_it->first || std_it->second != ft_it->second) {
			std::cout << RED "KO :(" REST << std::endl;
			flag = false;
		}
	}
	if (flag) {
		std::cout << GREEN "OK :)" REST << std::endl;
	}
	//size
	if (std_map.size() == ft_map.size()) {
		std::cout << "size:  " GREEN << std_map.size() << "==" << ft_map.size() << REST <<
		GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "size:  " RED << std_map.size() << "!=" << ft_map.size() << REST <<
		RED " KO :(" REST << std::endl;
	}
	// first value
	if (ft_map.size()) {
		if (std_map.begin()->second == ft_map.begin()->second) {
			std::cout << "first value: " GREEN << std_map.begin()->second << "==" << ft_map.begin()->second << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "first value: " RED << std_map.begin()->second << "!=" << ft_map.begin()->second << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	// //last element
	// if (ft_map.size()) {
	// 	if ((--std_map.end()) == (--ft_map.end())) {
	// 		std::cout << "last element:  " GREEN << std_map.begin()->second << "==" << ft_map.begin()->second << REST <<
	// 		GREEN " OK :)" REST << std::endl;
	// 	} else {
	// 		std::cout << "last element:  " RED << std_map.begin()->second << "!=" << ft_map.begin()->second << REST <<
	// 		RED " KO :(" REST << std::endl;
	// 	}
	// }
	std::cout << "=================================================================================="
	<< std::endl << std::endl;
}

void test_constructors(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №1 Constructors" REST << " ===" << std::endl;

	std::cout << GREEN "*** Default ***" REST << std::endl;
	{
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		std::cout << "Enter: " << CYAN "map<int, int> map" REST << std::endl;
		map_compare(ft_map, std_map);
	}

}

int main(void) {
	test_constructors();
	return 0;

}