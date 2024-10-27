#include <iostream>
#include "arraylist.hpp"
using namespace std;

//! Use F6 to build
//! Use F5 to run

int main(){

    //! Start to code here
    List* list = new ArrayList();
    char op; // choose operator
    int num, pos;

    // TODO: Use the List ADT opereation
    do
    {
        cout << "Operation: ";
        cin >> op;

        switch (op)
        {
            case 'a': // void add(int num)
                cin >> num;
                list->add(num);
                break;
            case '@': // void addAt(int num, int pos)
                cin >> num >> pos;
                list->addAt(num, pos);
                break;
            case 'r': // int removeAt(int pos)
                cin >> pos;
                cout << "Removed " << list->removeAt(pos) << endl;
                break;
            case 'R': // int removeAll(int num)
                cin >> num;
                cout << "Removed " << list->removeAll(num) << " element/s" << endl;
                break;
            case 'f': // void flip()
                list->flip();
                break;
            case '+': // void plus(int term)
                cin >> num;
                list->plus(num);
                break;
            case 's': // int summation()
                cout << "Sum: " << list->summation() << endl;
                break;
            case 'p': // void print()
                list->print();
                break;
            case 'x':
                cout << "Exiting..........";
                break;
            default:
                cout << "Invalid Operation" << endl;
        }

    } while (op != 'x');
    

    return 0;
}