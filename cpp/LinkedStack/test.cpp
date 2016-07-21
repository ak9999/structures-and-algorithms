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
	cout << "Top: " << a.top() << endl;
	for(size_t i = 0; i < 10; i++)
	{
		assert( a.size() == i + 1);
		a.push(i);
	} // LinkedStack a should now be of size 11.

	cout << "Printing out as we pop." << endl;
	while (a.size() > 0)
	{
		cout << "Top: " << a.top() << endl;
		a.pop();
	}

	cout << "Creating Stack `b` of size 5 with values: 1.57, 3.14, 6.12, 6.67, 10.24 via {}-list." << endl;
	LinkedStack<double> b{1.57, 3.14, 6.12, 6.67, 10.24};
	assert( b.size() == 5 );
	cout << "Size of stack b: " << b.size() << endl;

	return 0;
}
