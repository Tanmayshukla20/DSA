#include <iostream>
using namespace std;

class Stack
{
private:

    struct Node
    {
        int data;
        Node* next;
    };

    Node* top;   // initially the linked list is empty

public:

    // Constructor
    Stack()
    {
        top = nullptr;
    }

    // linkedListTraversal
    void linkedListTraversal()
    {
        Node* ptr = top;

        while (ptr != nullptr)
        {
            cout << "Element: " << ptr->data << endl;
            ptr = ptr->next;
        }
    }

    // isEmpty
    bool isEmpty()
    {
        if (top == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // isFull
    bool isFull()
    {
        Node* p = new Node;

        if (p == nullptr)
        {
            return true;
        }
        else
        {
            delete p;
            return false;
        }
    }

    // Push
    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        Node* n = new Node;

        n->data = x;
        n->next = top;
        top = n;
    }

    // Pop
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        Node* n = top;

        top = top->next;

        int x = n->data;

        delete n;

        return x;
    }
};

int main()
{
    Stack s;

    s.push(78);
    s.push(7);
    s.push(21);

    s.linkedListTraversal();

    int element = s.pop();

    cout << "Popped element is " << element << endl;

    s.linkedListTraversal();

    return 0;
}