/*
 * @Author: Abdullah Khan
 * @File: Algorithms.hpp
 * @Description: Algorithms
 */

#pragma once

// Includes
#include <algorithm>
#include <utility>
#include <iostream>

namespace algorithm {
	// Sort basic containers of any type.
	template<typename Container>
	void selection_sort(Container& c) {
		for (auto it = c.begin(); it != c.end(); ++it) {
		// Using std::min_element during an interview might be cheating.
			auto minimum_element_iterator = std::min_element(it, c.end());
			std::swap(*minimum_element_iterator, *it);
		}
		// for (auto i = begin; i != end; ++i) {
		// 	auto minimum_element_iterator = i;
		// 	for (auto j = begin++; j != end; ++j) {
		// 		if (*j < *minimum_element_iterator) {
		// 			minimum_element_iterator = j;
		// 		}
		// 	}
		// 	if (*minimum_element_iterator != *i) {
		// 		std::swap(*minimum_element_iterator, *i);
		// 	}
		// }
	}

	// Binary search on containers. Look into std::optional
	template <typename Container, typename T>
	T binary_search(Container& c, T key)
	{
		int low = 0;
		int high = c.size() - 1;

		while (low <= high) {
			int middle = (low + high) / 2;
			int middle_value = c[middle];

			if (middle_value < key) {
				low = middle + 1;
			} else if (middle_value > key) {
				high = middle - 1;
			} else {
				return middle; // Key found
			}
		}

		return -1 * (low + 1); // Key not found.
	}
} // namespace algorithm
