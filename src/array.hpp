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

template <typename T>


template <typename T>

template <typename T>

