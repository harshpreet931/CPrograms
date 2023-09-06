#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[100];
    int rno;
    float cgpa;
};

int main(){
    struct Student * sptr;

    sptr = (struct Student *)malloc(sizeof(struct Student));

    if(sptr == NULL){
        printf("Memory Allocation failed.\n");
        return 1;
    }

    printf("Enter Student name:");
    scanf("%s", (&sptr -> name));

    printf("Enter Student Marks:");
    scanf("%f", &(sptr -> cgpa));
}