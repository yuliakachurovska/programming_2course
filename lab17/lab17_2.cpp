#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Human {
protected:
    string fullName;
    string gender;
    int age;

public:
    Human() : fullName(""), gender(""), age(0) {}
    Human(string name, string gen, int a) : fullName(name), gender(gen), age(a) {}
    virtual void input() {
        cout << "Enter full name: ";
        getline(cin, fullName);
        cout << "Enter gender: ";
        getline(cin, gender);
        cout << "Enter age: ";
        while (!(cin >> age) || age <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a positive integer for Age: ";
        }
        cin.ignore();
    }
    virtual void output() const {
        cout << "Full Name: " << fullName << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
    }
    virtual string getUniversity() const { return "Unknown"; } //за замовчуванням ставлю ось так
    virtual ~Human() {}
};

class Student : public Human {
protected:
    int year;
    string group;
    string university;

public:
    Student() : Human(), year(0), group(""), university("") {}
    Student(string name, string gen, int a, int yr, string grp, string uni) 
        : Human(name, gen, a), year(yr), group(grp), university(uni) {}

    void input() override {
        Human::input();
        cout << "Enter year: ";
        while (!(cin >> year) || year <= 0) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a positive integer for Year: ";
        }
        cin.ignore();
        cout << "Enter group: ";
        getline(cin, group);
        cout << "Enter university: ";
        getline(cin, university);
    }

    void output() const override {
        Human::output();
        cout << "Year: " << year << endl;
        cout << "Group: " << group << endl;
        cout << "University: " << university << endl;
    }

    string getUniversity() const override {
        return university;
    }
};

class Lecturer : public Human {
protected:
    string university;
    string position;

public:
    Lecturer() : Human(), university(""), position("") {}
    Lecturer(string name, string gen, int a, string uni, string pos)
        : Human(name, gen, a), university(uni), position(pos) {}

    void input() override {
        Human::input();
        cout << "Enter university: ";
        getline(cin, university);
        cout << "Enter position: ";
        getline(cin, position);
    }

    void output() const override {
        Human::output();
        cout << "University: " << university << endl;
        cout << "Position: " << position << endl;
    }

    string getUniversity() const override {
        return university;
    }
};

class Postgraduate : public Lecturer {
public:
    Postgraduate() : Lecturer() {}
    Postgraduate(string name, string gen, int a, string uni, string pos)
        : Lecturer(name, gen, a, uni, pos) {}

    void input() override {
        Lecturer::input();
    }

    void output() const override {
        Lecturer::output();
    }

    string getUniversity() const override {
        return university;
    }
};

int main() {
    vector<Human*> people;

    int numPeople;
    cout << "Enter number of people: ";
    while (!(cin >> numPeople) || numPeople <= 0) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input. Enter a positive number for the number of people: ";
    }
    cin.ignore();

    for (int i = 0; i < numPeople; ++i) {
        string type;
        cout << "\nEnter type of person (Human, Student, Lecturer, Postgraduate): ";
        getline(cin, type);

        Human* person = nullptr;

        if (type == "Human") {
            person = new Human();
        } else if (type == "Student") {
            person = new Student();
        } else if (type == "Lecturer") {
            person = new Lecturer();
        } else if (type == "Postgraduate") {
            person = new Postgraduate();
        } else {
            cout << "Invalid type entered, try again." << endl;
            --i;
            continue;
        }

        person->input();
        people.push_back(person);
    }

    cout << "\nDetails of all people and their universities:\n";
    for (const auto& person : people) {
        person->output();
        cout << "University: " << person->getUniversity() << endl << endl;
    }

    for (auto& person : people) {
        delete person;
    }
}
