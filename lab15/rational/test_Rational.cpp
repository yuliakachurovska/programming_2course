#include "Rational.h"
#include <iostream>
#include <cmath>

Rational MinRational(const Rational* arr, int n) {
    Rational minRat = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i].less(minRat)) {
            minRat = arr[i];
        }
    }
    return minRat;
}

Rational Gregory(double eps) {
    Rational s;
    int sign = -1;
    for (int i = 1; eps * i * i < 1; i++) {
        Rational tmp;
        tmp.setNom(sign);
        tmp.setDenom(i * i);
        s = s.add(tmp);
        sign = -sign;
    }
    return s;
}

int main() {
    Rational r1, r2(2, 3);
    r1.input();

    Rational r3 = r1.add(r2);
    Rational r4 = r1.mult(r2);
    r3.show();
    r4.show();

    unsigned p = Rational::gcd(60, 35);
    std::cout << p << std::endl;

    Rational q = Gregory(0.01);
    q.show();
    std::cout << q.compare(M_PI * M_PI / 12.0) << std::endl;
}