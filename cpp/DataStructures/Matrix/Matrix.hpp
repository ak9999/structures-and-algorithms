// Abdullah Khan
// File: Matrix.hpp
// N-dimensional Matrix class, following the example in Ch. 29 of TC++PL.

#include <vector>

template <typename T, size_t N>
class Matrix {
private:
	Matrix_slice<N> desc;							// Slice defining extents in the N dimensions
	std::vector<T> elems;							// The elements
public:
	static constexpr size_t order = N;				// static variable
	
	// alias-declarations
	using value_type = T;
	using iterator = typename std::vector<T>::iterator;
	using const_iterator = typename std::vector<T>::const_iterator;

	// Constructors
	Matrix() = default;								// Default
	Matrix(Matrix&&) = default;						// Move
	Matrix& operator=(Matrix&&) = default;			// Move assignment
	Matrix(Matrix const&) = default;				// Copy
	Matrix& operator=(Matrix const&) = default;		// Copy assignment
	~Matrix() = default;							// Destructor

	template <typename U>
		Matrix(const Matrix_ref<U, N>&);			// Construct from Matrix_ref
	template <typename U>
		Matrix& operator=(const Matrix_ref<U, N>&);	// Assign from Matrix_ref
	template <typename... Exts>						// Specify the elements
		explicit Matrix(Exts... exts);

	Matrix(Matrix_initializer<T, N>);				// Initialize from list
	Matrix& operator=(Matrix_initializer<T, N>);	// Assign from list

	template <typename U>
		Matrix(std::initializer_list<U>) = delete;	// Don't use {} except for elements.
	template <typename U>
		Matrix& operator=(std::intializer_list<U>) = delete;

	static constexpr size_t order() { return N; }	// Number of dimensions
	size_t extent(size_t n) const {					// # elements in nth dimension
		return desc.extents[n];
	}
	size_t size() const { return elems.size(); }	// Total # of elements.
	const Matrix_slice<N>& descriptor() const {		// The slice defining subscripting
		return desc;
	}

	T* data() { return elems.data(); }				// "Flat" element access.
	const T* data() const { return elems.data(); }

};
