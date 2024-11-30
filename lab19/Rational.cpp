#include <iostream>
#include <string>
#include "Rational.h"

template<typename T>
T our_max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 5;
    int y = 3;
    std::cout << our_max(x, y) << std::endl; // Виведе 5

    double a = 7.5;
    double b = 3.4;
    std::cout << our_max(a, b) << std::endl; // Виведе 7.5

    std::string s1("s1");
    std::string s2("s2");
    std::cout << our_max(s1, s2) << std::endl; // Виведе "s2" (порівняння лексикографічне)

    Rational r1(1, 2); // 1/2
    Rational r2(3, 4); // 3/4
    std::cout << our_max(r1, r2) << std::endl; // Виведе 3/4, оскільки 3/4 > 1/2
}