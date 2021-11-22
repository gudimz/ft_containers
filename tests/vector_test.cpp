#include "../containers/vector.hpp"
#include <vector>
#include <iostream>

#define GREEN "\x1b[1;32m"
#define WHITE "\x1b[37m"
#define RED "\x1b[1;31m"
#define YEL "\x1b[1;33m"
#define MAG "\x1b[1;35m"
#define CYAN "\x1b[1;36m"
#define REST "\x1b[0m"
#define CLEAR "\e[1;1H\e[2J"

template<class T>
void vec_print(const T& vec, int num) {
	if (num == 1) {
		std::cout << CYAN "ft::vector<T>  " REST << "[ ";
	} else {
		std::cout << YEL "std::vector<T> " REST << "[ ";
	}
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << "]" <<std::endl;
}

template<class T>
void vec_compare(const ft::vector<T>& ft_vec, const std::vector<T>& std_vec) {
	std::cout << std::endl << MAG "compare: " REST << std::endl;
	vec_print(ft_vec, 1);
	vec_print(std_vec, 2);
	bool flag = true;
	for (size_t i = 0; i < std_vec.size() && i < ft_vec.size(); ++i) {
		if (std_vec[i] != ft_vec[i]) {
			std::cout << RED "KO :(" REST << std::endl;
			flag = false;
		}
	}
	if (flag) {
		std::cout << GREEN "OK :)" REST << std::endl;
	}
	//size
	if (std_vec.size() == ft_vec.size()) {
		std::cout << "size:  " GREEN << std_vec.size() << "==" << ft_vec.size() << REST <<
		GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "size:  " RED << std_vec.size() << "!=" << ft_vec.size() << REST <<
		RED " KO :(" REST << std::endl;
	}
	// front
	if (ft_vec.size()) {
		if (std_vec.front() == ft_vec.front()) {
			std::cout << "front: " GREEN << std_vec.front() << "==" << ft_vec.front() << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "front: " RED << std_vec.front() << "!=" << ft_vec.front() << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	//back
	if (ft_vec.size()) {
		if (std_vec.back() == ft_vec.back()) {
			std::cout << "back:  " GREEN << std_vec.back() << "==" << ft_vec.back() << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "back:  " RED << std_vec.back() << "!=" << ft_vec.back() << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	std::cout << "=================================================================================="
	<< std::endl << std::endl;
}

void test_constructors(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №1 Constructors" REST << " ===" << std::endl;

	std::cout << GREEN "*** Default ***" REST << std::endl;
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		std::cout << "Enter: " << CYAN "vector<int> vec" REST << std::endl;
		vec_compare(ft_vec, std_vec);
	}

	std::cout << GREEN "*** Fill ***" REST << std::endl;
	{
		ft::vector<int> ft_vec(10, 21);
		std::vector<int> std_vec(10,21);
		std::cout << "Enter: " << CYAN "vector<int> vec(10, 21)" REST << std::endl;
		vec_compare(ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec(0, 42);
		std::vector<int> std_vec(0,42);
		std::cout << "Enter: " << CYAN "vector<int> vec(0, 42)" REST << std::endl;
		vec_compare(ft_vec, std_vec);
	}

	{
		ft::vector<std::string> ft_vec(1, "school");
		std::vector<std::string> std_vec(1, "school");
		std::cout << "Enter: " << CYAN "vector<int> vec(1, \"school \")" REST << std::endl;
		ft_vec.push_back("21");
		std_vec.push_back("21");
		std::cout << "Enter: " << CYAN "vec.push_back(\"21\")" REST << std::endl;
		vec_compare(ft_vec, std_vec);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [1/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №1 Constructors" REST << " ===" << std::endl;
	std::cout << GREEN "*** Fill Range ***" REST << std::endl;
	{
		ft::vector<int> vec_fill;
		std::cout << "Enter: " << CYAN "vector<int> vec_fill" REST << std::endl;
		std::cout << "Enter: " << CYAN "vector<int> vec(vec_fill.begin(), vec_fill.end())" REST << std::endl;
		ft::vector<int> ft_vec_range(vec_fill.begin(), vec_fill.end());
		std::vector<int> std_vec_range(vec_fill.begin(), vec_fill.end());
		vec_compare(ft_vec_range, std_vec_range);
	}

	{
		ft::vector<int> vec_fill(10, 21);
		std::cout << "Enter: " << CYAN "vector<int> vec_fill(10, 21)" REST << std::endl;
		std::cout << "Enter: " << CYAN "vector<int> vec(vec_fill.begin(), vec_fill.end())" REST << std::endl;
		ft::vector<int> ft_vec_range(vec_fill.begin(), vec_fill.end());
		std::vector<int> std_vec_range(vec_fill.begin(), vec_fill.end());
		vec_compare(ft_vec_range, std_vec_range);
	}

	{
		ft::vector<int> vec_fill(0, 7);
		std::cout << "Enter: " << CYAN "vector<int> vec_fill(0, 7)" REST << std::endl;
		std::cout << "Enter: " << CYAN "vector<int> vec(vec_fill.begin(), vec_fill.end())" REST << std::endl;
		ft::vector<int> ft_vec_range(vec_fill.begin(), vec_fill.end());
		std::vector<int> std_vec_range(vec_fill.begin(), vec_fill.end());
		vec_compare(ft_vec_range, std_vec_range);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [2/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №1 Constructors" REST << " ===" << std::endl;
	std::cout << GREEN "*** Copy Constructors ***" REST << std::endl;
	{
		std::cout << std::endl << GREEN "*** Intenger ***" REST << std::endl;
		{
			std::cout << "Enter: " << CYAN "ft::vector<int> vec(10, 21)" REST << std::endl;
			ft::vector<int> vec(10, 21);
			vec_print(vec, 1);
			std::cout << "Enter: " << CYAN "ft::vector<int> vec_copy(vec)" REST << std::endl;
			ft::vector<int> vec_copy(vec);
			vec_print(vec_copy, 1);
			std::cout << "=================================================================================="
			<< std::endl << std::endl;
			std::cout << "Enter: " << CYAN "ft::vector<int> vec_copy_2 = vec" REST << std::endl;
			ft::vector<int> vec_copy_2 = vec;
			vec_print(vec_copy_2, 1);
		}
		std::cout << std::endl << GREEN "*** String ***" REST << std::endl;
		{
			std::cout << "Enter: " << CYAN "ft::vector<std::string> vec(3, \"string\")" REST << std::endl;
			ft::vector<std::string> vec(3, "string");
			vec_print(vec, 1);

			std::cout << "Enter: " << CYAN "ft::vector<std::string> vec_copy(vec)" REST << std::endl;
			ft::vector<std::string> vec_copy(vec);
			vec_print(vec_copy, 1);
			std::cout << "=================================================================================="
			<< std::endl << std::endl;
			std::cout << "Enter: " << CYAN "ft::vector<std::string> vec_copy_2 = vec;" REST << std::endl;
			ft::vector<std::string> vec_copy_2 = vec;
			vec_print(vec_copy_2, 1);
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [3/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_assigns(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №2 Assigns" REST << " ===" << std::endl;
	std::cout << GREEN "*** Assigment with counter ***" REST << std::endl;
	{
		std::cout << "Enter: " << CYAN "ft::vector<int> ft_vec(0, 21)" REST << std::endl;
		ft::vector<int> ft_vec(0, 21);
		vec_print(ft_vec, 1);

		std::cout << "Enter: " << CYAN "ft::vector<int> std_vec(0, 21)" REST << std::endl;
		std::vector<int> std_vec(0, 21);
		vec_print(std_vec, 2);

		std::cout << "Enter: " << CYAN "vec.assign(3, 21)" REST << std::endl;
		ft_vec.assign(3, 21);
		std_vec.assign(3, 21);
		vec_compare(ft_vec, std_vec);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [4/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << "=== " << MAG "TEST №2 Assigns" REST << " ===" << std::endl;
	std::cout << GREEN "*** Assigment with range ***" REST << std::endl;
	{
		std::vector<int> vec_fill;
		std::cout << "Enter: " << CYAN "ft::vector<int> vec_fill" REST << std::endl;

		ft::vector<int> ft_vec(5, 21);
		vec_print(ft_vec, 1);

		std::cout << "Enter: " << CYAN "vector<int> vec(5, 21)" REST << std::endl;
		std::vector<int> std_vec(5, 21);
		vec_print(std_vec, 2);

		ft_vec.assign(vec_fill.begin(), vec_fill.end());
		std_vec.assign(vec_fill.begin(), vec_fill.end());
		std::cout << "Enter: " << CYAN "vec.assign(vec.begin(), vec.end())" REST << std::endl;
		vec_compare(ft_vec, std_vec);
	}

	{
		std::vector<int> vec_fill(3, 7);
		std::cout << "Enter: " << CYAN "ft::vector<int> vec_fill(3, 7)" REST << std::endl;

		ft::vector<int> ft_vec(5, 21);
		vec_print(ft_vec, 1);

		std::cout << "Enter: " << CYAN "vector<int> vec(5, 21)" REST << std::endl;
		std::vector<int> std_vec(5, 21);
		vec_print(std_vec, 2);

		ft_vec.assign(vec_fill.begin(), vec_fill.end());
		std_vec.assign(vec_fill.begin(), vec_fill.end());
		std::cout << "Enter: " << CYAN "vec.assign(vec.begin(), vec.end())" REST << std::endl;
		vec_compare(ft_vec, std_vec);
	}

	{
		std::vector<int> vec_fill(10, 7);
		std::cout << "Enter: " << CYAN "ft::vector<int> vec_fill(10, 7)" REST << std::endl;

		ft::vector<int> ft_vec(5, 21);
		vec_print(ft_vec, 1);

		std::cout << "Enter: " << CYAN "vector<int> vec(5, 21)" REST << std::endl;
		std::vector<int> std_vec(5, 21);
		vec_print(std_vec, 2);

		ft_vec.assign(vec_fill.begin(), vec_fill.end());
		std_vec.assign(vec_fill.begin(), vec_fill.end());
		std::cout << "Enter: " << CYAN "vec.assign(vec.begin(), vec.end())" REST << std::endl;
		vec_compare(ft_vec, std_vec);
	}

	std::cout << GREEN "*** Get allocator ***" REST << std::endl;
	{
		ft::vector<int> ft_vec(0, 42);
		std::vector<int> std_vec(0,42);
		std::cout << "Enter: " << CYAN "vector<int> vec(7, 42)" REST << std::endl;
		if (std_vec.get_allocator() == ft_vec.get_allocator()) {
			std::cout << "std_vec.get_allocator() == ft_vec.get_allocator()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_vec.get_allocator() != ft_vec.get_allocator()" << REST <<
			RED " KO :(" REST << std::endl;
		}
	}

	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [5/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_element_access(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №3 Element Access" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** At ***" REST << std::endl;
	{
		ft::vector<int> vec;
		for (size_t i = 0; i < 7; ++i) {
		vec.push_back(i);
		}
		vec_print(vec, 1);

		vec.at(0) = 21;
		std::cout << "Enter: " << CYAN "vec.at(0) = 21" REST << std::endl;
		vec_print(vec, 1);
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		try {
			std::cout << "Enter: " << CYAN "vec.at(42)" REST << std::endl;
			vec.at(42);
		} catch (const std::exception& e) {
			std::cerr << RED "exception : " REST << e.what() << std::endl;
			std::cout << "=================================================================================="
			<< std::endl << std::endl;
		}
	}

	{
		ft::vector<int> const vec(10, 21);
		std::cout << "Enter: " << CYAN "ft::vector<int> const vec(10, 21)" REST << std::endl;
		std::cout << "Enter: " << CYAN "vec.at(2)" REST << std::endl;
		std::cout << vec.at(2) << std::endl;
	}

	std::cout << std::endl << GREEN "*** operator[] ***" REST << std::endl;
	{
		ft::vector<int> vec;
		for (size_t i = 0; i < 7; ++i) {
		vec.push_back(i);
		}
		vec_print(vec, 1);

		vec[2] = 21;
		std::cout << "Enter: " << CYAN "vec[2] = 21;" REST << std::endl;
		vec_print(vec, 1);
		std::cout << "=================================================================================="
			<< std::endl << std::endl;
	}

	{
		ft::vector<int> const vec(10, 21);
		std::cout << "Enter: " << CYAN "ft::vector<int> const vec(10, 21)" REST << std::endl;
		std::cout << "Enter: " << CYAN "vec[2]" REST << std::endl;
		std::cout << vec[2] << std::endl;
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [6/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << "=== " << MAG "TEST №3 Element Access" REST << " ===" << std::endl;
	std::cout << GREEN "*** front ***" REST << std::endl;
	{
		ft::vector<int> ft_vec(5, 42);
		vec_print(ft_vec, 1);
		std::vector<int> std_vec(5,42);
		vec_print(std_vec, 2);
		ft_vec.front() = 21;
		std::cout << "Enter: " << CYAN "vector<int> vec.front() = 21" REST << std::endl;
		std_vec.front() = 21;
		vec_compare(ft_vec, std_vec);
	}

	std::cout << GREEN "*** back ***" REST << std::endl;
	{
		ft::vector<int> ft_vec(5, 42);
		vec_print(ft_vec, 1);
		std::vector<int> std_vec(5,42);
		vec_print(std_vec, 2);
		ft_vec.back() = 21;
		std::cout << "Enter: " << CYAN "vector<int> vec.back() = 21" REST << std::endl;
		std_vec.back() = 21;
		vec_compare(ft_vec, std_vec);
	}

	std::cout << GREEN "*** data ***" REST << std::endl;
	{
		ft::vector<int> ft_vec(3, 42);
		vec_print(ft_vec, 1);
		std::vector<int> std_vec(3,42);
		vec_print(std_vec, 2);
		ft_vec.data()[1] = 21;
		std::cout << "Enter: " << CYAN "vector<int> vec.data() = 21" REST << std::endl;
		std_vec.data()[1] = 21;
		vec_compare(ft_vec, std_vec);
	}

	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [7/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_iterators(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №4 Iterators" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** empty vector ***" REST << std::endl;
	{
		ft::vector<int> ft_vec;
		ft::vector<const int> ft_const_vec;
		std::cout << "Enter: " << CYAN "vector<int> ft_vec" REST << std::endl;
		if (ft_vec.begin() == ft_vec.end()) {
			std::cout << "ft_vec.begin() == ft_vec.end()" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "ft_vec.begin() != ft_vec.end()" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}

		if (ft_vec.rbegin() == ft_vec.rend()) {
			std::cout << "ft_vec.rbegin() == ft_vec.rend()" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "ft_vec.rbegin() != ft_vec.rend()" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "vector<int> ft_const_vec" REST << std::endl;
		if (ft_const_vec.begin() == ft_const_vec.end()) {
			std::cout << "ft_const_vec.begin() == ft_const_vec.end()" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "ft_const_vec.begin() != ft_const_vec.end()" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}

		if (ft_const_vec.rbegin() == ft_const_vec.rend()) {
			std::cout << "ft_const_vec.rbegin() == ft_const_vec.rend()" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "ft_const_vec.rbegin() != ft_const_vec.rend()" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "*** fill vector ***" REST << std::endl;
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (size_t i = 0; i < 10; ++i) {
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		std::cout << "Enter: " << CYAN "vector<int> ft_vec(10, 21)" REST << std::endl;
		if (*ft_vec.begin() == *std_vec.begin()) {
			std::cout << "*ft_vec.begin() == *std_vec.begin()" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "*ft_vec.begin() != *std_vec.begin()" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}

		if (*ft_vec.rbegin() == *std_vec.rbegin()) {
			std::cout << "*ft_vec.rbegin() == *std_vec.rbegin()" << std::endl;
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << "*ft_vec.rbegin() != *std_vec.rbegin())" << std::endl;
			std::cout << RED "KO :(" REST << std::endl;
		}

	}
	std::cout << std::endl << GREEN "*** element access ***" REST << std::endl;
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (size_t i = 0; i < 10; ++i) {
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		std::cout << "Enter: " << CYAN "*vec.begin()" REST << std::endl;
		std::cout << CYAN "ft_vec.begin = " REST << GREEN <<*ft_vec.begin() << REST <<
				" and " << YEL "std_vec.begin() = " REST << GREEN << *std_vec.begin() << REST << std::endl;
		if (*(ft_vec.begin()) == *(std_vec.begin())) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "*vec.rbegin()" REST << std::endl;
		std::cout << CYAN "ft_vec.rbegin = " REST << GREEN << *ft_vec.rbegin() << REST <<
				" and " << YEL "std_vec.rbegin() = " REST << GREEN << *std_vec.rbegin() << REST << std::endl;
		if (*(ft_vec.rbegin()) == *(std_vec.rbegin())) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "vec.begin()[3]" REST << std::endl;
		std::cout << CYAN "ft_vec.begin()[3] = " REST << GREEN << ft_vec.begin()[3] << REST <<
				" and " << YEL << "std_vec.begin()[3] = " REST << GREEN << std_vec.begin()[3] << REST << std::endl;
		if (ft_vec.begin()[3] == std_vec.begin()[3]) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "vec.rbegin()[5]" REST << std::endl;
		std::cout << CYAN "ft_vec.rbegin()[5] = " REST << GREEN << ft_vec.rbegin()[5] << REST <<
				" and " << YEL << "std_vec.rbegin()[5] = " REST << GREEN << std_vec.rbegin()[5] << REST << std::endl;
		if (ft_vec.rbegin()[5] == std_vec.rbegin()[5]) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [8/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №4 Iterators" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** arithmetic with iterators ***" REST << std::endl;
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		for (size_t i = 0; i < 10; ++i) {
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		std::cout << RED "=== for iterator ===" REST << std::endl;
		ft::vector<int>::iterator ft_iter = ft_vec.begin();
		std::vector<int>::iterator std_iter = std_vec.begin();
		std::cout << "Enter: " << CYAN "++iter" REST << std::endl;
		++ft_iter;
		++std_iter;
		if (ft_iter >= ft_vec.begin() && std_iter >= std_vec.begin() && *ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "iter++" REST << std::endl;
		ft_iter++;
		std_iter++;
		if (ft_iter > ft_vec.begin() && std_iter > std_vec.begin() && *ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--iter" REST << std::endl;
		--ft_iter;
		--std_iter;
		if (!(ft_iter < ft_vec.begin()) && !(std_iter < std_vec.begin()) && *ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "iter--" REST << std::endl;
		ft_iter--;
		std_iter--;
		if (ft_iter <= ft_vec.begin() && std_iter <= std_vec.begin() && *ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "iter + 3" REST << std::endl;
		ft_iter + 3;
		std_iter + 3;
		if (ft_iter == ft_vec.begin() && std_iter == std_vec.begin() && *ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "iter += 3" REST << std::endl;
		ft_iter += 3;
		std_iter += 3;
		if (ft_iter != ft_vec.begin() && std_iter != std_vec.begin() && *ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "iter - 3" REST << std::endl;
		ft_iter - 3;
		std_iter - 3;
		if (ft_iter > ft_vec.begin() && std_iter > std_vec.begin() && *ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "iter -= 3" REST << std::endl;
		ft_iter -= 3;
		std_iter -= 3;
		if (ft_iter <= ft_vec.begin() && std_iter <= std_vec.begin() && *ft_iter == *std_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [9/23]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;

		std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
		std::cout << "=== " << MAG "TEST №4 Iterators" REST << " ===" << std::endl;
		std::cout << RED "=== for reverse_iterator ===" REST << std::endl;
		ft::vector<int>::reverse_iterator ft_rev_iter = ft_vec.rbegin();
		std::vector<int>::reverse_iterator std_rev_iter = std_vec.rbegin();
		std::cout << "Enter: " << CYAN "++rev_iter" REST << std::endl;
		++ft_rev_iter;
		++std_rev_iter;
		if (ft_rev_iter >= ft_vec.rbegin() && std_rev_iter >= std_vec.rbegin() && *ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rev_iter++" REST << std::endl;
		ft_rev_iter++;
		std_rev_iter++;
		if (ft_rev_iter > ft_vec.rbegin() && std_rev_iter > std_vec.rbegin() && *ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--rev_iter" REST << std::endl;
		--ft_rev_iter;
		--std_rev_iter;
		if (!(ft_rev_iter < ft_vec.rbegin()) && !(std_rev_iter < std_vec.rbegin()) && *ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rev_iter--" REST << std::endl;
		ft_rev_iter--;
		std_rev_iter--;
		if (ft_rev_iter <= ft_vec.rbegin() && std_rev_iter <= std_vec.rbegin() && *ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rev_iter + 3" REST << std::endl;
		ft_rev_iter + 3;
		std_rev_iter + 3;
		if (ft_rev_iter == ft_vec.rbegin() && std_rev_iter == std_vec.rbegin() && *ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rev_iter += 3" REST << std::endl;
		ft_rev_iter += 3;
		std_rev_iter += 3;
		if (ft_rev_iter != ft_vec.rbegin() && std_rev_iter != std_vec.rbegin() && *ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rev_iter - 3" REST << std::endl;
		ft_rev_iter - 3;
		std_rev_iter - 3;
		if (ft_rev_iter > ft_vec.rbegin() && std_rev_iter > std_vec.rbegin() && *ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rev_iter -= 3" REST << std::endl;
		ft_rev_iter -= 3;
		std_rev_iter -= 3;
		if (ft_rev_iter <= ft_vec.rbegin() && std_rev_iter <= std_vec.rbegin() && *ft_rev_iter == *std_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [10/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №4 Iterators" REST << " ===" << std::endl;
	std::cout << RED "=== for const_iterator ===" REST << std::endl;
		ft::vector<int>::const_iterator ft_const_iter = ft_vec.begin();
		std::vector<int>::const_iterator std_const_iter = std_vec.begin();
		std::cout << "Enter: " << CYAN "++const_iter" REST << std::endl;
		++ft_const_iter;
		++std_const_iter;
		if (ft_const_iter >= ft_vec.begin() && std_const_iter >= std_vec.begin() && *ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_iter++" REST << std::endl;
		ft_const_iter++;
		std_const_iter++;
		if (ft_const_iter > ft_vec.begin() && std_const_iter > std_vec.begin() && *ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--const_iter" REST << std::endl;
		--ft_const_iter;
		--std_const_iter;
		if (!(ft_const_iter < ft_vec.begin()) && !(std_const_iter < std_vec.begin()) && *ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_iter--" REST << std::endl;
		ft_const_iter--;
		std_const_iter--;
		if (ft_const_iter <= ft_vec.begin() && std_const_iter <= std_vec.begin() && *ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_iter + 3" REST << std::endl;
		ft_const_iter + 3;
		std_const_iter + 3;
		if (ft_const_iter == ft_vec.begin() && std_const_iter == std_vec.begin() && *ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_iter += 3" REST << std::endl;
		ft_const_iter += 3;
		std_const_iter += 3;
		if (ft_const_iter != ft_vec.begin() && std_const_iter != std_vec.begin() && *ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_iter - 3" REST << std::endl;
		ft_const_iter - 3;
		std_const_iter - 3;
		if (ft_const_iter > ft_vec.begin() && std_const_iter > std_vec.begin() && *ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_iter -= 3" REST << std::endl;
		ft_const_iter -= 3;
		std_const_iter -= 3;
		if (ft_const_iter <= ft_vec.begin() && std_const_iter <= std_vec.begin() && *ft_const_iter == *std_const_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [11/23]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;

		std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
		std::cout << "=== " << MAG "TEST №4 Iterators" REST << " ===" << std::endl;
		std::cout << RED "=== for const_reverse_iterator ===" REST << std::endl;
		ft::vector<int>::const_reverse_iterator ft_const_rev_iter = ft_vec.rbegin();
		std::vector<int>::const_reverse_iterator std_const_rev_iter = std_vec.rbegin();
		std::cout << "Enter: " << CYAN "++const_rev_iter" REST << std::endl;
		++ft_const_rev_iter;
		++std_const_rev_iter;
		if (ft_const_rev_iter >= ft_vec.rbegin() && std_const_rev_iter >= std_vec.rbegin() && *ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_rev_iter++" REST << std::endl;
		ft_const_rev_iter++;
		std_const_rev_iter++;
		if (ft_const_rev_iter > ft_vec.rbegin() && std_const_rev_iter > std_vec.rbegin() && *ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "--const_rev_iter" REST << std::endl;
		--ft_const_rev_iter;
		--std_const_rev_iter;
		if (!(ft_const_rev_iter < ft_vec.rbegin()) && !(std_const_rev_iter < std_vec.rbegin()) && *ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_rev_iter--" REST << std::endl;
		ft_const_rev_iter--;
		std_const_rev_iter--;
		if (ft_const_rev_iter <= ft_vec.rbegin() && std_const_rev_iter <= std_vec.rbegin() && *ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_rev_iter + 3" REST << std::endl;
		ft_const_rev_iter + 3;
		std_const_rev_iter + 3;
		if (ft_const_rev_iter == ft_vec.rbegin() && std_const_rev_iter == std_vec.rbegin() && *ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_rev_iter += 3" REST << std::endl;
		ft_const_rev_iter += 3;
		std_const_rev_iter += 3;
		if (ft_const_rev_iter != ft_vec.rbegin() && std_const_rev_iter != std_vec.rbegin() && *ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_rev_iter - 3" REST << std::endl;
		ft_const_rev_iter - 3;
		std_const_rev_iter - 3;
		if (ft_const_rev_iter > ft_vec.rbegin() && std_const_rev_iter > std_vec.rbegin() && *ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "const_rev_iter -= 3" REST << std::endl;
		ft_const_rev_iter -= 3;
		std_const_rev_iter -= 3;
		if (ft_const_rev_iter <= ft_vec.rbegin() && std_const_rev_iter <= std_vec.rbegin() && *ft_const_rev_iter == *std_const_rev_iter) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
	}

	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [12/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_capacity(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №6 Capacity" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** empty ***" REST << std::endl;
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		std::cout << "Enter: " << CYAN "vector<int> vec" REST << std::endl;
		if (std_vec.empty() == ft_vec.empty()) {
			std::cout << "std_vec.empty() == ft_vec.empty()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_vec.empty() != ft_vec.empty()" << REST <<
			RED " KO :(" REST << std::endl;
		}
		vec_compare(ft_vec, std_vec);
	}
	{
		ft::vector<int> ft_vec(10, 21);
		std::vector<int> std_vec(10, 21);
		std::cout << "Enter: " << CYAN "vector<int> vec(10,21)" REST << std::endl;
		if (std_vec.empty() == ft_vec.empty()) {
			std::cout << "std_vec.empty() == ft_vec.empty()" << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "std_vec.empty() != ft_vec.empty()" << REST <<
			RED " KO :(" REST << std::endl;
		}
	}

	std::cout << std::endl << GREEN "*** max_size ***" REST << std::endl;
	{
		ft::vector<std::string> ft_vec(21, "school");
		std::vector<std::string> std_vec(21, "school");
		std::cout << "Enter: " << CYAN "vector<int> vec(21, \"school\")" REST << std::endl;
		if (std_vec.max_size() == ft_vec.max_size()) {
			std::cout << "size:  " GREEN << std_vec.size() << "==" << ft_vec.size() << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "size:  " RED << std_vec.size() << "!=" << ft_vec.size() << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	std::cout << std::endl << GREEN "*** reserve ***" REST << std::endl;
	{
		std::cout << "Enter: " << CYAN "vector<int> vec" REST << std::endl;
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		std::cout << "Enter: " << CYAN "vector<int> vec.reserve(42)" REST << std::endl;
		ft_vec.reserve(21);
		std_vec.reserve(21);
		if (std_vec.capacity() == ft_vec.capacity()) {
		std::cout << std::endl << "capacity:  " GREEN << std_vec.capacity() << "==" << ft_vec.capacity() << REST <<
		GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "capacity:  " RED << std_vec.capacity() << "!=" << ft_vec.capacity() << REST <<
			RED " KO :(" REST << std::endl;
		}
		vec_compare(ft_vec, std_vec);
	}
	{
		std::cout << "Enter: " << CYAN "vector<int> vec(10, 21)" REST << std::endl;
		ft::vector<int> ft_vec(10, 21);
		std::vector<int> std_vec(10, 21);
		std::cout << "Enter: " << CYAN "vector<int> vec.reserve(42)" REST << std::endl;
		ft_vec.reserve(42);
		std_vec.reserve(42);
		if (std_vec.capacity() == ft_vec.capacity()) {
		std::cout << std::endl << "capacity:  " GREEN << std_vec.capacity() << "==" << ft_vec.capacity() << REST <<
		GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "capacity:  " RED << std_vec.capacity() << "!=" << ft_vec.capacity() << REST <<
			RED " KO :(" REST << std::endl;
		}
		vec_compare(ft_vec, std_vec);
	}

	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [13/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

}

void test_modifiers(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №7 Modifiers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** clear ***" REST << std::endl;
	{
		std::cout << "Enter: " << CYAN "vector<int> vec(10, 21)" REST << std::endl;
		ft::vector<int> ft_vec(10, 21);
		std::vector<int> std_vec(10, 21);
		std::cout << "Enter: " << CYAN "vector<int> vec.clear()" REST << std::endl;
		ft_vec.clear();
		std_vec.clear();
		std::cout << "Enter: " << CYAN "vector<int> vec.push_back(21)" REST << std::endl;
		ft_vec.push_back(21);
		std_vec.push_back(21);
		vec_compare(ft_vec, std_vec);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [14/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << std::endl << GREEN "*** insert ***" REST << std::endl;
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	{
		std::cout << RED "=== single ===" REST << std::endl;
		std::cout << "Enter: " << CYAN "vec.insert(vec.begin(), 21)" REST << std::endl;
		ft_vec.insert(ft_vec.begin(), 21);
		std_vec.insert(std_vec.begin(), 21);
		vec_compare(ft_vec, std_vec);
		std::cout << "Enter: " << CYAN "vec.insert(vec.end(), 42)" REST << std::endl;
		ft_vec.insert(ft_vec.end(), 42);
		std_vec.insert(std_vec.end(), 42);
		vec_compare(ft_vec, std_vec);
		std::cout << "Enter: " << CYAN "vec.insert(vec.begin() - 1, 3)" REST << std::endl;
		ft_vec.insert(ft_vec.begin() + 1, 3);
		std_vec.insert(std_vec.begin() + 1, 3);
		vec_compare(ft_vec, std_vec);
		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [15/23]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;

		std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
		std::cout << std::endl << GREEN "*** insert ***" REST << std::endl;
		std::cout << RED "=== fill ===" REST << std::endl;
		std::cout << "Enter: " << CYAN "vec.insert(vec.begin(), 2, 7)" REST << std::endl;
		ft_vec.insert(ft_vec.begin(), 2, 7);
		std_vec.insert(std_vec.begin(), 2, 7);
		vec_compare(ft_vec, std_vec);
		std::cout << "Enter: " << CYAN "vec.insert(vec.begin() + 3, 3, 6)" REST << std::endl;
		ft_vec.insert(ft_vec.begin() + 3, 3, 6);
		std_vec.insert(std_vec.begin() + 3, 3, 6);
		vec_compare(ft_vec, std_vec);
		std::cout << "Enter: " << CYAN "vec.insert(vec.end(), 2, 24)" REST << std::endl;
		ft_vec.insert(ft_vec.end(), 2, 24);
		std_vec.insert(std_vec.end(), 2, 24);
		vec_compare(ft_vec, std_vec);

		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [16/23]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;

		std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
		std::cout << std::endl << GREEN "*** insert ***" REST << std::endl;
		std::cout << RED "=== range ===" REST << std::endl;
		ft::vector<int> ft_other(2, 8);
		std::vector<int> std_other(2, 8);
		std::cout << "Enter: " << CYAN "vec.insert(vec.begin(), other.begin(), other.end())" REST << std::endl;
		ft_vec.insert(ft_vec.begin(), ft_other.begin(), ft_other.end());
		std_vec.insert(std_vec.begin(), std_other.begin(), std_other.end());
		vec_compare(ft_vec, std_vec);
		std::cout << "Enter: " << CYAN "vec.insert(vec.begin() + 4 , other.begin(), other.end())" REST << std::endl;
		ft_vec.insert(ft_vec.begin() + 4, ft_other.begin(), ft_other.end());
		std_vec.insert(std_vec.begin() + 4, std_other.begin(), std_other.end());
		vec_compare(ft_vec, std_vec);
		std::cout << "Enter: " << CYAN "vec.insert(vec.end(), other.begin(), other.end())" REST << std::endl;
		ft_vec.insert(ft_vec.end(), ft_other.begin(), ft_other.end());
		std_vec.insert(std_vec.end(), std_other.begin(), std_other.end());
		vec_compare(ft_vec, std_vec);
		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [17/23]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;

		std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
		std::cout << std::endl << GREEN "*** erase ***" REST << std::endl;
		std::cout << RED "=== single ===" REST << std::endl;
		std::cout << "Enter: " << CYAN "erase(vec.begin())" REST << std::endl;
		ft_vec.erase(ft_vec.begin());
		std_vec.erase(std_vec.begin());
		vec_compare(ft_vec, std_vec);
		std::cout << "Enter: " << CYAN "erase(vec.end()) - 1" REST << std::endl;
		ft_vec.erase(ft_vec.end() - 1);
		std_vec.erase(std_vec.end() - 1);
		vec_compare(ft_vec, std_vec);
		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [18/23]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;

		std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
		std::cout << std::endl << GREEN "*** erase ***" REST << std::endl;
		std::cout << RED "=== range ===" REST << std::endl;
		std::cout << "Enter: " << CYAN "erase(vec.begin() + 3, vec.begin() + 5)" REST << std::endl;
		ft_vec.erase(ft_vec.begin() + 3, ft_vec.begin() + 8);
		std_vec.erase(std_vec.begin() + 3, std_vec.begin() + 8);
		vec_compare(ft_vec, std_vec);
		std::cout << "Enter: " << CYAN "erase(vec.end() - 3, vec.end() - 5)" REST << std::endl;
		ft_vec.erase(ft_vec.end() - 6, ft_vec.end() - 3);
		std_vec.erase(std_vec.end() - 6, std_vec.end() - 3);
		vec_compare(ft_vec, std_vec);
		std::cout << "Enter: " << CYAN "erase(vec.begin(), vec.end())" REST << std::endl;
		ft_vec.erase(ft_vec.begin(), ft_vec.end());
		std_vec.erase(std_vec.begin(), std_vec.end());
		vec_compare(ft_vec, std_vec);
		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [19/23]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;
	}
	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << std::endl << GREEN "*** push_back ***" REST << std::endl;
	{
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		std::cout << "Enter: " << CYAN "for (size_t i = 0; i < 10; ++i) {vec.push_back(i);}" REST << std::endl;
		for (size_t i = 0; i < 10; ++i) {
			ft_vec.push_back(i);
			std_vec.push_back(i);
		}
		vec_compare(ft_vec, std_vec);
		std::cout << std::endl << GREEN "*** pop_back ***" REST << std::endl;
		vec_compare(ft_vec, std_vec);
		std::cout << "Enter: " << CYAN "for (size_t i = 0; i < 10; ++i) {vec.pop_back();}" REST << std::endl;
		for (size_t i = 0; i < 10; ++i) {
			ft_vec.pop_back();
			std_vec.pop_back();
		}
		vec_compare(ft_vec, std_vec);

		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [20/23]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;
	}

	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << std::endl << GREEN "*** resize ***" REST << std::endl;
	{
		std::cout << "Enter: " << CYAN "vector<int> vec" REST << std::endl;
		ft::vector<int> ft_vec;
		std::vector<int> std_vec;
		std::cout << "Enter: " << CYAN "vec.resize(10)" REST << std::endl;
		ft_vec.resize(10);
		std_vec.resize(10);
		vec_compare(ft_vec, std_vec);
	}
	{
		std::cout << "Enter: " << CYAN "vector<int> vec(10, 21)" REST << std::endl;
		ft::vector<int> ft_vec(10, 21);
		std::vector<int> std_vec(10, 21);
		std::cout << "Enter: " << CYAN "vec.resize(0)" REST << std::endl;
		ft_vec.resize(0);
		std_vec.resize(0);
		vec_compare(ft_vec, std_vec);
	}
	{
		std::cout << "Enter: " << CYAN "vector<int> vec(10, 42)" REST << std::endl;
		ft::vector<int> ft_vec(10, 42);
		std::vector<int> std_vec(10, 42);
		std::cout << "Enter: " << CYAN "vec.resize(15, 21)" REST << std::endl;
		ft_vec.resize(15, 21);
		std_vec.resize(15, 21);
		vec_compare(ft_vec, std_vec);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [21/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;

	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << std::endl << GREEN "*** swap ***" REST << std::endl;
	{
		ft::vector<int> vec_1(10, 42);
		ft::vector<int> vec_2(5, 21);
		vec_print(vec_1, 1);
		vec_print(vec_2, 1);
		std::cout << "Enter: " << CYAN "vector<int> vec_1.swap(vec_2)" REST << std::endl;
		vec_1.swap(vec_2);
		vec_print(vec_1, 1);
		vec_print(vec_2, 1);
	}
	std::cout << "=================================================================================="
	<< std::endl << std::endl;
	{
		ft::vector<std::string> vec_1(3, "hello");
		ft::vector<std::string> vec_2(3, "bye");
		vec_print(vec_1, 1);
		vec_print(vec_2, 1);
		std::cout << "Enter: " << CYAN "vector<int> vec_1.swap(vec_2)" REST << std::endl;
		vec_1.swap(vec_2);
		vec_print(vec_1, 1);
		vec_print(vec_2, 1);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [22/23]" << REST << std::endl;
		std::cin.get();
		std::cout << CLEAR;

}

void test_non_member() {
	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №8 Non member function" REST << " ===" << std::endl;
	{
		std::cout << "Enter: " << CYAN "vector<int> lhs(5, 21)" REST << std::endl;
		std::cout << "Enter: " << CYAN "vector<int> rhs(10, 42)" REST << std::endl;
		ft::vector<int> ft_lhs(5, 21);
		ft::vector<int> ft_rhs(10, 42);
		std::vector<int> std_lhs(5, 21);
		std::vector<int> std_rhs(10, 42);
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
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [23/23]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

int main(void) {
	test_constructors();
	test_assigns();
	test_element_access();
	test_iterators();
	test_capacity();
	test_modifiers();
	test_non_member();
	return 0;
}