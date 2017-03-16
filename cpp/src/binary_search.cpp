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
	std::cout << "Searching for \'2\': ";
	std::cout << binary_search(v, 2) << '\n';
	std::cout << "Searching for \'5\': ";
	std::cout << binary_search(v, 5) << '\n';
	std::vector<std::string> s{"amaze", "armor", "butt"};
	print_container(s);
	std::cout << "Searching for \"amaze\": ";
	std::cout << binary_search(s, "amaze") << '\n';
	std::cout << "Searching for \"fight\": ";
	std::cout << binary_search(s, "fight") << '\n';
	return 0;
}
