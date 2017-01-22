/*
 * @Author: Abdullah Khan
 * @File: Helper.hpp
 * @Description: A bunch of functions to help me test my data structures and
	algorithms.
 */

#pragma once // Include only once.

// Includes
#include <algorithm>
#include <random>
#include <utility>
#include <iostream>

namespace helper {

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

// Print the contents of any single-value container.
template<typename Container>
void print_container(const Container& c) {
	for (const auto i : c) { std::cout << i << ' '; }
		std::cout << '\n';
}
} // namespace helper
