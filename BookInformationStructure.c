#include <stdio.h>

struct Book{
    char title[100];
    char author[50];
    int pY;
};

int main(){
    struct Book books[5];
    int max = 0;
    printf("Enter details of 5 books: \n");
    for(int i=0;i<5;i++){
        printf("Book %d:\n",i+1);
        printf("Title:");
        scanf("%s",books[i].title);
        printf("Author:");
        scanf("%s",books[i].author);
        printf("Publication Year:");
        scanf("%d",&books[i].pY);

        if(books[i].pY > books[max].pY){
            max = i;
        }
    }
    printf("\nBook with the highest publication year:\n");
    printf("Title: %s\n", books[max].title);
    printf("Author: %s\n", books[max].author);
    printf("Publication Year: %d\n", books[max].pY);

    return 0;

}