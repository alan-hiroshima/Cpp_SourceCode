#include <iostream>
#include "list.hpp"
#include "node.hpp"
using namespace std;

class LinkedList : public List{
    private:
        node* head;
        node* tail;
        int size;

        void addBetween(node* pred, node* succ, int num){
            node* curr = new node();
            curr->elem = num;

            curr->next = succ;
            curr->prev = pred;
            pred->next = curr;
            succ->prev = curr;

            size++;
        }

        int removedNode(node* targetNode){
            if(targetNode == head || targetNode == tail){
                return -1;
            }

            int removedElem = targetNode->elem;

            targetNode->prev->next = targetNode->next;
            targetNode->next->prev = targetNode->prev;
            delete targetNode;
            size--;
            return removedElem;
        }
        
    public:
        LinkedList(){
            head = new node();
            tail = new node;
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        ~LinkedList(){
            node* curr = head->next;
            while (curr != tail)
            {
                node* temp = curr;
                curr = curr->next;
                delete temp;
            }
            delete head;
            delete tail;

            head = nullptr;
            tail = nullptr;
            size = 0;
        }

        void addHead(int num){
            addBetween(head, head->next, num);
        }

        void addTail(int num){
            addBetween(tail->prev, tail, num);
        }

        void addAt(int num, int pos){
            if(pos < 1 || pos > size+1)return;

            if(pos == 1){
                addHead(num);
                return;
            }
            if(pos == size + 1){
                addTail(num);
                return;
            }

            node* curr = head->next;
            for(int i = 1; i < pos - 1; i++){
                curr = curr->next;
            }
            addBetween(curr, curr->next, num);
            return;
        }

        int removeHead(){
            if(head->next == tail)return -1;

            return removedNode(head->next);
        }

        int removeTail(){
            if(tail->prev == head)return -1;

            return removedNode(tail->prev);
        }

        int remove(int num){
            if(size == 0){
                return -1;
            }

            node* curr = head->next;
            int index = 1;
            while(curr != tail){
                if(curr->elem == num){
                    removedNode(curr);
                    return index;
                }
                curr = curr->next;
                index++;
            }
            return -1;
        }

        int removeAt(int pos){
                
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
            return removedNode(curr);
        }

        int removeAll(int num){
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
                    removedNode(toRemove);
                    count++;
                }
                else
                {
                    curr = curr->next;
                }
            }
            return count;
        }

        int get(int pos){
                
            if (pos < 1 || pos > size)
            {
                return -1; // Invalid position
            }

            node *curr;
            int count = 1;

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