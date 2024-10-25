struct Node // linked Set
{
    int value;
    struct Node *link; // pointer that indicates node
};
struct OrderedSet
{
    int m_size; // size of OrderedSet instance
    Node *head; // OrderedSet instance's start node
    // OrderedSet() : head(nullptr), m_size(0) {} // initialize
};

// function that append new element v to new element v with maintaining increasing order
void add(OrderedSet *ordered, int v);

// function that takes an array with integer values and adds values to a Set while keeping them in the correct order
void add(OrderedSet *ordered, const int *arr, int size);

// function that deletes the element corresponding to the given index in a Set
void remove(OrderedSet *ordered, int index);

// function that returns number of elements of Set instance
int size(OrderedSet *ordered);

// function that checks whether given element exists or not
bool contains(OrderedSet *ordered, int v);

// function that checks if an element exists at a given index and returns a value
int getValue(OrderedSet *ordered, int idx);