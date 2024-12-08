//19.10г
#include <iostream>
#include <string>
#include <stack>

class Auto {
private:
    std::string name;
    std::string model;
    std::string number;
    int ownerID;

public:
    Auto(const std::string& name, const std::string& model, const std::string& number, int ownerID)
        : name(name), model(model), number(number), ownerID(ownerID) {}

    void output() const {
        std::cout << "Car Name: " << name << ", Model: " << model
                  << ", Number: " << number << ", Owner ID: " << ownerID << std::endl;
    }

    void arrivalMessage() const {
        std::cout << "The car " << name << " " << model << " (" << number << ") has arrived." << std::endl;
    }

    void departureMessage() const {
        std::cout << "The car " << name << " " << model << " (" << number << ") has left." << std::endl;
    }
};

void displayStack(std::stack<Auto>& storage) {
    std::cout << "Current storage state:\n";
    std::stack<Auto> temp = storage;
    while (!temp.empty()) {
        temp.top().output();
        temp.pop();
    }
}

int main() {
    std::stack<Auto> carStorage;

    Auto car1("Toyota", "Corolla", "AB1234CD", 101);
    carStorage.push(car1);
    car1.arrivalMessage();

    Auto car2("Honda", "Civic", "EF5678GH", 102);
    carStorage.push(car2);
    car2.arrivalMessage();

    Auto car3("Ford", "Focus", "IJ9012KL", 103);
    carStorage.push(car3);
    car3.arrivalMessage();

    std::cout << "\nAfter adding cars:\n";
    displayStack(carStorage);

    Auto car4("Nissan", "Altima", "MN3456OP", 104);
    carStorage.push(car4);
    car4.arrivalMessage();

    Auto car5("Chevrolet", "Malibu", "QR7890ST", 105);
    carStorage.push(car5);
    car5.arrivalMessage();

    std::cout << "\nAfter adding more cars:\n";
    displayStack(carStorage);

    carStorage.pop();
    car5.departureMessage();

    carStorage.pop();
    car4.departureMessage();

    std::cout << "\nAfter removing some cars:\n";
    displayStack(carStorage);
}
