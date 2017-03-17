// Abdullah Khan
// File: Vector.hpp
// STL-like vector.
// Drawing ideas from what I learned in implementing Array and the repo below:
// https://github.com/lnishan/vector

#pragma once

#include <memory>
#include <utility>
#include <iterator>

template <typename T>
class Vector {
public:
	// Types:
	using value_type = T;
	using size_type = size_t;
	using reference = T&;
	using const_reference = const T&;
	using pointer = T*;
	using const_pointer = const T*;
	using iterator = T*;
	using const_iterator = const T*;

	// Constructors
	Vector(); // Default c-tor
	explicit Vector(size_type size);
	Vector(const Vector&);					// copy-constructor
	Vector& operator=(const Vector&);		// copy-assignment
	Vector(Vector&&);						// move-constructor
	Vector& operator=(Vector&&);			// move-assignment
	~Vector() = default;					// destructor

	// Element access
	reference operator[] (size_type);
	const_reference operator[] (size_type) const;
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

	// Capacity.
	bool empty();
	size_type size() const;

	// Raw data access
	pointer data();
	const_pointer data() const;

	// Modifiers
	void push_back(const T&);
	void pop_back();
	void clear();

	// Iterator functions
	iterator begin() { return &array.get()[0]; }
	iterator end() { return &array.get()[vector_size]; }
	const_iterator begin() const { return &array.get()[0]; }
	const_iterator end() const { return &array.get()[vector_size]; }
	const_iterator cbegin() const { return begin(); }
	const_iterator cend() const { return end(); }
private:
	std::unique_ptr<T[]> array;
	size_type vector_size = 0;
	size_type reserved_size = 0;
};

#include "Vector.cpp"
