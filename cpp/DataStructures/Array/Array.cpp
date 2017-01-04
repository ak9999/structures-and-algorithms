// Abdullah Khan
// Array implementation

#include "Array.hpp"

template <typename T, size_t N>
Array<T, N>::Array()
    : array_{std::make_unique<T[]>(N)}
    , size_{N}
{}

template <typename T, size_t N>
Array<T, N>::Array(std::initializer_list<T> lst) {
    for (auto i : lst) {
        array_[i] = i;
    }
    size_ = lst.size();
}

template <typename T, size_t N>
Array<T, N>::~Array() { }

template <typename T, size_t N>
T& Array<T, N>::operator[] (size_t index) {
    return array_[index];
}

template <typename T, size_t N>
T const& Array<T, N>::operator[] (size_t index) const {
    return array_[index];
}

template <typename T, size_t N>
size_t Array<T, N>::size() const {
    return size_;
}
