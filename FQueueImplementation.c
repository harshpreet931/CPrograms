#include <stdio.h>

struct Customer{
    char name[50];
};

typedef struct Queue{
    struct Customer customers[100];
    int front,rear;
}Queue;

int isFull(Queue * q){
    return q->rear == 99;
}

int isEmpty(Queue * q){
    return q->front > q->rear;
}

void enqueue(Queue * q, struct Customer cust){
    if(!isFull(q)){
        q->customers[++q->rear] = cust;
    }
}

struct Customer dequeue(Queue * q){
    if(!isEmpty(q)){
        return q->customers[q->front++];
    }
}
