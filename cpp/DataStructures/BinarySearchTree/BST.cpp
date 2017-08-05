// @File: BST.cpp
// @Description: Part of my notes.

#include "BST.hpp"
#include <algorithm>
#include <utility>

// Default constructor
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree() : root{nullptr} {}

// Copy constructor
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(const BinarySearchTree& rhs) : root{nullptr} {
	root = clone(rhs.root);
}

// Move constructor
template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(BinarySearchTree&& rhs) : root{nullptr} {
	*this = std::move(rhs);
}

// Destructor for the tree.
template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree() {
	makeEmpty();
}

// Copy assignment
template <typename Comparable>
BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(const BinarySearchTree& rhs) {
	// this->root = clone(rhs.root);
	root = clone(rhs.root);
	size_ = rhs.size_;
	return *this;
}

// Move assignment
template <typename Comparable>
BinarySearchTree<Comparable>& BinarySearchTree<Comparable>::operator=(BinarySearchTree&& rhs) {
	if (this != &rhs) {
		delete root; // Free the existing memory
		root = rhs.root;
		size_ = rhs.size_;
		rhs.root = nullptr;
		rhs.size_ = 0;
	}
	return *this;
}

// Returns true if x is found in the tree.
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x) const {
	return contains(x, root);
}

// Insert x into the tree; duplicates are ignored.
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x) {
	insert(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable&& x) {
    insert(std::move(x), root);
}

// Remove x from the tree. Nothing is done if x is not found.
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x) {
	remove(x, root);
}

// Internal method to test if an item is in a subtree.
// x is the item to search for
// t is the node that roots the subtree
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable& x, BinaryNode* t) const {
	if (t == nullptr) {
		return false;
	}
	else if (x < t->element) {
		return contains(x, t->left);
	}
	else if (x > t->element) {
		return contains(x, t->right);
	}
	else {
		return true; // Match
	}
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::isEmpty() const {
	if (root == nullptr) {
		return true;
	} else {
		return false;
	}
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMin() const {
    return findMin(root)->element;
}

// Internal function.
// Finds the minimum element in the tree and returns a pointer to the node containing it.
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode*
BinarySearchTree<Comparable>::findMin(BinaryNode* t) const {
	if (t != nullptr) {
		while (t->left != nullptr) {
			t = t->left;
		}
	}
	return t;
}

template <typename Comparable>
const Comparable& BinarySearchTree<Comparable>::findMax() const {
    return findMax(root)->element;
}

// Internal function.
// Finds the maximum element in the tree and returns a pointer to the node containing it.
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode*
BinarySearchTree<Comparable>::findMax(BinaryNode* t) const {
	// t is a copy of a pointer, so it is safe to assign t to anything.
	if (t != nullptr) {
		while (t->right != nullptr) {
			t = t->right;
		}
	}
	return t;
}

// Preorder
template <typename Comparable>
void BinarySearchTree<Comparable>::print_preorder() const {
	print_preorder(root);
	std::cout << '\n';
}

template <typename Comparable>
void BinarySearchTree<Comparable>::print_preorder(BinaryNode* t) const {
	if (t == nullptr) {
		return;
	} else {
		std::cout << t->element << " ";
		print_preorder(t->left);
		print_preorder(t->right);
	}
}

// Inorder
template <typename Comparable>
void BinarySearchTree<Comparable>::print_inorder() const {
	print_inorder(root);
	std::cout << '\n';
}

template <typename Comparable>
void BinarySearchTree<Comparable>::print_inorder(BinaryNode* t) const {
	if (t == nullptr) {
		return;
	} else {
		print_inorder(t->left);
		std::cout << t->element << " ";
		print_inorder(t->right);
	}
}

// Postorder
template <typename Comparable>
void BinarySearchTree<Comparable>::print_postorder() const {
	print_postorder(root);
	std::cout << '\n';
}

template <typename Comparable>
void BinarySearchTree<Comparable>::print_postorder(BinaryNode* t) const {
	if (t == nullptr) {
		return;
	} else {
		print_inorder(t->left);
		print_inorder(t->right);
		std::cout << t->element << " ";
	}
}

// Internal function to insert into a subtree.
// x is the item to insert
// t is the node that roots the subtree
// Set the new root of the subtree.
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable& x, BinaryNode*& t) {
	if (t == nullptr) {
		t = new BinaryNode{x, nullptr, nullptr};
		size_++;
	}
	else if (x < t->element) {
		insert(x, t->left);
	}
	else if (x > t->element) {
		insert(x, t->right);
	}
	else {
		return; // Duplicate, do nothing.
	}
}

// Internal function to insert into a subtree.
// x is the item to insert
// t is the node that roots the subtree
// Set the new root of the subtree.
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable&& x, BinaryNode*& t) {
	if (t == nullptr) {
		t = new BinaryNode{std::move(x), nullptr, nullptr};
		size_++;
	}
	else if (x < t->element) {
		insert(std::move(x), t->left);
	}
	else if (x > t->element) {
		insert(std::move(x), t->right);
	}
	else {
		return; // Duplicate, do nothing.
	}
}

// Internal method to remove from a subtree.
// x is the item to remove.
// t is the node that roots the subtree
// Set the new root of the subtree.
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable& x, BinaryNode*& t) {
	if (t == nullptr) {
		return; // Item not found, do nothing.
	}
	if (x < t->element) {
		remove(x, t->left);
	} else if (x > t->element) {
		remove(x, t->right);
	} else if (t-> left != nullptr && t->right != nullptr) { // Two children
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	} else {
		BinaryNode* oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
		size_--;
	}
}

// Internal function to make subtree empty.
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(){
	makeEmpty(root);
}

// Internal function to make subtree empty.
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode*& t){
	if (t != nullptr) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}

// Internal function to clone subtree.
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode* BinarySearchTree<Comparable>::clone(BinaryNode* t) const {
	if (t == nullptr) {
		return nullptr;
	} else {
		return new BinaryNode{t->element, clone(t->left), clone(t->right)};
	}
}

template <typename Comparable>
size_t BinarySearchTree<Comparable>::size() const {
	return size_;
}
