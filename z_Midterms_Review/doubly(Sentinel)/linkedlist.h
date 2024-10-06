#include <iostream>
#include "list.h"
#include "node.h"
using namespace std;

class LinkedList : public List
{

    int size;
    node *head;
    node *tail;

    // Adds a new node between prev and curr
    void addBetween(node *curr, node *prev, int num)
    {
        node *newNode = new node;
        newNode->elem = num;

        newNode->next = curr;
        newNode->prev = prev;
        prev->next = newNode;
        curr->prev = newNode;
        size++;
    }

    // Removes the given node and returns its element
    int removeNode(node *curr)
    {
        if (curr == head || curr == tail)
        {
            return -1; // Cannot remove sentinel nodes
        }

        int removedElement = curr->elem;
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        size--;

        return removedElement;
    }

public:
    // Constructor to initialize sentinels
    LinkedList()
    {
        head = new node;
        tail = new node;
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    // Destructor to clean up all nodes
    ~LinkedList()
    {
        node *curr = head;
        while (curr != nullptr)
        {
            node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        size = 0;
    }

    // Add number at the tail (default position)
    void addNum(int num)
    {
        addBetween(tail, tail->prev, num);
    }

    // Add number at the head
    void addHead(int num)
    {
        addBetween(head->next, head, num);
    }

    // Add number at the tail
    void addTail(int num)
    {
        addBetween(tail, tail->prev, num);
    }

    // Add number at a specific position
    void addAt(int num, int pos)
    {
        if (pos < 1 || pos > size + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 1)
        {
            addHead(num);
        }
        else if (pos == size + 1)
        {
            addTail(num);
        }
        else
        {
            node *curr = head->next;
            for (int i = 1; i < pos; i++)
            {
                curr = curr->next;
            }
            addBetween(curr, curr->prev, num);
        }
    }

    // Remove the first element (head)
    void removeHead()
    {
        if (head->next == tail)
        {
            return; // List is empty
        }
        removeNode(head->next);
    }

    // Remove the last element (tail)
    void removeTail()
    {
        if (tail->prev == head)
        {
            return; // List is empty
        }
        removeNode(tail->prev);
    }

    // Remove the first occurrence of a number
    int remove(int num)
    {
        if (size == 0)
        {
            return -1;
        }

        node *curr = head->next;
        int index = 1;
        while (curr != tail)
        {
            if (curr->elem == num)
            {
                removeNode(curr);
                return index;
            }
            curr = curr->next;
            index++;
        }
        return -1; // Number not found
    }

    // Remove element at a specific position
    int removeAt(int pos)
    {
        if (pos < 1 || pos > size)
        {
            cout << "Invalid position" << endl;
            return -1;
        }

        node *curr = head->next;
        for (int i = 1; i < pos; i++)
        {
            curr = curr->next;
        }
        return removeNode(curr);
    }

    // Remove all occurrences of a number
    int removeAll(int num)
    {
        int count = 0;
        if (size == 0)
        {
            return count;
        }

        node *curr = head->next;
        while (curr != tail)
        {
            if (curr->elem == num)
            {
                node *toRemove = curr;
                curr = curr->next;
                removeNode(toRemove);
                count++;
            }
            else
            {
                curr = curr->next;
            }
        }
        return count;
    }

    // Get the element at a specific position
    int get(int pos)
    {
        if (pos < 1 || pos > size)
        {
            return -1; // Invalid position
        }

        node *curr;
        int count = 0;

        if (pos <= (size + 1) / 2)
        {
            curr = head->next;
            for (int i = 1; i < pos; i++)
            {
                curr = curr->next;
                count++;
            }
            cout << "From head: " << count << endl;
        }
        else
        {
            curr = tail->prev;
            for (int i = size; i > pos; i--)
            {
                curr = curr->prev;
                count++;
            }
            cout << "From tail: " << count << endl;
        }

        return curr->elem;
    }

    int corner(int left, int right){
        return 0;
    }

    int retain(int num){
        return 0;
    }

    // Print the list from head to tail and tail to head
    void print()
    {
        cout << "Size: " << size << endl;

        if (size == 0)
        {
            cout << "Empty" << endl;
            return;
        }

        // Print from head
        node *curr = head->next;
        cout << "From HEAD: ";
        while (curr != tail)
        {
            cout << curr->elem;
            curr = curr->next;
            if (curr != tail)
            {
                cout << " <-> ";
            }
        }
        cout << endl;

        // Print from tail
        curr = tail->prev;
        cout << "From TAIL: ";
        while (curr != head)
        {
            cout << curr->elem;
            curr = curr->prev;
            if (curr != head)
            {
                cout << " <-> ";
            }
        }
        cout << endl;
    }
};
