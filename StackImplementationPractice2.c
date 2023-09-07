#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int last;
    int * arr;
}Stack;

int * buildStack(int n){
    return (int *)malloc(n*sizeof(int));
}

void push(Stack * st, int data){
    st->arr[st->last] = data;
    st->last++;
}

void pop(Stack * st){
    st->last--;
}

int top(Stack * st){
    return st->arr[st->last-1];
}
int size(Stack * st){
    return st->last;
}
int empty(Stack * st){
    return st->last==0;
}