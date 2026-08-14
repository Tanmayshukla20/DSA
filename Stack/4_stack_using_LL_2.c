#include <stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* top = NULL; //initially the linked list is empty

//linkedListTraversal
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

//isEmpty
int isEmpty(struct Node* top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;   
    }
}

//isFull
int isFull(struct Node* top)
{
    struct Node* p = (struct Node*)malloc (sizeof(struct Node));
    if(p == NULL)
    {
        return 1; //f the computer cannot allocate the requested memory, malloc() returns:
    }
    else
    {
        return 0;
    } 
}

//Push
struct Node*  push(struct Node*top, int x) 
//Or struct Node*  push(int x) as struct Node* top is already a global variable so it wall already take it
//same goes with all other functions as well as for queue using linked list also.
{
    if (isFull(top)) {
        printf( "Stack Overflow\n");
        return top;
    }  

    else
    {
        struct Node* n = (struct Node*) malloc(sizeof (struct Node)) ;
        n-> data  = x; 
        n-> next = top;
        top = n;
        return top;
    }
}

//pop
int pop(struct Node *tp)
{
    if (isEmpty(tp)) 
    {
        printf( "Stack Underflow\n");
        return -1;
    }  

    else
    {
        struct Node* n = tp; 
        top =  (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int main()
{
    
    top = push(top, 78); //Or top = push(78)struct Node* top is already a global variable so it wall already take it
    top = push(top, 7);
    top = push(top, 21);

    linkedListTraversal(top);

    int element = pop(top);
    printf("Popped element is %d \n", element);
    linkedListTraversal(top);
    
    return 0; 
}