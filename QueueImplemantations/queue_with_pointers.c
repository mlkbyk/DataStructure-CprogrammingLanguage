#include<stdio.h>
#include <stdlib.h>

typedef struct q {
    int item;
    struct q* next;
}QUEUE;

QUEUE* front = NULL;
QUEUE* last = NULL;

// function declarations
int enqueu(int item);
int dequeu();
void reset();
void printQueue(); // Function to print the current state of the queue

int main() {
    int choice, item;

    while (1) {
        printf("\nQueue Operations with Linked List:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Reset Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter item to enqueue: ");
            scanf("%d", &item);
            if (enqueu(item) != -1) {
                printf("Enqueued: %d\n", item);
            }
            break;

        case 2:
            item = dequeu();
            if (item != -1) {
                printf("Dequeued: %d\n", item);
            }
            break;

        case 3:
            reset();
            printf("Queue has been reset.\n");
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }

        // Print the current state of the queue after each operation
        printQueue();
    }

    return 0; // end function main
}

// function definitions

int enqueu(int item) {
    QUEUE* p;
    p = (QUEUE*)malloc(sizeof(QUEUE));
    if (p == NULL) {
        printf("Memory is not available.\n");
        return -1;
    }
    p->item = item;
    p->next = NULL;
    if (front == NULL) { // initially queue is empty
        front = p;
        last = p;
    }
    else {
        last->next = p;
        last = p;
    }
    return 1;
}

int dequeu() {
    int item;
    QUEUE* p;
    if (front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    p = front;
    front = front->next;
    if (front == NULL) {
        last = NULL;
    }
    item = p->item;
    free(p);
    return item;
}

void reset() {
    QUEUE* p;
    p = front;
    while (p) {
        front = front->next;
        free(p);
        p = front;
    }
    last = NULL;
}

void printQueue() {
    QUEUE* temp = front;
    if (front == NULL) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Current Queue: ");
        while (temp != NULL) {
            printf("%d ", temp->item);
            temp = temp->next;
        }
        printf("\n");
    }
}
