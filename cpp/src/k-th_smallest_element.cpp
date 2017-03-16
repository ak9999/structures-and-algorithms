// Abdullah Khan
// Compile with: g++ -std=c++14 k-th_smallest_element.cpp
// Second smallest value in unsorted array/vector/list

#include <iostream>
#include <array>
#include <utility>
#include <random>
#include <Helper.hpp>
#include <Algorithms.hpp>
using namespace helper;
using namespace algorithm;

int main() {
    // std::vector<int> vec{42, 8, 13, 79, 5, 2, 18};
    // Below shows that it works for any given array.
    std::array<int, 7> arr = {};
    randomize(arr);
    std::cout << "Initial array:\n";
    for (int element : arr) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // In this call, k = 1 even though we want the 2nd smallest element
    // because we count from 0.
    int second_smallest = quick_select(arr, 0, arr.size()-1, 1);
    std::cout << "Partially sorted array:\n";
    for (int element : arr) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    std::cout << "The second smallest element is: " << second_smallest << '\n';
    return 0;
}
