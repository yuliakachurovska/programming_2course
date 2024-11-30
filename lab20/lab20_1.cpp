#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cctype>

int main() {
    std::ifstream inputFile("text.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordFrequency;
    std::string line, word;

    while (std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        while (lineStream >> word) {
            wordFrequency[word]++;
        }
    }

    inputFile.close();

    std::cout << "Result:\n";
    for (const auto& pair : wordFrequency) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }
}
