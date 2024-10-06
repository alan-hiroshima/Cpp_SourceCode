#include <iostream>
#include "linkedlist.hpp"
using namespace std;

//! Use F6 to build
//! Use F5 to run

int main(){
    
    //! Start to code here
    char operation;
    int num, pos; 
    //rem;

    linkedlist* list = new linkedlist();

    while (1)
    {
        cout << "Instructions: \n"; 
        cout << "t = addNum: \n";
        cout << "h = addHead: \n";
        cout << "@ = addAt: \n";
        cout << "g = get: \n";
        cout << "r = remove: \n";
        cout << "q = removeHead: \n";
        cout << "w = removeTail: \n";
        cout << "R = removeAt: \n";
        cout << "v = removeAll: \n";
        
        cout << "Enter op: ";
	    cin >> operation;


        switch (operation)
        {
            case 't':
	            cout << "Enter num: ";
	            cin >> num;
	            list->addTail(num);
	            break;
	            
	       case 'h':
	             cout << "Enter num: ";
	            cin >> num;
	            list->addHead(num); 
	            break;
            case 'g':
                cout << "Enter pos: ";
                cin >> pos;
                cout << "Element " << pos << ": " << list->get(pos) << endl;
                break;
	       case '@':
	            cout << "Enter num: ";
	            cin >> num;
	            cout << "Enter position: ";
	            cin >> pos;
	            list->addNodeAt(num,pos);
	            break;
            case 'r':
                cout << "Enter num: ";
		    	cin >> num;
                cout << "Removed position " << list->remove(num) << endl;
		    	break;
            case 'q':
                cout << "Removed element is " << list->removeHead() << endl;
		    	break;
            case 'w':
                cout << "Removed element is " << list->removeTail() << endl;
		    	break;
            case 'R':
                cout << "Enter a position to remove: ";
                cin >> pos;
                cout << "Removed element is " << list->removeAt(pos) << endl;
		    	break;
            case 'v':
                cout << "Enter num: ";
		    	cin >> num;
                cout << "The number of times "<< num << " will be removed is "<< list->removeAll(num) << endl;
		    	break;
            case 'p':
	            list->print();
	            break;

            default:
                break;
        }
    }
    
    return 0;
}