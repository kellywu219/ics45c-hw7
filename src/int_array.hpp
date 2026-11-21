#ifndef INT_ARRAY_HPP
#define INT_ARRAY_HPP

#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>
#include <string>

class Array {
public:
    Array() : len{0}, buf{nullptr} {
    }

    explicit Array(int len) : len{len}, buf{new int[len]} {
    }

    // TODO Step 4: copy constructor
    Array(const Array& other) : len{other.len}, buf{new int[other.len]} {
        for (int i = 0; i < len; ++i) {
            buf[i] = other.buf[i];
        }
    }
    // TODO Step 4: move constructor
    Array(Array&& other) noexcept : len{other.len}, buf{other.buf} {
    other.len = 0;
    other.buf = nullptr;
    }
    // TODO Step 5: friend void swap(Array& lhs, Array& rhs) noexcept
    friend void swap(Array& lhs, Array& rhs) noexcept {
        std::swap(lhs.len, rhs.len);
        std::swap(lhs.buf, rhs.buf);
    }
    // TODO Step 5: copy assignment
    Array& operator=(const Array& other) {
        if (this != &other) {
            Array temp {other};
            swap(*this, temp);
        }
        return *this;
    }
    // TODO Step 5: move assignment
    Array& operator=(Array&& other) noexcept{
        if (this != &other) {
            delete[] buf;
            len = other.len;
            buf = other.buf;
    
            other.len = 0;
            other.buf = nullptr;
        }
        return *this;
    }

    // TODO Step 4: destructor
    ~Array() {
    delete[] buf;
    }

    int length() const {
        return len;
    }

    int& operator[](int index) {
        // TODO Step 3: throw std::string when the index is out of bounds:
        //     "Exception operator[](" + std::to_string(index) + ") Out Of Range"
        if (!in_bounds(index)) {
            throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
        }
        return buf[index];
    }

    const int& operator[](int index) const {
        // TODO Step 3: the same check as above
        if (!in_bounds(index)) {
            throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
        }
        return buf[index];
    }

    // TODO Step 2: void fill(int val) - set every element to val
    void fill(int val) {
        for (int i = 0; i < len; ++i) {
            buf[i] = val;
        }
    }
private:
    int len;
    int* buf;

    bool in_bounds(int index) const {
        return index >= 0 && index < len;
    }
};

inline std::ostream& operator<<(std::ostream& out, const Array& array) {
    std::stringstream temp;
    // We don't want to set formatting flags globally.
    temp << std::setprecision(2) << std::fixed << std::right;

    for (int i = 0; i < array.length(); ++i) {
        temp << std::setw(8) << array[i];
    }

    out << temp.str();
    return out;
}

inline std::istream& operator>>(std::istream& in, Array& array) {
    for (int i = 0; i < array.length(); ++i) {
        in >> array[i];
    }

    return in;
}

#endif
