#include "node.h"
#include "list.h"

class LinkedList : public List
{
    node *head;
    node *tail;
    int size;

 public: 
 int get(int pos){
    node* curr = head;
    for(int i = 1; i < pos; i++){
        curr = curr->next;
    }
    return curr->elem;
 }

 void addHead(int num){
    node* newHead = new node();
    newHead->elem = num;

    if(size == 0){
        head = nullptr;
        tail = nullptr;
    }else{
        newHead->next = head;
        head = newHead;
    }
    size++;
 }
 void addTail(int num){
    node* newTail = new node();
    newTail->elem = num;

    if(size == 0){
        head = nullptr;
        tail = nullptr;
    }else{
        newTail->next = tail;
        tail = newTail;
    }
    size++;
 }
 void addNodeAt(int num, int pos){
    if(pos == 1){
        addHead(num);
        return;
    }

    if(pos >= size + 1){
        addTail(num);
        return;
    }

    node* curr = head;
    for(int i = 1; i < pos -1; i++){
        curr = curr->next;
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
        tail ->next = nullptr;
    }
    size--;
    return removedElem;
 }
 
 int remove(int num){
    if(!head){
        return -1;
    }

    if(head->elem == num){
        removeHead();
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
        }else{
            i++;
            curr = curr->next;
        }
    }

    return -1;
 } 

 int removeAt(int pos){

    if(!head){
        return -1;
    }

    if(pos == 1){
        removeHead();
        return 1;
    }

    if(pos == size){
        removeTail();
        return size;
    }

    node* curr = head;
    for(int i = 1; i < pos - 1; i++){
        curr = curr->next;
    }

    node* temp = curr->next;
    int removedElem = temp->elem;

    curr->next = temp->next;

    if(temp == tail){
        tail = curr;
        tail->next = nullptr;
    }

    delete temp;
    size--;
    return removedElem;
 }
 int removeAll(int num) {
    int counter = 0;

    if(!head){
        return counter;
    }

    while (head && head->elem == num)
    {
        removeHead();
        counter++;
    }

    node* curr = head;
    
    while (curr && curr->next)
    {
        if(curr->next->elem == num){
            node* temp = curr->next;
            curr->next = temp->next;

            if(temp == tail){
                tail = curr;
                tail->next = nullptr;
            }

            delete temp;
            size--;
            counter++;
        }else{
            curr = curr->next;
        }
    }
    
    return counter;
 }

};