// Abdullah Khan
// File: Array.hpp
// My attempt to implement a memory-safe static array.

#pragma once

#include <memory>

template <typename T, size_t N>
class Array {
private:
    const size_t size_ = N;
    std::unique_ptr<T[]> array_ = std::make_unique<T[]>(N);
public:
    Array(); // Default c-tor
    Array(const Array&) = delete; // No copy-constructor.
    Array(Array&&) = delete; // No move-constructor.
    ~Array(); // Destructor.

    // Public accessors.
    T& operator[] (size_t); // Accessor operator? I don't know what it's called.
    T const& operator[] (size_t) const; // const version

    // Public operations.
    int size() const; // Return size.
    T* data(); // Return underlying array.

    // Iterators
    using iterator = T*;
    using const_iterator = const T*;
    iterator begin() { return &array_.get()[0]; }
    iterator begin() const { return &array_.get()[0]; }
    iterator end() { return &array_.get()[size_]; }
    iterator end() const { return &array_.get()[size_]; }
    // const_iterator cbegin() const { return &array_.get()[0]; }
    // const_iterator cend() const { return &array_.get()[size_]; }
};

#include "Array.cpp"
