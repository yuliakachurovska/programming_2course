#include <iostream>
#include <fstream>
#include <stdexcept>

class Rational {
private:
    int numerator;   // Чисельник
    int denominator; // Знаменник

public:
    Rational(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        if (denom < 0) {
            numerator = -numerator;
            denominator = -denom;
        }
    }

    void setNumerator(int num) {
        numerator = num;
    }

    void setDenominator(int denom) {
        if (denom == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        if (denom < 0) {
            numerator = -numerator;
            denominator = -denom;
        } else {
            denominator = denom;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r.numerator << "/" << r.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Rational& r) {
        int num, denom;
        char slash;
        is >> num >> slash >> denom;
        if (slash != '/' || denom == 0) {
            throw std::invalid_argument("Invalid input format or denominator is zero.");
        }
        r = Rational(num, denom);
        return is;
    }

    Rational operator-() const {
        return Rational(-numerator, denominator);
    }

    Rational operator-(const Rational& other) const {
        return Rational(
            numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator
        );
    }

    Rational operator/(const Rational& other) const {
        if (other.numerator == 0) {
            throw std::domain_error("Division by zero.");
        }
        return Rational(numerator * other.denominator, denominator * other.numerator);
    }

    friend void writeToFile(const Rational& r, const std::string& filename) {
        std::ofstream file(filename);
        if (!file) {
            throw std::ios_base::failure("Failed to open file.");
        }
        file << r;
        file.close();
    }
};

int main() {
    try {
        Rational r1(3, 4);
        Rational r2(2, 5);

        std::cout << "r1: " << r1 << std::endl;
        std::cout << "r2: " << r2 << std::endl;

        Rational r3 = r1 - r2;
        std::cout << "r1 - r2: " << r3 << std::endl;

        Rational r4 = r1 / r2;
        std::cout << "r1 / r2: " << r4 << std::endl;

        std::cout << "Enter a rational number (format: a/b): ";
        Rational r5;
        std::cin >> r5;
        std::cout << "You entered: " << r5 << std::endl;

        writeToFile(r5, "output.txt");
        std::cout << "Rational number saved to file." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}