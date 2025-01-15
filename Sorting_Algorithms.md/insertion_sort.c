//file: insertion_sort.c
//Insertion sort mechanism 

#include<stdio.h>

//function declaration
void insertionSort(int D[], int n);

//function main begins with program execution
int main(void) {
    int item_of_arr = 7;
    int example_arr[7] = { 7, 4, 5, 10, 2, 3, 6 };
    printf("Array is:\n");
    for (int j = 0; j < item_of_arr; j++) {
        printf("%d ", example_arr[j]);
    }

    insertionSort(example_arr, item_of_arr);

    printf("\nInserted version is:\n");
    for (int m = 0; m < item_of_arr; m++) {
        printf("%d ", example_arr[m]);  // Print each element
    }
    printf("\n");  // To print a new line after the array

    return 0;
} // end main


// Definition of function
void insertionSort(int D[], int n) {// D arr = ordered array, n= number of item in the array
    int key, i, k;

    for (i = 1; i < n; i++) {
         
        key = D[i];
        for (k = i - 1; k >= 0 && key <= D[k]; k--) {
            D[k + 1] = D[k];
        }
        D[k + 1] = key;

    }


}
