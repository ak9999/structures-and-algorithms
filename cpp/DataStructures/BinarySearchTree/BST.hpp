// @File: BST.hpp
// @Description: Part of my notes.

#ifndef BST_HPP
#define BST_HPP

#include <iostream>

template <typename Comparable>
class BinarySearchTree {
public:
	// Constructors and destructors
	BinarySearchTree(); // Default constructor
	BinarySearchTree(const BinarySearchTree& rhs); // Copy constructor
	BinarySearchTree(BinarySearchTree&& rhs); // Move constructor
	~BinarySearchTree(); // Destructor

	// Public functions
	const Comparable& findMin() const;
	const Comparable& findMax() const;
	bool contains(const Comparable& x) const;
	bool isEmpty() const;

	void makeEmpty();
	void insert(const Comparable& x);
	void insert(Comparable&& x);
	void remove(const Comparable& x);
	size_t size() const;

	void print_preorder() const;
	void print_inorder() const;
	void print_postorder() const;

	// Assignment operators
	BinarySearchTree& operator=(const BinarySearchTree& rhs); // Copy assignment
	BinarySearchTree& operator=(BinarySearchTree&& rhs); // Move assignment

private:
	// BinaryNode is private to BinarySearchTree, but its members are publically
	// accessible by default since it is a struct.
	struct BinaryNode {
		Comparable element;
		BinaryNode* left;
		BinaryNode* right;

		// Constructors
		BinaryNode(const Comparable& e, BinaryNode* lt, BinaryNode* rt)
			: element{e}, left{lt}, right{rt} {}

		BinaryNode(const Comparable&& e, BinaryNode* lt, BinaryNode* rt)
			: element{std::move(e)}, left{lt}, right{rt} {}
	};

	BinaryNode* root;
	size_t size_ = 0;

	void insert(const Comparable& x, BinaryNode*& t);
	void insert(Comparable&& x, BinaryNode*& t);
	void remove(const Comparable& x, BinaryNode*& t);
	BinaryNode* findMin(BinaryNode* t) const;
	BinaryNode* findMax(BinaryNode* t) const;
	bool contains(const Comparable& x, BinaryNode* t) const;
	void makeEmpty(BinaryNode*& t);
	BinaryNode* clone(BinaryNode* t) const;
	void print_preorder(BinaryNode* t) const;
	void print_inorder(BinaryNode* t) const;
	void print_postorder(BinaryNode* t) const;
};

#include "BST.cpp"
#endif // BST_HPP
