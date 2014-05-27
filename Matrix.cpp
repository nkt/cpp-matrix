#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(size_t n, size_t m) : n(n), m(m)
{
    matrix = new T *[n];
    for (size_t i = 0; i < n; ++i) {
        matrix[i] = new T[m];
    }
}

template<typename T>
void Matrix<T>::set(size_t i, size_t j, const T value)
{
    checkIndexes(i, j);
    matrix[i][j] = value;
}

template<typename T>
T Matrix<T>::get(size_t i, size_t j) const
{
    checkIndexes(i, j);
    return matrix[i][j];
}

template<typename T>
void Matrix<T>::checkIndexes(size_t i, size_t j) const
{
    if (i > n || j > m) {
        throw new std::runtime_error("The indexes is outside the valid range");
    }
}
