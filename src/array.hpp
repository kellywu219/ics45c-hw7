#ifndef ARRAY_HPP
#define ARRAY_HPP

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
}