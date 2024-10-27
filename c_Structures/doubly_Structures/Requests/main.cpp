#include <iostream>
#include "linkedlist.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	LinkedList* list = new LinkedList();
	Person* p;
	char op;
	while (true) {
		cout << "Op: ";
		cin >> op;
		switch (op) {
			case 'a':
				p = new Person();
				cout << "Name: ";
				cin >> p->firstName >> p->lastName;
				cout << "Age: ";
				cin >> p->age;
				cout << "Requests (B,M,C,D): ";
				cin >> p->requests[0] >> p->requests[1] >> p->requests[2] >> p->requests[3];
				list->add(p);
				break;
			case 'B':
			case 'M':
			case 'C':
			case 'D':
				p = list->serveRequest(op);
				if (p) {
					cout << "Thanks for waiting, ";
					p->print_name();
				} else {
					cout << "No one in the waiting list." << endl;
				}
				break;
			case 'f':
				p = list->fastLane();
				if (p) {
					cout << "Fast lane for you, ";
					p->print_name();
				} else {
					cout << "No one in the waiting list." << endl;
				}
				break;
			case 'p':
				list->print();
				break;
			case 'x':
				cout << "Exiting...";
				return 0;
		}
	}
	return 0;
}