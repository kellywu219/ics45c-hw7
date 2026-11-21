#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
Array<T>::Array() : len{0}, buf{nullptr} {
}

template <typename T>
int Array<T>::length() const {
    return len;
}