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
    assert( a.size() == 0 );
    a.push_back(23);
    assert( a.size() == 1 );
    for(size_t i = 0; i < 10; i++)
    {
        assert( a.size() == i + 1 );
        a.push_front(d(g));
    }

    a.print();

    for(size_t i = 0; i < 10; i++)
    {
        assert( a.size() == i + 11 );
        a.push_back(d(g));
    }

    a.pop_back();
    assert( a.size() == 20 );
    a.push_front(120);
    assert( a.size() == 21 );
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
    return 0;
}
