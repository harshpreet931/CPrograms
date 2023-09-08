#include <stdio.h>

typedef struct Stack{
    int arr[100];
    int top;
}Stack;

int isFull(Stack * st){
    return st->top == 49;
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
    Stack st;
    st.top = -1;
     
    char input[100];
    printf("Enter the string:");
    scanf("%[^\n]s",input);

    for(int i=0;input[i]!='\0';i++){
        push(&st,input[i]);
    }

    printf("The reversed String is:");
    while(!isEmpty(&st)){
        printf("%c",peek(&st));
        pop(&st);
    }
    return 0;
}