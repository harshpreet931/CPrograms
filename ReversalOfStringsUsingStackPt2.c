#include <stdio.h>
#include <string.h>

typedef struct Stack{
    int arr[100];
    int top;
}Stack;

void initializeStack(Stack * st){
    st -> top = -1; 
}

int isFull(Stack * st){
    return st->top == 100;
}

int isEmpty(Stack * st){
    return st->top == -1;
}

void push(Stack * st, int value){
    if(!isFull(st)){
        st->arr[++st->top] = value;
    }
}

void pop(Stack * st){
    if(!isEmpty(st)){
        st->top--;
    }
}

int peek(Stack * st){
    return st->arr[st->top];
}

int main(){
    Stack stack;
    initializeStack(&stack);
    char arr[100];
    scanf("%s",arr);

    for(int i=0;i<strlen(arr);i++){
        push(&stack,arr[i]);
    }
    printf("Reverse String:");
    while(!isEmpty(&stack)){
        printf("%c",peek(&stack));
        pop(&stack);
    }
    return 0;

}