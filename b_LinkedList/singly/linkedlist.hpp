#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

class LinkedList : public List{
    private:
        node* head;
        node* tail;
        int size;
    
    public:
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        ~LinkedList(){
            node* curr = head;
            while(curr!= nullptr){
                node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            head = nullptr;
            size = 0;
        }

        void addHead(int num){
            node* newNode = new node();
            newNode->elem = num;

            if(size == 0){
                head = newNode;
                tail = newNode;
            }else{
                newNode->next = head;
                head = newNode; 
            }
            size++;
        }

        void addTail(int num){
            node* newNode = new node();
            newNode->elem = num;

            if(size == 0){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            size++;
        }

        void addAt(int num, int pos){
            if(pos == 1){
                addHead(num);
                return;
            }
            if(pos >= size + 1){
                addTail(num);
                return;
            }

            node* curr = head; 
            int i = 1;
            while(i < pos - 1){
                curr = curr->next;
                i++;
            }

            node* newNode = new node();
            newNode->elem = num;

            newNode->next = curr->next;
            curr->next = newNode;
            size++;
        }

        int removeHead(){
            int removeElem = head->elem;
            node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return removeElem;
        }

        int removeTail(){
            if(!head){
                return -1;
            }

            int removedElem = tail->elem;

            if(head == tail){
                delete head;
                head = nullptr;
                tail = nullptr;
            }else{
                node* curr = head;
                while(curr->next != tail){
                    curr = curr->next;
                } 

                delete tail;
                tail = curr;
                tail->next = nullptr;
            }

            size--;
            return removedElem;
        }

        int remove(int num){
            if(!head) return -1;

            if (head->elem == num) {
                node* temp = head;  
                head = head->next;  
                delete temp;        
                size--;             
                return 1;           
            }

            node* curr = head;
            int i = 2;
            while(curr->next != nullptr){
                if(curr->next->elem == num){
                    node* temp = curr->next;
                    curr->next = temp->next;


                    if(temp == tail){
                        tail = curr;
                        tail->next = nullptr;
                    }

                    delete temp;
                    size--;
                    return i;
                }

                curr = curr->next;
                i++;
            }

            return -1;
        }

        int removeAt(int pos){ 
            if(!head)return -1;

            if(pos == 1)return removeHead();
            if(pos == size)return removeTail();

            node* curr = head;
            for(int i = 1; i < pos - 1; i++){
                curr = curr->next; //move the node just before the one to be removed
            }

            node* temp = curr->next;
            int removedElement = temp->elem;

            curr->next = temp->next;

            if (temp == tail) {
                tail = curr; // Update the tail if the last node was removed
            }
            
            delete temp;
            size--;
            return removedElement;
        }

        int removeAll(int num){
            if(!head){return -1;}

            int count = 0;
            while(head && head->elem == num){
                node* temp = head;
                head = head->next;
                delete temp;
                size--;
                count++;
            }

            node* curr = head;
            while(curr && curr->next){
                if(curr->next->elem == num){
                    node* temp = curr->next;
                    curr->next = temp->next;

                    if(temp == tail){
                        tail = curr;
                    }
                    delete temp;
                    size--;
                    count++;
                }else{
                    curr = curr->next;
                }
            }
            return count;
        }

        int get(int pos){
            node* curr = head;
            for(int i = 1; i < pos; i++){
                curr = curr->next;
            }
            return curr->elem;
        }

        void print(){
            cout << "Size: " << size << endl;

            node* curr = head;
            while (curr)
            {   
                cout << curr->elem;
                if(curr->next){
                    cout << " -> ";
                }
                curr = curr->next;
            }
            cout << endl;
        }
};