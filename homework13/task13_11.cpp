#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

const size_t MAX_LENGTH = 50;

void centerAlignFile(const std::string& fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inputFile, line)) {
        lines.push_back(line);
    }
    inputFile.close();

    std::ofstream outputFile(fileName);
    if (!outputFile) {
        std::cerr << "Error writing to file: " << fileName << std::endl;
        return;
    }

    for (const auto& l : lines) {
        size_t lineLength = l.length();
        if (lineLength == 0) {
            outputFile << "\n";
            continue;
        }

        size_t totalSpaces = MAX_LENGTH - lineLength;
        size_t spacesToAdd = totalSpaces / 2;

        if (lineLength % 2 != 0) {
            spacesToAdd += 1;
        }

        for (size_t i = 0; i < spacesToAdd; ++i) {
            outputFile << " ";
        }
        outputFile << l << "\n";
    }

    outputFile.close();
}

int main() {
    std::string fileName = "text.txt";
    centerAlignFile(fileName);
    std::cout << "File has been centered and saved in " << fileName << std::endl;
}
