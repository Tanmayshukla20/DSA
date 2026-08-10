#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
}; 

int isEmpty(struct stack * ptr)
{
    if (ptr ->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}

int isFull(struct stack * ptr)
{
    if (ptr ->top == ptr ->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}
 
//Push
void push(struct stack*ptr, char val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
    }

//Pop
char pop(struct stack*ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1; //assume our stack does not contain the element -1 
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
        }
    }

int paranthesisMatch(char *exp)
{
    struct stack*sp;
    sp->size = 100;
    sp -> top = -1; //empty stack 
    sp -> arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='(')
        {
            push(sp, '(');
        }
        else if (exp[i]==')')
        {
            if (isEmpty(sp)){
                return 0;
            }
            else{
                pop(sp);
            }
        }
    }
    return (isEmpty(sp));
    }

int main(){

    char * exp = " 6*(9)+4 ";
    if(paranthesisMatch(exp)){
        printf("The paranthesis is matching\n");
    }
    else
    {
        printf("The paranthesis is not matching\n");
    }
   return 0; 
}





