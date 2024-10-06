#include <iostream>
#include <cstdlib>
#include <cmath>
#include "student.hpp"
#include "blocked.hpp"

using namespace std;

class Course
{
private:
    string topic;
    Student **students;
    int capacity = 5, size;
    Blocked **blocked;
    int blockCapacity = 5, blockSize;

    void reduceCapacity()
    { // if size == 2/3 of capacity then reduce by 30% (rounded down) but caps on 5
        if (size <= capacity * 2.0 / 3.0)
        {
            capacity = max(ceil(capacity * 0.7), 5.0);
            students = (Student **)realloc(students, capacity * sizeof(Student *));
        }
    }

    void increaseCapacity()
    { // increase by 50% round up
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
            capacity = ceil(capacity * 1.5);
            blocked = (Blocked **)realloc(blocked, capacity * sizeof(Blocked *));
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
    Course(const string &topic) : topic(topic), size(0), blockSize(0)
    {
        students = (Student **)malloc(capacity * sizeof(Student *));
        blocked = (Blocked **)malloc(blockCapacity * sizeof(Blocked *));
    }

    int add(Student *s)
    {
        for (int i = 0; i < blockSize; i++)
        {
            if (blocked[i]->program == s->program && blocked[i]->yearLevel == s->yearLevel)
            {
                return 1;
            }
        }
        increaseCapacity();
        students[size++] = s;
        return 0;
    }

    int remove(string name)
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (name == students[i]->name)
            {
                Student *temp = students[i];
                removeShift(i);
                size--;
                reduceCapacity();
                count++;

                increaseBlock();
                blocked[blockSize++] = new Blocked(temp->program, temp->yearLevel);

                Student *remove;
                for (int j = 0; j < size; j++)
                {
                    if (students[j]->program == temp->program && students[j]->yearLevel == temp->yearLevel)
                    {
                        remove = students[j];
                        removeShift(j);
                        size--;
                        reduceCapacity();
                        count++;
                        j--;
                        free(remove);
                    }
                }
                free(temp);
                return count;
            }
        }
        return count;
    }

    void print()
    {
        cout << "Size: " << size << "/" << capacity << endl;
        for (int i = 0; i < size; i++)
        {
            cout << students[i]->name << " - " << students[i]->program << " " << students[i]->yearLevel << endl;
        }
    }
};