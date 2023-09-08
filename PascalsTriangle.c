#include <stdio.h>

int factorial(int n){
    int fact = 1;
    for(int i=1;i<n;i++){
        fact *= i;
    }
    return fact;
}

int ncr(int n, int r){
    return factorial(n) / (factorial(n-r) * factorial(r));
}

int main(){
    int n , i , j; scanf("%d",&n);
    for(i=0;i<=n;i++){
        for(j = 0;j<=n-i;j++){
            printf(" ");
        }
        for(j=0;j<=i;j++){
            printf("%3d",ncr(i,j));
        }
        printf("\n");
    }
    return 0;
}