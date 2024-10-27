#include "node.h"

// B - certificate of live birth
// M - Marriage certificate
// C - Community tax certificate
// D - Death certificate

class LinkedList {
	node* head;
	node* tail;
	int size;


	public:
	LinkedList() {
		head = new node;
		tail = new node;
		head->next = tail;
		tail->prev = head;
		size = 0;
		
	}
    
    
    /*void addBetween(Person* p, node* pred, node* succ){
        node* n = new node;
        n->person = p;
        n->prev = pred;
        n->next = succ;
        pred->next = n;
        succ->prev = n;
        size++;
        return n;
    }*/
    
	// TODO add a person
	void add(Person* p) {
        node* newNode = new node();
        newNode->person = p;
        
        if(p->age >= 60){
            node* curr = head->next;
            while(curr != tail && curr->person->age >= 60){
                curr = curr->next;
            }
            
            newNode->next =curr;
            newNode->prev = curr->prev;
            curr->prev->next = newNode;
            curr->prev = newNode;
        }else{
            newNode->next =tail;
            newNode->prev = tail->prev;
            tail->prev->next = newNode;
            tail->prev = newNode;
                
        }
        size++;
	}
    
	// TODO serve the request
	void removeNode(node* targetNode){
	    if(!targetNode){
	        return;
	    }
	    
	    if(targetNode->prev){
	        targetNode->prev->next = targetNode->next;
	    }
	}
	
	
	Person* serveRequest(char ch) {
	   node* curr = head->next;
	   int reqIndx;
	   
	   switch(ch){
	        case'B': reqIndx = 0; break;
	        case'M': reqIndx = 1; break;
	        case'C': reqIndx = 2; break;
	        case'D': reqIndx = 3; break;
	        defaul: return NULL;
	   }
	   
	   while(curr != tail){
	        if(curr->person->requests[reqIndx] == 1){
	            curr->person->requests[reqIndx] = 0;
	            
	            bool hasRequests = false;
	            for(int i = 0; i< 4; i++){
	                if(curr->person->requests[i] == 1){
	                    hasRequests = true;
	                    break;
	                }
	            }
	            
	            if(!hasRequests){
	                curr->prev->next = curr->next;
	                curr->next->prev = curr->prev;
	                Person* personReturn = curr->person;
	                delete curr;
	                size--;
	                return personReturn;
	            }
	            return curr->person;
	        }
	        
	        curr = curr->next;
	   }
	   
	    return NULL;
	}
	
	

	// TODO serve the request
	Person* fastLane() {
	    
	    node* curr = head->next;
	    
	    while(curr != tail){
	        int reqCount = 0;
	        for(int i = 0; i < 4; i++){
	            if(curr->person->requests[i] == 1){
	                reqCount++;
	            }
	        }
	    
	    if(reqCount == 1){
	        curr->prev->next = curr->next;
	        curr->next->prev = curr->prev;
	        Person* personToReturn = curr->person;
	        delete curr;
	        size--;
	        return personToReturn;
	        
	    }
	    curr = curr->next;
	    }
	    return NULL;
	}

	// TODO print
	void print() {
		cout << "Counter: " << size << endl;
            if(size == 0){return;}
		cout << "From First: " << endl;
            node* curr = head->next;
            int ctr = 1;
            while(curr != tail){
                cout << ctr++ << ". ";
                curr->person->print();
                curr = curr->next;
            }
		cout << "From Last: " << endl;
		    curr = tail->prev;
            while(curr != head){
                cout << --ctr << ". ";
                curr->person->print();
                curr = curr->prev;
            }
	}
};