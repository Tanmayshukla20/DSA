#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left node to ne null
    n->right = NULL;                                // setting the right node to ne null
    return n;                                       // returning the created node
}

int main()
{
    /*
    // constructing the root node
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = 4;
    p->left = NULL;
    p->right = NULL;

    // constructing the first node
    struct node *p1;
    p1 = (struct node *)malloc(sizeof(struct node));
    p->data = 6;
    p1->left = NULL;
    p1->right = NULL;

    // constructing the second node
    struct node *p2;
    p2 = (struct node *)malloc(sizeof(struct node));
    p->data = 9;
    p2->left = NULL;
    p2->right = NULL;

    p->left = p1;
    p->right = p2;
    */

    // Constructing the root node - Using Functions
    struct node *p = createNode(4);
    struct node *p1 = createNode(6);
    struct node *p2 = createNode(9);

    // Linking the root node with left and right children
    p->left = p1;
    p->right = p2;

    return 0;
}