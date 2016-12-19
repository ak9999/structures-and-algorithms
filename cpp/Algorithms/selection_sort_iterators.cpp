#include <algorithm>
#include <iostream>
#include <random>
#include <utility>

// Needs containers.
#include <vector>
#include <array>

// using-declarations
using G = std::mt19937; //mersenne_twister_engine for random numbers
using D = std::uniform_int_distribution<>; // Inclusive distribution range.

// namespaces
using namespace std;

// Fills any given container with random integers [10,99]
// Should only be used with containers containing integers of course.
template<typename ForwardIterator>
void randomize(ForwardIterator begin, ForwardIterator end)
{
	G g;
	g.seed(random_device()());
	D d(10, 99);
	for (auto it = begin; it != end; ++it) { *begin = d(g); }
}

// Fills vector<int> with random integers [10,99]
void randomize(vector<int>& v)
{
	G g;
	g.seed(random_device()());
	D d(10, 99);
	for (int& i : v) { i = d(g); }
}

// Sorts any container
template<typename ForwardIterator>
void selection_sort(ForwardIterator begin, ForwardIterator end)
{
	// for (auto it = begin; it != end; it++) {
	// 	// Using std::min_element during an interview might be cheating.
	// 	ForwardIterator minimum_element_iterator = min_element(it, end);
	// 	swap(*minimum_element_iterator, *it);
	// }
	for (auto i = begin; i != end; ++i) {
		auto minimum_element_iterator = i;
		for (auto j = begin++; j != end; ++j) {
			if (*j < *minimum_element_iterator) {
				minimum_element_iterator = j;
			}
		}
		if (*minimum_element_iterator != *i) {
			swap(*minimum_element_iterator, *i);
		}
	}
}

template<typename Container>
void print_container(const Container& c)
{
	for (const auto i : c) { cout << i << ' '; }
	cout << '\n';
}

// Traditional selection sort.
void selection_sort(vector<int>& v);

int main(int argc, char ** argv)
{
	vector<int> v(5); // vector of 5 elements initialized to 0.
	randomize(v);
	cout << "Randomizing vector.\n";
	print_container(v);
	selection_sort(v.begin(), v.end());
	cout << "Sorted vector.\n";
	print_container(v);
	
	array<int, 5> a = {}; // Initializes all elements to 0.
	cout << "\nRandomizing array.\n";
	randomize(a.begin(), a.end());
	print_container(a);
	selection_sort(a.begin(), a.end());
	cout << "Sorted array.\n";
	print_container(a);

	return 0;
}

void selection_sort(vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; ++i) {
		int minimum_element = i;
		for (int j = i+1; j < v.size(); ++j) {
			if (v[j] < v[minimum_element]) {
				minimum_element = j;
			}
		}
		if (minimum_element != i) {
			swap(v[i], v[minimum_element]);
		}
	}
}
