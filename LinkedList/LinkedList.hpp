/*
 * @Author: Abdullah Khan
 * @File: LinkedList.h
 */

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <ostream>

template<typename T>
class LinkedList
{
    struct Node
    {
        Node(const T& x, Node* y) : data(x), next(y) {}
        T data;
        Node* next;
    };

    Node* root;
    size_t size_ = 0;
    void Clear();

    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const LinkedList<U>&);

public:
    LinkedList();
    LinkedList(const LinkedList&) = delete;
    ~LinkedList();
    LinkedList& operator=(const LinkedList&) = delete;

    // Operations
    size_t size() const;
    bool empty() const;
    bool pop_front();
    bool pop_back();
    void push_front(const T&);
    void push_back(const T&);
    Node* search(const T&);
    Node* GetRoot() const;
};

#include "LinkedList.cpp"
#endif //LINKEDLIST_HPP
