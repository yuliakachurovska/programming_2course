#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>

void processFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    int numbers[1000];
    size_t count = 0;

    while (inputFile >> numbers[count]) {
        ++count;
    }
    inputFile.close();

    for (size_t i = 0; i < count - 1; ++i) {
        if (numbers[i] > numbers[i + 1]) {
            numbers[i] = std::pow(numbers[i], 2);
        }
    }

    std::ofstream outputFile(fileName);
    if (!outputFile) {
        std::cerr << "Error writing to file: " << fileName << std::endl;
        return;
    }

    for (size_t i = 0; i < count; ++i) {
        outputFile << numbers[i];
        if (i != count - 1) {
            outputFile << " ";
        }
    }
    outputFile.close();
}

int main() {
    std::string fileName = "input.txt";  // 5 3 7 2 8 6
    processFile(fileName);
    std::cout << "File processing completed. The result is saved in " << fileName << std::endl;
}
