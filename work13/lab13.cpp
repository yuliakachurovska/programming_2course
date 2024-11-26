#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <climits>

//task1
std::string newstring(const std::string& input) {
    size_t p1 = input.find(':');
    if (p1 == std::string::npos) {
        return input;
    }

    size_t commaP = input.find(',', p1 + 1);
    if (commaP == std::string::npos) {
        return input.substr(p1 + 1);
    }

    return input.substr(p1 + 1, commaP - p1 - 1);
}

void inPlace(std::string& input) {
    size_t p1 = input.find(':');
    if (p1 == std::string::npos) {
        return;
    }

    size_t commaP = input.find(',', p1 + 1);
    if (commaP == std::string::npos) {
        input = input.substr(p1 + 1);
    } else {
        input = input.substr(p1 + 1, commaP - p1 - 1);
    }
}

//task2
void task2(std::string& input) {
    size_t dot1 = input.find(".");
    if (dot1 == std::string::npos) {
        size_t firstNonSpace = input.find_first_not_of(' ');
        input = (firstNonSpace == std::string::npos) ? "" : input.substr(firstNonSpace);
        return;
    }

    size_t dot2 = input.rfind(".");
    if (dot1 == dot2) {
        input = input.substr(dot1);
        return;
    }

    input = input.substr(0, dot1 + 1) + input.substr(dot2);
}

//task3
void task3(std::string& input) {
    size_t start = 0;
    for (size_t i = 0; i <= input.length(); ++i) {
        if (i == input.length() || input[i] == ' ') {
            if (i > start) {
                input[i - 1] = ' ';
            }
            start = i + 1;
        }
    }
}

// Task 4
bool isValidNumber(const std::string& str) {
    std::istringstream iss(str);
    double num;
    char c;
    return (iss >> num) && !(iss >> c);
}

void task4() {
    std::string input;
    char delimiter;
    size_t n;

    std::cout << "Enter the string: ";
    std::getline(std::cin, input);
    std::cout << "Enter the delimiter: ";
    std::cin >> delimiter;
    std::cout << "Enter the number of values to extract (n): ";
    std::cin >> n;

    std::vector<double> result;
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, delimiter) && result.size() < n) {
        if (isValidNumber(token)) {
            result.push_back(std::stod(token));
        }
    }

    std::cout << "Extracted numbers: ";
    for (double num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

//task5
std::vector<std::string> partialSplit(const std::string& input, char delimiter, size_t n) {
    std::vector<std::string> result;
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, delimiter) && result.size() < n) {
        result.push_back(token);
    }
    return result;
}

void task5() {
    std::string input;
    char delimiter;
    size_t n;

    std::cout << "Enter the string: ";
    std::getline(std::cin, input);
    std::cout << "Enter the delimiter: ";
    std::cin >> delimiter;
    std::cout << "Enter the number of words to extract (n): ";
    std::cin >> n;

    std::vector<std::string> words = partialSplit(input, delimiter, n);

    std::cout << "Extracted words: ";
    for (const std::string& word : words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;
}

//task6
void task6(const std::string& sentence) {
    int minLength = INT_MAX;
    std::string firstShortestWord = "", lastShortestWord = "";
    std::string words[100];
    int wordCount = 0;

    std::string currentWord = "";
    for (char c : sentence + " ") {
        if (std::isalpha(c)) {
            currentWord += c;
        } else if (!currentWord.empty()) {
            int length = currentWord.length();
            if (length < minLength) {
                minLength = length;
                firstShortestWord = currentWord;
                lastShortestWord = currentWord;
                wordCount = 0;
                words[wordCount++] = currentWord;
            } else if (length == minLength) {
                lastShortestWord = currentWord;
                words[wordCount++] = currentWord;
            }
            currentWord = "";
        }
    }

    std::cout << "Shortest word length: " << minLength << std::endl;
    std::cout << "First shortest word: " << firstShortestWord << std::endl;
    std::cout << "Last shortest word: " << lastShortestWord << std::endl;
    std::cout << "All shortest words: ";
    for (int i = 0; i < wordCount; i++) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    //1
    std::cout << "Task1" << "\n";
    std::string str1 = "hello:world,example";
    std::string str2 = "hello:world";
    std::string str3 = "hello world,example";
    std::string str4 = "hello world";

    std::cout << "Input: \"" << str1 << "\" -> \"" << newstring(str1) << "\"\n";
    std::cout << "Input: \"" << str2 << "\" -> \"" << newstring(str2) << "\"\n";
    std::cout << "Input: \"" << str3 << "\" -> \"" << newstring(str3) << "\"\n";
    std::cout << "Input: \"" << str4 << "\" -> \"" << newstring(str4) << "\"\n";

    std::cout << "\nString replacement:\n";
    std::string str5 = str1, str6 = str2, str7 = str3, str8 = str4;
    inPlace(str5);
    inPlace(str6);
    inPlace(str7);
    inPlace(str8);
    std::cout << "Input: \"" << str1 << "\" -> \"" << str5 << "\"\n";
    std::cout << "Input: \"" << str2 << "\" -> \"" << str6 << "\"\n";
    std::cout << "Input: \"" << str3 << "\" -> \"" << str7 << "\"\n";
    std::cout << "Input: \"" << str4 << "\" -> \"" << str8 << "\"\n";

    // //2
    std::cout << "\n" <<"Task2" << "\n";
    std::string inputs[] = {
        "hello world",
        "   hello world",
        "hello.world",
        "hello.world.example"
    };

    for (auto& str : inputs) {
        std::string original = str;
        task2(str);
        std::cout << "Input: \"" << original << "\" => \"" << str << "\"\n";
    }
 
    // //3
    std::cout << "\n" <<"Task3" << "\n";
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    task3(input);
    std::cout << "Result: " << input << std::endl;

    //4
    std::cout << "\n" <<"Task4" << "\n";
    task4();

    //5
    std::cout << "\n" <<"Task5" << "\n";
    task5();

    //6
    std::cout << "\n" <<"Task6" << "\n";
    std::string sentence;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, sentence);

    task6(sentence);
}