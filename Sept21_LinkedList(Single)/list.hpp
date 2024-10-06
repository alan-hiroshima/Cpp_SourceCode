class list
{
public:
    virtual void addNum(int num) = 0; // add new node as tail
    virtual void addHead(int num) = 0;
    virtual void addTail(int num) = 0;
    virtual void addNodeAt(int num, int pos) = 0;

    virtual int remove(int num) = 0;
    virtual int removeHead() = 0;
    virtual int removeTail() = 0; 
    virtual int removeAt(int pos) = 0;
    // Removes the element at the _pos_th position. For this problem, assume that there is an element in the _pos_th position. This returns the removed element.
    virtual int removeAll(int num) = 0;
    // Removes all instances of num from the list. Returns the total number of elements removed.


    virtual int get(int pos) = 0;
    virtual void print() = 0;
    
};


