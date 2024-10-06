struct node
{
    int data;
    node* next;

    node() : data(0), next(nullptr){}
    node(int val) : data(val), next(nullptr){}
};
