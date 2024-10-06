#include <iostream>
using namespace std;


class List { 

    public:

    virtual void addNum(int num) = 0;
    virtual void addHead(int num) = 0;
    virtual void addTail(int num) = 0;
    virtual void addAt(int num, int pos) = 0; // use addBetween


    virtual int remove(int num) = 0; // use removeNode 
    virtual int removeAt(int pos) = 0; // use removeNode
    virtual int removeAll(int num) = 0;

    virtual int retain(int num) = 0; // only reassign pointers
    virtual int corner(int left, int right) = 0; // remove all elements outside the range

    virtual int get(int pos) = 0; // compare which is faster: from head or from tail
    virtual void print() = 0;

};