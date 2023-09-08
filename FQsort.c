#include <stdio.h>
#include <stdlib.h>

int cmp (const void * a, const void * b){
    return *(int*)a - *(int*)b;
}

int main(){
    int values[] = {20,60,10,30,100,40};
    int len = sizeof(values)/sizeof(int);
    qsort(values,len,sizeof(int),cmp);
    
    for(int i=0;i<len;i++){
        printf("%d ",values[i]);
    }

    return 0;
}