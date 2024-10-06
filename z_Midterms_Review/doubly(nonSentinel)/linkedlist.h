#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class Linkedlist : public List{
    int size;
    node* head;
    node* tail;

    // helper functions
    void removeNode(node* targetNode){
        if(targetNode->prev){
            targetNode->prev->next = targetNode->next;
        }

        if(targetNode->next){
            targetNode->next->prev = targetNode->prev;
        }

        delete targetNode;
        size--;
    }

    public:
    void addHead(int num){
        node* newHead = new node();
        newHead->elem = num;

        if(size == 0) {
            head = newHead;  // Set head and tail to the new node
            tail = newHead;
            newHead->prev = nullptr;  // No previous node for the first element
            newHead->next = nullptr;  // No next node for the first element
        } else {
            newHead->next = head;  // Point the new head to the old head
            head->prev = newHead;  // Point the old head's previous to the new head
            head = newHead;  // Update head to the new head
        }
        size++;
    }

    void addTail(int num){
        node* newTail = new node();
        newTail->elem = num;

        if(size == 0) {
            head = newTail;  // Set head and tail to the new node
            tail = newTail;
            newTail->prev = nullptr;  // No previous node for the first element
            newTail->next = nullptr;  // No next node for the first element
        } else {
            tail->next = newTail;  // Link the current tail to the new node
            newTail->prev = tail;  // Link the new node back to the current tail
            tail = newTail;  // Update tail to the new node
        }
        size++;
    }

    void addAt(int num, int pos){
        if (pos < 1 || pos > size + 1) {  // Validate position
            return;
        }

        if (pos == 1) {
            addHead(num);  // Insert at the head
            return;
        }

        if (pos == size + 1) {
            addTail(num);  // Insert at the tail
            return;
        }

        node* curr = head;

        // Traverse to the (pos-1)th node
        for (int i = 1; i < pos - 1; i++) {
            curr = curr->next;
        }

        // Create the new node and insert it between curr and curr->next
        node* newNode = new node();
        newNode->elem = num;
        newNode->next = curr->next;
        newNode->prev = curr;

        curr->next->prev = newNode;
        curr->next = newNode;

        size++;  // Increment size of the list
    }


    void removeHead(){
        if(!head) {  // If the list is empty
            return;  
        }

        node* temp = head; 
        head = head->next;  // Update head to the next node

        if(head) {  // If there is a new head
            head->prev = nullptr;  // Set its previous to nullptr
        } else {
            tail = nullptr;  // If the list becomes empty, update tail
        }
        delete temp;  
        size--;  
    }

    void removeTail(){
        if(!tail) { 
            return;  
        }

        node* curr = tail;  
        tail = tail->prev;  // Update tail to the previous node

        if(tail) {  // If there is a new tail
            tail->next = nullptr;  // Set next of new tail to nullptr
        } else {
            head = nullptr;  // If the list becomes empty, update head
        }

        delete curr; 
        size--; 
    }

    int remove(int num){
        if (!head) {
            return -1;  // List is empty
        }

        node* curr = head;
        int i = 1;  // Position counter

        while (curr) {
            if (curr->elem == num) {
                if (curr == head) {
                    removeHead();  // Remove head if it matches
                } else if (curr == tail) {
                    removeTail();  // Remove tail if it matches
                } else {
                    removeNode(curr);  // Remove the current node
                }
                return i;  // Return the position
            }
            curr = curr->next;
            i++;
        }

        return -1;  // Element not found
    }

    int removeAt(int pos){
        if (pos < 1 || pos > size) {
            return -1;  // Invalid position
        }

        // Remove the first element
        if (pos == 1) {
            int removedElem = head->elem;
            removeHead();
            return removedElem;
        }

        // Remove the last element
        if (pos == size) {
            int removedElem = tail->elem;
            removeTail();
            return removedElem;
        }

        // Traverse to the desired position
        node* curr = head;  // Start from head
        for (int i = 1; i < pos; i++) {
            curr = curr->next;
        }

        int removedElem = curr->elem;  // Store the value to be removed
        removeNode(curr);  // Remove the node
        return removedElem; 
    }

    int removeAll(int num){
        int count = 0;
        node* curr = head;

        // Traverse the list while the current node is not NULL
        while (curr != nullptr) {
            if (curr->elem == num) {
                // Store the node to delete
                node* temp = curr;

                // Adjust links to remove the current node
                if (curr->prev) {
                    curr->prev->next = curr->next;  // Link previous to next
                } else {
                    head = curr->next;  // Update head if we're removing the first node
                }

                if (curr->next) {
                    curr->next->prev = curr->prev;  // Link next back to previous
                } else {
                    tail = curr->prev;  // Update tail if we're removing the last node
                }

                curr = curr->next; // Move to the next node before deleting 
                delete temp;       // Delete the node
                size--;
                count++;
            } else {
                curr = curr->next; // Move to the next node
            }
        }
        return count;  // Return the number of nodes removed
    }


    int get(int pos){
        if(pos <= 0 || pos > size) {
            return -1;  // Invalid position
        }
        
        node* curr = head;  // Start from the head
        
        int mid = (size % 2 == 0) ? size / 2 : size / 2 + 1;  // Determine midpoint
        int countPos = 1;  // Counter for comparisons

        if(pos <= mid) {
            while(--pos) {
                curr = curr->next;  // Move to the next node
                countPos++;  // Increment count
            }
            cout << "From head, number of comparisons: " << countPos << endl;
        } else {
            curr = tail;  // Start from the tail
            countPos = 1;
            while(pos != size) {
                curr = curr->prev;  // Move backward
                pos++;  // Increment position
                countPos++;
            }
            cout << "From tail, number of comparisons: " << countPos << endl;
        }
        return curr->elem;  // Return the element at the position
    }

    void print(){
        node* curr;
    	if (size == 0) {
    		cout << "Empty" << endl;
		} else {
			cout << "From HEAD: ";
    		curr = head;
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != tail) {
	    			cout << " -> ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->next;
			}
			cout << "From TAIL: ";
    		curr = tail;
	    	while (true) {
	    		cout << curr->elem;
	    		if (curr != head) {
	    			cout << " <- ";
				} else {
					cout << endl;
                    break;
				}
	    		curr = curr->prev;
			}
		}
    }
    
};