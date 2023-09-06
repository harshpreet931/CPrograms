#include <stdio.h>
#include <string.h>

struct Stack{
    char arr[100];
    int top;
};

void initializeStack(struct Stack * stack){
    stack -> top = -1;
}

int isFull(struct Stack * stack){
    return stack -> top == 99;
}

int isEmpty(struct Stack * stack){
    return stack -> top == -1;
}

void push(struct Stack * stack, char value){
    if(!isFull(stack)){
        stack -> arr[++(stack -> top)] = value;
    }
}

char pop(struct Stack * stack){
    if(!isEmpty(stack)){
        return stack -> arr[(stack -> top)--];
    }
    return '\0';
}

int main(){
    struct Stack stack;
    initializeStack(&stack);
    char input[100];
    printf("Enter a String:");
    gets(input);
    for(int i=0;i<strlen(input);i++){
        push(&stack,input[i]);
    }
    printf("Reversed String:");
    while(!isEmpty(&stack)){
        printf("%c",pop(&stack));
    }
    return 0;
}
