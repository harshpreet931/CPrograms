#include <stdio.h>

struct Rectangle{
    float length;
    float width;
};

int main(){
    struct Rectangle r1,r2;
    float area1,area2;

    printf("Enter the length and width of the first rectangle: ");
    scanf("%f %f",&r1.length, &r1.width);

    printf("Enter the length and width of the second rectangle: ");
    scanf("%f %f",&r2.length, &r2.width);

    area1 = r1.length * r1.width;
    area2 = r2.length * r2.width;

    if(area1 > area2) printf("RECTANGLE 1 is larger\n");
    else if(area1 < area2) printf("RECTANGLE 2 is larger\n");
    else printf("Both RECTANGLES are equal.");

    return 0;

}