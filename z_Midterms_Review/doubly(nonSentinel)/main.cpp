#include <iostream>
#include "linkedList.h"
using namespace std;

int main(){
    List* list = new Linkedlist();
    char op;
    int num, pos;

    do {
        cout << "Enter op: ";
        cin >> op;

        switch (op)
        {
        case 'h':
            cin >> num;
            list->addHead(num);
            break;
        case 't':
            cin >> num;
            list->addTail(num);
            break;
        case '@':
            cin >> num;
            cin >> pos;
            list->addAt(num, pos);
            break;
        case 'r':
            cin >> num;
            cout << "Removed " << num << " at position " << list->remove(num) << endl;
            break;
        case 'A':
            cin >> pos;
            cout << "Remove element: " << list->removeAt(pos) << endl;
            break;
        case 'R':
            cin >> num;
            cout << "Removed items: " << list->removeAll(num) << endl;
            break;
        case 'g':
            cin >> pos;
            cout << "Element: " << list->get(pos) << endl;
            break;
        case 'p':
            list->print();
            break;    
    
        default:
            cout << "Invalid operation!" << endl;
            break;
        }
    } while (op != 'x');
    return 0;
}