// Abdullah Khan
// Compile with: g++ -std=c++14 k-th_smallest_element.cpp
// Second smallest value in unsorted array/vector/list

#include <iostream>
#include <vector>
#include <utility>
#include <random>

using Generator = std::mt19937;
using Distribution = std::uniform_int_distribution<>;

void randomize(std::vector<int>& v) {
    Generator g;
    g.seed(std::random_device()());
    Distribution d(10, 99);
    for (auto it = v.begin(); it != v.end(); ++it) {
        *it = d(g);
    }
}

int partition(std::vector<int>& v, int left, int right, int pivot_index)
{
    int pivot = v[pivot_index]; // Get a pivot
    std::swap(v[pivot_index], v[right]); // Move it to the end.
    int store_index = left;
    for (int i = left; i < right; ++i) {
        if (v[i] < pivot) {
            std::swap(v[store_index], v[i]);
            ++store_index;
        }
    }
    std::swap(v[right], v[store_index]); // Move pivot to it's final place.
    return store_index;
}

// Returns the k-th smallest element.
int quick_select(std::vector<int>& v, int left, int right, int k) {
    if (left == right) { // Only one element.
        return v[left];
    }
    int pivot_index = ((right - left) >> 1) + left;
    pivot_index = partition(v, left, right, pivot_index);
    if (k == pivot_index) {
        return v[k];
    } else if (k < pivot_index) {
        return quick_select(v, left, pivot_index - 1, k);
    } else {
        return quick_select(v, pivot_index + 1, right, k);
    }
}

int main() {
    // std::vector<int> vec{42, 8, 13, 79, 5, 2, 18};
    std::vector<int> vec(7);
    randomize(vec);
    std::cout << "Initial vector:\n";
    for (int element : vec) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // In this call, k = 1 because we count from 0.
    int second_smallest = quick_select(vec, 0, vec.size()-1, 1);
    std::cout << "Partially sorted vector:\n";
    for (int element : vec) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    std::cout << "The second smallest element is: " << second_smallest << '\n';
    return 0;
}
