#include <iostream>
#include "binarytree.h"
using namespace std;


int main(int argc, char** argv){
    BinaryTree* tree = new BinaryTree();
    node* nine = tree->addRoot(9);
    node* thirteen = tree->addLeft(nine, 13);
    node* twenty = tree->addLeft(thirteen, 20);
    tree->print();

}