#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack{
    char items[100];
    int top;
}Stack;

void initializeStack(struct Stack * stack){
    stack -> top = -1;
}

bool isFull(struct Stack * stack){
    return stack -> top == 99;
}

bool isEmpty(struct Stack * stack){
    return stack -> top == -1;
}

void push(struct Stack * stack, char value){
    if(!isFull(stack)){
        stack -> items[++stack->top] = value;
    }
}

char pop(struct Stack * stack){
    if(!isEmpty(stack)){
        return stack -> items[stack -> top--];
    }
    return '\0';
}

bool isBalanced(char * expression){
    struct Stack stack;
    initializeStack(&stack);

    for(int i=0;i<strlen(expression);i++){
        char ch = expression[i];
        if(ch=='(' || ch=='[' || ch=='{'){
            push(&stack,ch);
        }
        else if(ch==')' || ch=='}' || ch==']'){
            if(isEmpty(&stack)){
                return false;
            }
            
            char topch = pop(&stack);
            if(ch == ')' && topch !='(' || ch == '}' && topch !='{' || ch == ']' && topch !='['){
                return false;
            }
        }
    }
    return isEmpty(&stack);
}

int main(){
    char expression[100];
    printf("Enter the String with parantheses:");
    gets(expression);

    if(isBalanced(expression)){
        printf("The paranthese are balananced\n");
    }
    else{
        printf("The parantheses are not balanced");
    }

    return 0;
}