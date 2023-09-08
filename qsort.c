#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void * a, const void  * b){
    return (*(int*)a - *(int*)b);
}

int main(){
    int i;
    int values[] = {88,56,100,2,25};
    int len = sizeof(values)/sizeof(int);

    qsort(values,len,sizeof(int),cmpfunc);
    for(i=0;i<len;i++){
        printf("%d ",values[i]);
    }
    return 0;

}