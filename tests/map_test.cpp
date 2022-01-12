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
		std::cout << it->first << RED ":" REST << it->second << " ";
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
	std::cout << GREEN "*** Default with alloc***" REST << std::endl;
	{
		std::allocator<int>  alloc;
		ft::map<int, int> ft_map(ft::less<int>(), alloc);
		std::map<int, int> std_map(std::less<int>(), alloc);
		std::cout << "Enter: " << CYAN "map<int, int> map(less<int>(), alloc)" REST << std::endl;
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
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [1/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №1 Constructors" REST << " ===" << std::endl;
	std::cout << GREEN "*** Copy Constructors ***" REST << std::endl;
	{
		std::cout << std::endl << GREEN "*** Intenger ***" REST << std::endl;
		{
			ft::map<int, int> ft_map_copy;
			std::map<int, int> std_map_copy;
			int y = 100;
			for (size_t i = 1; i < 8; ++i) {
			ft_map_copy.insert(ft::make_pair(i, y));
			std_map_copy.insert(std::make_pair(i, y));
			++y;
			}
			std::cout << "map_copy ";
			map_print(ft_map_copy, 0);
			std::cout << "Enter: " << CYAN "map<int, int> map(map_copy)" REST << std::endl;
			ft::map<int, int> ft_map(ft_map_copy);
			std::map<int, int> std_map(std_map_copy);
			map_compare(ft_map, std_map);

		}
		std::cout << std::endl << GREEN "*** String ***" REST << std::endl;
		{
			ft::map<std::string, std::string> ft_map_copy;
			std::map<std::string, std::string> std_map_copy;
			ft_map_copy.insert(ft::make_pair("Russia", "Moscow"));
			std_map_copy.insert(std::make_pair("Russia", "Moscow"));
			// double key
			ft_map_copy.insert(ft::make_pair("Russia", "Moscow"));
			std_map_copy.insert(std::make_pair("Russia", "Moscow"));
			ft_map_copy.insert(ft::make_pair("USA", "Washington"));
			std_map_copy.insert(std::make_pair("USA", "Washington"));
			ft_map_copy.insert(ft::make_pair("France", "Paris"));
			std_map_copy.insert(std::make_pair("France", "Paris"));
			ft_map_copy.insert(ft::make_pair("England", "London"));
			std_map_copy.insert(std::make_pair("England", "London"));
			ft_map_copy.insert(ft::make_pair("Spain", "Madrid"));
			std_map_copy.insert(std::make_pair("Spain", "Madrid"));
			ft_map_copy.insert(ft::make_pair("Japan", "Tokio"));
			std_map_copy.insert(std::make_pair("Japan", "Tokio"));
			ft_map_copy.insert(ft::make_pair("Canada", "Toronto"));
			std_map_copy.insert(std::make_pair("Canada", "Toronto"));

			std::cout << "map_copy ";
			map_print(ft_map_copy, 0);
			std::cout << "Enter: " << CYAN "map<std::string, std::string> map(map_copy)" REST << std::endl;
			ft::map<std::string, std::string> ft_map(ft_map_copy);
			std::map<std::string, std::string> std_map(std_map_copy);
			map_compare(ft_map, std_map);

		}
	}

	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [2/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

}

void test_assigns(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №2 Assigns" REST << " ===" << std::endl;

	std::cout << GREEN "*** Operator= ***" REST << std::endl;
	{
		ft::map<int, int> ft_map_copy;
		std::map<int, int> std_map_copy;
		int y = 100;
		for (size_t i = 1; i < 8; ++i) {
			ft_map_copy.insert(ft::make_pair(i, y));
			std_map_copy.insert(std::make_pair(i, y));
			++y;
		}
		std::cout << "map_copy ";
		map_print(ft_map_copy, 0);
		std::cout << "Enter: " << CYAN "map<int, int> map = map_copy" REST << std::endl;
		ft::map<int, int> ft_map(ft_map_copy);
		std::map<int, int> std_map(std_map_copy);
		map_compare(ft_map, std_map);
	}

	std::cout << GREEN "*** Get allocator ***" REST << std::endl;
	{
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		int y = 100;
		for (size_t i = 1; i < 8; ++i) {
			ft_map.insert(ft::make_pair(i, y));
			std_map.insert(std::make_pair(i, y));
			++y;
		}
		std::cout << "map<int, int> ";
		map_print(ft_map, 0);
		if (std_map.get_allocator() == ft_map.get_allocator()) {
			std::cout << "std_map.get_allocator() == ft_map.get_allocator()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_vec.get_allocator() != ft_vec.get_allocator()" << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [3/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_element_access(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №3 Element access" REST << " ===" << std::endl;

	std::cout << std::endl << GREEN "*** At ***" REST << std::endl;
	{
		ft::map<std::string, std::string> ft_map;
		ft_map.insert(ft::make_pair("Russia", "Empty"));
		ft_map.insert(ft::make_pair("USA", "Empty"));
		ft_map.insert(ft::make_pair("France", "Empty"));
		map_print(ft_map, 1);
		std::cout << "Enter: " << CYAN "ft_map.at(\"Russia\") = \"Moscow\"" REST << std::endl;
		ft_map.at("Russia") = "Moscow";
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "ft_map.at(\"USA\") = \"Washington\"" REST << std::endl;
		ft_map.at("USA") = "Washington";
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "ft_map.at(\"France\") = \"Paris\"" REST << std::endl;
		ft_map.at("France") = "Paris";
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		try {
			std::cout << "Enter: " << CYAN "ft_map.at(\"Canada\") = \"Toronto\"" REST << std::endl;
			ft_map.at("Canada");
		} catch (const std::exception& e) {
			std::cerr << RED "exception : " REST << e.what() << std::endl;
			std::cout << "=================================================================================="
			<< std::endl << std::endl;
		}
		map_print(ft_map, 1);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [4/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №3 Element access" REST << " ===" << std::endl;

	std::cout << std::endl << GREEN "*** operator[] ***" REST << std::endl;
	{
		ft::map<int, std::string> ft_map;
		std::map<int, std::string> std_map;

		std::cout << "Enter: " << CYAN "map[1] = \"one\"" REST << std::endl;
		ft_map[1] = "one";
		std_map[1] = "one";
		std::cout << "=================================================================================="
		<< std::endl << std::endl;

		std::cout << "Enter: " << CYAN "map[3] = \"three\"" REST << std::endl;
		ft_map[3] = "three";
		std_map[3] = "three";
		std::cout << "=================================================================================="
		<< std::endl << std::endl;

		std::cout << "Enter: " << CYAN "map[2] = \"two\"" REST << std::endl;
		ft_map[2] = "two";
		std_map[2] = "two";
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		map_compare(ft_map, std_map);

		for (size_t i = 1; i <= ft_map.size() && i <= std_map.size(); ++i) {
			if (std_map[i] == ft_map[i]) {
				std::cout << "std_map[" << i << "] == ft_map[" << i << "])" << REST <<
				GREEN " OK :)" REST << std::endl;
			} else {
				std::cout << "std_map[" << i << "] == ft_map[" << i << "])" << REST <<
				RED " KO :(" REST << std::endl;
			}
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [5/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_iterators(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №4 Iterators" REST << " ===" << std::endl;

	std::cout << std::endl << GREEN "*** empty map ***" REST << std::endl;
	ft::map<int, int> ft_map;
	ft::map<int, int> const ft_map_const;
	std::cout << "Enter: " << CYAN "map<int, int> ft_map;" REST << std::endl;
	if (ft_map.begin() == ft_map.end()) {
		std::cout << "ft_map.begin() == ft_map.end()" << std::endl;
		std::cout << GREEN "OK :)" REST << std::endl;
	} else {
		std::cout << "ft_map.begin() != ft_map.end()" << std::endl;
		std::cout << RED "KO :(" REST << std::endl;
	}

	if (ft_map.rbegin() == ft_map.rend()) {
		std::cout << "ft_map.rbegin() == ft_map.rend()" << std::endl;
		std::cout << GREEN "OK :)" REST << std::endl;
	} else {
		std::cout << "ft_map.rbegin() != ft_map.rend()" << std::endl;
		std::cout << RED "KO :(" REST << std::endl;
	}
	std::cout << "=================================================================================="
	<< std::endl << std::endl;
	std::cout << "Enter: " << CYAN "map<int, int> const ft_map_const;" REST << std::endl;
	if (ft_map_const.begin() == ft_map_const.end()) {
		std::cout << "ft_map_const.begin() == ft_map_const.end()" << std::endl;
		std::cout << GREEN "OK :)" REST << std::endl;
	} else {
		std::cout << "ft_map_const.begin() != ft_map_const.end()" << std::endl;
		std::cout << RED "KO :(" REST << std::endl;
	}

	if (ft_map_const.rbegin() == ft_map_const.rend()) {
		std::cout << "ft_map_const.rbegin() == ft_map_const.rend()" << std::endl;
		std::cout << GREEN "OK :)" REST << std::endl;
	} else {
		std::cout << "ft_map_const.rbegin() != ft_map_const.rend()" << std::endl;
		std::cout << RED "KO :(" REST << std::endl;
	}
	std::cout << std::endl << GREEN "*** fill map, iterator ***" REST << std::endl;
	{
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		int y = 100;
		for (size_t i = 1; i < 8; ++i) {
			ft_map.insert(ft::make_pair(i, y));
			std_map.insert(std::make_pair(i, y));
			++y;
		}
		map_print(ft_map, 0);

		if (ft_map.begin()->first == std_map.begin()->first) {
			std::cout << "ft_map.begin()->first == std_map.begin()->first" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "ft_map.begin()->first != std_map.begin()->first" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}

		if (ft_map.rbegin()->second == std_map.rbegin()->second) {
			std::cout << "ft_map.rbegin()->second == std_map.rbegin()->second" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "ft_map.rbegin()->second != std_map.rbegin()->second)" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << std::endl << GREEN "*** fill map, const iterator ***" REST << std::endl;

		ft::map<int, int> const ft_map_const(ft_map);
		std::map<int, int> const std_map_const(std_map);
		map_print(ft_map, 0);
		if (ft_map_const.begin()->first == std_map_const.begin()->first) {
			std::cout << "ft_map_const.begin()->first == std_map_const()->first" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "ft_map_const.begin()->first != std_map_const.begin()->first" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}

		if (ft_map_const.rbegin()->second == std_map_const.rbegin()->second) {
			std::cout << "ft_map_const.rbegin()->second == std_map_const.rbegin()->second" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "ft_map_const.rbegin()->second != std_map_const.rbegin()->second)" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [6/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №4 Iterators" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** arithmetic with iterators ***" REST << std::endl;
	{
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		int y = 21;
		for (size_t i = 1; i < 8; ++i) {
			ft_map.insert(ft::make_pair(i, y));
			std_map.insert(std::make_pair(i, y));
			++y;
		}
		map_print(ft_map, 0);
		std::cout << RED "=== for iterator ===" REST << std::endl;
		ft::map<int, int>::iterator ft_iter = ft_map.begin();
		std::map<int, int>::iterator std_iter = std_map.begin();
		std::cout << "Enter: " << CYAN "++iter" REST << std::endl;
		++ft_iter;
		++std_iter;
		if (ft_iter->first == std_iter->first && ft_iter->second == std_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "iter++" REST << std::endl;
		ft_iter++;
		std_iter++;
		if (ft_iter->first == std_iter->first && ft_iter->second == std_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--iter" REST << std::endl;
		--ft_iter;
		--std_iter;
		if (ft_iter->first == std_iter->first && ft_iter->second == std_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "iter--" REST << std::endl;
		ft_iter--;
		std_iter--;
		if (ft_iter->first == std_iter->first && ft_iter->second == std_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;

		std::cout << RED "=== for reverse_iterator ===" REST << std::endl;
		ft::map<int, int>::reverse_iterator ft_rev_iter = ft_map.rbegin();
		std::map<int, int>::reverse_iterator std_rev_iter = std_map.rbegin();
		std::cout << "Enter: " << CYAN "++rev_iter" REST << std::endl;
		++ft_rev_iter;
		++std_rev_iter;
		if (ft_rev_iter->first == std_rev_iter->first && ft_rev_iter->second == std_rev_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rev_iter++" REST << std::endl;
		ft_rev_iter++;
		std_rev_iter++;
		if (ft_rev_iter->first == std_rev_iter->first && ft_rev_iter->second == std_rev_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--rev_iter" REST << std::endl;
		--ft_rev_iter;
		--std_rev_iter;
		if (ft_rev_iter->first == std_rev_iter->first && ft_rev_iter->second == std_rev_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rev_iter--" REST << std::endl;
		ft_rev_iter--;
		std_rev_iter--;
		if (ft_rev_iter->first == std_rev_iter->first && ft_rev_iter->second == std_rev_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [7/*]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;

		std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
		std::cout << "=== " << MAG "TEST №4 Iterators" REST << " ===" << std::endl;

		std::cout << RED "=== for const_iterator ===" REST << std::endl;
		ft::map<int, int>::const_iterator ft_const_iter = ft_map.begin();
		std::map<int, int>::const_iterator std_const_iter = std_map.begin();
		std::cout << "Enter: " << CYAN "++const_iter" REST << std::endl;
		++ft_const_iter;
		++std_const_iter;
		if (ft_const_iter->first == std_const_iter->first && ft_const_iter->second == std_const_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_iter++" REST << std::endl;
		ft_const_iter++;
		std_const_iter++;
		if (ft_const_iter->first == std_const_iter->first && ft_const_iter->second == std_const_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--const_iter" REST << std::endl;
		--ft_const_iter;
		--std_const_iter;
		if (ft_const_iter->first == std_const_iter->first && ft_const_iter->second == std_const_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_iter--" REST << std::endl;
		ft_const_iter--;
		std_const_iter--;
		if (ft_const_iter->first == std_const_iter->first && ft_const_iter->second == std_const_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << RED "=== for const_reverse_iterator ===" REST << std::endl;
		ft::map<int, int>::const_reverse_iterator ft_const_rev_iter = ft_map.rbegin();
		std::map<int, int>::const_reverse_iterator std_const_rev_iter = std_map.rbegin();
		std::cout << "Enter: " << CYAN "++const_rev_iter" REST << std::endl;
		++ft_const_rev_iter;
		++std_const_rev_iter;
		if (ft_const_rev_iter->first == std_const_rev_iter->first && ft_const_rev_iter->second == std_const_rev_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_rev_iter++" REST << std::endl;
		ft_const_rev_iter++;
		std_const_rev_iter++;
		if (ft_const_rev_iter->first == std_const_rev_iter->first && ft_const_rev_iter->second == std_const_rev_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--const_rev_iter" REST << std::endl;
		--ft_const_rev_iter;
		--std_const_rev_iter;
		if (ft_const_rev_iter->first == std_const_rev_iter->first && ft_const_rev_iter->second == std_const_rev_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_rev_iter--" REST << std::endl;
		ft_const_rev_iter--;
		std_const_rev_iter--;
		if (ft_const_rev_iter->first == std_const_rev_iter->first && ft_const_rev_iter->second == std_const_rev_iter->second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [8/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_capacity(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №5 Capacity" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** empty ***" REST << std::endl;
	{
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		std::cout << "Enter: " << CYAN "map<int, int> map" REST << std::endl;
		if (std_map.empty() == ft_map.empty()) {
			std::cout << "std_map.empty() == ft_map.empty()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_map.empty() != ft_map.empty()" << REST <<
			RED " KO :(" REST << std::endl;
		}
		map_compare(ft_map, std_map);
	}
	{
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		int y = 21;
		for (size_t i = 1; i < 8; ++i) {
			ft_map.insert(ft::make_pair(i, y));
			std_map.insert(std::make_pair(i, y));
			++y;
		}
		map_print(ft_map, 0);
		if (std_map.empty() == ft_map.empty()) {
			std::cout << "std_map.empty() == ft_map.empty()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_map.empty() != ft_map.empty()" << REST <<
			RED " KO :(" REST << std::endl;
		}
		map_compare(ft_map, std_map);
	}
	std::cout << std::endl << GREEN "*** max_size ***" REST << std::endl;
	{
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		int y = 42;
		for (size_t i = 1; i < 8; ++i) {
			ft_map.insert(ft::make_pair(i, y));
			std_map.insert(std::make_pair(i, y));
			++y;
		}
		map_print(ft_map, 0);
		if (std_map.max_size() == ft_map.max_size()) {
			std::cout << "std_map.max_size() == ft_map.max_size()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_map.max_size() != ft_map.max_size()" << REST <<
			RED " KO :(" REST << std::endl;
		}
		map_compare(ft_map, std_map);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [9/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_modifiers(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №6 Modifiers" REST << " ===" << std::endl;

	std::cout << std::endl << GREEN "*** clear ***" REST << std::endl;
	{
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		int y = 42;
		for (size_t i = 1; i < 8; ++i) {
			ft_map.insert(ft::make_pair(i, y));
			std_map.insert(std::make_pair(i, y));
			++y;
		}
		map_print(ft_map, 0);
		std::cout << "Enter: " << CYAN "map.clear()" REST << std::endl;
		ft_map.clear();
		std_map.clear();
		map_compare(ft_map, std_map);
		std::cout << "Enter: " << CYAN "map[21] = 42" REST << std::endl;
		ft_map[21] = 42;
		std_map[21] = 42;
		map_compare(ft_map, std_map);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [10/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №6 Modifiers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** insert single element ***" REST << std::endl;
	{
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;

		std::cout << "Enter: " << CYAN "map.insert(make_pair(21, 42))" REST << std::endl;
		ft_map.insert(ft::make_pair(21, 42));
		std_map.insert(std::make_pair(21, 42));
		std::cout << "Enter: " << CYAN "map.insert(make_pair(-12, 32))" REST << std::endl;
		ft_map.insert(ft::make_pair(-12, 32));
		std_map.insert(std::make_pair(-12, 32));
		std::cout << "Enter: " << CYAN "map.insert(make_pair(-12, 32))" REST << std::endl;
		ft_map.insert(ft::make_pair(-12, 32));
		std_map.insert(std::make_pair(-12, 32));
		std::cout << "Enter: " << CYAN "map.insert(make_pair(0, -2))" REST << std::endl;
		ft_map.insert(ft::make_pair(0, -2));
		std_map.insert(std::make_pair(0, -2));
		std::cout << "Enter: " << CYAN "map.insert(make_pair(7, 7))" REST << std::endl;
		ft_map.insert(ft::make_pair(7, 7));
		std_map.insert(std::make_pair(7, 7));
		map_compare(ft_map, std_map);
	}
	std::cout << std::endl << GREEN "*** insert with hint ***" REST << std::endl;
	{
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;

		ft_map.insert(ft::make_pair(21, 42));
		std_map.insert(std::make_pair(21, 42));
		ft_map.insert(ft::make_pair(-12, 32));
		std_map.insert(std::make_pair(-12, 32));
		ft_map.insert(ft::make_pair(-12, 32));
		std_map.insert(std::make_pair(-12, 32));
		ft_map.insert(ft::make_pair(0, -2));
		std_map.insert(std::make_pair(0, -2));
		ft_map.insert(ft::make_pair(7, 7));
		std_map.insert(std::make_pair(7, 7));
		map_print(ft_map, 0);

		std::cout << "Enter: " << CYAN "map<int, int>::iterator hint = map.find(21)" REST << std::endl;
		ft::map<int, int>::iterator ft_hint = ft_map.find(0);
		std::map<int, int>::iterator std_hint = std_map.find(0);

		std::cout << "Enter: " << CYAN "map.insert(hint, make_pair(6, 6)" REST << std::endl;
		ft_map.insert(ft_hint, ft::make_pair(6, 6));
		std_map.insert(std_hint, std::make_pair(6, 6));
		map_compare(ft_map, std_map);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [11/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №6 Modifiers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** insert with range ***" REST << std::endl;
	{
		ft::map<int, int> ft_map_copy;
		std::map<int, int> std_map_copy;
		std::cout << "map_copy ";
		map_print(ft_map_copy, 0);
		ft::map<int, int> ft_map;
		std::map<int, int> std_map;
		std::cout << "Enter: " << CYAN "map.insert(map_copy.begin(), map_copy.end())" REST << std::endl;
		ft_map.insert(ft_map_copy.begin(), ft_map_copy.end());
		std_map.insert(std_map_copy.begin(), std_map_copy.end());
		map_compare(ft_map, std_map);

		ft_map_copy[21] = 42;
		std_map_copy[21] = 42;
		ft_map_copy[-16] = 5;
		std_map_copy[-16] = 5;
		ft_map_copy[7] = 77;
		std_map_copy[7] = 77;
		ft_map_copy[10] = 18;
		std_map_copy[10] = 18;
		std::cout << "map_copy ";
		map_print(ft_map_copy, 0);

		std::cout << "Enter: " << CYAN "map.insert(map_copy.begin(), map_copy.end())" REST << std::endl;
		ft_map.insert(ft_map_copy.begin(), ft_map_copy.end());
		std_map.insert(std_map_copy.begin(), std_map_copy.end());
		map_compare(ft_map, std_map);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [12/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №6 Modifiers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** erase key value ***" REST << std::endl;
	{
		ft::map<std::string, std::string> ft_map;
		std::map<std::string, std::string> std_map;
		ft_map.insert(ft::make_pair("Russia", "Moscow"));
		std_map.insert(std::make_pair("Russia", "Moscow"));
		ft_map.insert(ft::make_pair("USA", "Washington"));
		std_map.insert(std::make_pair("USA", "Washington"));
		ft_map.insert(ft::make_pair("France", "Paris"));
		std_map.insert(std::make_pair("France", "Paris"));
		ft_map.insert(ft::make_pair("England", "London"));
		std_map.insert(std::make_pair("England", "London"));
		ft_map.insert(ft::make_pair("Spain", "Madrid"));
		std_map.insert(std::make_pair("Spain", "Madrid"));
		map_print(ft_map, 0);

		std::cout << "Enter: " << CYAN "map.erase(\"England\")" REST << std::endl;
		ft_map.erase("England");
		std_map.erase("England");

		std::cout << "Enter: " << CYAN "map.erase(\"Germany\")" REST << std::endl;
		ft_map.erase("Germany");
		std_map.erase("Germany");
		map_compare(ft_map, std_map);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [13/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №6 Modifiers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** swap ***" REST << std::endl;
	{
		ft::map<int, std::string> ft_map_first;
		ft::map<int, std::string> ft_map_second;
		ft_map_first.insert(ft::make_pair(21, "School 21"));
		ft_map_first.insert(ft::make_pair(1, "School 21"));
		ft_map_first.insert(ft::make_pair(77, "School 21"));
		ft_map_first.insert(ft::make_pair(5, "School 21"));
		map_print(ft_map_first, 1);
		ft_map_second.insert(ft::make_pair(42, "Ecole 42"));
		ft_map_second.insert(ft::make_pair(3, "Ecole 42"));
		ft_map_second.insert(ft::make_pair(15, "Ecole 42"));
		ft_map_second.insert(ft::make_pair(23, "Ecole 42"));
		map_print(ft_map_second, 1);

		std::map<int, std::string> std_map_first;
		std::map<int, std::string> std_map_second;
		std_map_first.insert(std::make_pair(21, "School 21"));
		std_map_first.insert(std::make_pair(1, "School 21"));
		std_map_first.insert(std::make_pair(77, "School 21"));
		std_map_first.insert(std::make_pair(5, "School 21"));
		map_print(std_map_first, 2);
		std_map_second.insert(std::make_pair(42, "Ecole 42"));
		std_map_second.insert(std::make_pair(3, "Ecole 42"));
		std_map_second.insert(std::make_pair(15, "Ecole 42"));
		std_map_second.insert(std::make_pair(23, "Ecole 42"));
		map_print(std_map_second, 2);

		std::cout << "Enter: " << CYAN "map_first.swap(map_second)" REST << std::endl;
		ft_map_first.swap(ft_map_second);
		std_map_first.swap(std_map_second);

		map_compare(ft_map_first, std_map_first);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [14/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_lookup() {
	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №7 Lookup" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** count ***" REST << std::endl;
	{
		ft::map<std::string, std::string> ft_map;
		std::map<std::string, std::string> std_map;
		ft_map.insert(ft::make_pair("Russia", "Moscow"));
		std_map.insert(std::make_pair("Russia", "Moscow"));
		ft_map.insert(ft::make_pair("USA", "Washington"));
		std_map.insert(std::make_pair("USA", "Washington"));
		ft_map.insert(ft::make_pair("France", "Paris"));
		std_map.insert(std::make_pair("France", "Paris"));
		map_print(ft_map, 0);

		if (std_map.count("USA") == ft_map.count("USA")) {
			std::cout << "std_map.count(\"USA\") == ft_map.count(\"USA\")" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_map.count(\"USA\") != ft_map.count(\"USA\")" << REST <<
			RED " KO :(" REST << std::endl;
		}

		if (std_map.count("Germany") == ft_map.count("Germany")) {
			std::cout << "std_map.count(\"Germany\") == ft_map.count(\"Germany\")" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_map.count(\"Germany\") != ft_map.count(\"Germany\")" << REST <<
			RED " KO :(" REST << std::endl;
		}
	}

	std::cout << std::endl << GREEN "*** find key ***" REST << std::endl;
	{
		ft::map<std::string, std::string> ft_map;
		std::map<std::string, std::string> std_map;
		ft_map.insert(ft::make_pair("Russia", "Moscow"));
		std_map.insert(std::make_pair("Russia", "Moscow"));
		ft_map.insert(ft::make_pair("USA", "Washington"));
		std_map.insert(std::make_pair("USA", "Washington"));
		ft_map.insert(ft::make_pair("France", "Paris"));
		std_map.insert(std::make_pair("France", "Paris"));
		map_print(ft_map, 0);

		if (std_map.find("USA")->second  == ft_map.find("USA")->second) {
			std::cout << "std_map.find(\"USA\")->second == ft_map.find(\"USA\")->second" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_map.find(\"USA\")->second != ft_map.find(\"USA\")->second" << REST <<
			RED " KO :(" REST << std::endl;
		}
		if ((std_map.find("Germany") == std_map.end() && ft_map.find("Germany") == ft_map.end())) {
			std::cout << "if (std_map.find(\"Germany\") == std_map.end() && ft_map.find(\"Germany\") == ft_map.end())" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "if (std_map.find(\"Germany\") == std_map.end() && ft_map.find(\"Germany\") == ft_map.end())" << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [15/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_MAP" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №7 Lookup" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** equal_range ***" REST << std::endl;
	{
		ft::map<int, std::string> ft_map;
		ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ft_map_pair;
		std::map<int, std::string> std_map;
		std::pair<std::map<int, std::string>::iterator, std::map<int, std::string>::iterator > std_map_pair;
		ft_map.insert(ft::make_pair(1, "one"));
		std_map.insert(std::make_pair(1, "one"));
		ft_map.insert(ft::make_pair(5, "five"));
		std_map.insert(std::make_pair(5, "five"));
		ft_map.insert(ft::make_pair(2, "two"));
		std_map.insert(std::make_pair(2, "two"));
		ft_map.insert(ft::make_pair(9, "nine"));
		std_map.insert(std::make_pair(9, "nine"));
		map_print(ft_map, 0);

		std::cout << "Enter: " << CYAN "map_pair = map.equal_range(2)" REST << std::endl;
		ft_map_pair = ft_map.equal_range(2);
		std_map_pair = std_map.equal_range(2);
		std::cout << "first " << ft_map_pair.first ->first  << " " << std_map_pair.first ->first  << std::endl;
		if (ft_map_pair.first->first == std_map_pair.first->first && ft_map_pair.second->second == std_map_pair.second->second) {
			std::cout << "if (ft_map_pair.first->first == std_map_pair.first->first && ft_map_pair.second->second == std_map_pair.second->second)" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "if (ft_map_pair.first->first == std_map_pair.first->first && ft_map_pair.second->second == std_map_pair.second->second)" << REST <<
			RED " KO :(" REST << std::endl;
		}


	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [16/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

int main(void) {
	// test_constructors();
	// test_assigns();
	// test_element_access();
	// test_iterators();
	// test_capacity();
	// test_modifiers();
	test_lookup();
	return 0;

}