#include "../containers/vector/vector.hpp"
#include "../containers/stack/stack.hpp"
#include <stack>
#include <vector>
#include <deque>
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
void stack_print(const T& stack, int num) {
	if (num == 1) {
		std::cout << CYAN "ft::stack<T>  " REST << "[ ";
	} else {
		std::cout << YEL "std::stack<T> " REST << "[ ";
	}
	T tmp(stack);
	while (!tmp.empty()) {
		std::cout << tmp.top() << " ";
		tmp.pop();
	}
	std::cout << "]" <<std::endl;
}

template<class T>
void stack_compare(const ft::stack<T>& ft_stack, const std::stack<T>& std_stack) {
	std::cout << std::endl << MAG "compare: " REST << std::endl;
	stack_print(ft_stack, 1);
	stack_print(std_stack, 2);
	ft::stack<T> ft_tmp(ft_stack);
	std::stack<T> std_tmp(std_stack);
	bool flag = true;
	while (!std_tmp.empty() && !ft_tmp.empty()) {
		if (std_tmp.top() != ft_tmp.top()) {
			std::cout << RED "KO :(" REST << std::endl;
			flag = false;
		}
		std_tmp.pop();
		ft_tmp.pop();
	}
	if (flag) {
		std::cout << GREEN "OK :)" REST << std::endl;
	}
	//size
	if (std_stack.size() == ft_stack.size()) {
		std::cout << "size:  " GREEN << std_stack.size() << "==" << ft_stack.size() << REST <<
		GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "size:  " RED << std_stack.size() << "!=" << ft_stack.size() << REST <<
		RED " KO :(" REST << std::endl;
	}
	//top
	if (ft_stack.size()) {
		if (std_stack.top() == ft_stack.top()) {
			std::cout << "top:   " GREEN << std_stack.top() << "==" << ft_stack.top() << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "top:   " RED << std_stack.top() << "!=" << ft_stack.top() << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	std::cout << "=================================================================================="
	<< std::endl << std::endl;
}

template<class T, class Container>
void stack_compare(const ft::stack<T, Container>& ft_stack, const std::stack<T, Container >& std_stack) {
	std::cout << std::endl << MAG "compare: " REST << std::endl;
	stack_print(ft_stack, 1);
	stack_print(std_stack, 2);
	ft::stack<T, Container> ft_tmp(ft_stack);
	std::stack<T, Container> std_tmp(std_stack);
	bool flag = true;
	while (!std_tmp.empty() && !ft_tmp.empty()) {
		if (std_tmp.top() != ft_tmp.top()) {
			std::cout << RED "KO :(" REST << std::endl;
			flag = false;
		}
		std_tmp.pop();
		ft_tmp.pop();
	}
	if (flag) {
		std::cout << GREEN "OK :)" REST << std::endl;
	}
	//size
	if (std_stack.size() == ft_stack.size()) {
		std::cout << "size:  " GREEN << std_stack.size() << "==" << ft_stack.size() << REST <<
		GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "size:  " RED << std_stack.size() << "!=" << ft_stack.size() << REST <<
		RED " KO :(" REST << std::endl;
	}
	//top
	if (ft_stack.size()) {
		if (std_stack.top() == ft_stack.top()) {
			std::cout << "top:   " GREEN << std_stack.top() << "==" << ft_stack.top() << REST <<
			GREEN " OK :)" REST << std::endl;
		} else {
			std::cout << "top:   " RED << std_stack.top() << "!=" << ft_stack.top() << REST <<
			RED " KO :(" REST << std::endl;
		}
	}
	std::cout << "=================================================================================="
	<< std::endl << std::endl;
}

void test_constructors(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_STACK" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №1 Constructors" REST << " ===" << std::endl;

	std::cout << GREEN "*** Default ***" REST << std::endl;
	{
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		std::cout << "Enter: " << CYAN "stack<int> stack" REST << std::endl;
		stack_compare(ft_stack, std_stack);
	}
	std::cout << GREEN "*** empty stack ***" REST << std::endl;
	{
		ft::stack<int, std::deque<int> > ft_stack;
		std::stack<int, std::deque<int> > std_stack;
		std::cout << "Enter: " << CYAN "stack<int, vector<int> > stack" REST << std::endl;
		stack_compare(ft_stack, std_stack);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [1/7]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
	std::cout << GREEN "*** copy constuctor ***" REST << std::endl;
	{
		ft::stack<int> ft_copy;
		std::stack<int> std_copy;
		ft::stack<int> ft_stack(ft_copy);
		std::stack<int> std_stack(std_copy);
		std::cout << "Enter: " << CYAN "stack<int> stack(copy)" REST << std::endl;
		stack_compare(ft_stack, std_stack);
	}
	{
		std::deque<std::string> deq_copy(3, "deque");
		ft::stack<std::string, std::deque<std::string>  >ft_stack(deq_copy);
		std::stack<std::string, std::deque<std::string> > std_stack(deq_copy);
		std::cout << "Enter: " << CYAN "stack<std::string, std::deque<std::string stack(deq_copy)" REST << std::endl;
		stack_compare(ft_stack, std_stack);
	}
	{
		ft::stack<int> ft_copy;
		std::stack<int> std_copy;
		for (size_t i = 0; i < 5; ++i) {
			ft_copy.push(i);
			std_copy.push(i);
		}
		ft::stack<int> ft_stack(ft_copy);
		std::stack<int> std_stack(std_copy);
		std::cout << "Enter: " << CYAN "stack<int> stack(copy)" REST << std::endl;
		stack_compare(ft_stack, std_stack);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [2/7]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_assigns(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_STACK" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №2 Assigns" REST << " ===" << std::endl;
	{
		ft::stack<int> ft_copy;
		std::stack<int> std_copy;
		ft::stack<int> ft_stack = ft_copy;
		std::stack<int> std_stack = std_copy;
		std::cout << "Enter: " << CYAN "stack<int> stack = copy" REST << std::endl;
		stack_compare(ft_stack, std_stack);
	}
	{
		ft::stack<int> ft_copy;
		std::stack<int> std_copy;
		for (size_t i = 0; i < 5; ++i) {
			ft_copy.push(i);
			std_copy.push(i);
		}
		ft::stack<int> ft_stack = ft_copy;
		std::stack<int> std_stack = std_copy;
		std::cout << "Enter: " << CYAN "stack<int> stack = copy" REST << std::endl;
		stack_compare(ft_stack, std_stack);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [3/7]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_element_access(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_STACK" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №3 Element access" REST << " ===" << std::endl;
	ft::stack<int> ft_stack;
	std::stack<int> std_stack;
	for (size_t i = 5; i > 0; --i) {
		ft_stack.push(i);
		std_stack.push(i);
	}
	stack_compare(ft_stack, std_stack);
	std::cout << "Enter: " << CYAN "stack.top() = 21" REST << std::endl;
	ft_stack.top() = 21;
	std_stack.top() = 21;
	stack_compare(ft_stack, std_stack);
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [4/7]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_capacity(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_STACK" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №4 Capacity" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** empty ***" REST << std::endl;
	{
	ft::stack<int> ft_stack;
	std::stack<int> std_stack;
	std::cout << "Enter: " << CYAN "stack<int> stack" REST << std::endl;
	if (std_stack.empty() == ft_stack.empty()) {
			std::cout << "std_stack.empty() == ft_stack.empty()" << REST <<
			GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "std_stack.empty() != ft_stack.empty()" << REST <<
		RED " KO :(" REST << std::endl;
	}
	stack_compare(ft_stack, std_stack);
	}
	{
	ft::stack<int> ft_stack;
	std::stack<int> std_stack;
	ft_stack.push(21);
	std_stack.push(21);
	std::cout << "Enter: " << CYAN "stack<int> stack" REST << std::endl;
	if (std_stack.empty() == ft_stack.empty()) {
			std::cout << "std_stack.empty() == ft_stack.empty()" << REST <<
			GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "std_stack.empty() != ft_stack.empty()" << REST <<
		RED " KO :(" REST << std::endl;
	}
	stack_compare(ft_stack, std_stack);
	}

	std::cout << std::endl << GREEN "*** size ***" REST << std::endl;
	{
	ft::stack<int> ft_stack;
	std::stack<int> std_stack;
	std::cout << "Enter: " << CYAN "stack<int> stack" REST << std::endl;
	if (std_stack.size() == ft_stack.size()) {
			std::cout << "std_stack.size() == ft_stack.size()" << REST <<
			GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "std_stack.size() != ft_stack.size()" << REST <<
		RED " KO :(" REST << std::endl;
	}
	stack_compare(ft_stack, std_stack);
	}
	{
	ft::stack<int> ft_stack;
	std::stack<int> std_stack;
	ft_stack.push(21);
	std_stack.push(21);
	std::cout << "Enter: " << CYAN "stack<int> stack" REST << std::endl;
	if (std_stack.size() == ft_stack.size()) {
			std::cout << "std_stack.size() == ft_stack.size()" << REST <<
			GREEN " OK :)" REST << std::endl;
	} else {
		std::cout << "std_stack.size() != ft_stack.size()" << REST <<
		RED " KO :(" REST << std::endl;
	}
	stack_compare(ft_stack, std_stack);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [5/7]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_modifiers(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_STACK" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №5 Modifiers" REST << " ===" << std::endl;
	std::cout << std::endl << GREEN "*** push ***" REST << std::endl;
	{
		ft::stack<int> ft_stack;
		std::stack<int> std_stack;
		std::cout << "Enter: " << CYAN "for (size_t i = 0; i < 10; ++i) {stack.push(i);}" REST << std::endl;
		for (size_t i = 0; i < 10; ++i) {
			ft_stack.push(i);
			std_stack.push(i);
		}
		stack_compare(ft_stack, std_stack);
		std::cout << std::endl << GREEN "*** pop ***" REST << std::endl;
		stack_compare(ft_stack, std_stack);
		std::cout << "Enter: " << CYAN "for (size_t i = 0; i < 10; ++i) {stack.pop();}" REST << std::endl;
		for (size_t i = 0; i < 10; ++i) {
			ft_stack.pop();
			std_stack.pop();
		}
		stack_compare(ft_stack, std_stack);
	}
	std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [6/7]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

void test_non_member(void) {
	std::cout << std::endl << "*** " << CYAN "TEST FT_STACK" REST << " ***" << std::endl << std::endl;
	std::cout << "=== " << MAG "TEST №6 Non member function" REST << " ===" << std::endl;
	std::cout << "Enter: " << CYAN "vector<int> lhs(5, 21)" REST << std::endl;
		std::cout << "Enter: " << CYAN "vector<int> rhs(10, 42)" REST << std::endl;
		ft::stack<int> ft_lhs;
		ft::stack<int> ft_rhs;
		std::stack<int> std_lhs;
		std::stack<int> std_rhs;
		for (size_t i = 0; i < 10; ++i) {
			ft_lhs.push(i);
			std_lhs.push(i);
		}
		for (size_t i = 0; i < 5; ++i) {
			ft_rhs.push(i);
			std_rhs.push(i);
		}
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
		std::cout << "Enter: " << CYAN "rhs < lhs" << std::endl;
		if (ft_rhs < ft_lhs && std_rhs < std_lhs) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "rhs <= lhs" << std::endl;
		if (ft_rhs <= ft_lhs && std_rhs <= std_lhs) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "lhs > rhs" << std::endl;
		if (ft_lhs > ft_rhs && std_lhs > std_rhs) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << "Enter: " << CYAN "lhs >= rhs" << std::endl;
		if (ft_lhs >= ft_rhs && std_lhs >= std_rhs) {
			std::cout << GREEN "OK :)" REST << std::endl;
		} else {
			std::cout << RED "KO :(" REST << std::endl;
		}
		std::cout << "=================================================================================="
		<< std::endl << std::endl;
		std::cout << std::endl << GREEN "Press any key to continue ..." REST << YEL "    [7/7]" << REST << std::endl;
	std::cin.get();
	std::cout << CLEAR;
}

int main(void) {
	test_constructors();
	test_assigns();
	test_element_access();
	test_capacity();
	test_modifiers();
	test_non_member();
	return 0;
}
