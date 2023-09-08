#include <stdio.h>

typedef struct Stack{
    int arr[100];
    int top;
}Stack;

int isFull(Stack * st){
    return st->top == 99;
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
    char string[100];
    printf("Enter a String to reverse: ");
    scanf("%[^\n]s",string);

    Stack st;
    st.top = -1;

    for(int i=0;string[i]!='\0';i++){
        push(&st,string[i]);
    }

    printf("\nThe reversed String is: ");

    for(int i=0;string[i]!='\0';i++){
        printf("%c",peek(&st));
        pop(&st);
    }

    return 0;
}