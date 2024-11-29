#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

void createStudentFile(const char* fname) {
    ofstream f1(fname);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string surname, group, marks;
        int course;
        cin >> surname >> course >> group >> marks;
        f1 << surname << " " << course << " " << group << " " << marks << "\n";
    }

    f1.close();
}

double averageMark(const string& marks) {
    int tmp;
    double sum = 0;
    int counter = 0;
    stringstream str(marks);

    while (str >> tmp) {
        sum += tmp;
        counter++;
        char comma;
        str >> comma;
    }
    return counter > 0 ? sum / counter : 0;
}

string findStudent(const char* fname) {
    double min_mark = 13.0;
    string loser;
    ifstream f1(fname);

    if (!f1.is_open()) {
        cerr << "Error " << fname << endl;
        return "";
    }

    string surname, group, marks;
    int course;

    while (f1 >> surname >> course >> group >> marks) {
        double avg_mark = averageMark(marks);

        if (avg_mark < min_mark) {
            min_mark = avg_mark;
            loser = surname;
        }
    }

    f1.close();
    return loser;
}

int main() {
    createStudentFile("students.txt");
    cout << findStudent("students.txt") << endl;
}