#include <iostream>
#include "Matrix.h"

int main(int argc, const char *argv[])
{
    Matrix<int> m(5, 5);
    m.set(0,0,1);
    for (size_t i = 0; i < 5; ++i) {
        for (size_t j = 0; j < 5; ++j) {
            m.set(i, j, rand() % 10);
        }
    }
    std::cout << m;
    return 0;
}