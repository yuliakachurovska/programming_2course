#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    unsigned byear;
    virtual void input() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Byear: ";
        cin >> byear;
    }
    virtual void show() const {
        cout << "Name: " << name << "\nbyear: " << byear << endl;
    }
    friend ostream &operator<<(ostream &out, const Person &p) {
        out << p.name << " " << p.byear;
        return out;
    }
    friend istream &operator>>(istream &in, Person &p) {
        getline(in, p.name, ' ');
        in >> p.byear;
        return in;
    }
};

class Acquaintance : public Person {
public:
    string phone_number;
    void input() {
        Person::input();
        cout << "Enter phone number: ";
        cin >> phone_number;
    }
    void show() const {
        Person::show();
        cout << "Phone number: " << phone_number << endl;
    }
    friend ostream &operator<<(ostream &out, const Acquaintance &a) {
        out << static_cast<const Person &>(a) << " " << a.phone_number;
        return out;
    }
    friend istream &operator>>(istream &in, Acquaintance &a) {
        in >> static_cast<Person &>(a);
        cout << "Enter phone number: ";
        in >> a.phone_number;
        return in;
    }
};

class PhoneBook {
public:
    Acquaintance contacts[100];
    int count;
public:
    PhoneBook() : count(0) {}

    void add_contact(const string &filename) {
        if (count >= 100) {
            cout << "Error: more than 100 contact!" << endl;
            return;
        }
        cout << "Adding new contact:\n";
        contacts[count].input();
        count++;
        save_file(filename);
        cout << "Contact saved to file: " << filename << endl;
    }

    void save_file(const string &filename) const {
        ofstream file(filename, ios::app);
        if (!file) {
            cout << "Error!" << endl;
            return;
        }
        file << contacts[count - 1] << endl;
    }

    void search_name(const string &name) const {
        for (int i = 0; i < count; i++) {
            if (contacts[i].name == name) {
                cout << "Contact found:\n";
                contacts[i].show();
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void change_phone_number(const string &name, const string &new_number) {
        for (int i = 0; i < count; i++) {
            if (contacts[i].name == name) {
                contacts[i].phone_number = new_number;
                cout << "Phone number updated for " << name << "." << endl;
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void open_file(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file for reading!" << endl;
            return;
        }
        file >> count;
        file.ignore();
        for (int i = 0; i < count; ++i) {
            file >> contacts[i];
            file.ignore();
        }
        cout << "Loaded successfully from " << filename << endl;
    }

    void show_contacts() const {
        cout << "Phone Book:\n";
        for (int i = 0; i < count; i++) {
            contacts[i].show();
            cout << "\n";
        }
    }
};

int main() {
    PhoneBook phoneBook1;
    PhoneBook phoneBook2;
    string filename = "phonebook.txt";
    string create_file = "phonebook.txt";

    ofstream testFile(create_file);
    testFile << "3\n";
    testFile << "Kate 2000 54653213546\n";
    testFile << "Jhonny 1963 21654213\n";
    testFile << "Liliya 2008 1236587\n";
    testFile.close();

    phoneBook1.open_file(create_file);
    phoneBook1.show_contacts();

    cout << "\nSearching for Liliya:\n";
    phoneBook1.search_name("Liliya");
    cout << "\nChanging phone number for Kate:\n";
    phoneBook1.change_phone_number("Kate", "212133654654");
    phoneBook1.save_file(create_file);
    phoneBook1.show_contacts();
    phoneBook2.add_contact(filename);
    phoneBook2.show_contacts();

}