#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* data;
    size_t length;

public:
    String(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);        
    }

    ~String() {
        delete[] data;
    }

    void shiftLetters() {
        for (size_t i = 0; i < length; ++i) {
            if (isalpha(data[i])) {
                if (data[i] == 'z') {
                    data[i] = 'a';
                } else if (data[i] == 'Z') {
                    data[i] = 'A';
                } else {
                    data[i]++;
                }
            }
        }
    }

    void print() const {
        cout << data << endl;
    }
};

int main() {
    const char input[] = "This is a zebra. Her name is Zyuzie";
    cout << input<< endl;
    String myString(input);
    myString.shiftLetters();
    myString.print();
}
