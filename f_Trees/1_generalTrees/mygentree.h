#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include "gentree.h"
using namespace std;

class MyGenTree : public GenTree {
	node* root;
	int size;
	
	// helper Functions
	node* createNode(int elem){
	    node* newNode = new node;
	    newNode->elem = elem;
	    newNode->num_child = 0;
	    newNode->parent = nullptr;
	    newNode->children = (node**)malloc(0);
	    size++;
	    return newNode;
	}

	public:
	
	MyGenTree(){
	    size = 0;
	    root = nullptr;
	}
	
	int getSize(){
	    return size;
	}
	
	node* getRoot(){
	   return root;
	}
	
	node* addRoot(int e) {
		// TODO implementation [+10 pts]
        if(root){
            throw logic_error("Already has root");
        }
        
        node* n = createNode(e);
		root = n;
		// size++;
		return n;
	}

	node* addChild(node* p, int e) {
		// TODO implementation [+30 pts]
		
		node* temp = createNode(e);
		p->num_child++;
		p->children = (node**)realloc(p->children, sizeof(node*) * p->num_child);
		p->children[p->num_child - 1] = temp;
		temp->parent = p;
		return temp;
	}


	void remove(node* n) {
		// TODO implementation [+35 pts]
        if(n->num_child >= 2){
            throw logic_error (to_string(n->elem) + " has children");
        }
        
        if(n->parent){
            for(int i = 0; i < n->parent->num_child; i++){
                if(n->parent->children[i] == n){
                    for(int j = i+1; j < n->parent->num_child; j++){
                        n->parent->children[j-1] = n->parent->children[j];
                    }
                    n->parent->num_child--;
                    n->parent = (node*)realloc(n->parent->children, sizeof(node*) * n->parent->num_child);
                    break;
                }
            }
        }else{
            root = nullptr;
        }
        delete n;
        size--;
	}

    // DO NOT MODIFY this line onwards.
	void print() {
		cout << "Size: " << size << endl;
		if (!root) {
			cout << "EMPTY" << endl;
			return;
		}
		node* curr = root;
		print_node("", root);
        cout << "Status: " << check_parent(root, NULL) << endl;
	}

	void print_node(string prefix, node* n) {
		cout << prefix;
        cout << "+-->: ";
        cout << n->elem << endl;
		for (int i = 0; i < n->num_child; i++) {
			print_node(prefix + "|   ", n->children[i]);
		}
	}

    bool check_parent(node* curr, node* par) {
        if (!curr) {
            return true;
        }
        if (curr->parent != par) {
            return false;
        }
        bool res = true;
		for (int i = 0; i < curr->num_child; i++) {
			res &= check_parent(curr->children[i], curr);
		}
        return res;
    }
};