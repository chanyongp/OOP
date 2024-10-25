#pragma once
#ifndef MULTIHEADLIST_H
#define MULTIHEADLIST_H

using namespace std;

// Node which is used for MultiHeadList
template <typename T>
struct Node
{
    T data;
    Node *prev; // indicating previous Node
    Node *next; // indicating next Node
    // constructor
    Node(const T &data) : data(data), prev(nullptr), next(nullptr) {}
};

// doubly linked list which has several Heads
template <typename T>
class MultiHeadList
{
private:
    vector<Node<T> *> headList; // vector containing Heads' addresses

public:
    // iterator which is used for operator overloading
    template <typename TI>
    class Iterator
    {
    private:
        Node<TI> *curr; // indicating current Node

    public:
        // constructor
        Iterator(Node<TI> *node) { curr = node; }

        Iterator &operator++() // for ++it operator
        {
            curr = curr->next; // assign next Node
            return *this;      // reference of Iterator itself
        }
        Iterator operator++(int) // for it++ operator
        {
            /*
            Since we have to operate with value before operating,
            it returns tmp, not *this
            */
            Iterator tmp = *this;
            curr = curr->next; // assign next Node
            return tmp;        // it cannot be duplicated
        }
        Iterator &operator--() // for --it operator
        {
            curr = curr->prev; // assign previous Node
            return *this;      // reference of Iterator itself
        }
        Iterator operator--(int) // for it-- operator
        {
            /*
            Since we have to operate with value before operating,
            it returns tmp, not *this
            */
            Iterator tmp = *this;
            curr = curr->prev; // assign next Node
            return tmp;        // it cannot be duplicated
        }
        Iterator &operator+(int n)
        {
            // assign next Node n times
            for (int i = 0; i < n; i++)
            {
                curr = curr->next;
            }
            return *this; // reference of Iterator itself
        }
        Iterator &operator-(int n)
        {
            // assign previous Node n times
            for (int i = 0; i < n; i++)
            {
                curr = curr->prev;
            }
            return *this; // reference of Iterator itself
        }
        bool operator!=(Iterator curr2)
        {
            /*
            it compares with current node's next node and curr2's current node
            Since MultiHeadList has head, tail Nodes
            */
            return curr->next != curr2.getcurr();
        }
        bool operator==(Iterator curr2)
        {
            // it compares current node and curr2's current node
            return curr == curr2.getcurr();
        }
        TI &operator*()
        {
            // it returns current node's data
            return curr->data;
        }
        Node<TI> *getcurr()
        {
            // it returns current node
            return curr;
        }
    };
    // reverse iterator which is used for operator overloading
    template <typename TRI>
    class ReverseIterator
    {
    private:
        Node<TRI> *curr; // indicating current Node

    public:
        // constructor
        ReverseIterator(Node<TRI> *node) { curr = node; }
        ReverseIterator &operator++() // for ++it operator
        {
            curr = curr->prev; // assign previous Node
            return *this;      // reference of Iterator itself
        }
        ReverseIterator operator++(int) // for it++ operator
        {
            /*
            Since we have to operate with value before operating,
            it returns tmp, not *this
            */
            ReverseIterator tmp = *this;
            curr = curr->prev; // assign previous Node
            return tmp;        // it cannot be duplicated
        }
        ReverseIterator &operator--() // for --it operator
        {
            curr = curr->next; // assign next Node
            return *this;      // reference of Iterator itself
        }
        ReverseIterator operator--(int) // for it-- operator
        {
            /*
            Since we have to operate with value before operating,
            it returns tmp, not *this
            */
            ReverseIterator tmp = *this;
            curr = curr->next; // assign next Node
            return tmp;        // it cannot be duplicated
        }
        ReverseIterator &operator+(int n)
        {
            // assign previous Node n times
            for (int i = 0; i < n; i++)
            {
                curr = curr->prev;
            }
            return *this; // reference of Iterator itself
        }
        ReverseIterator &operator-(int n)
        {
            // assign next Node n times
            for (int i = 0; i < n; i++)
            {
                curr = curr->next;
            }
            return *this; // reference of Iterator itself
        }
        bool operator!=(ReverseIterator curr2)
        {
            /*
            it compares with current node's previous node and curr2's current node
            Since MultiHeadList has head, tail Nodes
            */
            return curr->prev != curr2.getcurr();
        }
        bool operator==(ReverseIterator curr2)
        {
            // it compares current node and curr2's current node
            return curr == curr2.getcurr();
        }
        TRI &operator*()
        {
            // it returns current node's data
            return curr->data;
        }
        Node<TRI> *getcurr()
        {
            // it returns current node
            return curr;
        }
    };

public:
    // default constructor
    MultiHeadList() {}
    // destructor
    ~MultiHeadList()
    {
        // delete all nodes in the headList
        for (int i = 0; i != headSize(); i++)
        {
            Node<T> *curNode = headList[i];
            while (true)
            {
                if (curNode->next == nullptr)
                {
                    // cout << curNode->data;
                    delete curNode;
                    break;
                }
                Node<T> *delNode = curNode;
                curNode = curNode->next;
                // cout << delNode->data;
                delete delNode;
            }
            // cout << "\n";
        }
    }
    // return size of headList
    int headSize()
    {
        return headList.size();
    }
    // add node having data at the end of headList's headIdx'th list
    void push_back(const T &data, int headIdx = -1) // default headIdx value is -1
    {
        // if headIdx is negative or if it exceeds size of headList
        if ((headIdx < 0) || headIdx > (headSize() - 1))
        {
            // dynamic allocation of HeadNode, TailNode
            Node<T> *HeadNode = new Node<T>(T(NULL));
            Node<T> *TailNode = new Node<T>(T(NULL));
            // push back HeadNode in the headLIst
            headList.push_back(HeadNode);
            // connect HeadNode and TailNode
            HeadNode->next = TailNode;
            HeadNode->prev = nullptr;
            TailNode->prev = HeadNode;
            TailNode->next = nullptr;

            // first element of headlist's last list
            Node<T> *preNode = headList[headSize() - 1];
            while (true)
            {
                // if preNode's next node is TailNode, break
                if (preNode->next->next == nullptr)
                {
                    break;
                }
                preNode = preNode->next;
            }
            // dynamic allocation of newNode with data
            Node<T> *newNode = new Node<T>(data);
            // connect newNode between preNode and TailNode
            newNode->next = preNode->next;
            preNode->next->prev = newNode;
            preNode->next = newNode;
            newNode->prev = preNode;
        }
        else
        {
            // first element of headlist's 'headIdx'th list
            Node<T> *preNode = headList[headIdx];
            while (true)
            {
                // if preNode's next node is TailNode, break
                if (preNode->next->next == nullptr)
                {
                    break;
                }
                preNode = preNode->next;
            }
            // dynamic allocation of newNode with data
            Node<T> *newNode = new Node<T>(data);
            // connect newNode between preNode and TailNode
            newNode->next = preNode->next;
            preNode->next->prev = newNode;
            preNode->next = newNode;
            newNode->prev = preNode;
        }
    }
    // add node having data in front of headList's headIdx'th list
    void push_front(const T &data, int headIdx = -1)
    {
        // if headIdx is negative or if it exceeds size of headList
        if ((headIdx < 0) || headIdx > (headSize() - 1))
        {
            // dynamic allocation of HeadNode, TailNode
            Node<T> *HeadNode = new Node<T>(T(NULL));
            Node<T> *TailNode = new Node<T>(T(NULL));
            // push back HeadNode in the headLIst
            headList.push_back(HeadNode);
            // connect HeadNode and TailNode
            HeadNode->next = TailNode;
            HeadNode->prev = nullptr;
            TailNode->prev = HeadNode;
            TailNode->next = nullptr;

            // first element of headlist's last list
            Node<T> *preNode = headList[headSize() - 1];
            // dynamic allocation of newNode with data
            Node<T> *newNode = new Node<T>(data);
            // connect newNode between preNode and preNode's next node
            newNode->next = preNode->next;
            preNode->next->prev = newNode;
            preNode->next = newNode;
            newNode->prev = preNode;
        }
        else
        {
            // first element of headlist's 'headIdx'th list
            Node<T> *preNode = headList[headIdx];
            // dynamic allocation of newNode with data
            Node<T> *newNode = new Node<T>(data);
            // connect newNode between preNode and preNode's next node
            newNode->next = preNode->next;
            preNode->next->prev = newNode;
            preNode->next = newNode;
            newNode->prev = preNode;
        }
    }
    // add node having data to location where pos indicates
    void insert(Iterator<T> pos, const T &data)
    {
        // dynamic allocation of newNode with data
        Node<T> *newNode = new Node<T>(data);
        // previous node of pos' current node
        Node<T> *preNode = pos.getcurr()->prev;
        // connect newNode between preNode and pos' current node
        preNode->next = newNode;
        newNode->prev = preNode;
        pos.getcurr()->prev = newNode;
        newNode->next = pos.getcurr();
    }
    // delete node at the end of headList's headIdx'th list
    void pop_back(int headIdx)
    {
        // if headIdx is negative or if it exceeds size of headList
        if (!((headIdx < 0) || headIdx > (headSize() - 1)))
        {
            // first element of headlist's 'headIdx'th list
            Node<T> *delNode = headList[headIdx];
            while (true)
            {
                // if delNode's next node is TailNode, break
                if (delNode->next->next == nullptr)
                {
                    break;
                }
                delNode = delNode->next;
            }
            // previous node of delNode
            Node<T> *preNode = delNode->prev;
            // connect preNode and delNode's next node and delete delNode
            preNode->next = delNode->next;
            delNode->next->prev = preNode;
            delete delNode;
            // if this row is empty, delete it
            if (headList[headIdx]->next->next == nullptr)
            {
                headList.erase(headList.begin() + headIdx);
            }
        }
    }
    // delete node in front of headList's headIdx'th list
    void pop_front(int headIdx)
    {
        // if headIdx is negative or if it exceeds size of headList
        if (!((headIdx < 0) || headIdx > (headSize() - 1)))
        {
            // first element of headlist's headIdx'th list
            Node<T> *delNode = headList[headIdx]->next;
            // previous node of delNode
            Node<T> *preNode = delNode->prev;
            // connect preNode and delNode's next node and delete delNode
            preNode->next = delNode->next;
            delNode->next->prev = preNode;
            delete delNode;
            // if this row is empty, delete it
            if (headList[headIdx]->next->next == nullptr)
            {
                headList.erase(headList.begin() + headIdx);
            }
        }
    }
    // attach backHeadIdx'th list at the end of frontHeadIdx'th list
    void merge(int frontHeadIdx, int backHeadIdx)
    {
        // it works if frontHeadIdx != backHeadIdx
        if (frontHeadIdx != backHeadIdx)
        {
            // HeadNode of headList's frontHeadIdx'th list
            Node<T> *preNode = headList[frontHeadIdx];
            // HeadNode of headList's backHeadIdx'th list
            Node<T> *mid2Node = headList[backHeadIdx];
            while (true)
            {
                // if preNode's next node is TailNode, break
                if (preNode->next->next == nullptr)
                {
                    break;
                }
                preNode = preNode->next;
            }
            // mid1Node is TailNode of headList's frontHeadIdx'th list
            Node<T> *mid1Node = preNode->next;
            // aftNode is first element of headList's backHeadIdx'th list
            Node<T> *aftNode = mid2Node->next;
            // connect preNode and aftNode
            preNode->next = aftNode;
            aftNode->prev = preNode;
            // delete TailNode of frontHeadIdx'th list and HeadNode of headList's backHeadIdx'th list
            delete mid1Node;
            delete mid2Node;

            // delete row which is moved
            headList.erase(headList.begin() + backHeadIdx);
        }
    }
    // delete if there's node with data in the targetHeadIdx'th list
    bool erase(const T &data, int targetHeadIdx)
    {
        // HeadNode of headList's targetHeadIdx'th list
        Node<T> *preNode = headList[targetHeadIdx];
        while (true)
        {
            // if preNode is TailNode, return false
            if (preNode->next == nullptr)
            {
                return false;
            }
            // if data of preNode's next node is correct, break
            if (preNode->next->data == data)
            {
                break;
            }

            preNode = preNode->next;
        }
        // node which has correct data
        Node<T> *delNode = preNode->next;
        // connect preNode and delNode's next node
        preNode->next = delNode->next;
        delNode->next->prev = preNode;
        // delete delNode
        delete delNode;

        // if row is empty, delete it
        for (int i = 0; i < headSize(); i++)
        {
            Node<T> *curNode = headList[i];
            if (curNode->next->next == nullptr)
            {
                headList.erase(headList.begin() + i);
            }
        }
        // after erasing, return true
        return true;
    }
    // delete node where pos is indicating and separate
    bool erase(Iterator<T> pos)
    {
        // dynamic allocation of HeadNode(which will be a new list's HeadNode), TailNode(which will be a current list's TailNode)
        Node<T> *HeadNode = new Node<T>(T(NULL));
        Node<T> *TailNode = new Node<T>(T(NULL));
        // push back HeadNode in the headList
        headList.push_back(HeadNode);

        // previous node of pos' current node
        Node<T> *preNode = pos.getcurr()->prev;
        // next node of pos' current node
        Node<T> *aftNode = pos.getcurr()->next;

        // connect preNode and TailNode
        preNode->next = TailNode;
        TailNode->prev = preNode;
        TailNode->next = nullptr;

        // connect aftNode and HeadNode
        HeadNode->next = aftNode;
        HeadNode->prev = nullptr;
        aftNode->prev = HeadNode;

        // delete pos' current node and separate
        delete pos.getcurr();

        // if row is empty, delete it
        for (int i = 0; i < headSize(); i++)
        {
            Node<T> *curNode = headList[i];
            if (curNode->next->next == nullptr)
            {
                headList.erase(headList.begin() + i);
            }
        }
        // after erasing, return true
        return true;
    }

    // indicate first node(not HeadNode) of headList's headIdx'th list
    Iterator<T> begin(int headIdx)
    {
        return Iterator<T>(headList[headIdx]->next);
    }
    // indicate TailNode's next node, thus return nullptr
    Iterator<T> end()
    {
        return nullptr;
    }
    // indicate last node(not TailNode) of headList's headIdx'th list
    ReverseIterator<T> rbegin(int headIdx)
    {
        // HeadNode of headList's headIdx'th list
        Node<T> *curNode = headList[headIdx];
        while (true)
        {
            // if curNode's next node is TailNode, make curNode to ReverseIterator
            if (curNode->next->next == nullptr)
            {
                return ReverseIterator<T>(curNode);
            }
            curNode = curNode->next;
        }
    }
    // indicate HeadNode's previous node, thus return nullptr
    ReverseIterator<T> rend()
    {
        return nullptr;
    }
};

// type definition of pair<string, string>
typedef pair<string, string> T;
// template specialization for pair
// doubly linked list which has several Heads
template <>
class MultiHeadList<T>
{
private:
    vector<Node<T> *> headList; // vector containing Heads' addresses

public:
    // iterator which is used for operator overloading
    template <typename TI>
    class Iterator
    {
    private:
        Node<TI> *curr; // indicating current Node

    public:
        // constructor
        Iterator(Node<TI> *node) { curr = node; }

        Iterator &operator++() // for ++it operator
        {
            curr = curr->next; // assign next Node
            return *this;      // reference of Iterator itself
        }
        Iterator operator++(int) // for it++ operator
        {
            /*
            Since we have to operate with value before operating,
            it returns tmp, not *this
            */
            Iterator tmp = *this;
            curr = curr->next; // assign next Node
            return tmp;        // it cannot be duplicated
        }
        Iterator &operator--() // for --it operator
        {
            curr = curr->prev; // assign previous Node
            return *this;      // reference of Iterator itself
        }
        Iterator operator--(int) // for it-- operator
        {
            /*
            Since we have to operate with value before operating,
            it returns tmp, not *this
            */
            Iterator tmp = *this;
            curr = curr->prev; // assign next Node
            return tmp;        // it cannot be duplicated
        }
        Iterator &operator+(int n)
        {
            // assign next Node n times
            for (int i = 0; i < n; i++)
            {
                curr = curr->next;
            }
            return *this; // reference of Iterator itself
        }
        Iterator &operator-(int n)
        {
            // assign previous Node n times
            for (int i = 0; i < n; i++)
            {
                curr = curr->prev;
            }
            return *this; // reference of Iterator itself
        }
        bool operator!=(Iterator curr2)
        {
            /*
            it compares with current node's next node and curr2's current node
            Since MultiHeadList has head, tail Nodes
            */
            return curr->next != curr2.getcurr();
        }
        bool operator==(Iterator curr2)
        {
            // it compares current node and curr2's current node
            return curr == curr2.getcurr();
        }
        TI &operator*()
        {
            // it returns current node's data
            return curr->data;
        }
        Node<TI> *getcurr()
        {
            // it returns current node
            return curr;
        }
    };
    // reverse iterator which is used for operator overloading
    template <typename TRI>
    class ReverseIterator
    {
    private:
        Node<TRI> *curr; // indicating current Node

    public:
        // constructor
        ReverseIterator(Node<TRI> *node) { curr = node; }
        ReverseIterator &operator++() // for ++it operator
        {
            curr = curr->prev; // assign previous Node
            return *this;      // reference of Iterator itself
        }
        ReverseIterator operator++(int) // for it++ operator
        {
            /*
            Since we have to operate with value before operating,
            it returns tmp, not *this
            */
            ReverseIterator tmp = *this;
            curr = curr->prev; // assign previous Node
            return tmp;        // it cannot be duplicated
        }
        ReverseIterator &operator--() // for --it operator
        {
            curr = curr->next; // assign next Node
            return *this;      // reference of Iterator itself
        }
        ReverseIterator operator--(int) // for it-- operator
        {
            /*
            Since we have to operate with value before operating,
            it returns tmp, not *this
            */
            ReverseIterator tmp = *this;
            curr = curr->next; // assign next Node
            return tmp;        // it cannot be duplicated
        }
        ReverseIterator &operator+(int n)
        {
            // assign previous Node n times
            for (int i = 0; i < n; i++)
            {
                curr = curr->prev;
            }
            return *this; // reference of Iterator itself
        }
        ReverseIterator &operator-(int n)
        {
            // assign next Node n times
            for (int i = 0; i < n; i++)
            {
                curr = curr->next;
            }
            return *this; // reference of Iterator itself
        }
        bool operator!=(ReverseIterator curr2)
        {
            /*
            it compares with current node's previous node and curr2's current node
            Since MultiHeadList has head, tail Nodes
            */
            return curr->prev != curr2.getcurr();
        }
        bool operator==(ReverseIterator curr2)
        {
            // it compares current node and curr2's current node
            return curr == curr2.getcurr();
        }
        TRI &operator*()
        {
            // it returns current node's data
            return curr->data;
        }
        Node<TRI> *getcurr()
        {
            // it returns current node
            return curr;
        }
    };

public:
    // default constructor
    MultiHeadList() {}
    // destructor
    ~MultiHeadList()
    {
        // delete all nodes in the headList
        for (int i = 0; i != headSize(); i++)
        {
            Node<T> *curNode = headList[i];
            while (true)
            {
                if (curNode->next == nullptr)
                {
                    // cout << curNode->data.first << curNode->data.second;
                    delete curNode;
                    break;
                }
                Node<T> *delNode = curNode;
                curNode = curNode->next;
                // cout << delNode->data.first << delNode->data.second;
                delete delNode;
            }
            // cout << "\n";
        }
    }
    // return size of headList
    int headSize()
    {
        return headList.size();
    }
    // add node having data at the end of list
    void push_back(const pair<string, string> &data)
    {
        // dynamic allocation of HeadNode, TailNode
        Node<T> *HeadNode = new Node<T>(make_pair("head1", "head2"));
        Node<T> *TailNode = new Node<T>(make_pair("tail1", "tail2"));
        // push back HeadNode in the headLIst
        headList.push_back(HeadNode);
        // connect HeadNode and TailNode
        HeadNode->next = TailNode;
        HeadNode->prev = nullptr;
        TailNode->prev = HeadNode;
        TailNode->next = nullptr;

        // first element of headlist's last list
        Node<T> *preNode = headList[headSize() - 1];
        while (true)
        {
            // if preNode's next node is TailNode, break
            if (preNode->next->next == nullptr)
            {
                break;
            }
            preNode = preNode->next;
        }
        // dynamic allocation of newNode with data
        Node<T> *newNode = new Node<T>(data);
        // connect newNode between preNode and TailNode
        newNode->next = preNode->next;
        preNode->next->prev = newNode;
        preNode->next = newNode;
        newNode->prev = preNode;
    }
    // attach backHeadIdx'th list at the end of frontHeadIdx'th list
    void merge(int frontHeadIdx, int backHeadIdx)
    {
        // it works if frontHeadIdx != backHeadIdx
        if (frontHeadIdx != backHeadIdx)
        {
            // HeadNode of headList's frontHeadIdx'th list
            Node<T> *preNode = headList[frontHeadIdx];
            // HeadNode of headList's backHeadIdx'th list
            Node<T> *mid2Node = headList[backHeadIdx];
            while (true)
            {
                // if preNode's next node is TailNode, break
                if (preNode->next->next == nullptr)
                {
                    break;
                }
                preNode = preNode->next;
            }
            // mid1Node is TailNode of headList's frontHeadIdx'th list
            Node<T> *mid1Node = preNode->next;
            // aftNode is first element of headList's backHeadIdx'th list
            Node<T> *aftNode = mid2Node->next;
            // connect preNode and aftNode
            preNode->next = aftNode;
            aftNode->prev = preNode;
            // delete TailNode of frontHeadIdx'th list and HeadNode of headList's backHeadIdx'th list
            delete mid1Node;
            delete mid2Node;

            // delete row which is moved
            headList.erase(headList.begin() + backHeadIdx);
        }
    }
    // indicate first node(not HeadNode) of headList's headIdx'th list
    Iterator<T> begin(int headIdx)
    {
        return Iterator<T>(headList[headIdx]->next);
    }
    // indicate TailNode's next node, thus return nullptr
    Iterator<T> end()
    {
        return nullptr;
    }
    // indicate last node(not TailNode) of headList's headIdx'th list
    ReverseIterator<T> rbegin(int headIdx)
    {
        // HeadNode of headList's headIdx'th list
        Node<T> *curNode = headList[headIdx];
        while (true)
        {
            // if curNode's next node is TailNode, make curNode to ReverseIterator
            if (curNode->next == nullptr)
            {
                return ReverseIterator<T>(curNode);
            }
            curNode = curNode->next;
        }
    }
    // indicate HeadNode's previous node, thus return nullptr
    ReverseIterator<T> rend()
    {
        return nullptr;
    }
};
#endif