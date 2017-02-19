#include "Array.hpp"
#include <iostream>
#include <random>
#include <algorithm>
using std::cout;

// Print the contents of a container.
template<typename Container>
void print_container(const Container& c) {
	for (const auto &i : c) { std::cout << i << ' '; }
		std::cout << '\n';
}

using Generator = std::mt19937; // mersenne_twister_engine for random numbers
using Distribution = std::uniform_int_distribution<>; // Inclusive distribution range.

// Fills any given container with random integers [10,99]
// Should only be used with containers that can hold integers.
template<typename Container>
void randomize(Container& c) {
	Generator g;
	g.seed(std::random_device()());
	Distribution d(10,99);
	for (auto it = c.begin(); it != c.end(); ++it) {
		*it = d(g);
	}
}

int main() {
    Array<int, 3> array;
    array[0] = 1; array[1] = 2; array[2] = 3;
    print_container(array);
    cout << "is_sorted: " << std::boolalpha
         << std::is_sorted(array.begin(), array.end()) << '\n';
    randomize(array);
    print_container(array);
    cout << "is_sorted: " << std::boolalpha
         << std::is_sorted(array.begin(), array.end()) << '\n';
}