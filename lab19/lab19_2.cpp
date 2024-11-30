#include <iostream>
#include <vector>
#include <cmath>

double Norm_vect(const std::vector<double>& vec) {
    double sum = 0.0;
    for (double val : vec) {
        sum += val * val;
    }
    return std::sqrt(sum);
}

std::vector<double> inputVector(int d) {
    std::vector<double> vec(d);
    std::cout << "Enter the elements of a " << d << "-dimensional vector: ";
    for (int i = 0; i < d; ++i) {
        std::cin >> vec[i];
    }
    return vec;
}

int main() {
    int d = 3; // Розмірність
    int p = 2; // Кількість векторів

    std::vector<std::vector<double>> vectors = {
        {1.0, 2.0, -2.0},
        {3.0, -4.0, 0.0}
    };

    double summ = 0.0;
    for (const auto& vec : vectors) {
        summ += Norm_vect(vec);
    }

    std::cout << "Dimension of vectors: " << d << std::endl;
    std::cout << "Number of vectors: " << p << std::endl;
    for (size_t i = 0; i < vectors.size(); ++i) {
        std::cout << "Vector " << i + 1 << ": ";
        for (double val : vectors[i]) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "Sum of norms of the vectors: " << summ << std::endl;
}
