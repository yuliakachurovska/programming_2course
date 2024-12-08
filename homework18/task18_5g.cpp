#include <iostream>
#include <vector>

template <typename T>
class Array {
private:
    size_t size;      // Розмір масиву
    T* data;          // Вказівник на масив даних

public:
    Array(size_t size) : size(size), data(new T[size]) {}

    ~Array() {
        delete[] data;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    size_t getSize() const {
        return size;
    }

    void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    static void insertSort(Array<T>& array) {
        for (int i = 1; i < array.size; i++) {
            T buff = array.data[i];
            int j = i - 1;

            while (j >= 0 && array.data[j] > buff) {
                array.data[j + 1] = array.data[j];
                j--;
            }
            array.data[j + 1] = buff;
        }
    }
};

int main() {
    Array<int> arr(4);
    arr[0] = 12;
    arr[1] = 3;
    arr[2] = 5;
    arr[3] = 9;

    std::cout << "Original: ";
    arr.print();

    Array<int>::insertSort(arr);

    std::cout << "Sorted: ";
    arr.print();
}
