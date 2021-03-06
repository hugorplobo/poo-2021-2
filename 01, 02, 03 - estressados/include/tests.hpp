#ifndef SIMPLE_TEST_HPP
#define SIMPLE_TEST_HPP

#include <iostream>
#include <vector>

template <typename T>
void testar(const T& A, const T& B) {
    if (A == B)
        std::cout << "\tOk\n";
    else
        std::cout << "\t" << A << " != " << B << "\n";
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[ ";
    for (auto i : v)
        os << i << " ";
    os << "]";
    return os;
}

#endif