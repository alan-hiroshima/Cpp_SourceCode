#include <iostream>
#include <cstdlib>
#include <cmath>
#include "list.h"
using namespace std;

class ArrayList : public List{
    int* array;
    int size, capacity = 5;

    public:
        // constructor
    ArrayList(){
        array = (int*)calloc(capacity, sizeof(int));
        size = 0;
    }

    int get(int pos) {
        return array[pos-1];
    }

    void print(){
        cout << "Size: " << size << " / " << capacity << endl;
        int i;
        for (i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        for (; i < capacity; i++) {
            cout << "? ";
        }
        cout << endl;
    }


    // TODO: dynamic add(int num)
    void add(int num){
        if(size == capacity){
            capacity = ceil(capacity * 1.5);
            array=(int*)realloc(array, capacity * sizeof(int));
        }
        array[size++] = num;
    }

    // * Deduce function to used on remove() Function
     void deduce(){
        if(capacity == 0){
            return;
        }

        capacity = ceil(capacity * 0.75);

        if(capacity <= 5){
            capacity = 5;
        }

        array = (int*)realloc(array, sizeof(int) * capacity);
    }

    // TODO: dynamic remove(int num)
    int remove(int num){
        for (int i = 0; i < size; i++)
        {
            if (array[i] == num)
            {
                for (int j = i ; j < size; j++)
                {
                    array[j] = array[j+1];
                }
                array[size--] = 0;
                size--;
                if(size <= 2.0/3 * capacity){
                    deduce();
                }
                return i+1;
            }
        }
        return -1;
    }

    // TODO: dynamic addAt(int num, int pos)
    void addAt(int num, int pos){

        if(size == capacity){
            capacity = ceil(capacity * 1.5);
            array=(int*)realloc(array, capacity * sizeof(int));
        }
        
        for(int j = size; j > pos - 1; j--){
            array[j] = array[j - 1];
        }
        
        array[pos - 1] = num;
        size++;
    }

    // TODO: dynamic removeAt(int num, int pos)
    int removeAt(int pos){
        int temp = array[pos - 1];

        for(int i = pos - 1; i < size; i++){
            array[i] = array[i + 1];
        }
        size--;

        if(size <= 2.0/3 * capacity){
            deduce();
        }
        return temp;
    }

};
