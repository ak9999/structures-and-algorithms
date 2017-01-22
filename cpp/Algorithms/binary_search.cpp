#include <vector>
#include <random>
#include <iostream>
#include "Helper.hpp"
#include "Algorithms.hpp"
using namespace helper;
using namespace algorithm;

int main() {
	std::vector<int> v(3);
	for (unsigned i = 0; i < v.size(); ++i) {
		v[i] = i;
	}
	print_container(v);
	std::cout << binary_search(v, 7) << '\n';
	return 0;
}
