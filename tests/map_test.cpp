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
	if (!num) {
		std::cout << CYAN "map<T>  " REST << "[ ";
	} else if (num == 1) {
		std::cout << CYAN "ft::map<T>  " REST << "[ ";
	} else {
		std::cout << YEL "std::map<T> " REST << "[ ";
	}
	for (typename T::const_iterator it = map.begin(); it != map.end(); ++it) {
		std::cout << it->first << ":" << it->second << " ";
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
	if (ft_map.size() && std_map.size()) {
		if (std_map.begin()->second == ft_map.begin()->second) {
			std::cout << "first value: " GREEN << std_map.begin()->second << "==" << ft_map.begin()->second << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "first value: " RED << std_map.begin()->second << "!=" << ft_map.begin()->second << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	// last element
	if (ft_map.size() && std_map.size()) {
		if ((--std_map.end())->second == (--ft_map.end())->second) {
			std::cout << "last element:  " GREEN << (--std_map.end())->second << "==" << (--ft_map.end())->second << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "last element:  " RED << (--std_map.end())->second << "!=" << (--ft_map.end())->second << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
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

	std::cout << GREEN "*** Range ***" REST << std::endl;
	{
		ft::map<int, char> ft_map_fill;
		std::map<int, char> std_map_fill;
		ft_map_fill.insert(ft::make_pair(1, 'c'));
		std_map_fill.insert(std::make_pair(1, 'c'));
		// double key
		ft_map_fill.insert(ft::make_pair(1, 'c'));
		std_map_fill.insert(std::make_pair(1, 'c'));
		ft_map_fill.insert(ft::make_pair(7, 'a'));
		std_map_fill.insert(std::make_pair(7, 'a'));
		ft_map_fill.insert(ft::make_pair(3, 'n'));
		std_map_fill.insert(std::make_pair(3, 'n'));
		ft_map_fill.insert(ft::make_pair(100, 'z'));
		std_map_fill.insert(std::make_pair(100, 'z'));
		ft_map_fill.insert(ft::make_pair(10, 'f'));
		std_map_fill.insert(std::make_pair(10, 'f'));
		ft_map_fill.insert(ft::make_pair(4, 'g'));
		std_map_fill.insert(std::make_pair(4, 'g'));
		ft_map_fill.insert(ft::make_pair(21, 's'));
		std_map_fill.insert(std::make_pair(21, 's'));
		map_print(ft_map_fill, 0);
		std::cout << "Enter: " << CYAN "map<int, char> map(map_fill.begin(), map_fill.end())" REST << std::endl;
		ft::map<int, char> ft_map_range(ft_map_fill.begin(), ft_map_fill.end());
		std::map<int, char> std_map_range(std_map_fill.begin(), std_map_fill.end());

		map_compare(ft_map_range, std_map_range);
	}

	std::cout << GREEN "*** Copy Constructors ***" REST << std::endl;
	{
		std::cout << std::endl << GREEN "*** Intenger ***" REST << std::endl;
		{

	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [1/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

}

int main(void) {
	test_constructors();
	
	return 0;

}