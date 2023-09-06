#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int last;
    int * arr;
}Stack;

int * buildStack(int n){
    int * arr = (int *)malloc(n*sizeof(int));
}

void push(Stack * st1, int data){
    st1 -> arr[++(st1->last)] = data;
}

void pop(Stack * st1){
    st1 -> last--;
}

int size(Stack * st1){
    return st1 -> last + 1;
}

int top(Stack * st1){
    return st1 -> arr[st1->last];
}

int empty(Stack * st1){
    return st1 -> last == -1;
}




int main(){
    Stack st1;
    st1.last = -1;
    int n;
    scanf("%d",&n);
    st1.arr = buildStack(n);
    return 0;
}