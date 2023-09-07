#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer{
    char name[50];
};

struct Queue{
    struct Customer customers[100];
    int front,rear;
};

void initializeQueue(struct Queue * queue){
    queue -> front = 0;
    queue -> rear = -1;
}

int isFull(struct Queue * queue){
    return queue -> rear == 99;
}
int isEmpty(struct Queue * queue){
    return queue -> front > queue -> rear;
}

void enqueue(struct Queue * queue , struct Customer customer){
    if(!isFull(queue)){
        queue -> customers[++queue -> rear] = customer;
    }
}

struct Customer dequeue(struct Queue * queue){
    struct Customer emptyCustomer;
    if(!isEmpty(queue)){
        return queue -> customers[queue->front++];
    }
    return emptyCustomer;
}

void displayQueue(struct Queue * queue){
    printf("Current Queue:\n");
    for(int i=queue->front;i<=queue->rear;i++){
        printf("%s\n",queue->customers[i].name);
    }
}

int main(){
    struct Queue bankQueue;
    initializeQueue(&bankQueue);
    int choice;

    while(1){
        printf("1. Add a customer\n");
        printf("2. Process a customer\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:{
                struct Customer newCustomer;
                printf("ENter the customer name:");
                scanf("%49[^\n]",newCustomer.name);
                enqueue(&bankQueue,newCustomer);
                break;
            }
            case 2: {
                struct Customer processedCustomer = dequeue(&bankQueue);
                if (strcmp(processedCustomer.name, "") != 0) {
                    printf("Processing customer: %s\n", processedCustomer.name);
                } else {
                    printf("No customers to process.\n");
                }
                break;
            }
            case 3:
                displayQueue(&bankQueue);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");

        }
    }
}

