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
Array<T>& Matrix<T>::operator[](int row) {
    return data[row];
}

template <typename T>
const Array<T>& Matrix<T>::operator[](int row) const {
    return data[row];
}

template <typename T>
void Matrix<T>::fill(const T& val) {
    for (int i = 0; i < rows; ++i) {
        data[i].fill(val);
    }
}

template <typename T>
template <typename Fn>
void Matrix<T>::fill_with_fn(Fn fn) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = fn(i, j(;
        }
    }
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const Matrix<T>& matrix) {
    for (int i = 0; i < matrix.num_rows(); ++i) {
        out << matrix[i] << '\n';
    }
    return out;
}

template <typename T>
std::istream& operator>>(std::istream& in, Matrix<T>& matrix) {
    for (int i = 0; i < matrix.num_rows(); ++i) {
        in >> matrix[i];
    }
    return in;
}
#endif