#include <iostream>
#include <limits> //minimum value of data type
#include "prob2.h"

// prototype of function contains
bool contains(OrderedSet *ordered, int v);

// function that append new element v to new element v with maintaining increasing order
void add(OrderedSet *ordered, int v)
{
    if (contains(ordered, v) == true)
        return;

    // dynamic memory allocation
    Node *newNode = new Node;
    newNode->value = v;
    newNode->link = nullptr;
    // if head == NULL or value of head > value of newNode, append
    if (ordered->head == nullptr || ordered->head->value > v)
    {
        // assign ordered->head to newNode->link and assign newNode to ordered->head
        // it doesn't mean to assign newNode to newNode->link since c++ is calling by value
        newNode->link = ordered->head;
        ordered->head = newNode;
        ordered->m_size += 1;
    }
    else if (ordered->head->value < v)
    {
        // define pointer that indicates current node
        Node *curNode = ordered->head;
        // operate while curNode's link is not NULL or value of curNode < v
        while (curNode->link != nullptr && curNode->link->value < v)
        {
            // assign curNode's next node to curNode
            curNode = curNode->link;
        }
        // assign curNode's link to newNode's link and insert newNode between curNode and curNode's next node
        newNode->link = curNode->link;
        curNode->link = newNode;
        ordered->m_size += 1;
    }
};

// function that takes an array with integer values and adds values to a Set while keeping them in the correct order
void add(OrderedSet *ordered, const int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        add(ordered, arr[i]);
    }
}

// function that deletes the element corresponding to the given index in a Set
void remove(OrderedSet *ordered, int index)
{
    // define find_idx for searching
    int find_idx = 0;
    Node *preNode = ordered->head;
    Node *removeNode = nullptr;
    if (index == 0)
    {
        // assign ordered->head's link to itself and delete previous ordered->head
        // it doesn't mean to assign ordered->head->link to removeNode since c++ is calling by value
        removeNode = ordered->head;
        ordered->head = ordered->head->link;
        delete removeNode;
    }
    else
    {
        // assign preNode's next node to preNode while find_idx is not index-1
        while (find_idx != index - 1)
        {
            preNode = preNode->link;
            find_idx += 1;
        }
        // assign preNode's next node to removeNode,link preNode to removeNode's next node
        removeNode = preNode->link;
        preNode->link = preNode->link->link;
        // delete removeNode which was dynamically allocated
        delete removeNode;
    }

    ordered->m_size -= 1;
}

// function that returns number of elements of Set instance
int size(OrderedSet *ordered)
{
    return ordered->m_size;
}

// function that checks whether given element exists or not
bool contains(OrderedSet *ordered, int v)
{
    if (ordered->m_size == 0)
        return false;
    else
    {
        // define pointer that indicates current node
        Node *curNode = ordered->head;
        // operate while curNode's next node is not NULL
        while (curNode->link != nullptr)
        {
            // if curNode's value is v, then return true
            if (curNode->value == v)
                return true;
            // assign curNode's next node to curNode
            curNode = curNode->link;
        }
        // check last curNode's value
        if (curNode->value == v)
            return true;
        // if there's no node with value v in linked Set, return false
        return false;
    }
}

// function that checks if an element exists at a given index and returns a value
int getValue(OrderedSet *ordered, int idx)
{
    int find_idx = 0;
    Node *curNode = ordered->head;

    // if idx is 0, then return value of current node
    if (idx == 0)
        return curNode->value;
    else if (idx > 0 && idx < ordered->m_size)
    {
        // assign curNode's next node to curNode while find_idx is not idx
        while (find_idx != idx)
        {
            curNode = curNode->link;
            find_idx += 1;
            // if find_idx is idx, return value of current node
            if (find_idx == idx)
                return curNode->value;
        }
    }
    // if idx is out_of_index, return minimum integer
    int min = std::numeric_limits<int>::min();
    return min;
}