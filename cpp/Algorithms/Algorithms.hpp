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

	template <typename Container>
	int partition(Container& c, int left, int right, int pivot_index)
	{
		auto pivot = c[pivot_index]; // Get a pivot
		std::swap(c[pivot_index], c[right]); // Move it to the end.
		int store_index = left;
		for (int i = left; i < right; ++i) {
			if (c[i] < pivot) {
				std::swap(c[store_index], c[i]);
				++store_index;
			}
		}
		std::swap(c[right], c[store_index]); // Move pivot to it's final place.
		return store_index;
	}

	template <typename Container>
	// Returns the k-th smallest element.
	auto quick_select(Container &c, int left, int right, int k) {
		if (left == right) { // Only one element.
			return c[left];
		}
		int pivot_index = ((right - left) >> 1) + left;
		pivot_index = partition(c, left, right, pivot_index);
		if (k == pivot_index) {
			return c[k];
		} else if (k < pivot_index) {
			return quick_select(c, left, pivot_index - 1, k);
		} else {
			return quick_select(c, pivot_index + 1, right, k);
		}
	}
} // namespace algorithm
