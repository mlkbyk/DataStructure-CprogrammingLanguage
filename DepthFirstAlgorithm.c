// file: recursive-depth-first-algorithm.c
// Depth first algorithm but recursive

#include <stdio.h>
#include <stdlib.h>

// 6x6 adjacency matrix representing the graph (0 means no edge, 1 means an edge exists)
int G[6][6] = {
    {0, 1, 1, 0, 0, 1}, // Node 0 is connected to Node 1, 2, and 5
    {1, 0, 1, 1, 0, 0}, // Node 1 is connected to Node 0, 2, and 3
    {1, 1, 0, 0, 1, 0}, // Node 2 is connected to Node 0, 1, and 4
    {0, 1, 0, 0, 1, 1}, // Node 3 is connected to Node 1, 4, and 5
    {0, 0, 1, 1, 0, 0}, // Node 4 is connected to Node 2 and 3
    {1, 0, 0, 1, 0, 0}  // Node 5 is connected to Node 0 and 3
};

// visited array to track visited nodes
int visited[6] = { 0, 0, 0, 0, 0, 0 };

// function declarations
void DFT(void);
void TraverseGraph(int node);

// main function to start the depth-first traversal
int main(void) {
    printf("Depth-First Traversal (Recursive):\n");
    DFT();  // Call the DFT function to start traversal from unvisited nodes
    return 0;
}

// DFT function - calls TraverseGraph for each unvisited node
void DFT(void) {
    int node;
    for (node = 0; node < 6; node++) {
        // If the node is not visited yet, start the traversal
        if (visited[node] == 0) {
            TraverseGraph(node);  // Recursive call to TraverseGraph
        }
    }
}

// TraverseGraph function - recursively visits nodes and prints them
void TraverseGraph(int node) {
    int i;
    visited[node] = 1;  // Mark the current node as visited
    printf("%d\n", node);  // Print the current node

    // Traverse all adjacent nodes that are connected and unvisited
    for (i = 0; i < 6; i++) {
        if ((G[node][i] != 0) && (visited[i] == 0)) {
            TraverseGraph(i);  // Recursively visit the connected node
        }
    }
}
