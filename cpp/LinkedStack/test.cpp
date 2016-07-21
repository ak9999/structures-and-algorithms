/*
 * @Author: Abdullah Khan
 * @File: main.cpp
 * @Description: Test LinkedList.
 */

#include <iostream>
#include <cassert>

#include "LinkedStack.hpp"

using namespace std;

int main()
{
	// We create the blank LinkedList a here.
	LinkedStack<int> a;
	assert( a.size() == 0 ); // If the size isn't 0, the program stops here.
	a.push(23);         // Add 23 to a.
	assert( a.size() == 1 );
	cout << a.top() << endl;
	for(size_t i = 0; i < 10; i++)
	{
		assert( a.size() == i + 1 );
		a.push(i);
	} // LinkedStack a should now be of size 11.

	assert( a.size() == 11);

	cout << a.pop() << endl;
	assert( a.size() == 10);
	int removed{a.pop()};
	assert ( a.size () == 9);
	cout << removed << endl;

	cout << "Printing out as we pop." << endl;
	while (!a.empty())
		cout << a.pop() << endl;
	return 0;
}
