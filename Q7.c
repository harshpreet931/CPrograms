#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct PrintJob{
    char documentName[50];
};

struct Queue{
    struct PrintJob jobs[100];
    int front,rear;
};

void initializeQueue(struct Queue * queue){
    queue -> rear = -1;
    queue -> front = 0;
}

bool isFull(struct Queue * queue){
    return (queue -> rear == 99 && queue -> front == 0) || (queue -> rear+1 == queue -> front);
}

bool isEmpty(struct Queue * queue){
    return queue -> front > queue -> rear;
}

void enqueue(struct Queue * queue , struct PrintJob job){
    if(!isFull(queue)){
        if(queue -> rear == 99){
            queue -> rear = -1;
        }
        queue -> jobs[++queue->rear] = job;
        printf("Job '%s' added to the queue.\n",job.documentName);
    }
    else{
        printf("Queue is Full.. Cannot add more jobs.\n");
    }
    
}

struct PrintJob dequeue(struct Queue * queue){
    struct PrintJob emptyJob;
    strcpy(emptyJob.documentName,"");

    if(!isEmpty(queue)){
        if(queue->front == 100){
            queue->front = 0;
        }
        return queue->jobs[queue->front++];
    }
    return emptyJob;
}

void displayQueue(struct Queue * queue){
    if(!isEmpty(queue)){
        printf("Current queue:\n");
        for(int i=queue->front;i<=queue->rear;i++){
            printf("%s\n",queue->jobs[i].documentName);
        }
    }
    else{
        printf("The queue is empty.");
    }
}

int main(){
    struct Queue printQueue;
    initializeQueue(&printQueue);
    int choice;

    while (1) {
        printf("\n1. Add a print job\n");
        printf("2. Process a print job\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                struct PrintJob newJob;
                printf("Enter document name: ");
                scanf(" %49[^\n]", newJob.documentName);
                enqueue(&printQueue, newJob);
                break;
            }
            case 2: {
                struct PrintJob processedJob = dequeue(&printQueue);
                if (strcmp(processedJob.documentName, "") != 0) {
                    printf("Processing document: %s\n", processedJob.documentName);
                } else {
                    printf("No documents to process.\n");
                }
                break;
            }
            case 3:
                displayQueue(&printQueue);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

