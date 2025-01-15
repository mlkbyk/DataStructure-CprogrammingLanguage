// file: bubble_sort.c
// How to sort an array with the bubble sort algorithm.

#include<stdio.h>

// Function declaration
void BubbleSort(int D[], int n);

// Function main begins with program execution
int main(void) {
    // Initialize an example array with 7 elements
    int exam_arr[7] = { 3, 7, 8, 2, 1, 10, 4 };

    // Call BubbleSort function to sort the array
    BubbleSort(exam_arr, 7);

    // Print the sorted array
    printf("Sorted version:\n");
    for (int m = 0; m < 7; m++) {
        printf("%d ", exam_arr[m]); // Output each element of the sorted array
    }
    printf("\n");

    return 0; // End of program execution
} // End function main

// Function definition for BubbleSort
void BubbleSort(int D[], int n) {
    int i, temp, move;

    // Outer loop controls the number of passes
    for (move = 0; move < n - 1; move++) {
        // Inner loop performs comparisons and swaps elements
        for (i = 0; i < n - 1 - move; i++) {
            // Check if the current element is greater than the next
            if (D[i] > D[i + 1]) {
                // Swap elements if they are out of order
                temp = D[i];
                D[i] = D[i + 1];
                D[i + 1] = temp;
            }
        }
    }
} // End function BubbleSort

