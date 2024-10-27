#include "person.h"

struct node {
	Person* person;
	node* next;
	node* prev;
};

typedef node Node;