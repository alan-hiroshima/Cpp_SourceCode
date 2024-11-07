#include "node.h"
#include <iostream>
using namespace std;

class BinaryTree{
    int size;
    node* root;

    private:
    void print(node* n){
        if(n->left){
            print(n->left);
        }

        cout << n->elem << endl;

        if(n->right){
            print(n->right);
        }

        //cout << n->elem << endl;
    }

    node* addNode(node* p, int num){
            node* n = new node;
            n->elem = num;
            n->parent = p;
            n->left = nullptr;
            n->right = nullptr;
            size++;
            return n;
    }

    public:
    BinaryTree(){
        root = nullptr;
        size = 0;
    }

    node* addRoot(int num){
        if(!root){
            root  = addNode(nullptr, num);
            return root;  
        }

        return nullptr; 
    }

    node* addLeft(node* p, int num){
        if(!p->left){
            p->left = addNode(p, num);
        }
        return p->left;
    }

    void print(){
        cout << "size: " << size << endl;
        print(root);
    }

};