#include <stdio.h>

struct Rect{
    int length;
    int width;
};

void calculateArea(int length,int width){
    int area = length * width;
    printf("%d\n",area);
}

void calculateArea2(struct Rect rect) 
{
    int area = rect.length * rect.width;
    printf("The area of the rectangle is: %d\n", area);
}


int main(){
    struct Rect rect;
    rect.length = 5;
    rect.width = 3;

    calculateArea(rect.length,rect.width);
    calculateArea2(rect);

}