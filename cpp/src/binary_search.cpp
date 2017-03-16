#include <vector>
#include <iostream>
#include <Helper.hpp>
#include <Algorithms.hpp>
using namespace helper;
using namespace algorithm;

int main() {
	std::vector<int> v(3);
	std::iota(v.begin(), v.end(), 0);
	print_container(v);
	std::cout << binary_search(v, 2) << '\n';
	std::vector<std::string> s{"amaze", "armor", "butt"};
	print_container(s);
	std::cout << binary_search(s, "amaze") << '\n';
	return 0;
}
