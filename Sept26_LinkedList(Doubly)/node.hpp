
struct node
{
    int data;
    node* next;
    node* prev;

    node() : data(0) , next(nullptr), prev(nullptr){}
    node(int val) : data(val), next(nullptr), prev(nullptr){}
};
