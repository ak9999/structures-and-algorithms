/*
 * @Author: Abdullah Khan
 * @File: LinkedList.hpp
 * @Description: Part of my notes.
 */

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <ostream>

template<typename T>
class LinkedList
{
    /*
     * Node is private to LinkedList, but since it is a struct,
     * its members are publically accessible by default to LinkedList.
     * When referencing this Node struct outside of LinkedList.hpp,
     * I must prefix it with "typename LinkedList<T>::" so the compiler knows
     * where to find it.
     */
    struct Node
    {
        Node(const T& x, Node* y) : data(x), next(y) {}
        T data;
        Node* next;
    };

    Node* root;
    size_t size_ = 0;
    void Clear();

public:
    LinkedList(); // default constructor
    LinkedList(std::initializer_list<T> lst); // initializer-list ctor.
    ~LinkedList(); // default destructor

    // This tells the compiler not to generate an implicit copy-constructor.
    LinkedList(const LinkedList&) = delete;
    // This tells the compiler not to generate an implicit copy-assignment.
    LinkedList& operator=(const LinkedList&) = delete;

    // Overload stream operator
    /*
     * This needs to have a different template of a different typename.
     * It is a friend function, so it must be defined outside of the class.
     */
    template <typename U>
    friend std::ostream& operator<<(std::ostream&, const LinkedList<U>& l);

    // Public Operations
    size_t size() const;
    bool empty() const;
    bool pop_front();
    bool pop_back();
    void push_front(const T&);
    void push_back(const T&);
    Node* search(const T&);
    void print();
};

/*
 * Templated classes must have all functions defined within the header.
 * I include the implementation of LinkedList at the end of the header,
 * so that all the code is technically inside the header.
 */

#include "LinkedList.cpp"
#endif //LINKEDLIST_HPP
