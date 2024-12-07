#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* data;

public:
    String(const char* str) {
        size_t len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);         // Копіюємо вміст рядка
    }

    ~String() {
        delete[] data;
    }

    // Переведення класу в C-рядок
    const char* c_str() const {
        return data;
    }

    int countWordOccurrences(const String& word) const {
        int count = 0;
        const char* found = data;
        size_t word_len = strlen(word.c_str());

        // Шукаємо всі входження слова в рядок
        while ((found = strstr(found, word.c_str())) != nullptr) {
            count++;
            found += word_len;
        }
        return count;
    }

    int countSubstringOccurrences(const String& substring) const {
        int count = 0;
        const char* found = data;
        size_t sub_len = strlen(substring.c_str());

        // Шукаємо всі входження підрядка в рядок
        while ((found = strstr(found, substring.c_str())) != nullptr) {
            count++;
            found += sub_len;
        }
        return count;
    }
};

int main() {
    String text("this is a test. this is another test.");
    String word("test");
    String substring("is");
    int wordCount = text.countWordOccurrences(word);
    int substringCount = text.countSubstringOccurrences(substring);
    cout << "The word \"" << word.c_str() << "\" appears " << wordCount << " times in the text.\n";
    cout << "The substring \"" << substring.c_str() << "\" appears " << substringCount << " times in the text.\n";
}
