/*
 * @Author: Abdullah Khan
 * @File: main.cpp
 * @Description: Test LinkedList.
 */

#include <iostream>
#include <random>

#include "LinkedList.h"

using namespace std;
using G = mt19937_64; // mersenne twister engine for random numbers
using D = uniform_int_distribution<>; // inclusive distribution range

int main()
{
    // Set up random number generation
    G g;
    g.seed(random_device()());
    D d(10, 99); // Random numbers in range 10 through 99 inclusive.

    // We create the blank LinkedList a here.
    LinkedList<int> a;
    cout << "Size: " << a.size() << endl; // Should print 0.
    cout << a << endl; // Should print "Empty!"

    cout << "Adding 10 random integers in range [10, 99] to a." << endl;
    for(int i = 0; i < 10; i++)
        a.push_front(d(g));

    cout << a << endl;

    cout << "We're going to keep popping from the back until a is empty." << endl;

    while (!a.empty())
    {
        cout << "Size: " << a.size() << ", List: " << a << endl;
        a.pop_front();
    }

    return 0;
}
