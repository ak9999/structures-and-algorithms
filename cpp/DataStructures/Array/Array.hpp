// Abdullah Khan
// File: Array.hpp
// My attempt to implement a memory-safe static array.

#pragma once

#include <memory>
#include <initializer_list>

template <typename T, size_t N>
class Array {
private:
    const size_t size_ = N;
    std::unique_ptr<T[]> array_ = std::make_unique<T[]>(N);
public:
    Array(); // Default c-tor
    Array(const Array&) = delete; // No copy-constructor.
    Array(Array&&) = delete; // No move-constructor.
    // Array(std::initializer_list<T> lst); // Initializer-list constructor.
    ~Array(); // Destructor.

    // Public accessors.
    T& operator[] (size_t); // Accessor operator? I don't know what it's called.
    T const& operator[] (size_t) const; // const version

    // Public operations.
    int size() const; // Return size.
    T* data(); // Return underlying array.
};

#include "Array.cpp"
