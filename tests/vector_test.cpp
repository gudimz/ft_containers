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
		std::cout << CYAN "std::vector<T> " REST << "[ ";
	}
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << "]" <<std::endl;
}
template<class T>
void vec_compare(const ft::vector<T>& ft_vec, const std::vector<T>& std_vec) {
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
		std::cout << "size:     " YEL << std_vec.size() << "==" << ft_vec.size() << REST <<
		GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "size:     " YEL << std_vec.size() << "!=" << ft_vec.size() << REST <<
		RED " KO :(" REST << std::endl;
	}
	//capacity
	if (std_vec.capacity() == ft_vec.capacity()) {
		std::cout << "capacity: " YEL << std_vec.capacity() << "==" << ft_vec.capacity() << REST <<
		GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "capacity: " YEL << std_vec.capacity() << "!=" << ft_vec.capacity() << REST <<
		RED " KO :(" REST << std::endl;
	}
	std::cout << "==================================================================================" << std::endl;
}

void test_constructors(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_VECTOR" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №1 Constructors" REST << " ===" << std::endl;

	std::cout << GREEN "Default" REST << std::endl;
	{
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;
	std::cout << "Enter: " << CYAN "vector<int> vec" REST << std::endl;
	vec_compare(ft_vec, std_vec);
	}

	std::cout << GREEN "Fill" REST << std::endl;
	{
	ft::vector<int> ft_vec(10, 21);
	std::vector<int> std_vec(10,21);
	std::cout << "Enter: " << CYAN "vector<int> vec(10, 21)" REST << std::endl;
	vec_compare(ft_vec, std_vec);
	}

	{
	ft::vector<std::string> ft_vec(1, "school ");
	std::vector<std::string> std_vec(1, "school ");
	std::cout << "Enter: " << CYAN "vector<int> vec(1, \"school \")" REST << std::endl;
	ft_vec.push_back("21");
	std_vec.push_back("21");
	std::cout << "Enter: " << CYAN "vec.push_back(\"21\")" REST << std::endl;
	vec_compare(ft_vec, std_vec);
	}

	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [1/*]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

int main(void) {
	test_constructors();

	return 0;
}