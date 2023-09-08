#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char stack[50];
int top = -1;

int isEmpty(){
    return top == -1;
}

int isFull(){
    return top == 49;
}

char peek(){
    return stack[top];
}

char pop(){
    if(isEmpty()) return -1;

    char ch = stack[top];
    top--;
    return ch;
}

void push(char op){
    if(isFull()){
        printf("Stack is full");
    }
    else{
        top++;
        stack[top] = op;
    }
}

int isOP(char ch){
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
}

int precendence(char ch){
    switch (ch)   
    {   
    case '+':   
    case '-':   
        return 1;   
  
    case '*':   
    case '/':   
        return 2;   
  
    case '^':   
        return 3;   
    }   
    return -1; 
}

int covertInfixToPostFix(char * exp){
    int i,j;
    for(i=0,j=-1;exp[i];i++){
        if(isOP(exp[i])) exp[++j] = exp[i];
        else if(exp[i] == '('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            while(!isEmpty() && peek()!='(')
                exp[++j] = pop();
            
            if(!isEmpty() && peek()!='('){
                return -1;
            }
            else{
                pop();
            }
        }
        else{
            while(!isEmpty() && precendence(exp[i]) <= precendence(peek())){
                exp[++j] = pop();
            }
            push(exp[i]);
        }
    }

    while(!isEmpty()){
        exp[++j] = pop();
    }
    exp[++j] = '\0';
    printf("%s\n",exp);
}

int main()  
{  
    char expression[] = "a+b*(c^d-e)^(f+g*h)-i";   
    covertInfixToPostFix(expression);   
    return 0;   
}