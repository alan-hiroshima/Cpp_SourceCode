#include <iostream>
#include "arraylist.h"
using namespace std;

//! Use F6 to build
//! Use F5 to run

int main(){

    //! Start to code here
    List* list = new ArrayList();
    char ch;
    int num, pos;
    do {
        cout << "Op: ";
        cin >> ch;
        switch (ch) {
            case 'a':
                cin >> num;
                list->add(num);
                break;
            case 'r':
                cin >> num;
                cout << "Remove "<<num << " at pos " << list->remove(num) << endl;
                break;
            case '@':
                cin >> num >> pos;
                list->addAt(num, pos);
                break;
            case 'R':
                cin >> pos;
                cout << "Removed " << list->removeAt(pos) << endl;
                break;
            case 'p':
                list->print();
                break;
            case 'x':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    } while (ch != 'x');


    return 0;
}