#include "node.h"
#include <iostream>


class LinkedList {
	node* head;
	node* tail;
	int size;

    void swapNode(node* dest, node* src){
        if(dest->next == src){
            src->prev = dest->prev;
            dest->next = src->next;
            dest->prev = src;
            src->next = dest;

            src->next->prev = src;
            src->prev->next = src;

            dest->next->prev = dest;
            dest->prev->next = dest;
            return;
        }else if(dest->prev == src){
            src->next = dest->next;
            dest->prev = src->prev;
            dest->next = src;
            src->prev = dest;

            src->next->prev = src;
            src->prev->next = src;

            dest->next->prev = dest;
            dest->prev->next = dest;
            return;
        }

        node* temp = dest->prev;
        dest->next = src->next;
        src->next = temp;

        temp = 
    }

	public:
	LinkedList() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
		size = 0;
	}

	// TODO add a person
	void add(Person* p) {
        node* newNode = new node();
        newNode->person = p;
        
        newNode->next = tail;
        newNode->prev = tail->prev;
        tail->prev->next = newNode;
        tail->prev = newNode;
        
        size++;
	}

	// TODO advance
	void advance(string name, int forward) {
        node*curr = head->next;
        
        while(curr != tail){
            if(curr->person->firstName == name || curr->person->lastName == name){
                node* target = curr;
                for(int i = 0;  i < forward; i++){
                    if(target->prev != head){
                        target = target->prev;
                    }else{
                        break;
                    }
                }
                
                curr->prev->next =curr->next;
                curr->next->prev =curr->prev;
                
                
                curr->next = target;
                curr->prev = target->prev;
                target->prev->next = curr;
                target->prev = curr;
                return; 
            }
            curr = curr->next;
        }
	}


	// TODO delay
	void delay(string name, int back) {
        node*curr = head->next;
        
        while(curr != tail){
            if(curr->person->firstName == name || curr->person->lastName == name){
                node* target = curr;
                for(int i = 0;  i < back; i++){
                    if(target->next != tail){
                        target = target->next;
                    }else{
                        break;
                    }
                }
                
                if(target ==curr){
                return;
                }
                
                curr->prev->next =curr->next;
                curr->next->prev =curr->prev;
                
                
                curr->next = target->next;
                curr->prev = target;
                target->next->prev = curr;
                target->next = curr;
                return; 
            }
            curr = curr->next;
            
        }
	}


	// TODO trade places
	void trade(string name1, string name2) {
        return;
	}

	// TODO serve the request
	Person* fastLane() {
	    return NULL;
	}

	// TODO print
	void print() {
		cout << "Counter: " << size << endl;
            if(size = 0){return ;}
		cout << "From First: " << endl;
            node* curr = head->next;
            int ctr = 1;
            while(curr != tail){
                cout << ctr++ << ". ";
                curr->person->print();
                curr = curr->next;
            }
		cout << "From Last: " << endl;
            curr = tail->prev;
            while(curr != head){
                cout << --ctr << ". ";
                curr->person->print();
                curr = curr->prev;
            }
	}
};