#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

template<typename T>
class Array {
    friend std::ostream& operator<<(std::ostream& output, const Array<T>& a) {
        for (size_t i = 0; i < a.size; ++i) {
            output << a.ptr[i] << " ";
        }
        return output;
    }

    friend std::istream& operator>>(std::istream& input, Array<T>& a) {
        for (size_t i = 0; i < a.size; ++i) {
            input >> a.ptr[i];
        }
        return input;
    }

public:
    // Constructs an array with specified size, initializing all elements to default value
    explicit Array(int arraySize = 10)
        : size(arraySize > 0 ? arraySize : throw std::invalid_argument("Array size must be positive")),
          ptr(new T[size]) {
        // Initialize all elements to default value of type T
        for (size_t i = 0; i < size; ++i) {
            ptr[i] = T();
        }
    }

    // Copy constructor performs deep copy of the source array
    Array(const Array& source) : size(source.size), ptr(new T[size]) {
        // Copy all elements from source array
        for (size_t i = 0; i < size; ++i) {
            ptr[i] = source.ptr[i];
        }
    }

    // Destructor deallocates dynamic memory
    ~Array() {
        delete[] ptr;
    }

    // Returns the number of elements in the array
    size_t getSize() const {
        return size;
    }

    // Assignment operator creates a deep copy
    const Array& operator=(const Array& right) {
        if (&right != this) {
            // Handle arrays of different sizes
            if (size != right.size) {
                delete[] ptr;
                size = right.size;
                ptr = new T[size];
            }
            // Copy elements from right array
            for (size_t i = 0; i < size; ++i) {
                ptr[i] = right.ptr[i];
            }
        }
        return *this;
    }

    // Equality comparison operator
    bool operator==(const Array& right) const {
        if (size != right.size) {
            return false;
        }
        for (size_t i = 0; i < size; ++i) {
            if (ptr[i] != right.ptr[i]) {
                return false;
            }
        }
        return true;
    }

    // Inequality operator leverages equality operator
    bool operator!=(const Array& right) const {
        return !(*this == right);
    }

    // Subscript operator for non-const arrays
    T& operator[](int subscript) {
        validateSubscript(subscript);
        return ptr[subscript];
    }

    // Subscript operator for const arrays
    const T& operator[](int subscript) const {
        validateSubscript(subscript);
        return ptr[subscript];
    }

private:
    size_t size;
    T* ptr;

    // Validates array subscript
    void validateSubscript(int sub) const {
        if (sub < 0 || sub >= static_cast<int>(size)) {
            throw std::out_of_range("Subscript out of range");
        }
    }
};

#endif