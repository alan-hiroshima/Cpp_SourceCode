#include <iostream>
#include "course.hpp"

using namespace std;

int main() {
    char op;
    Course* course = new Course("DSA");
    Student* student;
    string name;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch(op) {
            case 'a':
                student = new Student();
                cout << "Enter name: ";
                cin >> student->name;
                cout << "Enter program: ";
                cin >> student->program;
                cout << "Enter year level: ";
                cin >> student->yearLevel;
                if(course->add(student)) {
                    cout << student->program << " " << student->yearLevel << " is blocked" << endl;
                } else {
                    cout << student->name << " added! Horray" << endl;
                }
                break;

            case 'r':
                cout << "Enter name: ";
                cin >> name;
                cout << course->remove(name) << " student/s removed\n";
                break;

            case 'p':
                course->print();

            case 'x':
                break;

            default:
                cout << "Enter a valid operation\n";
        }
    } while(op != 'x');
}