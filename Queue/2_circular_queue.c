#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct circularQueue* q){
    if((q->r+1)%q->size == q->f){
        return 1;
    }
    return 0;
}

int isEmpty(struct circularQueue* q){
    if(q->r == q->f){
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue* q, int val){
    if(isFull(q)){
        printf("the circularQueue is full\n");
    }
    else{
        q->r = (q->r+1)%q->size;
        q->arr[q->r] = val; 
        printf( "Enqued element: %d\n", val);
    }
}  

int dequeue(struct circularQueue* q){
    int a = -1;
    if(isEmpty(q)){
        printf("the circularQueue is Empty\n");
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

int main(){
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0; // it was -1 in queue
    q.arr = (int*) malloc(q.size * sizeof(int));
    
    // Or if taking circularQueue as a pointer:
    // struct circularQueue *q;
    // q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    // q -> size = 100;
    // q ->f = q->r = -1;
    // q -> arr = (int *)malloc(s->size * sizeof(int));

    // Enqueue few elements
    enqueue (&q, 12);  // & because we used *q in enqueue so we 
    enqueue (&q, 55);
    enqueue (&q, 95);
    enqueue (&q, 67);
    printf("dequeuing the element %d \n", dequeue(&q));
    printf("dequeuing the element %d \n", dequeue(&q));
    printf("dequeuing the element %d \n", dequeue(&q));
    printf("dequeuing the element %d \n", dequeue(&q));

    if(isEmpty(&q)){
        printf("circularQueue is empty\n");
    }

    if(isFull(&q)){
        printf("circularQueue is full\n");
    }

    return 0;
} 