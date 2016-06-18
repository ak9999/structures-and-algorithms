/*
 * @Author: Abdullah Khan
 * @File: LinkedList.cpp
 */

#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList() : root{nullptr}, size_{0} {}

template <typename T>
LinkedList<T>::~LinkedList()
{
    Clear();
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

template <typename T>
void LinkedList<T>::Clear()
{
    while(!empty())
        pop_front();
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::search(const T& x)
{
    Node* temp = root;
    while (temp != nullptr && temp->data != x)
        temp = temp->next;
    return temp;
}

template <typename T>
void LinkedList<T>::pop_front()
{
    if (!empty())
    {
        Node* temp = root;
        root = root->next;
        delete temp;
        size_--;
    }
    else { return; }
}

template <typename T>
void LinkedList<T>::pop_back()
{
    if (!empty())
    {
        Node* curr = root;
        Node* prev = root;
        while (curr != nullptr)
        {
            if (curr->next == nullptr)
            {
                prev->next = nullptr;
                if (prev == curr)
                {
                    delete curr;
                    root = nullptr;
                }
                else { delete curr; }
                size_--;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    else { return; }
}

template <typename T>
void LinkedList<T>::push_front(const T& x)
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

template <typename T>
void LinkedList<T>::push_back(const T& x)
{
    Node* temp = new Node(x, nullptr);
    if (!root) { root = std::move(temp); }
    else
    {
        Node* curr = root;
        while(curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = std::move(temp);
    }
    size_++;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const LinkedList<T>& list)
{
    if (list.empty()) { out << "Empty!"; }
    else
    {
        typename LinkedList<T>::Node* curr = list.GetRoot();
        while (curr != nullptr)
        {
            out << curr->data << " ";
            curr = curr->next;
        }
    }
    return out;
}
