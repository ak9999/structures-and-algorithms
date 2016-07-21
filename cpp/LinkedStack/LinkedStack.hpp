/*
 * @Author: Abdullah Khan
 * @File: LinkedStack.hpp
 * @Description: Part of my notes.
 */

#ifndef LINKEDSTACK_HPP
#define LINKEDSTACK_HPP

template<typename T>
class LinkedStack
{
	/*
	 * Node is private to LinkedStack, but since it is a struct,
	 * its members are publically accessible by default to LinkedStack.
	 * When referencing this Node struct outside of LinkedStack.hpp,
	 * I must prefix it with "typename LinkedStack<T>::" so the compiler knows
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
	LinkedStack(); // default constructor
	LinkedStack(std::initializer_list<T> lst); // initializer-list ctor.
	~LinkedStack(); // default destructor

	// This tells the compiler not to generate an implicit copy-constructor.
	LinkedStack(const LinkedStack&) = delete;
	// This tells the compiler not to generate an implicit copy-assignment.
	LinkedStack& operator=(const LinkedStack&) = delete;

	// Public Operations
	size_t size() const;
	bool empty() const;
	bool pop(); // Pop an element from the top of the stack and return it.
	void push(const T&);
	T top(); // Return what is at the top of the stack.
};

/*
 * Templated classes must have all functions defined within the header.
 * I include the implementation of LinkedStack at the end of the header,
 * so that all the code is technically inside the header.
 */

#include "LinkedStack.cpp"
#endif //LINKEDSTACK_HPP
