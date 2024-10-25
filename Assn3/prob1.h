struct Node // linked list
{
    int value;
    struct Node *link; // pointer that indicates node
};
struct OrderedList
{
    int m_size; // size of OrderedList instance
    Node *head; // OrderedList instance's start node
    // OrderedList() : head(nullptr), m_size(0) {} // initialize
};

// function that append new element v to new element v with maintaining increasing order
void add(OrderedList *ordered, int v);

// function that takes an array with integer values and adds values to a list while keeping them in the correct order
void add(OrderedList *ordered, const int *arr, int size);

// function that deletes the element corresponding to the given index in a list
void remove(OrderedList *ordered, int index);

// function that returns number of elements of list instance
int size(OrderedList *ordered);

// function that checks whether given element exists or not
bool contains(OrderedList *ordered, int v);

// function that checks if an element exists at a given index and returns a value
int getValue(OrderedList *ordered, int idx);