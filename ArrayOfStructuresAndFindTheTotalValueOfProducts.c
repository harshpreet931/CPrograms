#include <stdio.h>

struct Product{
    char name[50];
    float price;
    int qu;
};

int main(){
    struct Product pd[10];
    int i;
    float totalValue = 0;

    for(i = 0;i<10;i++){
        printf("Enter details for product %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", pd[i].name);
        printf("Price: ");
        scanf("%f", &pd[i].price);
        printf("Quantity: ");
        scanf("%d", &pd[i].qu);
    }

    for(i=0;i<10;i++){
        totalValue += pd[i].price * pd[i].qu;
    }

    printf("\nTotal Value of all products $%.2f\n",totalValue);
    return 0;
}

