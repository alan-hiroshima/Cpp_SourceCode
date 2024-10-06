#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

class linkedlist : public list
{
    node *head;
    node *tail;
    int size;

public:
    // Constructor
    linkedlist() : head(nullptr), tail(nullptr), size(0) {}

    // Destructor
    ~linkedlist() {
        node* curr = head;
        while (curr != nullptr)
        {
            node* nextNode = curr->next;
            delete curr; // Use delete instead of free
            curr = nextNode;
        }
        head = nullptr;
        size = 0;
    }

    void addNum(int num)
    {
        node *n = new node(num); // Use new instead of calloc
        if (size == 0)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        size++;
    }

    void addHead(int num)
    {
        node *newHead = new node(num); // Use new instead of new node;
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
        if (pos < 0 || pos > size)
        {
            cout << "Out of bounds." << endl;
            return;
        }
        if (pos == 1)
        {
            addHead(num);
            return;
        }
        if (pos > size)
        {
            addNum(num);
            return;
        }

        node *curr = head;
        for (int i = 1; i < pos - 1; i++)
        {
            curr = curr->next;
        }

        node *newNode = new node(); // Use new instead of calloc
        newNode->data = num;
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
    }

    int removeHead()
    {
        if (head == nullptr) return -1; // Check for empty list

        int res = head->data;
        node *temp = head;
        head = head->next;
        delete temp; // Use delete instead of free
        size--;
        return res;
    }

    int removeTail(){
        if(head == nullptr){return -1;}

        int res = tail->data;
        
        if(head == tail){
            delete head;
            head = nullptr;
            tail = nullptr;
            size--;
            return res;
        }

        node* curr = head;
        while(curr->next != tail){
            curr = curr->next;
        }

        delete tail;
        tail = curr;
        tail->next = nullptr;
        
        size--;
        return res;
    }

    int remove(int num)
    {
        if (!head)
        {
            return -1; // List is empty
        }

        if (head->data == num)
        {
            //removeHead()
            node* temp = head;
            head = head->next;
            delete temp;
            size--;
            return 1;
        }

        node *curr = head;
        int i = 2;

        while (curr->next != nullptr && curr->next->data != num)
        {
            i++;
            curr = curr->next; // Move to next node
        }

        // If we reached the end without finding num
        if (curr->next == nullptr)
        {
            return -1; // Number not found
        }

        // Remove the node containing num
        node *temp = curr->next; // Node to be removed
        curr->next = temp->next; // Bypass the removed node

        if (temp == tail)
        {
            tail = curr; // Update tail if necessary
        }

        delete temp; // Use delete instead of free
        size--;

        return i; // Return the position of the removed node
    }

    int removeAt(int pos)
    {
        if (pos < 0 || pos >= size) return -1; // Check for out of bounds

        if (pos == 0)
        {
            return removeHead();
        }

        node* curr = head;
        for (int i = 1; i < pos - 1; i++)
        {
            curr = curr->next;
        }

        node* temp = curr->next;
        int removedElement = temp->data;

        curr->next = temp->next;

        if (temp == tail)
        {
            tail = curr;
        }

        delete temp; // Use delete instead of free
        size--;

        return removedElement;
    }

    int removeAll(int num)
    {
        int counter = 0;

        while (head && head->data == num) {
            removeHead(); // Removes the head if it matches `num`
            counter++;
        }

        if (!head) return counter;

        node* curr = head;

        while (curr && curr->next) {
            if (curr->next->data == num) {
                node* temp = curr->next;
                curr->next = temp->next;

                if (temp == tail) {
                    tail = curr;
                }

                delete temp; // Use delete instead of free
                size--;
                counter++;

            } else {
                curr = curr->next;
            }
        }
        return counter;
    }

    int get(int pos)
    {
        node *curr = head;
        int count = 0; // Changed to start from 0
        while (curr)
        {
            if (count == pos) // Check for pos, not count+1
            {
                return curr->data;
            }
            count++;
            curr = curr->next;
        }
        return -1; // Return -1 if not found
    }

    void print()
    {
        node *curr = head;

        if (size == 0 || head == nullptr)
        {
            cout << "empty" << endl;
        }
        else
        {
            cout << "\nThe size of the List is " << size << endl;
            cout << "First elem " << head->data << endl;
            cout << "Last elem " << tail->data << endl;

            while (curr != nullptr)
            {
                cout << curr->data;
                if (curr->next != nullptr)
                {
                    cout << " -> ";
                }
                else
                {
                    cout << endl;
                }

                curr = curr->next;
            }
        }
    }
};
