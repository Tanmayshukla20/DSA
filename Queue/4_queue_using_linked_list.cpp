#include <iostream>
using namespace std;

class Queue
{
private:

    struct Node
    {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:

    // Constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Display the queue
    void display()
    {
        Node* ptr = front;

        cout << "Printing the elements of this linked list" << endl;

        while (ptr != nullptr)
        {
            cout << "Element: " << ptr->data << endl;
            ptr = ptr->next;
        }
    }

    // Enqueue
    void enqueue(int val)
    {
        Node* n = new Node;

        n->data = val;
        n->next = nullptr;

        // If queue is empty
        if (front == nullptr)
        {
            front = n;
            rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }

    // Dequeue
    int dequeue()
    {
        // If queue is empty
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        Node* ptr = front;

        front = front->next;

        int val = ptr->data;

        delete ptr;

        // If queue becomes empty
        if (front == nullptr)
        {
            rear = nullptr;
        }

        return val;
    }
};


int main()
{
    Queue q;

    q.display();

    // Dequeue from empty queue
    int element = q.dequeue();
    cout << "Dequeuing element " << element << endl;

    // Enqueue elements
    q.enqueue(34);
    q.enqueue(98);
    q.enqueue(50);

    // Dequeue elements
    element = q.dequeue();
    cout << "Dequeuing element " << element << endl;

    element = q.dequeue();
    cout << "Dequeuing element " << element << endl;

    element = q.dequeue();
    cout << "Dequeuing element " << element << endl;

    // Display queue
    q.display();

    return 0;
}