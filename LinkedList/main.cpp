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

    // We are pushing 10 random numbers to the front of the LinkedList.
    for(int i = 0; i < 10; i++)
        a.push_front(d(g));

    cout << "Size: " << a.size() << endl;
    cout << "Front: " << a.front() << endl;
    cout << "Back: " << a.back() << endl;

    cout << "Printing entire list." << endl;
    cout << a << endl;

    a.push_back(2);
    cout << "Pushed integer 2 to list a." << endl;
    cout << a << endl;

    return 0;
}
