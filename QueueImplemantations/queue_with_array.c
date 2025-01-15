//How to implement queue with array
// file: queue_with_array.c

#include <stdio.h>
#define N 50 //max number of elements
int Q[N];//queue
int last = 0;// initially queue is empty

//function declarations
int enqueue(int item);
int dequeue();
void reset();

int main() {
    int choice, item;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue (Add an item)\n");
        printf("2. Dequeue (Remove an item)\n");
        printf("3. Reset (Clear the queue)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the item to enqueue: ");
            scanf("%d", &item);
            if (enqueue(item) == 0) {
                printf("Item %d added to the queue.\n", item);
            }
            break;

        case 2:
            item = dequeue();
            if (item != -1) {
                printf("Item %d removed from the queue.\n", item);
            }
            break;

        case 3:
            reset();
            printf("Queue has been cleared.\n");
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


//function definiton
int enqueue(int item){
	if (last == N) {
		printf("Queue is full.\n");
		return -1;
	}
	else {
		Q[last] = item;
		last++;
		return 0;
	}
}

int dequeue(){
	int item, i;
	if (last == 0) {
		printf("Queue is empty.");
		return -1;
	}
	else{
		item = Q[0];
		for (i = 1; i < last; i++) {
			Q[i - 1] = Q[i];

		}
		last--;
		return item;

	}
}
void reset(){
	last = 0;
}


