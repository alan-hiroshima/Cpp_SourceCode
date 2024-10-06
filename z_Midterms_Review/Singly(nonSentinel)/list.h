class List
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
    virtual int removeAll(int num) = 0;

    virtual int get(int pos) = 0;
    virtual void print() = 0;
    
};


