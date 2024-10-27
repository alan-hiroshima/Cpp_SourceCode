#include <iostream>
#include <cstdlib>
#include <cmath>
#include "blocked.h"
#include "student.h"
// #include "hidden.h"
using namespace std;


class Course {
    private:
	string topic;
	Student** students;
	int size;
	int capacity;
	Blocked **blocked;
    int blockCapacity = 5, blockSize;
	
	void reduceCapacity()
    {
        if (size <= capacity * 2.0 / 3.0 && capacity > 5 )
        {
            capacity = max(ceil(capacity * 0.75), 5.0);
            students = (Student **)realloc(students, capacity * sizeof(Student *));
        }
    }


    void increaseCapacity()
    {
        if (size == capacity)
        {
            capacity = ceil(capacity * 1.5);
            students = (Student **)realloc(students, capacity * sizeof(Student *));
        }
    }
    
    void increaseBlock()
    {
        if (blockSize == blockCapacity)
        {
            blockCapacity = ceil(blockCapacity * 1.5);
            blocked = (Blocked **)realloc(blocked, blockCapacity * sizeof(Blocked *));
        }
    }

    void removeShift(int index)
    {
        for (int j = index; j < size - 1; j++)
        {
            students[j] = students[j + 1];
        }
    }
    
    

	public:
	Course(string topic) {
		// students = hidden_init(topic, &this->topic, &size, &capacity);
        students = (Student**)malloc(capacity * sizeof(Student *));
	    blocked = (Blocked**)malloc(blockCapacity * sizeof(Blocked *));	
	}
	

    // TODO fix this to exclude blocked students
	int addStudent(Student* s) {
	
	    for (int i = 0; i < blockSize; i++)
        {
            if (blocked[i]->program == s->program && blocked[i]->yearLevel == s->year)
            {
                return 0;
            }
        }
        
        increaseCapacity();
        students[size++] = s;
        return 1;
	    
	    //students = hidden_addStudent(s, &size, &capacity, students);
	    //return 1;
	}

	// TODO remove a cheater and their classmates
	int removeCheater(string name) {
        int count = 0;
        Student *temp = nullptr;

        for (int i = 0; i < size; i++)
        {
            if (name == students[i]->name)
            {
                temp = students[i];
                removeShift(i);
                size--;
                reduceCapacity();
                count++;
                break;
            }
        }

        if (temp != nullptr) 
        {
            increaseBlock();
            blocked[blockSize++] = new Blocked(temp->program, temp->year);

            for (int i = 0; i < size; i++)
            {
                if (students[i]->program == temp->program && students[i]->year == temp->year)
                {
                    Student *remove = students[i];
                    removeShift(i);
                    size--;
                    reduceCapacity();
                    count++;
                    i--;
                    free(remove);
                }
            }
            free(temp);

        }

        return count; 
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