#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size; 
    int top;
    int * arr;
};

int isFull(struct stack*ptr){
    if (ptr->top == ptr->size-1 ){
        return 1;
    }
    else{
        return 0;
    }
}
int isEmpty(struct stack*ptr){
    if (ptr->top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

//Push
void push(struct stack*ptr, int val){
    if (isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
    }

//Pop
int pop(struct stack*ptr){
    if (isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1; //assume our stack does not contain the element -1 
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
        }
    }

//Peek    
int peek(struct stack*sp, int i){
        int arrayInd = sp->top-i+1;
        if (arrayInd < 0){
            printf("Not a valid position for the stack\n");
            return -1;
        }
        else{
            return sp->arr[arrayInd];
        }
    }
 
//Stack Top    
int stackTop(struct stack*sp){
    return sp->arr[sp->top];
}

//Stack Bottom
int stackBottom(struct stack*sp){
    return sp->arr[0];
}

int main(){
    //sp is a structure pointer which store address of stack structure(the custom datatype)
    //sp is a pointer to a structure of type stack
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack)); 
    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof (int));
    printf("stack has been created successfully\n");

    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    push(sp, 70);
    push(sp, 80);
    push(sp,  7);
    push(sp, 68);
    push(sp, 56);
    push(sp, 70);
    push(sp, 44);
    push(sp, 15);
    push(sp, 24); 
    push(sp, 50);// ---> pushed 10th element
    push(sp, 91);// stack overflow since the size of the stack is 10
    printf("After pushing, Full: %d\n", isFull(sp));
    printf("After pushing, Empty:%d\n", isEmpty(sp));

    printf("Popped %d from the stack\n", pop(sp));// --> last in first out
    printf("Popped %d from the stack\n", pop(sp));// --> last in first out
    printf("Popped %d from the stack\n", pop(sp));// --> last in first out

    printf("The top most value of this stack is %d\n", stackTop (sp));
    printf("The bottom most value of this stack is %d\n", stackBottom (sp));
    
    //printing values from the stack:
    for (int j = 1; j <= sp->top+1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
     
    return 0;
}
