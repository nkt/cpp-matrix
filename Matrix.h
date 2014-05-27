#ifndef __Matrix_H_
#define __Matrix_H_

#include <iostream>

template<typename T>
class Matrix {
protected:
    T **matrix;
    size_t n;
    size_t m;

    inline void checkIndexes(size_t i, size_t j) const
    {
        if (i > n || j > m) {
            throw new std::runtime_error("The indexes is outside the valid range");
        }
    }

public:
    Matrix(size_t n, size_t m) : n(n), m(m)
    {
        matrix = new T *[n];
        for (size_t i = 0; i < n; ++i) {
            matrix[i] = new T[m];
        }
    }

    void set(size_t i, size_t j, const T value)
    {
        checkIndexes(i, j);
        matrix[i][j] = value;
    }

    T get(size_t i, size_t j) const
    {
        checkIndexes(i, j);
        return matrix[i][j];
    }


    friend std::ostream &operator<<(std::ostream &output, Matrix &matrix)
    {
        for (size_t i = 0; i < matrix.n; ++i) {
            for (size_t j = 0; j < matrix.m; ++j) {
                output << matrix.matrix[i][j] << " ";
            }
            output << std::endl;
        }
        return output;
    }

};

#endif
