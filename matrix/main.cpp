#include <iostream>
#include "Matrix.hpp"


template<typename T>
Matrix<T> generateMatrix(size_t n, size_t m)
{
    Matrix<T> result(n, m);
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            result.set(i, j, rand() % 10);
        }
    }
    return result;
}

int main(int argc, const char *argv[])
{
    try {
        auto m1 = generateMatrix<int>(2, 2), m2 = generateMatrix<int>(2, 2);
        std::cout << m1 << std::endl << m2 << std::endl;
        auto res = m1 * m2;
        std::cout << res;
    } catch (std::runtime_error *e) {
        std::cerr << e->what() << std::endl;
    }

    return 0;
}