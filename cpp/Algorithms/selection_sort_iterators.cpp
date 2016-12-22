// Needs containers.
#include <vector>
#include <array>

// Include helper
#include "Helper.hpp"

// namespaces
using namespace std;

int main(int argc, char ** argv)
{
	vector<int> v(5); // vector of 5 elements initialized to 0.
	helper::randomize(v.begin(), v.end());
	cout << "Randomizing vector.\n";
	helper::print_container(v);
	helper::selection_sort(v.begin(), v.end());
	cout << "Sorted vector.\n";
	helper::print_container(v);
	
	array<int, 5> a = {}; // Initializes all elements to 0.
	cout << "\nRandomizing array.\n";
	helper::randomize(a.begin(), a.end());
	helper::print_container(a);
	helper::selection_sort(a.begin(), a.end());
	cout << "Sorted array.\n";
	helper::print_container(a);

	return 0;
}
