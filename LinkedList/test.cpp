/*
 * @Author: Abdullah Khan
 * @File: main.cpp
 * @Description: Test LinkedList.
 */

#include <iostream>
#include <random>
#include <cassert>

#include "LinkedList.hpp"

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
    assert( a.size() == 0 );
    for(int i = 0; i < 10; i++)
    {
        assert( a.size() == i );
        a.push_front(d(g));
    }

    a.pop_back();
    assert( a.size() == 9 );
    a.push_front(120);
    assert( a.front() == 120 );
    a.push_back(500);
    assert( a.back() == 500 );

    return 0;
}
