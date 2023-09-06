#include <stdio.h>

struct Employee{
    char name[100];
    int id;
    float salary;
};

int main(){
    struct Employee emp[5];
    int i,maxIndex;

    for(i = 0;i<5;i++){
        printf("Enter name id and salary from emp %d :",i+1);
        scanf("%s %d %f",emp[i].name, &emp[i].id, &emp[i].salary);
    }
    maxIndex = 0;

    for(int i = 1 ; i<5;i++){
        if(emp[i].salary > emp[maxIndex].salary){
            maxIndex = i;
        }
    }

    printf("THE EMPLOYEE WITH THE HIGHEST SALARY IS:\n");
    printf("%s %d %.2f",emp[maxIndex].name,emp[maxIndex].id,emp[maxIndex].salary);
    return 0;
}