#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int getPrecedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

int alphaNum(char ch){
	if(ch >= 'a' && ch <= 'z') return 1;
	if(ch >= 'A' && ch <= 'Z') return 1;
	if(ch >= '0' && ch <= '9') return 1;
	return 0;
}

void reverseString(char str[]){
    int i,j,length = 0;
    char temp;
    for(i=0;str[i]!='\0';i++){
        length++;
    }
    for(i=0,j=length-1;i<j;i++,j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]){
    char stack[MAX];
    int top = -1;
    int i,j=0;
    
    reverseString(infix);

    for (i = 0; infix[i] != '\0' ; i++) {
        if (infix[i] == '(') {
            infix[i] = ')';
        } else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }

    for(i=0;infix[i]!='\0';i++){
        if(alphaNum(infix[i])){
            prefix[j++] = infix[i];
        }
        else if(infix[i] == '('){
            stack[++top] = infix[i];
        }
        else if(infix[i] == ')'){
            while(top>=0 && stack[top]!='('){
                prefix[j++] = stack[top--];
            }
            if(top>=0 && stack[top] == '('){
                top--;
            }
        }
        else if(isOperator(infix[i])){
            while(top>=0 && getPrecedence(stack[top]) > getPrecedence(infix[i])){
                prefix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
    }
    while(top>=0){
        prefix[j++] = stack[top--];
    }

    prefix[j] = '\0';

    reverseString(prefix);
}

int evaluatePrefix(char prefix[]){
    int stack[MAX];
    int top = -1;
    int i,operand1,operand2,result;
    int length = 0;
    for(int i=0;prefix[i]!='\0';i++){
        length++;
    }

    for(i = length-1;i>=0;i--){
        if(alphaNum(prefix[i])){
            stack[++top] = prefix[i] - '0';
        }
        else if(isOperator(prefix[i])){
            operand1 = stack[top--];
            operand2 = stack[top--];

            switch (prefix[i]) {
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
                    result = operand1 / operand2;
                    break;
                case '^':
                    result = 1;
                    for(int j = 0; j < operand2; j++) {
                        result *= operand1;
                    }
                    break;
            }
            stack[++top] = result;
        }
    }
    return stack[0];
}


int main() {
    char prefix[MAX];
    char infix[MAX] = "2+3^(4-(1+2)^2+((3-2)*4)+3)";

    infixToPrefix(infix, prefix);

    printf("Postfix expression: %s\n", prefix);

    int result = evaluatePrefix(prefix);
    printf("Result: %d\n",result);
    return 0;
}