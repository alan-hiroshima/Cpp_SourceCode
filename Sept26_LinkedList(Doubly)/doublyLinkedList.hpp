#include <iostream>
#include "node.hpp"
#include "list.hpp"
using namespace std;

class doublyLinkedList : public list
{
    private:
        int size;
        node* head;
        node* tail;

    public:
       // constructor
       doublyLinkedList() : size(0), head(nullptr), tail(nullptr){}
       

         void addHead(int num){
            node* newNode = new node(num);

            if(!head){
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }

            size++;
         }

         void addTail(int num){
            //* allocate a new node when adding
            node* newNode = new node(num);
            
            //* check if list is empty, else append the new node to the current tail and set is as new tail
            if(!head){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
            size++;
         } 

         void addBetween(node* newNode, node* prevNode, node* nextNode){
            if(prevNode){
                prevNode->next = newNode;
                newNode->prev = prevNode;
            }
            if(newNode){
                nextNode->prev = newNode;
                newNode->next = nextNode;
            }

            if(prevNode == tail){
                tail = newNode;
            }
            size++;
         }

         void addAt(int num, int pos){
            if (pos < 0 || pos > size)
            {
                cout << "Out of bounds." << endl;
            }

            if(pos == 0){
                addHead(num);
                return;
            }
            if (pos == size)
            {
                addTail(num);
                return;
            }
            
            node* newNode = new node(num);
            node* curr = head;

            for(int i = 1; i < pos ; i++){
                curr = curr->next;
            }
            
            addBetween(newNode, curr->prev, curr);
         }
        
        //!  REMOVE
         int removeHead(){
            if(!head){
                return -1;
            }

            node* curr = head;
            head = head->next;

            if(head){
                head->prev = nullptr;
            }else{
                tail = nullptr;
            }
            delete curr;
            size--;

            return 1;
         }

         int removeTail(){
            if(!tail){
                return -1;
            }

            int position = size;

            node* curr = tail;
            tail = tail->prev;

            if(tail){
                tail->next = nullptr;
            }else{
                head = nullptr;
            }

            delete curr;
            size--;
            
            return position;
         }
         
         void removeNode(node* targetNode){
            if(!targetNode){return;}

            if(targetNode->prev){
                targetNode->prev->next = targetNode->next;
            }

            if(targetNode->next){
                targetNode->next->prev = targetNode->prev;
            }

            delete targetNode;
            size--;
         }

         int remove(int num){
            if(!head){
                return -1;
            } 

            if(head->data == num){
                return removeHead();
            }

            if(tail->data == num){
                return removeTail();
            }

            node *curr = head;
            int i = 2;

            while (curr->next != nullptr && curr->next->data != num)
            {
                i++;
                curr = curr->next; // Move to next node
            }

            if (curr->next == nullptr)
            {
                return -1; // Number not found
            }

            removeNode(curr);

            return i; // Return the position of the removed node
         }

         int removeAt(int pos){
            if (pos < 1 || pos > size) {
                return -1;  // Invalid position
            }

            if (pos == 1) {
                return removeHead();  // Remove the head if position is 1
            }

            if (pos == size) {
                return removeTail();  // Remove the tail if position is the size of the list
            }

            // Traverse the list to find the node at the given position
            node* curr = head;
            int i = 1;  // Start counting from the head

            while (i < pos) {
                curr = curr->next;
                i++;
            }

            // Now curr is the node at the position pos
            int removedData = curr->data;  // Save the data of the node to be removed
            removeNode(curr);  // Use removeNode() to remove the node

            return removedData; 
            
         }

         int removeAll(int num){
            
            return 0;
         }

         int getSize(){
            
            return 0;
         }

         int get(int pos){
            if (pos < 0 || pos > size){return -1;}

            node* curr = head;

            //* find the middle of the size
            int mid;
            if(size % 2 == 0){
                mid = size / 2;
            }else{
                mid = size / 2 + 1;
            }

            int ctrPos = 1;

            if(pos <= mid){
                while(--pos){
                    curr = curr->next;
                    ctrPos++;
                }
                cout << "From Head, number of comparisons: " << ctrPos<< endl;
            }else{
                curr = tail;
                while (pos!= size)
                {
                    curr = curr->prev;
                    pos++;
                    ctrPos++;
                }
                cout << "From Tail, number of comparisons: " << ctrPos<< endl;
            }
            return curr->data;
         }

         int retain(int num){
            
            return 0;
         }

         int corner(int left, int right){
            
            return 0;
         }

         void reverse(){
            
         }

         void printList(){
            node* curr = head;

            cout <<"Size of the Linkedlist: " << size << endl;
            cout << "From HEAD: ";

            while (curr)
            {
                cout << curr->data;
                if(curr->next != nullptr){
                    cout << " -> ";
                }
                curr = curr->next;
            }
            cout << endl;

            cout << "From Tail: ";
            curr = tail;

            while (curr)
            {
                cout << curr->data;
                if(curr->prev != nullptr){
                    cout << " <- ";
                }
                curr = curr->prev;
            }
            cout << endl;
         }

};