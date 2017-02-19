// Abdullah Khan
// Array implementation

#include "Array.hpp"
#include <algorithm> // std::copy

template <typename T, size_t N>
Array<T, N>::Array() {}

template <typename T, size_t N>
Array<T, N>::Array(std::initializer_list<T> lst) {
	std::copy(lst.begin(), lst.begin() + size_, array_.get());
}

template <typename T, size_t N>
T& Array<T, N>::operator[] (size_t index) {
	return array_[index];
}

template <typename T, size_t N>
T const& Array<T, N>::operator[] (size_t index) const {
	return array_[index];
}

template <typename T, size_t N>
int Array<T, N>::size() const {
	return size_;
}

template <typename T, size_t N>
T* Array<T, N>::data() {
	return array_.get();
}
