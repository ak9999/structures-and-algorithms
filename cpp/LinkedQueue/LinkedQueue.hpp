/*
 * @Author: Abdullah Khan
 * @File: LinkedQueue.hpp
 * @Description: Part of my notes.
 */

#ifndef LINKEDQUEUE_HPP
#define LINKEDQUEUE_HPP

template<typename T>
class LinkedQueue
{
	struct Node
	{
		Node(const T& x, Node* y) : data(x), next(y) {}
		T data;
		Node* next;
	};

	Node* head; Node* tail;
	size_t size_ = 0;
	void Clear();

public:
	LinkedQueue(); // default constructor
	LinkedQueue(std::initializer_list<T> lst); // initializer-list ctor.
	~LinkedQueue(); // default destructor

	// This tells the compiler not to generate an implicit copy-constructor.
	LinkedQueue(const LinkedQueue&) = delete;
	// This tells the compiler not to generate an implicit copy-assignment.
	LinkedQueue& operator=(const LinkedQueue&) = delete;

	// Public Operations
	size_t size() const;
	bool empty() const;
	bool pop();
	void push(const T&);
	T& front() const; // Return element at the front of the queue.
};

/*
 * Templated classes must have all functions defined within the header.
 * I include the implementation of LinkedQueue at the end of the header,
 * so that all the code is technically inside the header.
 */

#include "LinkedQueue.cpp"
#endif //LINKEDQUEUE_HPP
