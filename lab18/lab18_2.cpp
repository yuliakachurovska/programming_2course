#include<iostream>
#include<stack>

template<typename T>
int input_stack(std::stack<T>& s) {
    T x;
    int count = 0;
    std::cout << "Enter elements (enter 0 to stop): ";
    do {
        std::cin >> x;
        if (x == 0) {
            return count;
        }
        count++;
        s.push(x);
    } while (true);
}

namespace Our {
    template<class T = int>
    struct Node {
        T data;
        Node* ptr;
    };

    template<typename T = int>
    class Stack {
        size_t n;
        Node<T>* current;

    public:
        Stack() : n(0), current(nullptr) {}

        void push(T x) {
            Node<T>* z = new Node<T>;
            z->data = x;
            z->ptr = current;
            current = z;
            n++;
        }

        void pop() {
            if (n == 0) return;
            Node<T>* temp = current;
            current = current->ptr;
            delete temp;
            n--;
        }

        T top() {
            if (n == 0) throw std::out_of_range("Stack is empty");
            return current->data;
        }

        size_t len() {
            return n;
        }

        bool isempty() {
            return n == 0;
        }

        void show() {
            while (!isempty()) {
                std::cout << top() << " ";
                pop();
            }
            std::cout << "\n\n";
        }
    };
}

int main() {
    std::stack<int> s;
    int n = input_stack(s);

    std::cout << "Standard stack (STL):\n";
    std::cout << "Elements entered: ";
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << "\n\n";

    Our::Stack<int> customStack;
    int x;
    std::cout << "Enter elements for custom stack (enter 0 to stop): ";
    while (true) {
        std::cin >> x;
        if (x == 0) break;
        customStack.push(x);
    }

    std::cout << "Custom stack (Our::Stack):\n";
    customStack.show();
    std::cout << "Total elements entered: " << n << std::endl;

}