# Array

This is my attempt at implementing my own version of `std::array`.
The array is implemented using a `std::unique_ptr<T[]>`, this way I don't have
to implement a destructor.

Features I'd like to add:
* [x] Iterators
* [x] Construction from initialization list.

No real testing has been done yet, but this class works with some functions in `<algorithm>`.