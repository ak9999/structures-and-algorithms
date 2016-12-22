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
template<typename Iterator>
void randomize(Iterator begin, Iterator end) {
	Generator g;
	g.seed(std::random_device()());
	Distribution d(10,99);
	for (auto it = begin; it != end; ++it) {
		*it = d(g);
	}
}

// Sort basic containers of any type.
template<typename Iterator>
void selection_sort(Iterator begin, Iterator end) {
	// for (auto it = begin; it != end; ++it) {
	// 	// Using std::min_element during an interview might be cheating.
	// 	auto minimum_element_iterator = min_element(it, end);
	// 	std::swap(*minimum_element_iterator, *it);
	// }
	for (auto i = begin; i != end; ++i) {
		auto minimum_element_iterator = i;
		for (auto j = begin++; j != end; ++j) {
			if (*j < *minimum_element_iterator) {
				minimum_element_iterator = j;
			}
		}
		if (*minimum_element_iterator != *i) {
			std::swap(*minimum_element_iterator, *i);
		}
	}
}

// Print the contents of any single-value container.
template<typename Container>
void print_container(const Container& c) {
	for (const auto i : c) { std::cout << i << ' '; }
	std::cout << '\n';
}
} // namespace helper
