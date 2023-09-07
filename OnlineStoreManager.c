#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Order{
    int orderNumber;
    char customerName[50];
};

struct Queue{
    struct Order orders[100];
    int front,rear;
};

void initializeQueue(struct Queue * queue){
    queue -> front = 0;
    queue -> rear = -1;
}

void enqueue(struct Queue * queue, struct Order order){
    if(queue->rear < 99){
        order.orderNumber = queue -> rear + 2;
        queue->orders[++queue->rear] = order;
        printf("Order #%d added for customer: %s\n", order.orderNumber, order.customerName);
    }
    else{
        printf("Queue is Full. Cannot add more orders.\n");
        exit(1);
    }
}

struct Order dequeue(struct Queue *queue) {
    if (queue->front <= queue->rear) {
        return queue->orders[queue->front++];
    } else {
        printf("Queue is empty. No orders to process.\n");
        exit(1);
    }
}

int main() {
    struct Queue orderQueue;
    initializeQueue(&orderQueue);
    int orderCounter = 0;

    while (1) {
        printf("1. Add a new order\n");
        printf("2. Process next order\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct Order newOrder;
                printf("Enter customer name: ");
                scanf("%s", newOrder.customerName);
                enqueue(&orderQueue, newOrder);
                break;
            }
            case 2: {
                if (orderQueue.front <= orderQueue.rear) {
                    struct Order processedOrder = dequeue(&orderQueue);
                    printf("Processing Order #%d for customer: %s\n", processedOrder.orderNumber, processedOrder.customerName);
                } else {
                    printf("No orders to process.\n");
                }
                break;
            }
            case 3:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

