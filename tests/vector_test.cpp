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
	for (size_t i = 0; i < std_vec.size(); ++i) {
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

	std::cout << "=== " << MAG "TEST №2 Copy Constructors" REST << " ===" << std::endl;
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
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [1/*]" << REST << std::endl;
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

	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [2/*]" << REST << std::endl;
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

	std::cout << GREEN "*** back ***" REST << std::endl;
	{
		ft::vector<int> ft_vec(3, 42);
		vec_print(ft_vec, 1);
		std::vector<int> std_vec(3,42);
		vec_print(std_vec, 2);
		ft_vec.data()[1] = 21;
		std::cout << "Enter: " << CYAN "vector<int> vec.back() = 21" REST << std::endl;
		std_vec.data()[1] = 21;
		vec_compare(ft_vec, std_vec);
	}

	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [3/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

int main(void) {
	// test_constructors();
	// test_assigns();
	test_element_access();

	return 0;
}