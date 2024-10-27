#include "list.hpp"
#include <iostream>
#include <cstdlib> // for malloc, calloc, realloc
using namespace std;

class ArrayList : public List{
    int array[5];
    int size;

    public:
    ArrayList(){
        for(int i = 0; i < 5; i++){
            array[i] = 0;
        }
        size = 0;
    }

    void add(int num){
        if(size < 5){
            array[size++] = num;
        }else{
            cout << "The array is full" << endl;
        }
    }

    int get(int pos){
        return array[pos - 1];
    }   
      
    int remove(int num){
        // TODO: Find the num
        for(int i = 0; i < size; i++){
            if(array[i] == num){
                // TODO: Move elements to the left
                for(int j = i; j < size - 1; j++){
                    array[j] = array[j + 1]; 
                }
                // TODO: Set the size
                array[size--] = 0;
                size--;
                return i+1;
            }
        }
        return -1;
    } 

    void print(){
        for(int i = 0; i < 5; i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void addAt(int num, int pos){
        // TODO: Shift elements to the right to make space for the new element 
        // TODO: Start from the END of the array and move towards the specified position
        for(int j = size; j >   pos - 1; j--){
            array[j] = array[j - 1]; 
        }

        // TODO: Insert the new element at the specified position
        array[pos - 1] = num;
        size++;
    }

    int removeAt(int pos){
        int temp = array[pos - 1]; // Store the element to be removed so it can be returned
        
        // TODO: shift elements to the left to fill the gap created by the removed element
        // TODO: Start from the position of the removed element and move towards the end of the array
        for(int i = pos - 1; i < size; i++){
            array[i] = array[i + 1];
        }

        // TODO: Set the last element to 0 and Decrease the size for the removal of the element
        array[size - 1] = 0;
        size--;
        return temp;
    }

    int removeAll(int num){
       int count = 0;
        // Step 1: FIND the num
        for (int i = 0; i < size; i++) {
            if (array[i] == num) {
                // Step 2: MOVE the elements to left
                for (int j = i; j < size-1; j++) {
                    array[j] = array[j+1];
                }
                
                array[size-1] = 0;
                size = size-1;
                i--;
                count++;
            } 
        }
        return count;
        
    }


    void flip(){
        if(size > 1)
        {
            swap(array[0], array[size-1]);
            swap(array[1], array[size-2]);
        }
    }

    void plus(int term){
        for(int i = 0; i < size; i++){
            array[i] += term;
        }
    }
    
    int summation(){
        int sum = 0;
        for(int i = 0; i <size; i++){
            sum += array[i];
        }
        return sum;
    }



};