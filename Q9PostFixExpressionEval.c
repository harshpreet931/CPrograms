#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Stack{
    int items[100];
    int top;
};

void initializeStack(struct Stack * stack){
    stack -> top = -1;
}

bool isFull(struct Stack * stack){
    return stack -> top == 99;
}

bool isEmpty(struct Stack * stack){
    return stack -> top == -1;
}

void push(struct Stack * stack, int value){
    if(!isFull(stack)){
        stack -> items[++stack->top] = value;
    }
}

int pop(struct Stack * stack){
    if(!isEmpty(stack)){
        return stack -> items[stack->top--];
    }
    return -1;
}

int evaluatePostfix(char * expression){
    struct Stack stack;
    initializeStack(&stack);

    for(int i=0;i<strlen(expression);i++){
        char currentChar = expression[i];

        if(isdigit(currentChar)){
            push(&stack,currentChar - '0');
        }
        else if(currentChar=='+' || currentChar=='-' || currentChar=='*' || currentChar=='/'){
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (currentChar) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 != 0) {
                        result = operand1 / operand2;
                    } else {
                        printf("Error: Division by zero.\n");
                        exit(1);
                    }
                    break;
            }

            push(&stack,result);

        }
        return pop(&stack);
    }
}

int main(){
    char expression[100];
    printf("Enter a postfix expression:");
    gets(expression);
    int result = evaluatePostfix(expression);
    printf("Result: %d\n",result);
    return 0;
}