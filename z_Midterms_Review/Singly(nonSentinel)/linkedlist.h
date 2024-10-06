#include <cstdlib>
#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class LinkedList : public List
{
    node *head;
    node *tail;
    int size;

public:
    // ADD's
    void addNum(int num)
    {
        node *newNode = new node();
        newNode->elem = num;

        // size == 0 or !head
        if (size == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void addHead(int num)
    {
        node *newHead = new node();
        newHead->elem = num;
        if (size == 0)
        {
            head = newHead;
            tail = newHead;
        }
        else
        {
            newHead->next = head;
            head = newHead;
        }
        size++;
    }

    void addTail(int num)
    {
        addNum(num);
    }

    void addNodeAt(int num, int pos)
    {
        if (pos == 1)
        { // Check if the position is the head
            addHead(num);
            return;
        }

        if (pos > size)
        { // If position is greater than size, add to the tail
            addNum(num);
            return;
        }

        node *curr = head; // Initialize current pointer to head
        // Traverse to the node just before the desired position
        for (int i = 1; i < pos - 1; i++)
        {
            curr = curr->next; // Move to the next node
        }

        // Create and insert the new node
        node *newNode = new node();
        newNode->elem = num;        // Set the element value
        newNode->next = curr->next; // Link new node to the next node
        curr->next = newNode;       // Link previous node to the new node
        size++;                     // Increment the size of the list
    }

    // REMOVE's
    int removeHead()
    {
        int removedElem = head->elem;
        node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return removedElem;
    }

    int removeTail()
    {
        // Check if the linked list is empty
        if (head == nullptr)
        {
            return -1; // Return -1 to indicate an error (empty list)
        }

        int removedElem = tail->elem; // Store the data of the tail node to return later

        // Check if there is only one node in the list
        if (head == tail)
        {
            delete head;    // Free the memory of the only node
            head = nullptr; // Set head to nullptr, indicating the list is empty
            tail = nullptr; // Set tail to nullptr as well
        }
        else
        {
            node *curr = head; // Initialize a pointer to traverse the list
            // Traverse the list until reaching the second-to-last node
            while (curr->next != tail)
            {
                curr = curr->next; // Move to the next node
            }

            delete tail;          // Free the memory of the tail node
            tail = curr;          // Update the tail pointer to the second-to-last node
            tail->next = nullptr; // Set the next pointer of the new tail to nullptr
        }

        size--;             // Decrement the size of the list, reflecting the removal
        return removedElem; // Return the value of the removed tail node
    }

    int remove(int num) {
    // If the list is empty, return -1 to indicate the element was not found
        if (!head) {
            return -1;
        }

        // Check if the head node contains the element to be removed
        if (head->elem == num) {
            node* temp = head;  
            head = head->next;  
            delete temp;        
            size--;             
            return 1;           
        }

        node* curr = head;
        int i = 2;  // Initialize position tracking, starting from the second node

        // Traverse the list to find the node with the target element
        while (curr->next != nullptr) {
            // Check if the next node contains the element to remove
            if (curr->next->elem == num) {
                node* temp = curr->next;  // Temporarily store the node to be removed
                curr->next = temp->next;  // Bypass the node by linking the current node to the next

                // If the node being removed is the tail, update the tail pointer
                if (temp == tail) {
                    tail = curr;
                    tail->next = curr;
                }

                delete temp;  // Free the memory of the removed node
                size--;       // Decrease the size of the list

                return i;  // Return the position of the removed node
            }

            curr = curr->next;  // Move to the next node
            i++;                // Increment position counter
        }

        // Return -1 if the element was not found in the list
        return -1;
    }

    int removeAt(int pos)
    {
        if(!head){
            return -1;
        }
        
        if(pos == 1){
            return removeHead();
        }
        
        if(pos == size){
            return  removeTail();
        }
        
        node* curr = head;
        for(int i = 1; i < pos - 1; i++){
            curr = curr->next;
        }
        
        node* temp = curr->next;
        int removeElement = temp->elem;
        
        curr->next = temp->next;
        
        if(temp == tail){
            tail = curr;
        }
        
        delete temp;
        size--;
        return removeElement;
    }

        int removeAll(int num)
        {
            int counter = 0; // Tracks how many elements with the value `num` are removed.

            // Remove nodes from the head that match the value `num`
            while (head && head->elem == num) {
                node* temp = head;
                head = head->next;
                delete temp;
                size--;
                counter++;    // Increment counter for each node removed
            }

            // If the list becomes empty after removing from the head, return the count
            if (!head) return counter;

            node* curr = head; // Start from the head to traverse the list

            // Traverse the list to find and remove matching nodes
            while (curr && curr->next) {
                // Check if the next node contains the value `num`
                if (curr->next->elem == num) {
                    node* temp = curr->next;   // Store the node to be deleted
                    curr->next = temp->next;   // Bypass the node to be removed

                    // If the removed node was the tail, update the tail pointer
                    if (temp == tail) {
                        tail = curr;           // Update tail to the current node
                    }

                    delete temp; 
                    size--;      
                    counter++;   
                } else {
                    // Move to the next node if no match
                    curr = curr->next;
                }
            }

            // Return the total count of removed nodes
            return counter;
    }

    int get(int pos)
    {
        node *curr = head;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        return curr->elem;
    }

    // DO NOT modify the code below.
    void print()
    {
        node *curr = head;
        if (size == 0)
        {
            cout << "Empty" << endl;
        }
        else
        {
            while (true)
            {
                cout << curr->elem;
                if (curr != tail)
                {
                    cout << " -> ";
                }
                else
                {
                    cout << endl;
                    break;
                }
                curr = curr->next;
            }
        }
    }
};