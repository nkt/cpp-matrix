#ifndef __Matrix_H_
#define __Matrix_H_

#include <iostream>

template<typename T, typename K = double>

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

    inline void checkEqualSizes(const Matrix &arg) const
    {
        if (arg.n != n || arg.m != m) {
            throw new std::runtime_error("The matrix sizes not equals");
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

    Matrix(const Matrix &arg) : Matrix(arg.n, arg.m)
    {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                matrix[i][j] = arg.matrix[i][j];
            }
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

    Matrix operator+(const Matrix &arg) const
    {
        checkEqualSizes(arg);
        Matrix<T, K> result(n, m);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                result.matrix[i][j] = matrix[i][j] + arg.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const K &num) const
    {
        Matrix<T, K> result(n, m);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < m; ++j) {
                result.matrix[i][j] = matrix[i][j] * num;
            }
        }
        return result;
    }

    Matrix operator-(const Matrix &arg) const
    {
        return (arg * -1) + *this;
    }

    Matrix operator*(const Matrix &arg) const
    {
        Matrix<T, K> result(n, m);
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < arg.m; ++j) {
                for (size_t k = 0; k < m; ++k) {
                    result.matrix[i][j] = matrix[i][k] * arg.matrix[k][j];
                }
            }
        }
        return result;
    }


    friend std::ostream &operator<<(std::ostream &output, Matrix &arg)
    {
        for (size_t i = 0; i < arg.n; ++i) {
            for (size_t j = 0; j < arg.m; ++j) {
                output << arg.matrix[i][j] << " ";
            }
            output << std::endl;
        }
        return output;
    }

};

#endif
