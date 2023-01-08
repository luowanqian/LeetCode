#ifndef SOLUTIONS_PRINT
#define SOLUTIONS_PRINT

#include <vector>
#include <iostream>

template <typename T>
void printVector(const std::vector<T>& arr)
{
    std::cout << "Arr: ";
    for (auto& x : arr) {
        std::cout << x << ", ";
    }
    std::cout << std::endl;
}

#endif