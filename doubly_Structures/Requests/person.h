#include <iostream>
using namespace std;

struct Person {
	string firstName;
	string lastName;
	int age;
	int requests[4];

	void print_name() {
		cout << firstName << " " << lastName << endl;
		
	}
	
	void print(){
	    cout << firstName << " " << lastName << " ("<< age << ") - req: ";
	    char req_ch[4] = {'B', 'M' , 'C', 'D'};
	    for(int i = 0; i< 4; i++){
	        if(requests[i] == 1){
	            cout << req_ch[i] << " ";
	        }
	    }
	    cout << endl;
		
	}
};