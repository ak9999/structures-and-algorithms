/*
 * @Author: Abdullah Khan
 * @File: LinkedList.h
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <iostream>

class LinkedList_Error : public std::logic_error
{
public:
    LinkedList_Error(const std::string &msg) : std::logic_error(msg) {}
};

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
    unsigned int size_ = 0;
    void Clear();
    
    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const LinkedList<U>&);

public:
    LinkedList();
    LinkedList(const LinkedList&);
    ~LinkedList();
    LinkedList& operator=(const LinkedList&);

    // Operations
    Node* GetRoot() const;
    unsigned int size() const;
    bool empty() const;
    void pop_front();
    void pop_back();
    T& front() const;
    T& back() const;
    void push_front(const T&);
    void push_back(const T&);
};

#include "LinkedList.cpp"
#endif //LINKEDLIST_H
