#include <vector>
#include <iostream>
#include "ft_vector.hpp"

int main() {
	ft::vector <int> v(10, 42);
	std::vector <int> sv(10, 42);
	std::cout << v.size() << " " << v.capacity() << std::endl;
	std::cout << sv.size() << " " << sv.capacity() << std::endl;
	for (int i = 0; i < 12; ++i) {
		v.push_back(i);
		std::cout << "my: "<< v.size() << " " << v.capacity() << std::endl;
	}
	for (int i = 0; i < 12; ++i) {
		sv.push_back(i);
		std::cout << "orig: " << sv.size() << " " << sv.capacity() << std::endl;
	}
	ft::vector <int> copy(v);
	std::cout << "copy: "<< copy.size() << " " << copy.capacity() << std::endl;
}