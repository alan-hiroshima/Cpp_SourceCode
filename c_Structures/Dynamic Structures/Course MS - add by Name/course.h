#include <iostream>
#include <cstdlib>
#include <cmath>
#include "student.h"
using namespace std;
class Course {
	string topic;
	Student** students;
	int size;
	int capacity;

	public:
	// TODO constructor
	Course(string topic) {
        this->topic = topic;
        size = 0;
        capacity = 5;
        students = (Student**)malloc(capacity * sizeof(Student *));
	}

	// TODO add student
	void addStudent(Student* s) {
        if(size == capacity){
            capacity = ceil(capacity * 1.5);
            students = (Student**)realloc(students, capacity * sizeof(Student *));
        }
        
        int i = size - 1;
        while(i >= 0 && students[i]->name > s->name){
            students[i+1] = students[i];
            i--;
        }
        
        students[i + 1] = s;
        size++;
	}

	// DO NOT MODIFY
	void print() {
		cout << "Title: "<< topic << endl;
		cout << "Student size: " << size << "/" << capacity << endl;
		for (int i = 0; i < capacity; i++) {
			if (i >= size) {
				cout << i+1<< ". (none)" << endl;
			} else {
			    Student* s = students[i];
				cout << i+1 << ". " << s->name << " (" << s->program << " " << s->year << ")" << endl;
			}
		}
	}
};