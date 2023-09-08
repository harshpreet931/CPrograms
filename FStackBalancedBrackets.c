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

int isBalanced(char * expression){
    Stack st; st.top = -1;
    for(int i=0;expression[i]!='\0';i++){
        char ch = expression[i];
        if(ch == '(' || ch == '{' || ch == '['){
            push(&st,ch);
        }
        else if(ch == ')' || ch == '}' || ch == ']'){
            if(isEmpty(&st)) return 0;
            char topch = peek(&st);
            pop(&st);
            if((ch == ')' && topch != '(') || (ch == '}' && topch != '{') || (ch == ']' && topch != '[')){
                return 0;
            }
        }
    }
    return isEmpty(&st);
}
    

int main(){
    char exp[100];
    scanf("%[^\n]s",exp);
    if(isBalanced(exp)){
        printf("The brackets are balanced");
    }
    else{
        printf("The brackets are not balanced");
    }

    return 0;
}