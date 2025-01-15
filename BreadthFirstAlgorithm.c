// breadth-first-algorithm-with-queue.c
// Breadth-First Search Algorithm using a queue
#include <stdio.h>
#include <stdlib.h>
#define N 50 // Maximum number of elements in the queue

int G[6][6]; // Adjacency matrix representation of the graph
int visited[6] = { 0, 0, 0, 0, 0, 0 }; // To track visited nodes
int Q[N]; // Queue for BFS
int last = 0; // Initially, the queue is empty

// Function declarations
int enqueue(int item);
int dequeue();
void reset();
void BFT(void);
int isEmptyQueue();

// Function definitions

// Adds an item to the queue
int enqueue(int item) {
    if (last == N) { // Check if the queue is full
        printf("Queue is full.\n");
        return -1;
    }
    else {
        Q[last] = item; // Add item to the queue
        last++;
        return 0;
    }
}

// Removes and returns an item from the front of the queue
int dequeue() {
    int item, i;
    if (last == 0) { // Check if the queue is empty
        printf("Queue is empty.\n");
        return -1;
    }
    else {
        item = Q[0]; // Get the front item
        for (i = 1; i < last; i++) {
            Q[i - 1] = Q[i]; // Shift remaining items
        }
        last--; // Decrement the queue size
        return item;
    }
}

// Resets the queue
void reset() {
    last = 0; // Set the queue to empty
}

// Checks if the queue is empty
int isEmptyQueue() {
    return (last == 0); // Returns 1 if the queue is empty, 0 otherwise
}

// Breadth-First Traversal of the graph
void BFT(void) {
    int node, n, i;
    for (node = 0; node < 6; node++) { // Loop through all nodes
        if (visited[node] == 0) { // If the node is not visited
            enqueue(node); // Enqueue the starting node
            while (!isEmptyQueue()) { // While there are nodes in the queue
                n = dequeue(); // Dequeue a node
                if (visited[n] != 0) { // Skip if already visited
                    continue;
                }
                visited[n] = 1; // Mark the node as visited
                printf("Visited: %d\n", n); // Print the visited node

                // Enqueue all unvisited adjacent nodes
                for (i = 0; i < 6; i++) {
                    if ((G[n][i] != 0) && (visited[i] == 0)) {
                        enqueue(i);
                    }
                }
            }
        }
    }
}

// Main function
int main() {
    // Define a sample graph using adjacency matrix
    // Graph connections:
    // 0 -- 1, 0 -- 2, 0 -- 5
    // 1 -- 3, 1 -- 2
    // 2 -- 4
    G[0][1] = 1; G[0][2] = 1; G[0][5] = 1;
    G[1][0] = 1; G[1][2] = 1; G[1][3] = 1;
    G[2][0] = 1; G[2][1] = 1; G[2][4] = 1;
    G[3][1] = 1; G[3][4] = 1; G[3][5] = 1;
    G[4][2] = 1; G[4][3] = 1;
    G[5][0] = 1; G[5][3] = 1;

    // Perform Breadth-First Traversal
    printf("Breadth-First Traversal of the Graph:\n");
    BFT();

    return 0;
}
