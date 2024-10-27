#include <iostream>
#include <cstdlib>
#include <cmath>
#include "student.h"
//#include "hidden.h"
using namespace std;
class Course {
	string topic;
	Student** students;
	int size;
	int capacity;
	
	void deduce(){
	    if(size <= capacity * 2.0/3.0){
	        capacity = max(ceil(capacity * 0.75), 5.0);
	        students = (Student**)realloc(students, capacity * sizeof(Student *));
	    }
	}
	
	void removeShift(int index){
	    for(int i = index; i < size - 1; i++){
	        students[i] = students[i + 1];
	    }
	}

	public:
    //TODO: impliment course and addStudent()
	Course(string topic) { 
		students = hidden_init(topic, &this->topic, &size, &capacity);
	}

	void addStudent(Student* s) {
	    students = hidden_addStudent(s, &size, &capacity, students);
	}

	// TODO remove a Student
	string removeStudent(string name) {
	    string course;
	    for(int i = 0; i < size; i++){
	        if(name == students[i]->name){
	        
	            course = students[i]->program;
	            Student* temp = students[i];
	            removeShift(i);
	            size--;
	            deduce();
	            free(temp);
	            return course;
	        }
	    }
        return "";
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