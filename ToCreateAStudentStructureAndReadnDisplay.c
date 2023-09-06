#include <stdio.h>

struct Student{
    int rollno;
    char name[100];
    float gpa;
};

int main(){
    struct Student s1;
    printf("Enter the Roll Number:");
    scanf("%d",&s1.rollno);

    printf("Enter the Student Name:");
    getchar();
    gets(s1.name);

    printf("Enter Student CGPA:");
    scanf("%f",&s1.gpa);


    printf("Student Roll No: %d\n",s1.rollno);
    printf("Student Name: %s\n",s1.name);
    printf("Student GPA: %.2f\n",s1.gpa);

    return 0;
}