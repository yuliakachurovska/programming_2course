#include <iostream>
#include "Rational.h" // Підключаю файл з раціональними числами
#include <vector>

template<typename T>
class Polynomial {
private:
    std::vector<T> coeff;

public:
    Polynomial() = default;
    Polynomial(const std::vector<T>& coeffs) : coeff(coeffs) {}

    void input() {
        size_t degree;
        std::cout << "Enter degree of the polynomial: ";
        std::cin >> degree;
        coeff.resize(degree + 1);
        std::cout << "Enter coeff (from lowest to highest degree): ";
        for (size_t i = 0; i <= degree; ++i) {
            std::cin >> coeff[i];
        }
    }

    void output() const {
        for (size_t i = coeff.size(); i-- > 0;) {
            std::cout << coeff[i];
            if (i > 0) {
                std::cout << "x^" << i << " + ";
            }
        }
        std::cout << std::endl;
    }

    Polynomial operator+(const Polynomial& other) const {
        size_t maxDegree = std::max(coeff.size(), other.coeff.size());
        std::vector<T> res(maxDegree, T{});

        for (size_t i = 0; i < maxDegree; ++i) {
            if (i < coeff.size()) res[i] += coeff[i];
            if (i < other.coeff.size()) res[i] += other.coeff[i];
        }

        return Polynomial(res);
    }

    Polynomial operator*(const Polynomial& other) const {
        size_t resDegree = coeff.size() + other.coeff.size() - 1;
        std::vector<T> res(resDegree, T{});

        for (size_t i = 0; i < coeff.size(); ++i) {
            for (size_t j = 0; j < other.coeff.size(); ++j) {
                res[i + j] += coeff[i] * other.coeff[j];
            }
        }

        return Polynomial(res);
    }

    T evaluate(const T& x) const {
        T res = T{};
        T power = T{1};

        for (const T& coeff : coeff) {
            res += coeff * power;
            power *= x;
        }

        return res;
    }
};

int main() {
    Polynomial<Rational> polyRational({
        Rational(1, 2),  // 1/2
        Rational(3, 4),  // 3/4
        Rational(5, 6)   // 5/6
    });

    std::cout << "Rational polynomial:\n";
    polyRational.output();

    Rational x(2, 1); // x = 2
    std::cout << "Value at x = 2: " << polyRational.evaluate(x) << std::endl;
}
