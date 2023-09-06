#include <stdio.h>

struct Course {
    char code[10];
    char name[50];
    int credits;
};

struct Student {
    int rollNumber;
    char name[50];
    struct Course course;
};

void displayStudentInfo(struct Student st) 
{
    printf("Student Details:\n");
    printf("Roll Number: %d\n", st.rollNumber);
    printf("Name: %s\n", st.name);
    printf("Course Code: %s\n", st.course.code);
    printf("Course Name: %s\n", st.course.name);
    printf("Credits: %d\n", st.course.credits);
}
int main() {
    struct Student student;
    
    // Input
    printf("Enter Roll Number: ");
    scanf("%d", &student.rollNumber);
    
    printf("Enter Name: ");
    scanf("%s", student.name);
    
    printf("Enter Course Code: ");
    scanf("%s", student.course.code);
    
    printf("Enter Course Name: ");
    scanf("%s", student.course.name);
    
    printf("Enter Credits: ");
    scanf("%d", &student.course.credits);
    
    // Output
    displayStudentInfo(student);
    
    return 0;
}