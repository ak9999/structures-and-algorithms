/*
 * @Author: Abdullah Khan
 * @File: Algorithms.hpp
 * @Description: Algorithms
 */

#pragma once // Similar to include guards.

#include <utility>

namespace algorithm {
	// Sort basic containers of any type.
	template<typename Container>
	void selection_sort(Container& c) {
		// If we include <algorithm> we can use the following instead:
		// for (auto it = c.begin(); it != c.end(); ++it) {
		// // Using std::min_element during an interview might be cheating.
		// 	auto minimum_element_iterator = std::min_element(it, c.end());
		// 	std::swap(*minimum_element_iterator, *it);
		// }
		for (auto i = c.begin(); i != c.end(); ++i) {
			auto minimum_element_iterator = i;
			for (auto j = i+1; j != c.end(); ++j) {
				if (*j < *minimum_element_iterator) {
					minimum_element_iterator = j;
				}
			}
			if (*minimum_element_iterator != *i) {
				std::swap(*minimum_element_iterator, *i);
			}
		}
	}

	// Binary search on containers.
	// Returns the index of the element found.
	// Otherwise returns -1.
	template <typename Container, typename T>
	int binary_search(const Container& c, const T& key) {
		int low = 0;
		int high = c.size() - 1;
		while (low <= high) {
			int middle = (low + high) / 2;
			// Can't use T for middle_value's type because if the key passed to binary_search
			// is an r-value expression, the compiler may not interpret it as type T.
			// Ex: key = "ball" can be an std::string or a char array.
			auto middle_value = c[middle];
			if (middle_value < key) {
				low = middle + 1;
			} else if (middle_value > key) {
				high = middle - 1;
			} else {
				return middle; // Key found
			}
		}
		return -1; // Key not found.
	}

	// TODO: Add more comments.
	// Returns an index to an element in a container.
	template <typename Container>
	size_t partition(Container& c, size_t left, size_t right, size_t pivot_index) {
		auto pivot = c[pivot_index]; // Get a pivot
		std::swap(c[pivot_index], c[right]); // Move it to the end.
		size_t store_index = left;
		for (size_t i = left; i < right; ++i) {
			if (c[i] < pivot) {
				std::swap(c[store_index], c[i]);
				++store_index;
			}
		}
		std::swap(c[right], c[store_index]); // Move pivot to it's final place.
		return store_index;
	}

	// Returns the k-th smallest element.
	// TODO: Add more comments.
	template <typename Container>
	auto quick_select(Container &c, size_t left, size_t right, size_t k) {
		if (left == right) { // Only one element.
			return c[left];
		}
		size_t pivot_index = ((right - left) >> 1) + left;
		pivot_index = partition(c, left, right, pivot_index);
		if (k == pivot_index) {
			return c[k];
		} else if (k < pivot_index) {
			return quick_select(c, left, pivot_index - 1, k);
		} else {
			return quick_select(c, pivot_index + 1, right, k);
		}
	}

	// QuickSort
	// TODO: Add comments.
	template <typename Container>
	void quick_sort(Container& c, size_t left, size_t right) {
		if (left == right) {
			return;
		}
		if (left < right) {
			size_t pivot_index = ((right - left) >> 1) + left;
			pivot_index = partition(c, left, right, pivot_index);
			quick_sort(c, left, pivot_index);
			quick_sort(c, pivot_index+1, right);
			return;
		} else {
			return;
		}
	}
} // namespace algorithm
