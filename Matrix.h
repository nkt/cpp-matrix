#ifndef __Matrix_H_
#define __Matrix_H_

#include <iostream>

template<typename T>
class Matrix {
protected:
    T **matrix;
    size_t n;
    size_t m;

    inline void checkIndexes(size_t i, size_t j) const;

public:
    Matrix(size_t n, size_t m);

    void set(size_t i, size_t j, const T value);

    T get(size_t i, size_t j) const;

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
