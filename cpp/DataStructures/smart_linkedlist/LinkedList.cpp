/*
 * @Author: Abdullah Khan
 * @File: LinkedList.cpp
 */

#include "LinkedList.hpp"

// Non-member functions std::rbegin and std::rend
// are defined in <iterator>.
#include <iterator>

template <typename T>
LinkedList<T>::LinkedList() : root{nullptr}, size_{0} {}

template <typename T>
LinkedList<T>::LinkedList(std::initializer_list<T> lst) : root{nullptr}
{
	/* push_front is cheaper than push_back.
	 * So reverse the {}-list and call push_front, LinkedList will have the same
	 * order, and will be filled faster.
	 */
	for (auto i = std::rbegin(lst); i != std::rend(lst); ++i)
		this->push_front(*i);
	this->size_ = lst.size();
}

template <typename T>
size_t LinkedList<T>::size() const
{
	return size_;
}

template <typename T>
bool LinkedList<T>::empty() const
{
	return (root == nullptr) && (size_ == 0);
}

// Finds the first instance of x in the LinkedList.
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::search(const T& x)
{
	std::shared_ptr<Node> temp = root;
	while (temp != nullptr && temp->data != x)
		temp = temp->next;
	return temp.get();
}

template <typename T>
bool LinkedList<T>::pop_front()
{
	if (!empty())
	{
		root = std::move(root->next);
		size_--;
		return true;
	}
	else { return false; }
}

template <typename T>
bool LinkedList<T>::pop_back()
{
	if (!empty())
	{
		auto curr = root;
		auto prev = curr;
		while (curr != nullptr)
		{
			if (curr->next == nullptr)
			{
				prev->next = nullptr;
				// Create a smart pointer "temp" for the sake of being freed.
				if (prev == curr)
				{
					root.reset();
				}
				else { curr.reset(); }
				size_--;
				return true;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	return false;
}

template <typename T>
void LinkedList<T>::push_front(const T& x)
{
	if (!empty())
	{
		std::unique_ptr<Node> temp(new Node(x, root));
		root = std::move(temp);
		size_++;
	}
	else
	{
		std::unique_ptr<Node> temp(new Node(x, nullptr));
		root = std::move(temp);
		size_++;
	}
}

template <typename T>
void LinkedList<T>::push_back(const T& x)
{
	std::unique_ptr<Node> temp(new Node(x, nullptr));
	if (!root) { root = std::move(temp); }
	else
	{
		std::shared_ptr<Node> curr = root;
		while(curr->next != nullptr)
			curr = curr->next;

		curr->next = std::move(temp);
	}
	size_++;
}

template <typename T>
void LinkedList<T>::print()
{
	if (empty()) { std::cout << "[]" << std::endl; }
	else
	{
		std::shared_ptr<Node> curr = root;
		std::cout << "[";
		while (curr != nullptr)
		{
			std::cout << "\'" << curr->data;
			if(curr->next != nullptr)
				std::cout << "\', ";
			else { std::cout << "\'"; }
			curr = curr->next;
		}
		std::cout << "]" << std::endl;
	}
}

template <typename U>
std::ostream& operator<<(std::ostream& os, const LinkedList<U>& l)
{
	if(l.empty()) { os << "[]" << std::endl; }
	else
	{
		// This function is not part of LinkedList, it is just a friend.
		// So you must include the "typename" so the compiler knows what
		// to look for.
		std::shared_ptr<typename LinkedList<U>::Node> curr = l.root;
		os << "[";
		while (curr != nullptr)
		{
			os << "\'" << curr->data;
			if(curr->next != nullptr)
				os << "\', ";
			else { os << "\'"; }
			curr = curr->next;
		}
		os << "]" << std::endl;
	}
	return os;
}
