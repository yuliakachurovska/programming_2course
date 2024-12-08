#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <algorithm>

class StringValidator {
private:
    std::string allowedChars;
    size_t allowedLength;
    std::string userString;
    size_t userLength;

public:
    StringValidator(const char* allowed = "", const char* userInput = "") {
        if (!allowed || !userInput) {
            throw std::invalid_argument("Null pointer passed to StringValidator constructor.");
        }

        allowedChars = allowed;
        userString = userInput;
        allowedLength = allowedChars.length();
        userLength = userString.length();
    }

    ~StringValidator() {}

    // Оператор введення з консолі
    friend std::istream& operator>>(std::istream& is, StringValidator& obj) {
        std::cout << "Enter allowed characters: ";
        is >> obj.allowedChars;
        if (is.fail()) {
            throw std::ios_base::failure("Failed to read allowed characters.");
        }
        obj.allowedLength = obj.allowedChars.length();

        std::cout << "Enter user string: ";
        is >> obj.userString;
        if (is.fail()) {
            throw std::ios_base::failure("Failed to read user string.");
        }
        obj.userLength = obj.userString.length();

        return is;
    }

    // Оператор виведення в консоль
    friend std::ostream& operator<<(std::ostream& os, const StringValidator& obj) {
        os << "Allowed characters: " << obj.allowedChars << " (Length: " << obj.allowedLength << ")" << std::endl;
        os << "User input: " << obj.userString << " (Length: " << obj.userLength << ")" << std::endl;
        return os;
    }

    // Оператор виведення в файл
    friend std::ofstream& operator<<(std::ofstream& ofs, const StringValidator& obj) {
        if (!ofs.is_open()) {
            throw std::ios_base::failure("File could not be opened for writing.");
        }
        ofs << "Allowed characters: " << obj.allowedChars << " (Length: " << obj.allowedLength << ")" << std::endl;
        ofs << "User input: " << obj.userString << " (Length: " << obj.userLength << ")" << std::endl;
        return ofs;
    }

    // Оператор введення з файлу
    friend std::ifstream& operator>>(std::ifstream& ifs, StringValidator& obj) {
        if (!ifs.is_open()) {
            throw std::ios_base::failure("File could not be opened for reading.");
        }

        std::getline(ifs, obj.allowedChars);
        obj.allowedLength = obj.allowedChars.length();

        std::getline(ifs, obj.userString);
        obj.userLength = obj.userString.length();

        return ifs;
    }

    void addAllowedChar(char ch) {
        if (allowedChars.find(ch) == std::string::npos) {
            allowedChars += ch;
            allowedLength = allowedChars.length();
        } else {
            std::cout << "Character '" << ch << "' is already in allowed characters." << std::endl;
        }
    }

    void removeAllowedChar(char ch) {
        auto pos = allowedChars.find(ch);
        if (pos != std::string::npos) {
            allowedChars.erase(pos, 1);
            allowedLength = allowedChars.length();
        } else {
            std::cout << "Character '" << ch << "' not found in allowed characters." << std::endl;
        }
    }

    // Метод конкатенації
    void concatenate() {
        std::string intersection;
        for (char c : userString) {
            if (allowedChars.find(c) != std::string::npos) {
                intersection += c;
            }
        }
        userString += intersection;  // Додаємо перетин до рядка користувача
        userLength = userString.length();
    }

    // Метод хешування (ASCII хеш)
    int asciiHash() const {
        int hash = 0;
        for (char c : userString) {
            hash += static_cast<int>(c);
        }
        return hash;
    }

    size_t getAllowedLength() const {
        return allowedLength;
    }

    size_t getUserLength() const {
        return userLength;
    }
};

int main() {
    try {
        StringValidator validator("abcABC", "acBD");

        std::cout << "\nInitial state:" << std::endl;
        std::cout << validator;

        // Тестування методу довжини
        std::cout << "\nLength of allowedChars: " << validator.getAllowedLength() << std::endl;
        std::cout << "Length of userString: " << validator.getUserLength() << std::endl;

        // Додавання допустимого символу
        std::cout << "\nAdding character 'D' to allowed characters:" << std::endl;
        validator.addAllowedChar('D');
        std::cout << validator;

        // Спроба додавання вже існуючого символу
        std::cout << "\nAdding character 'a' again:" << std::endl;
        validator.addAllowedChar('a');
        std::cout << validator;

        // Видалення символу з допустимих
        std::cout << "\nRemoving character 'B' from allowed characters:" << std::endl;
        validator.removeAllowedChar('B');
        std::cout << validator;

        // Спроба видалення відсутнього символу
        std::cout << "\nRemoving character 'Z' (not in allowed characters):" << std::endl;
        validator.removeAllowedChar('Z');  // Цього символ немає в списку
        std::cout << validator;

        // Тест конкатенації
        std::cout << "\nConcatenating user string with allowed characters intersection:" << std::endl;
        validator.concatenate();
        std::cout << validator;

        // Тест хешування
        std::cout << "\nHash of the user string: " << validator.asciiHash() << std::endl;

        // Перевірка введення/виводу з файлу
        std::ofstream outFile("test_output.txt");
        outFile << validator;
        outFile.close();

        StringValidator fileValidator;
        std::ifstream inFile("test_output.txt");
        inFile >> fileValidator;
        inFile.close();

        std::cout << "\nState after reading from file:" << std::endl;
        std::cout << fileValidator;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
