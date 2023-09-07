#include <stdio.h>

union Data{
    int intValue;
    float floatValue;
    char stringValue[100];
};

int main(){
    union Data data;
    int choice;
    printf("1. Enter a integer\n");
    printf("2. Enter a float\n");
    printf("3. Enter a string\n");

    printf("Enter your choice:");
    scanf("%d",&choice);

    switch (choice) {
        case 1:
            printf("Enter an integer: ");
            scanf("%d", &data.intValue);
            printf("Data Type: Integer\n");
            printf("Value: %d\n", data.intValue);
            break;
        case 2:
            printf("Enter a float: ");
            scanf("%f", &data.floatValue);
            printf("Data Type: Float\n");
            printf("Value: %.2f\n", data.floatValue);
            break;
        case 3:
            printf("Enter a string: ");
            scanf(" %99[^\n]", data.stringValue); // %99[^\n]
            printf("Data Type: String\n");
            printf("Value: %s\n", data.stringValue);
            break;
        default:
            printf("Invalid choice.\n");
    }

}