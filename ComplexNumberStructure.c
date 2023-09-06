#include <stdio.h>

struct complex{
    float real;
    float image;
};

int main(){
    struct complex c1,c2,c3;
    printf("Enter the 2 complex Numbers:");
    scanf("%f %f",&c1.real,&c1.image);
    scanf("%f %f",&c2.real,&c2.image);

    c3.real = c1.real + c2.real;
    c3.image = c1.image + c2.image;

    printf("Sum = %.2f + i%.2f",c3.real,c3.image);
}