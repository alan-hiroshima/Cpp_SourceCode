
class list {
public:
    //!  ADD
    virtual void addHead(int num) = 0;
    virtual void addTail(int num) = 0; //also know as addNode
    virtual void addAt(int num, int pos) = 0;
    
    //!  REMOVE
    virtual int removeHead() = 0;
    virtual int removeTail() = 0;
    virtual int remove(int num) = 0; // 1st occurence of num and return pos & if does not exist return -1
    virtual int removeAt(int pos) = 0;
    virtual int removeAll(int num) = 0;

    virtual int getSize() = 0;

    virtual int get(int pos) = 0;
    virtual int retain(int num) = 0;
    virtual int corner(int left, int right) = 0;
    virtual void reverse() = 0;
    virtual void printList() = 0;
};