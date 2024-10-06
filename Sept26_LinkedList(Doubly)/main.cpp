#include <iostream>
#include "interface.hpp"
#include "doublyLinkedList.hpp"

using namespace std;

//! Use F6 to build
//! Use F5 to run

int main(){

    //! Start to code here

    doublyLinkedList* list = new doublyLinkedList();
    char op;
    int input;

    do
    {
        interface();
        cout << "Op: ";
        cin >> op;

        switch (op)
        {
            case 'a':
                cout << "Enter num: ";
                cin >> input;
                list->addTail(input);
        
                break;

            case 'b':
                cout << "Enter num: ";
                cin >> input;
                list->addHead(input);
        
                break;

            case 'c':
                int index;
                cout << "Enter index: ";
                cin >> index;
                cout << "Enter num: ";
                cin >> input;
                list->addAt(input, index);
        
                break;

            case 'd':
                list->removeHead();
                break;

            case 'e':
                list->removeTail();
                break;

            case 'f':
                cout << "Removing: ";
                cin >> input;
                cout << "Removed position: " <<list->remove(input) << endl;
                break;
            
            case 'g':
                cout << "Remove index: ";
                cin >> input;
                cout << "Removed element: " << list->removeAt(input) << endl;

                break;
            
            case 'h':
                cout << "Remove: ";
                cin >> input;
                list->removeAll(input);
                break;

            case 'j':
                int num;
                cout << "Search for: ";
                cin >> num;

                int res;
                res = list->get(num);

                (res != -1) ? cout << "Found at node #" << res : cout << "Node not found";
                cout << endl << endl;

                break;

            case 'p':
                list->printList();
                break;

            case 's':
                cout << "There are " << list->getSize() << " node/s.\n\n";
                break;

            case 'x':
                cout << "Exiting...\n\n";
                return 0;

            default:
                cout << "Invalid operation.\n\n";
        }

    } while (true);


    return 0;
}