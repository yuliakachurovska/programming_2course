#ifndef __RATIONAL__
#define __RATIONAL__

#include <iostream>
#include <cmath>
#include <exception>

class WrongRatioException : public std::exception {
    int nom;
public:
    WrongRatioException() {}
    WrongRatioException(int x) : nom(x) {}

    const char* what() const noexcept override {
        return "Denominator can't be 0";
    }

    void show() {
        std::cerr << "Ratio Exception\n" << nom << "\n";
    }
};

class Rational {
private:
    int nom;    // чисельник
    unsigned denom;  // знаменник

public:
    Rational() : nom(1), denom(1U) {}

    Rational(int x, unsigned y) : nom(x), denom(y) {
        if (denom == 0) throw WrongRatioException();
        reduce();
    }

    void show() const {
        std::cout << nom << "/" << denom << std::endl;
    }

    int setNom(int x) {
        nom = x;
        return 0;
    }

    int setDenom(unsigned y) {
        if (y != 0) {
            denom = y;
            return 0;
        }
        throw WrongRatioException(nom);
        return -1;
    }

    Rational add(const Rational& x) const {
        int ch = nom * x.denom + x.nom * denom;
        unsigned zn = denom * x.denom;
        return Rational(ch, zn);
    }

    Rational mult(const Rational& x) const {
        int ch = nom * x.nom;
        unsigned zn = denom * x.denom;
        return Rational(ch, zn);
    }

    Rational operator+(const Rational& x) {
        return add(x);
    }

    Rational operator*(const Rational& x) {
        return mult(x);
    }

    Rational operator-(const Rational& x) {
        int ch = static_cast<int>(x.denom * nom - x.nom * denom);
        unsigned zn = x.denom * denom;
        return Rational(ch, zn);
    }

    Rational operator/(const Rational& x) {
        int ch = static_cast<int>(x.denom * nom);
        unsigned zn = x.nom * denom;
        return Rational(ch, zn);
    }

    Rational operator-() const {
        return Rational(-nom, denom);
    }

    bool less(const Rational& x) const {
        return (nom * x.denom < denom * x.nom);
    }

    bool operator<(const Rational& x) const {
        return less(x);
    }

    bool operator>(const Rational& x) const {
        return !less(x);
    }

    bool operator==(const Rational& x) const {
        return (nom * x.denom == denom * x.nom);
    }

    bool operator!=(const Rational& x) const {
        return !(*this == x);
    }

    bool operator<(double x) const {
        return fabs(x - static_cast<double>(nom) / denom) > 1e-9;
    }

    bool compare(double z) const {
        return fabs(z - static_cast<double>(nom) / denom) < 1e-9;
    }

    static unsigned gcd(unsigned x, unsigned y) {
        while (y != 0) {
            unsigned temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }

    void reduce() {
        int g = gcd(nom, denom);
        nom /= g;
        denom /= g;
    }

    friend std::ostream& operator<<(std::ostream& output, const Rational& D) {
        output << D.nom << "/" << D.denom;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, Rational& D) {
        input >> D.nom >> D.denom;
        if (D.denom == 0) throw WrongRatioException();
        D.reduce();
        return input;
    }
};

#endif // __RATIONAL__