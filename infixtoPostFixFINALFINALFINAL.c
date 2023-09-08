#include <stdio.h>
#include <string.h>

int isOperator(char ch){
    return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^';
}

int isAlphaNum(char ch){
    return ('a'<=ch && ch>='z') || ('A'<=ch && ch>='Z') || ('0'<=ch && '9'>=ch);
}

int precedence(char ch){
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return 0;
}

void convert(char infix[], char postfix[]){
    char stack[100];
    int j = 0, top = -1;
    for(int i = 0 ; infix[i]!='\0' ; i++){
        if(isAlphaNum(infix[i])){
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '('){
            stack[++top] = infix[i];
        }
        else if(infix[i] == ')'){
            while(top>=0 && stack[top]!='('){
                postfix[j++] = stack[top--];
            }
            top--;
        }
        else if(isOperator(infix[i])){
            while(top>=0 && precedence(stack[top])>=precedence(infix[i])){
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }

    while(top>=0){
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
}

int eval(char postfix[]){
    int stack[100];
    int top = -1;
    int operand1,operand2,result;
    for(int i=0;postfix[i]!='\0';i++){
        if(isAlphaNum(postfix[i])){
            stack[++top] = postfix[i] - '0';
        }
        else if(isOperator(postfix[i])){
            operand2 = stack[top--];
            operand1 = stack[top--];
            switch(postfix[i]){
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '^': result = 1;
                    for(int j=0;j<operand2;j++){
                        result*=operand1;
                    }
                    break;
            }
            stack[++top] = result;
        }
    }
    return stack[0];
}

int main(){
    char infix[100], postfix[100];
    scanf("%[^\n]s",infix);
    convert(infix,postfix);
    printf("%s\n",postfix);

    int result = eval(postfix);
    printf("Result: %d\n",result);
    return 0;
}