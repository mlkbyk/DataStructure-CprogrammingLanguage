//file: stack_implementation_with_linked_list.c
// How to implement stack using a linked list in C

#include <stdio.h>
#include <stdlib.h>  // For malloc and free functions

// Stack structure definition
// A Stack is represented by a linked list where each node contains an item and a reference to the next node.
typedef struct s {
    int item;      // The data held by the stack node
    struct s* next; // A pointer to the next node in the stack (NULL for the last node)
} STACK;

// Global pointer to the top of the stack (initially NULL, representing an empty stack)
STACK* sp = NULL;

// Function to add an item to the top of the stack (push operation)
int push(int item) {
    STACK* p; // Pointer to hold the new node
    // Allocate memory for a new node
    p = (STACK*)malloc(sizeof(STACK));

    if (p == NULL) { // Check if memory allocation failed
        printf("Error, not enough memory.\n");
        return -1; // Return -1 if memory allocation fails
    }
    else {
        p->item = item;   // Assign the given item to the new node
        p->next = sp;      // Set the next pointer of the new node to the current top of the stack
        sp = p;            // Move the stack pointer to the new node, making it the new top of the stack
        return 0;          // Return 0 to indicate the push operation was successful
    }
}

// Function to remove and return the top item of the stack (pop operation)
int pop() {
    STACK* p; // Pointer to temporarily hold the top node
    int i;    // Variable to store the value of the popped item

    if (sp == NULL) { // Check if the stack is empty
        printf("Stack is empty.\n");
        return -1; // Return -1 if the stack is empty
    }
    else {
        p = sp;        // Temporarily store the top node in p
        i = sp->item;  // Store the value of the top item
        sp = sp->next; // Move the stack pointer to the next node (the new top)
        free(p);       // Free the memory allocated to the old top node
        return i;      // Return the value of the popped item
    }
}

// Function to clear the entire stack (delete all nodes in the stack)
void reset() {
    STACK* p; // Pointer to temporarily hold the current node
    while (sp != NULL) { // While the stack is not empty
        p = sp;        // Store the current top node in p
        sp = sp->next; // Move the stack pointer to the next node
        free(p);       // Free the memory allocated to the current top node
    }
}

// Function to return the reference to the top of the stack (but not remove it)
STACK* top() {
    return sp;  // Return the current top node of the stack
}

// Function to return the number of elements currently in the stack
int size() {
    STACK* p;   // Pointer to traverse the stack
    int i = 0;  // Counter to track the number of elements
    p = sp;      // Start from the top of the stack
    while (p) {  // Traverse the stack while there are nodes
        i++;      // Increment the counter for each node
        p = p->next; // Move to the next node
    }
    return i; // Return the total number of elements in the stack
}

// Function to check if the stack is empty
STACK* isEmpty() {
    return sp; // If the stack pointer is NULL, the stack is empty
}

// Main function to demonstrate the stack operations
int main() {
    // Push items to the stack
    push(10);
    push(20);
    push(30);

    // Print the top element of the stack
    printf("Top element: %d\n", top()->item);

    // Print the current size of the stack
    printf("Size of stack: %d\n", size());

    // Pop an item from the stack and print it
    printf("Popped element: %d\n", pop());

    // Print the size of the stack after popping an element
    printf("Size of stack after pop: %d\n", size());

    // Reset the stack (clear all elements)
    reset();

    // Check if the stack is empty after reset and print the message
    if (isEmpty() == NULL) {
        printf("Stack is empty.\n");
    }

    return 0;
}
