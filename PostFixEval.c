#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int stack[100];
int top = -1;

void push(int value){
    if(top<100){
        stack[++top] = value;
    }
    else{
        printf("Stack overflow");
        exit(1);
    }
}

int pop(){
    if(top >= 0){
        return stack[top--];
    }
    else{
        printf("Stack underflow");
        exit(1);
    }
}

int main(){
    char exp[100];
    printf("ENter a postfix expression:");
    gets(exp);

    int i = 0;
    while(exp[i]!='\0'){
        if(exp[i]>='0' && exp[i]<='9'){
            push(exp[i]-'0');
        }
        else if(exp[i]==' '){
            continue;
        }
        else if(exp[i] == '+'){
            int op1 = pop();
            int op2 = pop();
            push(op1 + op2);
        }
        else if(exp[i] == '-'){
            int op1 = pop();
            int op2 = pop();
            push(op1 - op2);
        }
        i++;

    }
    printf("res : %d",stack[top]);
    return 0;

}