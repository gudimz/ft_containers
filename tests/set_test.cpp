#include "../containers/set/set.hpp"
#include <set>

#define GREEN "\x1b[1;32m"
#define WHITE "\x1b[37m"
#define RED "\x1b[1;31m"
#define YEL "\x1b[1;33m"
#define MAG "\x1b[1;35m"
#define CYAN "\x1b[1;36m"
#define REST "\x1b[0m"
#define CLEAR "\e[1;1H\e[2J"


template<class T>
void set_print(const T& set, int num) {
	if (!num) {
		std::cout << CYAN "set<T>  " REST << "[ ";
	} else if (num == 1) {
		std::cout << CYAN "ft::set<T>  " REST << "[ ";
	} else {
		std::cout << YEL "std::set<T> " REST << "[ ";
	}
	for (typename T::const_iterator it = set.begin(); it != set.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "]" <<std::endl;
}

template<class Key>
void set_compare(const ft::set<Key>& ft_set, const std::set<Key>& std_set) {
	std::cout << std::endl << MAG "compare: " REST << std::endl;
	set_print(ft_set, 1);
	set_print(std_set, 2);
	bool flag = true;
	typename ft::set<Key>::const_iterator ft_it = ft_set.begin();
	typename std::set<Key>::const_iterator std_it = std_set.begin();
	for (; std_it != std_set.end() && ft_it != ft_set.end(); ++std_it, ++ft_it) {
		if (*std_it != *ft_it) {
			std::cout << RED "KO :(" REST << std::endl;
			flag = false;
		}
	}
	if (flag) {
		std::cout << GREEN "OK :)" REST << std::endl;
	}
	//size
	if (std_set.size() == ft_set.size()) {
		std::cout << "size:  " GREEN << std_set.size() << "==" << ft_set.size() << REST <<
		GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "size:  " RED << std_set.size() << "!=" << ft_set.size() << REST <<
		RED " KO :(" REST << std::endl;
	}
	// first value
	if (ft_set.size() && std_set.size()) {
		if (*std_set.begin() == *ft_set.begin()) {
			std::cout << "first element: " GREEN << *std_set.begin() << "==" << *ft_set.begin() << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "first element: " RED << *std_set.begin()<< "!=" << *ft_set.begin() << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	// last element
	if (ft_set.size() && std_set.size()) {
		if (*(--std_set.end()) == *(--ft_set.end())) {
			std::cout << "last element:  " GREEN << *(--std_set.end()) << "==" << *(--ft_set.end()) << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "last element:  " RED << *(--std_set.end()) << "!=" << *(--ft_set.end()) << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	std::cout << "=================================================================================="
	<< std::endl << std::endl;
}

void test_constructors(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №1 Constructors" REST << " ===" << std::endl;

	std::cout << GREEN "*** Default ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		std::cout << "Enter: " << CYAN "set<int> set" REST << std::endl;
		set_compare(ft_set, std_set);
	}
	std::cout << GREEN "*** Default with alloc***" REST << std::endl;
	{
		std::allocator<int>  alloc;
		ft::set<int> ft_set(ft::less<int>(), alloc);
		std::set<int> std_set(std::less<int>(), alloc);
		std::cout << "Enter: " << CYAN "set<int> set(less<int>(), alloc)" REST << std::endl;
		set_compare(ft_set, std_set);
	}

	std::cout << GREEN "*** Range ***" REST << std::endl;
	{
		ft::set<int> ft_set_fill;
		std::set<int> std_set_fill;
		ft_set_fill.insert(1);
		std_set_fill.insert(1);
		// double key
		ft_set_fill.insert(1);
		std_set_fill.insert(1);
		ft_set_fill.insert(7);
		std_set_fill.insert(7);
		ft_set_fill.insert(3);
		std_set_fill.insert(3);
		ft_set_fill.insert(42);
		std_set_fill.insert(42);
		ft_set_fill.insert(10);
		std_set_fill.insert(10);
		ft_set_fill.insert(4);
		std_set_fill.insert(4);
		ft_set_fill.insert(21);
		std_set_fill.insert(21);
		set_print(ft_set_fill, 0);
		std::cout << "Enter: " << CYAN "set<int> set(set_fill.begin(), set_fill.end())" REST << std::endl;
		ft::set<int> ft_set_range(ft_set_fill.begin(), ft_set_fill.end());
		std::set<int> std_set_range(std_set_fill.begin(), std_set_fill.end());

		set_compare(ft_set_range, std_set_range);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [1/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №1 Constructors" REST << " ===" << std::endl;
	std::cout << GREEN "*** Copy Constructors ***" REST << std::endl;
	{
		std::cout << std::endl << GREEN "*** Intenger ***" REST << std::endl;
		{
			ft::set<int> ft_set_copy;
			std::set<int> std_set_copy;
			for (size_t i = 1; i < 8; ++i) {
				ft_set_copy.insert(i);
				std_set_copy.insert(i);
			}
			std::cout << "set_copy ";
			set_print(ft_set_copy, 0);
			std::cout << "Enter: " << CYAN "set<int> set(set_copy)" REST << std::endl;
			ft::set<int> ft_set(ft_set_copy);
			std::set<int> std_set(std_set_copy);
			set_compare(ft_set, std_set);

		}
		std::cout << std::endl << GREEN "*** String ***" REST << std::endl;
		{
			ft::set<std::string> ft_set_copy;
			std::set<std::string> std_set_copy;
			ft_set_copy.insert("Russia");
			std_set_copy.insert("Russia");
			// double key
			ft_set_copy.insert("Russia");
			std_set_copy.insert("Russia");
			ft_set_copy.insert("USA");
			std_set_copy.insert("USA");
			ft_set_copy.insert("France");
			std_set_copy.insert("France");
			ft_set_copy.insert("England");
			std_set_copy.insert("England");
			ft_set_copy.insert("Spain");
			std_set_copy.insert("Spain");
			ft_set_copy.insert("Japan");
			std_set_copy.insert("Japan");
			ft_set_copy.insert("Canada");
			std_set_copy.insert("Canada");

			std::cout << "set_copy ";
			set_print(ft_set_copy, 0);
			std::cout << "Enter: " << CYAN "set<std::string> set(set_copy)" REST << std::endl;
			ft::set<std::string> ft_set(ft_set_copy);
			std::set<std::string> std_set(std_set_copy);
			set_compare(ft_set, std_set);

		}
	}

	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [2/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

}

void test_assigns(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №2 Assigns" REST << " ===" << std::endl;

	std::cout << GREEN "*** Operator= ***" REST << std::endl;
	{
		ft::set<int> ft_set_copy;
		std::set<int> std_set_copy;
		for (size_t i = 1; i < 8; ++i) {
			ft_set_copy.insert(i);
			std_set_copy.insert(i);
		}
		std::cout << "set_copy ";
		set_print(ft_set_copy, 0);
		std::cout << "Enter: " << CYAN "set<int> set = set_copy" REST << std::endl;
		ft::set<int> ft_set(ft_set_copy);
		std::set<int> std_set(std_set_copy);
		set_compare(ft_set, std_set);
	}

	std::cout << GREEN "*** Get allocator ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		for (size_t i = 1; i < 8; ++i) {
			ft_set.insert(i);
			std_set.insert(i);
		}
		std::cout << "set<int> ";
		set_print(ft_set, 0);
		if (std_set.get_allocator() == ft_set.get_allocator()) {
			std::cout << "std_set.get_allocator() == ft_set.get_allocator()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_vec.get_allocator() != ft_vec.get_allocator()" << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [3/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_iterators(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №3 Iterators" REST << " ===" << std::endl;

	std::cout << std::endl << GREEN "*** empty set ***" REST << std::endl;
	ft::set<int> ft_set;
	ft::set<int> const ft_set_const;
	std::cout << "Enter: " << CYAN "set<int> ft_set;" REST << std::endl;
	if (ft_set.begin() == ft_set.end()) {
		std::cout << "ft_set.begin() == ft_set.end()" << std::endl;
		std::cout << GREEN "OK :)" REST << std::endl;
	} else {
		std::cout << "ft_set.begin() != ft_set.end()" << std::endl;
		std::cout << RED "KO :(" REST << std::endl;
	}

	if (ft_set.rbegin() == ft_set.rend()) {
		std::cout << "ft_set.rbegin() == ft_set.rend()" << std::endl;
		std::cout << GREEN "OK :)" REST << std::endl;
	} else {
		std::cout << "ft_set.rbegin() != ft_set.rend()" << std::endl;
		std::cout << RED "KO :(" REST << std::endl;
	}
	std::cout << "=================================================================================="
	<< std::endl << std::endl;
	std::cout << "Enter: " << CYAN "set<int> const ft_set_const;" REST << std::endl;
	if (ft_set_const.begin() == ft_set_const.end()) {
		std::cout << "ft_set_const.begin() == ft_set_const.end()" << std::endl;
		std::cout << GREEN "OK :)" REST << std::endl;
	} else {
		std::cout << "ft_set_const.begin() != ft_set_const.end()" << std::endl;
		std::cout << RED "KO :(" REST << std::endl;
	}

	if (ft_set_const.rbegin() == ft_set_const.rend()) {
		std::cout << "ft_set_const.rbegin() == ft_set_const.rend()" << std::endl;
		std::cout << GREEN "OK :)" REST << std::endl;
	} else {
		std::cout << "ft_set_const.rbegin() != ft_set_const.rend()" << std::endl;
		std::cout << RED "KO :(" REST << std::endl;
	}
	std::cout << std::endl << GREEN "*** fill set, iterator ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		for (size_t i = 1; i < 8; ++i) {
			ft_set.insert(i);
			std_set.insert(i);
		}
		set_print(ft_set, 0);

		if (*ft_set.begin() == *std_set.begin()) {
			std::cout << "*ft_set.begin() == *std_set.begin()" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "*ft_set.begin() != *std_set.begin()" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}

		if (*ft_set.rbegin() == *std_set.rbegin()) {
			std::cout << "*ft_set.rbegin()== *std_set.rbegin()" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "*ft_set.rbegin() != *std_set.rbegin()" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << std::endl << GREEN "*** fill set, const iterator ***" REST << std::endl;

		ft::set<int> const ft_set_const(ft_set);
		std::set<int> const std_set_const(std_set);
		set_print(ft_set, 0);
		if (*ft_set_const.begin() == *std_set_const.begin()) {
			std::cout << "*ft_set_const.begin() == *std_set_const()" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "*ft_set_const.begin() != *std_set_const.begin()" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}

		if (*ft_set_const.rbegin() == *std_set_const.rbegin()) {
			std::cout << "*ft_set_const.rbegin() == *std_set_const.rbegin()" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "*ft_set_const.rbegin() != *std_set_const.rbegin()" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [4/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_set" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №3 Iterators" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** arithmetic with iterators ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		for (size_t i = 1; i < 8; ++i) {
			ft_set.insert(i);
			std_set.insert(i);
		}
		set_print(ft_set, 0);
		std::cout << RED "=== for iterator ===" REST << std::endl;
		ft::set<int>::iterator ft_iter = ft_set.begin();
		std::set<int>::iterator std_iter = std_set.begin();
		std::cout << "Enter: " << CYAN "++iter" REST << std::endl;
		++ft_iter;
		++std_iter;
		if (*ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "iter++" REST << std::endl;
		ft_iter++;
		std_iter++;
		if (*ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--iter" REST << std::endl;
		--ft_iter;
		--std_iter;
		if (*ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "iter--" REST << std::endl;
		ft_iter--;
		std_iter--;
		if (*ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;

		std::cout << RED "=== for reverse_iterator ===" REST << std::endl;
		ft::set<int>::reverse_iterator ft_rev_iter = ft_set.rbegin();
		std::set<int>::reverse_iterator std_rev_iter = std_set.rbegin();
		std::cout << "Enter: " << CYAN "++rev_iter" REST << std::endl;
		++ft_rev_iter;
		++std_rev_iter;
		if (*ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rev_iter++" REST << std::endl;
		ft_rev_iter++;
		std_rev_iter++;
		if (*ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--rev_iter" REST << std::endl;
		--ft_rev_iter;
		--std_rev_iter;
		if (*ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rev_iter--" REST << std::endl;
		ft_rev_iter--;
		std_rev_iter--;
		if (*ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [5/18]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;

		std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
		std::cout << "=== " << MAG "TEST №3 Iterators" REST << " ===" << std::endl;

		std::cout << RED "=== for const_iterator ===" REST << std::endl;
		ft::set<int>::const_iterator ft_const_iter = ft_set.begin();
		std::set<int>::const_iterator std_const_iter = std_set.begin();
		std::cout << "Enter: " << CYAN "++const_iter" REST << std::endl;
		++ft_const_iter;
		++std_const_iter;
		if (*ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_iter++" REST << std::endl;
		ft_const_iter++;
		std_const_iter++;
		if (*ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--const_iter" REST << std::endl;
		--ft_const_iter;
		--std_const_iter;
		if (*ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_iter--" REST << std::endl;
		ft_const_iter--;
		std_const_iter--;
		if (*ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << RED "=== for const_reverse_iterator ===" REST << std::endl;
		ft::set<int>::const_reverse_iterator ft_const_rev_iter = ft_set.rbegin();
		std::set<int>::const_reverse_iterator std_const_rev_iter = std_set.rbegin();
		std::cout << "Enter: " << CYAN "++const_rev_iter" REST << std::endl;
		++ft_const_rev_iter;
		++std_const_rev_iter;
		if (*ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_rev_iter++" REST << std::endl;
		ft_const_rev_iter++;
		std_const_rev_iter++;
		if (*ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--const_rev_iter" REST << std::endl;
		--ft_const_rev_iter;
		--std_const_rev_iter;
		if (*ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_rev_iter--" REST << std::endl;
		ft_const_rev_iter--;
		std_const_rev_iter--;
		if (*ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [6/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_capacity(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №4 Capacity" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** empty ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		std::cout << "Enter: " << CYAN "set<int> set" REST << std::endl;
		if (std_set.empty() == ft_set.empty()) {
			std::cout << "std_set.empty() == ft_set.empty()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_set.empty() != ft_set.empty()" << REST <<
			RED " KO :(" REST << std::endl;
		}
		set_compare(ft_set, std_set);
	}
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		for (size_t i = 1; i < 8; ++i) {
			ft_set.insert(i);
			std_set.insert(i);
		}
		set_print(ft_set, 0);
		if (std_set.empty() == ft_set.empty()) {
			std::cout << "std_set.empty() == ft_set.empty()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_set.empty() != ft_set.empty()" << REST <<
			RED " KO :(" REST << std::endl;
		}
		set_compare(ft_set, std_set);
	}
	std::cout << std::endl << GREEN "*** max_size ***" REST << std::endl;
	{
		ft::set<std::string> ft_set;
		std::set<std::string> std_set;
		ft_set.insert("Russia");
		std_set.insert("Russia");
		ft_set.insert("USA");
		std_set.insert("USA");
		ft_set.insert("France");
		std_set.insert("France");
		ft_set.insert("England");
		std_set.insert("England");
		set_print(ft_set, 0);
		if (std_set.max_size() == ft_set.max_size()) {
			std::cout << "std_set.max_size() == ft_set.max_size()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_set.max_size() != ft_set.max_size()" << REST <<
			RED " KO :(" REST << std::endl;
		}
		set_compare(ft_set, std_set);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [7/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_modifiers(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №5 Modifiers" REST << " ===" << std::endl;

	std::cout << std::endl << GREEN "*** clear ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		for (size_t i = 1; i < 8; ++i) {
			ft_set.insert(i);
			std_set.insert(i);
		}
		set_print(ft_set, 0);
		std::cout << "Enter: " << CYAN "set.clear()" REST << std::endl;
		ft_set.clear();
		std_set.clear();
		set_compare(ft_set, std_set);
		std::cout << "Enter: " << CYAN "set.insert(21)" REST << std::endl;
		ft_set.insert(21);
		std_set.insert(21);
		set_compare(ft_set, std_set);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [8/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №5 Modifiers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** insert single element ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;

		std::cout << "Enter: " << CYAN "set.insert(21)" REST << std::endl;
		ft_set.insert(21);
		std_set.insert(21);
		std::cout << "Enter: " << CYAN "set.insert(-12)" REST << std::endl;
		ft_set.insert(-12);
		std_set.insert(-12);
		std::cout << "Enter: " << CYAN "set.insert(-12)" REST << std::endl;
		ft_set.insert(-12);
		std_set.insert(-12);
		std::cout << "Enter: " << CYAN "set.insert(0)" REST << std::endl;
		ft_set.insert(0);
		std_set.insert(0);
		std::cout << "Enter: " << CYAN "set.insert(7)" REST << std::endl;
		ft_set.insert(7);
		std_set.insert(7);
		set_compare(ft_set, std_set);
	}
	std::cout << std::endl << GREEN "*** insert with hint ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;

		ft_set.insert(21);
		std_set.insert(21);
		ft_set.insert(-12);
		std_set.insert(-12);
		ft_set.insert(-12);
		std_set.insert(-12);
		ft_set.insert(0);
		std_set.insert(0);
		ft_set.insert(7);
		std_set.insert(7);
		set_print(ft_set, 0);

		std::cout << "Enter: " << CYAN "set<int>::iterator hint = set.find(21)" REST << std::endl;
		ft::set<int>::iterator ft_hint = ft_set.find(0);
		std::set<int>::iterator std_hint = std_set.find(0);

		std::cout << "Enter: " << CYAN "set.insert(hint, 6)" REST << std::endl;
		ft_set.insert(ft_hint, 6);
		std_set.insert(std_hint, 6);
		set_compare(ft_set, std_set);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [9/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №5 Modifiers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** insert with range ***" REST << std::endl;
	{
		ft::set<int> ft_set_copy;
		std::set<int> std_set_copy;
		std::cout << "set_copy ";
		set_print(ft_set_copy, 0);
		ft::set<int> ft_set;
		std::set<int> std_set;
		std::cout << "Enter: " << CYAN "set.insert(set_copy.begin(), set_copy.end())" REST << std::endl;
		ft_set.insert(ft_set_copy.begin(), ft_set_copy.end());
		std_set.insert(std_set_copy.begin(), std_set_copy.end());
		set_compare(ft_set, std_set);

		ft_set_copy.insert(21);
		std_set_copy.insert(21);
		ft_set_copy.insert(-16);
		std_set_copy.insert(-16);
		ft_set_copy.insert(7);
		std_set_copy.insert(7);
		ft_set_copy.insert(18);
		std_set_copy.insert(18);
		std::cout << "set_copy ";
		set_print(ft_set_copy, 0);

		std::cout << "Enter: " << CYAN "set.insert(set_copy.begin(), set_copy.end())" REST << std::endl;
		ft_set.insert(ft_set_copy.begin(), ft_set_copy.end());
		std_set.insert(std_set_copy.begin(), std_set_copy.end());
		set_compare(ft_set, std_set);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [10/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №5 Modifiers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** erase key value ***" REST << std::endl;
	{
		ft::set<std::string> ft_set;
		std::set<std::string> std_set;
		ft_set.insert("Russia");
		std_set.insert("Russia");
		ft_set.insert("USA");
		std_set.insert("USA");
		ft_set.insert("France");
		std_set.insert("France");
		ft_set.insert("England");
		std_set.insert("England");
		ft_set.insert("Spain");
		std_set.insert("Spain");
		set_print(ft_set, 0);

		std::cout << "Enter: " << CYAN "set.erase(\"England\")" REST << std::endl;
		ft_set.erase("England");
		std_set.erase("England");

		std::cout << "Enter: " << CYAN "set.erase(\"Germany\")" REST << std::endl;
		ft_set.erase("Germany");
		std_set.erase("Germany");
		set_compare(ft_set, std_set);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [11/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №5 Modifiers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** swap ***" REST << std::endl;
	{
		ft::set<int> ft_set_first;
		ft::set<int> ft_set_second;
		ft_set_first.insert(2);
		ft_set_first.insert(1);
		ft_set_first.insert(7);
		ft_set_first.insert(10);
		std::cout << "set_first ";
		set_print(ft_set_first, 1);
		ft_set_second.insert(702);
		ft_set_second.insert(701);
		ft_set_second.insert(707);
		ft_set_second.insert(710);
		std::cout << "set_second ";
		set_print(ft_set_second, 1);

		std::set<int> std_set_first;
		std::set<int> std_set_second;
		std_set_first.insert(2);
		std_set_first.insert(1);
		std_set_first.insert(7);
		std_set_first.insert(10);
		std::cout << "set_first ";
		set_print(std_set_first, 2);
		std_set_second.insert(702);
		std_set_second.insert(701);
		std_set_second.insert(707);
		std_set_second.insert(710);
		std::cout << "set_second ";
		set_print(std_set_second, 2);

		std::cout << "Enter: " << CYAN "set_first.swap(set_second)" REST << std::endl;
		ft_set_first.swap(ft_set_second);
		std_set_first.swap(std_set_second);
		std::cout << "Enter: " << CYAN "set_compare(ft_set_first, std_set_first);" REST << std::endl;
		set_compare(ft_set_first, std_set_first);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [12/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_lookup() {
	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №6 Lookup" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** count ***" REST << std::endl;
	{
		ft::set<std::string> ft_set;
		std::set<std::string> std_set;
		ft_set.insert("Moscow");
		std_set.insert("Moscow");
		ft_set.insert("Washington");
		std_set.insert("Washington");
		ft_set.insert("Paris");
		std_set.insert("Paris");
		set_print(ft_set, 0);

		if (std_set.count("Washington") == ft_set.count("Washington")) {
			std::cout << "std_set.count(\"Washington\") == ft_set.count(\"Washington\")" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_set.count(\"Washington\") != ft_set.count(\"Washington\")" << REST <<
			RED " KO :(" REST << std::endl;
		}

		if (std_set.count("London") == ft_set.count("London")) {
			std::cout << "std_set.count(\"London\") == ft_set.count(\"London\")" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_set.count(\"London\") != ft_set.count(\"London\")" << REST <<
			RED " KO :(" REST << std::endl;
		}
	}

	std::cout << std::endl << GREEN "*** find key ***" REST << std::endl;
	{
		ft::set<std::string> ft_set;
		std::set<std::string> std_set;
		ft_set.insert("Russia");
		std_set.insert("Russia");
		ft_set.insert("USA");
		std_set.insert("USA");
		ft_set.insert("France");
		std_set.insert("France");
		set_print(ft_set, 0);

		if (*std_set.find("USA")  == *ft_set.find("USA")) {
			std::cout << "*std_set.find(\"USA\") == *ft_set.find(\"USA\")" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "*std_set.find(\"USA\") != *ft_set.find(\"USA\")" << REST <<
			RED " KO :(" REST << std::endl;
		}
		if ((std_set.find("Germany") == std_set.end() && ft_set.find("Germany") == ft_set.end())) {
			std::cout << "if (std_set.find(\"Germany\") == std_set.end() && ft_set.find(\"Germany\") == ft_set.end())" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "if (std_set.find(\"Germany\") == std_set.end() && ft_set.find(\"Germany\") == ft_set.end())" << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [13/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №6 Lookup" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** equal_range ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> ft_set_pair;
		std::set<int> std_set;
		std::pair<std::set<int>::iterator, std::set<int>::iterator > std_set_pair;
		ft_set.insert(1);
		std_set.insert(1);
		ft_set.insert(5);
		std_set.insert(5);
		ft_set.insert(2);
		std_set.insert(2);
		ft_set.insert(9);
		std_set.insert(9);
		set_print(ft_set, 0);

		std::cout << "Enter: " << CYAN "set_pair = set.equal_range(2)" REST << std::endl;
		ft_set_pair = ft_set.equal_range(2);
		std_set_pair = std_set.equal_range(2);
		std::cout << CYAN "ft_set_pair: " REST << "first(" << *ft_set_pair.first << ")";
		std::cout << YEL " and " REST << "second(" << *ft_set_pair.second << ")"  << std::endl;
		std::cout << CYAN "std_set_pair: " REST << "first(" << *std_set_pair.first << ")";
		std::cout << YEL " and " REST << "second(" << *std_set_pair.second << ")"  << std::endl;
		if (*ft_set_pair.first == *std_set_pair.first && *ft_set_pair.second == *std_set_pair.second) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}

		std::cout << "Enter: " << CYAN "set_pair = set.equal_range(7)" REST << std::endl;
		ft_set_pair = ft_set.equal_range(7);
		std_set_pair = std_set.equal_range(7);
		std::cout << CYAN "ft_set_pair: " REST << "first(" << *ft_set_pair.first << ")";
		std::cout << YEL " and " REST << "second(" << *ft_set_pair.second << ")"  << std::endl;
		std::cout << CYAN "std_set_pair: " REST << "first(" << *std_set_pair.first << ")";
		std::cout << YEL " and " REST << "second(" << *std_set_pair.second << ")"  << std::endl;
		if (*ft_set_pair.first == *std_set_pair.first && *ft_set_pair.second == *std_set_pair.second) {
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << RED " KO :(" REST << std::endl;
		}

		std::cout << "Enter: " << CYAN "set_pair = set.equal_range(9)" REST << std::endl;
		ft_set_pair = ft_set.equal_range(9);
		std_set_pair = std_set.equal_range(9);
		std::cout << CYAN "ft_set_pair: " REST << "first(" << *ft_set_pair.first << ")";
		std::cout << YEL " and " REST << "second(ft_set.end())" << std::endl;
		std::cout << CYAN "std_set_pair: " REST << "first(" << *std_set_pair.first << ")";
		std::cout << YEL " and " REST << "second(std_set.end())" << std::endl;
		if (ft_set_pair.second == ft_set.end() && std_set_pair.second == std_set.end()) {
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << RED " KO :(" REST << std::endl;
		}
	}

	std::cout << std::endl << GREEN "*** lower_bound ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		ft_set.insert(1);
		std_set.insert(1);
		ft_set.insert(5);
		std_set.insert(5);
		ft_set.insert(2);
		std_set.insert(2);
		ft_set.insert(9);
		std_set.insert(9);
		ft_set.insert(7);
		std_set.insert(7);
		ft_set.insert(10);
		std_set.insert(10);
		set_print(ft_set, 0);

		ft_set.lower_bound(5);
		std_set.lower_bound(5);
		std::cout << "Enter: " << CYAN "set.lower_bound(5)" REST << std::endl;
		if (*ft_set.lower_bound(5) == *std_set.lower_bound(5)) {
			std::cout << *ft_set.lower_bound(5) << " == " << *std_set.lower_bound(5) << std::endl;
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << *ft_set.lower_bound(5) << " != " << *std_set.lower_bound(5) << std::endl;
			std::cout << RED " KO :(" REST << std::endl;
		}

		ft_set.lower_bound(-10);
		std_set.lower_bound(-10);
		std::cout << "Enter: " << CYAN "set.lower_bound(-10)" REST << std::endl;
		if (*ft_set.lower_bound(-10) == *std_set.lower_bound(-10)) {
			std::cout << *ft_set.lower_bound(-10) << " == " << *std_set.lower_bound(-10) << std::endl;
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << *ft_set.lower_bound(-10) << " != " << *std_set.lower_bound(-10) << std::endl;
			std::cout << RED " KO :(" REST << std::endl;
		}

		ft_set.lower_bound(9);
		std_set.lower_bound(9);
		std::cout << "Enter: " << CYAN "set.lower_bound(9)" REST << std::endl;
		if (*ft_set.lower_bound(9) == *std_set.lower_bound(9)) {
			std::cout << *ft_set.lower_bound(9) << " == " << *std_set.lower_bound(9) << std::endl;
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << *ft_set.lower_bound(9) << " != " << *std_set.lower_bound(9) << std::endl;
			std::cout << RED " KO :(" REST << std::endl;
		}
	}

	std::cout << std::endl << GREEN "*** upper_bound ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		ft_set.insert(1);
		std_set.insert(1);
		ft_set.insert(5);
		std_set.insert(5);
		ft_set.insert(2);
		std_set.insert(2);
		ft_set.insert(9);
		std_set.insert(9);
		ft_set.insert(7);
		std_set.insert(7);
		ft_set.insert(10);
		std_set.insert(10);
		set_print(ft_set, 0);

		ft_set.upper_bound(5);
		std_set.upper_bound(5);
		std::cout << "Enter: " << CYAN "set.upper_bound(5)" REST << std::endl;
		if (*ft_set.upper_bound(5) == *std_set.upper_bound(5)) {
			std::cout << *ft_set.upper_bound(5) << " == " << *std_set.upper_bound(5) << std::endl;
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << *ft_set.upper_bound(5) << " != " << *std_set.upper_bound(5) << std::endl;
			std::cout << RED " KO :(" REST << std::endl;
		}

		ft_set.upper_bound(-10);
		std_set.upper_bound(-10);
		std::cout << "Enter: " << CYAN "set.upper_bound(-10)" REST << std::endl;
		if (*ft_set.upper_bound(-10) == *std_set.upper_bound(-10)) {
			std::cout << *ft_set.upper_bound(-10) << " == " << *std_set.upper_bound(-10) << std::endl;
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << *ft_set.upper_bound(-10) << " != " << *std_set.upper_bound(-10) << std::endl;
			std::cout << RED " KO :(" REST << std::endl;
		}

		ft_set.upper_bound(9);
		std_set.upper_bound(9);
		std::cout << "Enter: " << CYAN "set.lower_bound(9)" REST << std::endl;
		if (*ft_set.upper_bound(9) == *std_set.upper_bound(9)) {
			std::cout << *ft_set.upper_bound(9) << " == " << *std_set.upper_bound(9) << std::endl;
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << *ft_set.upper_bound(9) << " != " << *std_set.upper_bound(9) << std::endl;
			std::cout << RED " KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [14/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_observers() {
	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №7 Observers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** key_comp ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		ft_set.insert(1);
		std_set.insert(1);
		ft_set.insert(5);
		std_set.insert(5);
		ft_set.insert(2);
		std_set.insert(2);
		ft_set.insert(9);
		std_set.insert(9);
		ft_set.insert(7);
		std_set.insert(7);
		ft_set.insert(10);
		std_set.insert(10);
		set_print(ft_set, 0);

		std::cout << "Enter: " << CYAN "set<int>::key_compare comp = set.key_comp()" REST << std::endl << std::endl;
		ft::set<int>::key_compare ft_comp = ft_set.key_comp();
		std::set<int>::key_compare std_comp = std_set.key_comp();

		std::cout << "Enter: " << CYAN "comp(*set.begin(), *set.rbegin())" REST << std::endl;
		if (ft_comp(*ft_set.begin(), *ft_set.rbegin()) == std_comp(*std_set.begin(), *std_set.rbegin())) {
			std::cout << ft_comp(*ft_set.begin(), *ft_set.rbegin()) << " == "
			<< std_comp(*std_set.begin(), *std_set.rbegin()) << std::endl;
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << ft_comp(*ft_set.begin(), *ft_set.rbegin()) << " != "
			<< std_comp(*std_set.begin(), *std_set.rbegin()) << std::endl;
			std::cout << RED " KO :(" REST << std::endl;
		}

		std::cout << "Enter: " << CYAN "comp(*set.rbegin(), *set.begin())" REST << std::endl;
		if (ft_comp(*ft_set.rbegin(), *ft_set.begin()) == std_comp(*std_set.rbegin(), *std_set.begin())) {
			std::cout << ft_comp(*ft_set.rbegin(), *ft_set.begin()) << " == "
			<< std_comp(*std_set.rbegin(), *std_set.begin()) << std::endl;
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << ft_comp(*ft_set.rbegin(), *ft_set.begin()) << " != "
			<< std_comp(*std_set.rbegin(), *std_set.begin()) << std::endl;
			std::cout << RED " KO :(" REST << std::endl;
		}
	}

	std::cout << std::endl << GREEN "*** value_comp ***" REST << std::endl;
	{
		ft::set<int> ft_set;
		std::set<int> std_set;
		ft_set.insert(1);
		std_set.insert(1);
		ft_set.insert(5);
		std_set.insert(5);
		ft_set.insert(2);
		std_set.insert(2);
		ft_set.insert(9);
		std_set.insert(9);
		ft_set.insert(7);
		std_set.insert(7);
		ft_set.insert(10);
		std_set.insert(10);
		set_print(ft_set, 0);

		std::cout << "Enter: " << CYAN "set.value_comp()(*set.begin(), *set.rbegin())" REST << std::endl;
		if (ft_set.value_comp()(*ft_set.begin(), *ft_set.rbegin()) == std_set.value_comp()(*std_set.begin(), *std_set.rbegin())) {
			std::cout << ft_set.value_comp()(*ft_set.begin(), *ft_set.rbegin()) << " == "
			<< std_set.value_comp()(*std_set.begin(), *std_set.rbegin()) << std::endl;
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << ft_set.value_comp()(*ft_set.begin(), *ft_set.rbegin()) << " != "
			<< std_set.value_comp()(*std_set.begin(), *std_set.rbegin()) << std::endl;
			std::cout << RED " KO :(" REST << std::endl;
		}

		std::cout << "Enter: " << CYAN "set.value_comp()(*set.rbegin(), *set.begin())" REST << std::endl;
		if (ft_set.value_comp()(*ft_set.rbegin(), *ft_set.begin()) == std_set.value_comp()(*std_set.rbegin(), *std_set.begin())) {
			std::cout << ft_set.value_comp()(*ft_set.rbegin(), *ft_set.begin()) << " == "
			<< std_set.value_comp()(*std_set.rbegin(), *std_set.begin()) << std::endl;
			std::cout << GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << ft_set.value_comp()(*ft_set.rbegin(), *ft_set.begin()) << " != "
			<< std_set.value_comp()(*std_set.rbegin(), *std_set.begin()) << std::endl;
			std::cout << RED " KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [15/18]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_non_member() {
	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №8 Non members" REST << " ===" << std::endl;
	{
		ft::set<int> ft_lhs;
		ft::set<int> ft_rhs;
		std::set<int> std_lhs;
		std::set<int> std_rhs;
		ft_lhs.insert(1);
		ft_rhs.insert(2);
		std_lhs.insert(1);
		std_rhs.insert(2);
		ft_lhs.insert(5);
		ft_rhs.insert(5);
		std_lhs.insert(5);
		std_rhs.insert(5);
		ft_lhs.insert(10);
		ft_rhs.insert(7);
		std_lhs.insert(10);
		std_rhs.insert(7);
		ft_lhs.insert(3);
		ft_rhs.insert(9);
		std_lhs.insert(3);
		std_rhs.insert(9);
		ft_lhs.insert(4);
		ft_rhs.insert(6);
		std_lhs.insert(4);
		std_rhs.insert(6);
		std::cout << CYAN "lhs ";
		set_print(ft_lhs, 0);
		std::cout << CYAN "rhs ";
		set_print(ft_rhs, 0);

		std::cout << "Enter: " << CYAN "!(lhs == rhs)" << std::endl;
		if (!(ft_lhs == ft_rhs) && !(std_lhs == std_rhs)) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "lhs != rhs" << std::endl;
		if (ft_lhs != ft_rhs && std_lhs != std_rhs) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "lhs < rhs" << std::endl;
		if (ft_lhs < ft_rhs && std_lhs < std_rhs) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "lhs <= rhs" << std::endl;
		if (ft_lhs <= ft_rhs && std_lhs <= std_rhs) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "!(lhs > rhs)" << std::endl;
		if (!(ft_lhs > ft_rhs) && !(std_lhs > std_rhs)) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "!(lhs >= rhs)" << std::endl;
		if (!(ft_lhs >= ft_rhs) && !(std_lhs >= std_rhs)) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;

		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [16/18]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;
	}

	std::cout << std::endl << "*** " << CYAN "TEST FT_SET" REST << " ***" << std::endl << std::endl;
	std::cout << std::endl << GREEN "*** swap(non member) ***" REST << std::endl;
	{
		ft::set<int> ft_set_first;
		ft::set<int> ft_set_second;
		ft_set_first.insert(1);
		ft_set_first.insert(5);
		ft_set_first.insert(7);
		ft_set_first.insert(9);
		set_print(ft_set_first, 1);
		ft_set_second.insert(708);
		ft_set_second.insert(715);
		ft_set_second.insert(777);
		ft_set_second.insert(742);
		set_print(ft_set_second, 1);

		std::set<int> std_set_first;
		std::set<int> std_set_second;
		std_set_first.insert(1);
		std_set_first.insert(5);
		std_set_first.insert(7);
		std_set_first.insert(9);
		set_print(std_set_first, 2);
		std_set_second.insert(708);
		std_set_second.insert(715);
		std_set_second.insert(777);
		std_set_second.insert(742);
		set_print(std_set_second, 2);

		std::cout << "Enter: " << CYAN "set_first.swap(set_second)" REST << std::endl;
		swap(ft_set_first, ft_set_second);
		swap(std_set_first, std_set_second);

		set_compare(ft_set_first, std_set_first);
		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [17/18]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;
	}
}

int main(void) {
	test_constructors();
	test_assigns();
	test_iterators();
	test_capacity();
	test_modifiers();
	test_lookup();
	test_observers();
	test_non_member();
	return 0;

}