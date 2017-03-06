// Abdullah Khan
// File: Vector.hpp
// STL-like vector.

#pragma once

#include <memory>

template <typename T>
class Vector {
private:
// TODO
public:
    Vector(); // Default c-tor
    ~Vector() = default; // Destructor.

    // Public accessors.
    T& operator[] (size_t); // Accessor operator? I don't know what it's called.
    T const& operator[] (size_t) const; // const version

    // Public operations.
    int size() const; // Return size.
    T* data(); // Return underlying array.

    // Iterators
    // using iterator = T*;
    // iterator begin() { return &array_.get()[0]; }
    // iterator end() { return &array_.get()[size_]; }

    // using const_iterator = const T*;
    // const_iterator begin() const { return &array_.get()[0]; }
    // const_iterator end() const { return &array_.get()[size_]; }
    // const_iterator cbegin() const { return begin(); }
    // const_iterator cend() const { return end(); }
};

#include "Vector.cpp"
