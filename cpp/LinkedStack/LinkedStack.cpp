/*
 * @Author: Abdullah Khan
 * @File: LinkedStack.cpp
 */

#include "LinkedStack.hpp"

// Non-member functions std::rbegin and std::rend
// are defined in <iterator>.
#include <iterator>

template <typename T>
LinkedStack<T>::LinkedStack() : root{nullptr}, size_{0} {}

template <typename T>
LinkedStack<T>::LinkedStack(std::initializer_list<T> lst) : root{nullptr}
{
	/*
	 * Reverse the {}-list and push to the stack.
	 * Left to right, the {}-list represents the Stack from
	 * top to bottom.
	 */
	for (auto i = std::rbegin(lst); i != std::rend(lst); ++i)
		this->push(*i);
	this->size_ = lst.size();
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
	Clear();
}

template <typename T>
size_t LinkedStack<T>::size() const
{
	return size_;
}

template <typename T>
bool LinkedStack<T>::empty() const
{
	return (root == nullptr) && (size_ == 0);
}

template <typename T>
void LinkedStack<T>::Clear()
{
	while(!empty())
		pop();
}

template <typename T>
bool LinkedStack<T>::pop()
{
	if (!empty())
	{
		Node* temp = root;
		root = root->next;
		delete temp;
		size_--;
		return true; // Successfully deleted element from stack.
	}
	else { return false; }
}

template <typename T>
void LinkedStack<T>::push(const T& x)
{
	if (!empty())
	{
		Node* temp = new Node(x, root);
		root = temp;
		size_++;
	}
	else
	{
		Node* temp = new Node(x, nullptr);
		root = std::move(temp);
		size_++;
	}
}

// Calling code should check if empty first.
template <typename T>
T LinkedStack<T>::top() { return this->root->data; }
