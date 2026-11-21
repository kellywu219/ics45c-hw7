#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <sstream>
#include <string>

#include <utility>

#include <iomanip>


template <typename T>
Array<T>::Array() : len{0}, buf{nullptr} {
}

template <typename T>
int Array<T>::length() const {
    return len;
}

template <typename T>
void Array<T>::fill(const T& val) {
    for (int i = 0; i < len; ++i) {
        buf[i] = val;
    }
}

template <typename T>
bool Array<T>::in_bounds(int index) const {
    return index >= 0 && index < len;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if (!in_bounds(index)) {
        throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
    }
    return buf[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (!in_bounds(index)) {
        throw "Exception operator[](" + std::to_string(index) + ") Out Of Range";
    }
    return buf[index];
}

template <typename T>
Array<T>::~Array() {
    delete[] buf;
}

template <typename T>
Array<T>::Array(const Array& other) : Array(other.len) {
    for (int i = 0; i < len; ++i) {
        buf[i] = other.buf[i];
    }
}

template <typename T>
Array<T>::Array(Array&& other) noexcept
    : len{other.len}, buf{other.buf} {
    other.buf = nullptr;
    other.len = 0;
}

template <typename T>
void swap(Array<T>& lhs, Array<T>& rhs) noexcept {
    std::swap(lhs.len, rhs.len);
    std::swap(lhs.buf, rhs.buf);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        Array temp{other};
        swap(*this, temp);
    }
    return *this;
}

template <typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] buf;
        len = other.len;
        buf = other.buf;

        other.len = 0;
        other.buf = nullptr;
    }
    return *this;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array) {
    std::stringstream temp;
    temp << std::setprecision(2) << std::fixed << std::right;

    for (int i = 0; i < array.length(); ++i) {
        temp << std::setw(8) << array[i];
    }

    out << temp.str();
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Array<T>& array) {
    for (int i = 0; i < array.length(); ++i) {
        in >> array[i];
    }
    return in;
}

#endif