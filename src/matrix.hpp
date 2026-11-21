#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <iomanip>

template <typename T>
Matrix<T>::Matrix() : rows{0}, cols{0}, data{} {
}

template <typename T>
Matrix<T>::Matrix(int rows, int cols)
    : rows{rows}, cols{cols}, data{rows} {
    for (int i = 0; i < rows; ++i) {
        data[i] = Array<T>{cols};
    }
}

template <typename T>
int Matrix<T>::num_rows() const {
    return rows;
}

template <typename T>
int Matrix<T>::num_cols() const {
    return cols;
}

template <typename T>
void Array<T>::fill(const T& val) {
    for (int i = 0; i < len; ++i) {
        buf[i] = val;
    }
}