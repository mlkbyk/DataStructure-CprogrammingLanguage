#include <stdio.h>

#define N 5 // max number of items
int Q[N]; // circular queue
int front = 0; // front item
int last = 0; // last item
int count = 0; // number of items

// function declarations
int enqueue(int item);
int dequeue();
void reset();
void printQueue(); // Function to print the current state of the queue

int main() {
    int choice, item;

    while (1) {
        printf("\nCircular Queue Operations:\n");
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
            if (enqueue(item) != -1) {
                printf("Enqueued: %d\n", item);
            }
            break;

        case 2:
            item = dequeue();
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

int enqueue(int item) {
    if (count >= N) {
        printf("Queue is full.\n");
        return -1;
    }
    else {
        Q[last] = item;
        last = (last + 1) % N;
        count++;
        return item;
    }
}

int dequeue() {
    int item;
    if (count == 0) {
        printf("Queue is empty.\n");
        return -1;
    }
    else {
        item = Q[front];
        front = (front + 1) % N;
        count--;
        return item;
    }
}

void reset() {
    front = 0;
    last = 0;
    count = 0;
}

// Function to print the current state of the queue
void printQueue() {
    if (count == 0) {
        printf("Queue is empty.\n");
    }
    else {
        printf("Current Queue: ");
        int i = front;
        for (int j = 0; j < count; j++) {
            printf("%d ", Q[i]);
            i = (i + 1) % N; // Circular indexing
        }
        printf("\n");
    }
}
