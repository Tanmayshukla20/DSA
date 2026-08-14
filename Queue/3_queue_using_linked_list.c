#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL; // setting front as null initially // making f and r global variables
struct Node *r = NULL; // setting rear as null initially

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the elements of this linked list\n");
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void enqueue(int val)
// no need for void enqueue(struct Node *f, struct Node *r, int val) as we made a global varible of struct queue*f and r
//same goes for all other stack as well as for stack using linked lists too
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    // isFull()
    if (n == NULL)
    {
        printf("Queue is full");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n; // queue is empty currently
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    int val = -1;
    struct Node *ptr = f;
    // isEmpty()
    if (f == NULL) // f = r = n
    {
        printf("Queue is empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
    }
    return val;
}

int main()
{
    linkedListTraversal(f);
    printf("Dequeuing element %d\n", dequeue ()) ;
    enqueue(34); // no need for enqueue(f,r,34) as we made a global varible of f and r
    enqueue(98);
    enqueue(50);
    printf("Dequeuing element %d\n", dequeue ()) ;
    printf("Dequeuing element %d\n", dequeue ()) ;
    printf("Dequeuing element %d\n", dequeue ()) ;
    linkedListTraversal(f);

    return 0;
}