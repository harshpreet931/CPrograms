#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int arr[100];
    int top;
};

void initializeStack(struct Stack * stack){
    int top = -1;
}

int isFull(struct Stack * stack){
    return stack -> top == 99;
}

int isEmpty(struct Stack * stack){
    return stack -> top == -1;
}

void push(struct Stack * stack , int value){
    if(!isFull(stack)){
        stack -> arr[++stack -> top] = value;
    }
}

int pop(struct Stack * stack){
    if(!isEmpty(stack)){
        return stack -> arr[stack->top--];
    }
    return '\0';
}



