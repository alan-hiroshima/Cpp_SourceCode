#include "student.h"
#include <iostream>
#include <cmath>
using namespace std;
class Course
{
    string name;        // 8
    Student **students; // 8
    int size;           // 4
    int capacity;       // 4

public:
    Course(string name)
    {
        this->name = name;
        size = 0;
        capacity = 2;
        // students = new Student[capacity];
        students = (Student **)malloc(sizeof(Student *) * capacity);
        cout << "Allocated done" << endl;
    }

    // ALan solution
    /*void addStudent(Student *s) 
    {

        if (size == capacity)
        {
            capacity = ceil(capacity * 1.5);
            students = (Student **)realloc(students, sizeof(Student *) * capacity);
        }

        int i = size - 1;
        while (i >= 0 && students[i]->name > s->name) {
            students[i + 1] = students[i]; // Shift student to the right
            i--;
        }

        students[i + 1] = s; // Insert the new student at the correct position
        size++;

        cout << "Student " << s->name << " added." << endl;
        // cout << "ADDING " << s->name << endl;
        // students[size++] = s;
        // cout << "DONE" << endl;
    } */

    // Carl solution
    void addStudent(Student *s) {
        if(size == capacity) {
            capacity = ceil(capacity * 1.5);
            students = (Student**) realloc (students, capacity * sizeof(Student*));
        }

        for(int i = 0; i < size; i++) {
            if(students[i]->name.compare(s->name) > 0) {
                size++;
                for(int j = size - 1; j >= i; j--) {
                    students[j] = students[j-1];
                }
                students[i] = s;
                return;
            }
        }
        students[size++] = s;
    }

    void print()
    {
        cout << name << endl;
        cout << "Student Size: " << size << " / " << capacity << endl;
        for (int i = 0; i < size; i++)
        {
            cout << i + 1 << ". " << students[i]->name << ", " << students[i]->program << ", " << students[i]->yearLevel << endl;
        }
    }
};