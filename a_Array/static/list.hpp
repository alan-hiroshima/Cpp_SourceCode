class List {
    public:
    // Adds num to the end of the list.
    virtual void add(int num) = 0;
    
    // Returns the element at the specified position in the list.
    virtual int get(int pos) = 0;
    
    // Removes the first occurrence of num from the list and returns its position.
    // If num is not found, behavior is implementation-dependent.
    virtual int remove(int num) = 0;
    
    // Prints all elements in the list.
    virtual void print() = 0;
    
    // Inserts num at the specified position.
    // The value of pos is assumed to be valid.
    virtual void addAt(int num, int pos) = 0;
    
    // Removes the element at the specified position and returns it.
    // Assumes there is an element at that position.
    virtual int removeAt(int pos) = 0;
    
    // Removes all occurrences of num and returns the count of elements removed.
    virtual int removeAll(int num) = 0;
    
    // Reverses the order of the elements in the list.
    virtual void flip() = 0;
    
    // Adds the specified term to each element in the list.
    virtual void plus(int term) = 0;
    
    // Returns the sum of all elements in the list.
    virtual int summation() = 0;
};
