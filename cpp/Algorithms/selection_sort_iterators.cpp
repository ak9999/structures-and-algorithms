// Needs containers.
#include <vector>
#include <array>

// Include helper
#include "Helper.hpp"
#include "Algorithms.hpp"

// namespaces
using namespace std;

int main(int argc, char ** argv)
{
	vector<int> v(5); // vector of 5 elements initialized to 0.
	helper::randomize(v);
	cout << "Randomizing vector.\n";
	helper::print_container(v);
	algorithm::selection_sort(v);
	cout << "Sorted vector.\n";
	helper::print_container(v);

	array<int, 5> a = {}; // Initializes all elements to 0.
	cout << "\nRandomizing array.\n";
	helper::randomize(a);
	helper::print_container(a);
	algorithm::selection_sort(a);
	cout << "Sorted array.\n";
	helper::print_container(a);

	return 0;
}
