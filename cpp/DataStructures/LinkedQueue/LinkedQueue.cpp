/*
 * @Author: Abdullah Khan
 * @File: LinkedQueue.cpp
 */

#include "LinkedQueue.hpp"

#include <iterator>

template <typename T>
LinkedQueue<T>::LinkedQueue() : head{nullptr}, tail{nullptr}, size_{0} {}

template <typename T>
LinkedQueue<T>::LinkedQueue(std::initializer_list<T> lst)
{
	this->head = nullptr; this->tail = nullptr;
	for (auto i = std::begin(lst); i != std::end(lst); ++i)
		this->push(*i);
	this->size_ = lst.size();
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
	Clear();
}

template <typename T>
size_t LinkedQueue<T>::size() const
{
	return size_;
}

template <typename T>
bool LinkedQueue<T>::empty() const
{
	return (head == nullptr) && (size_ == 0);
}

template <typename T>
void LinkedQueue<T>::Clear()
{
	while(!empty())
		pop();
}

template <typename T>
bool LinkedQueue<T>::pop()
{
	if (!empty())
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		size_--;
		return true;
	}
	else { return false; }
}

template <typename T>
void LinkedQueue<T>::push(const T& x)
{
	Node* temp = new Node(x, nullptr);
	if (!head) { head = std::move(temp); tail = head; }
	else
	{
		tail->next = std::move(temp);
		tail = tail->next;
	}
	size_++;
}

template <typename T>
T& LinkedQueue<T>::front() const { return this->head->data; }