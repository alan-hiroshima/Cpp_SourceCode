#include <iostream>
#include "linkedList.hpp"
using namespace std;

int main(){
    LinkedList* list = new LinkedList();
    char op;
    int num, pos;

    do{
        cout << "a. add node" << endl;
        cout << "b. add head" << endl;
        cout << "c. add node at" << endl;

        cout << "d. remove head" << endl;
        cout << "e. remove tail" << endl;
        cout << "f. remove value" << endl;
        cout << "g. remove index" << endl;
        cout << "h. remove all" << endl;
        
        cout << "j. get/Search" << endl;

        cout << "p. print list" << endl;
        cout << "x. exit" << endl << endl;
        
        cout << "Enter op: ";
        cin >> op;
        
        switch (op)
        {
        case 'a':
            cin >> num;
            list->addTail(num);
            break;
        case 'b':
            cin >> num;
            list->addHead(num);
            break;
        case 'c':
            cin >> num;
            cin >> pos;
            list->addAt(num, pos);
            break;
        case 'd':
            cout << "Removed Element: " << list->removeHead() << endl;
            break;
        case 'e':
            cout << "Removed Element: " << list->removeTail() << endl;
            break;
        case 'f':
            cin >> num;
            cout << num << " is found at " << list->remove(num) << " and is removed" << endl;
            break;
        case 'g':
            cin >> pos;
            cout << "Removed Element: " << list->removeAt(pos) << endl;
            break;
        case 'h':
            cin >> num;
            cout << "Removed Element "<< num << " in " << list->removeAll(num) << " times"<< endl;
            break;
        case 'j':
            cin >> pos;
            cout << list->get(pos) <<endl;
            break;

        case 'p':
            list->print();
            break;
        case 'x':
            break;

        default:
            cout << "invalide operation!!";
            break;
        }

    }while(op != 'x');
    
}