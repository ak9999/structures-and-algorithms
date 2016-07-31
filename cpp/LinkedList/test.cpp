/*
 * @Author: Abdullah Khan
 * @File: main.cpp
 * @Description: Test LinkedList.
 */

#include <iostream>
#include <random>
#include <cassert>
#include <string>

#include "LinkedList.hpp"

using namespace std;
using G = mt19937; // mersenne twister engine for random numbers
using D = uniform_int_distribution<>; // inclusive distribution range

int main()
{
	// Set up random number generation
	G g;
	g.seed(random_device()());
	D d(10, 99); // Random numbers in range 10 through 99 inclusive.

	// We create the blank LinkedList a here.
	LinkedList<int> a;
	assert( a.size() == 0 ); // If the size isn't 0, the program stops here.
	a.push_back(23);         // Add 23 to a.
	assert( a.size() == 1 );
	for(size_t i = 0; i < 10; i++)
	{
		assert( a.size() == i + 1 );
		a.push_front(d(g));
	} // LinkedList a should now be of size 11.

	a.print(); // Print it using the LinkedList's print function.

	for(size_t i = 0; i < 10; i++)
	{
		assert( a.size() == i + 11 );
		a.push_back(d(g));
	} // Add 10 more elements.

	a.pop_back();             // Remove the element from the back.
	assert( a.size() == 20 ); // We should have 20 elements.
	a.push_front(120);        // Add 120 to the front.
	assert( a.size() == 21 ); // We should have 21.
	a.push_back(500);
	assert( a.size() == 22 );

	while(!a.empty())
	{
		assert( a.size() > 0 );
		a.pop_back();
	}

	assert( a.size() == 0 );

	a.pop_back();
	assert( a.size() == 0 );

	a.push_back(999);
	assert( a.search(999) != nullptr );
	assert( a.search(1000) == nullptr );
	
	a.print();

	a.pop_back();
	a.print();

	LinkedList<string> b{ "yes", "no", "maybe" };
	cout << b; // operator<< was overloaded for LinkedList.

	// Both of these LinkedLists are created by the initialization-list ctor.
	cout << "Initialization-list constructor." << endl;
	LinkedList<float> c{.3, 3.14159, .69};
	cout << c;
	c.insert(2000.16, 1); // Insert 2000.16 into the 2nd position.
	cout << c;
	cout << c.remove(5) << endl;
	cout << c.remove(2) << endl;
	cout << c;
	LinkedList<char> clist = {'a', 'b', 'c'};
	cout << clist;

	cout << "Copy constructor." << endl;
	LinkedList<float> f(c);
	assert( c.size() == f.size() );
	cout << f;

	cout << "Copy-assignment operator." << endl;
	LinkedList<char> e = clist;
	assert( clist.size() == e.size() );
	cout << e;

	LinkedList<float> movef(std::move(f));
	assert( movef.size() != f.size() );

	cout << "Move-assignment operator." << endl;
	LinkedList<char> ecopy = std::move(e);
	assert( ecopy.size() != e.size() );
}
