#include <stdio.h>

struct Student{
    char name[50];
    int rollNo;
    float mathMarks;
    float physicsMarks;
    float chemistryMarks;
};

int main(){
    struct Student students[5];
    printf("Enter the details of 5 students:\n");

    for(int i=0;i<5;i++){
        printf("Student #%d:\n", i + 1);
        printf("Name: ");
        scanf(" %49[^\n]", students[i].name);  // %49[^\n]
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);
        printf("Math Marks: ");
        scanf("%f", &students[i].mathMarks);
        printf("Physics Marks: ");
        scanf("%f", &students[i].physicsMarks);
        printf("Chemistry Marks: ");
        scanf("%f", &students[i].chemistryMarks);
    }

    printf("\nStudentInformation:\n");
    for(int i=0;i<5;i++){
        printf("Student #%d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNo);
        printf("Math Marks: %.2f\n", students[i].mathMarks);
        printf("Physics Marks: %.2f\n", students[i].physicsMarks);
        printf("Chemistry Marks: %.2f\n", students[i].chemistryMarks);
        printf("\n");

    }
    return 0;
}