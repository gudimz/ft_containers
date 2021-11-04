#include <vector>
#include <iostream>
#include "vector.hpp"

int main() {
	ft::vector<int> ft_vec;
	for (size_t i = 0; i < 10; ++i) {
		ft_vec.push_back(i);
	}
	std::cout << "ft_vec.end() = " << *ft_vec.end() << std::endl;
}