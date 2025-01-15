#include <stdio.h>

int left(int i);
int right(int i);
void heapify(int D[], int i);
void buildHeap(int D[], int n);
void HeapSort(int D[], int n);
int heap_size;

int main() {
    int arr[10] = { 1, 4, 10, 3, 2, 38, 5, 9, 61, 77 };

    printf("Unsorted version is:\n");
    for (int m = 0; m < 10; m++) {
        printf("%d ", arr[m]);
    }
    printf("\n\nSorted version is:\n");

    HeapSort(arr, 10);

    for (int m = 0; m < 10; m++) {
        printf("%d ", arr[m]);
    }

    return 0; // end function main
}

void buildHeap(int D[], int n) {
    heap_size = n - 1;
    for (int i = (n - 1) / 2; i >= 0; i--) {
        heapify(D, i);
    }
}

void heapify(int D[], int i) {
    int max, temp, left_child, right_child;
    left_child = left(i);
    right_child = right(i);

    if (left_child <= heap_size && D[left_child] > D[i]) {
        max = left_child;
    }
    else {
        max = i;
    }

    if (right_child <= heap_size && D[right_child] > D[max]) {
        max = right_child;
    }

    if (max != i) {
        temp = D[max];
        D[max] = D[i];
        D[i] = temp;
        heapify(D, max);
    }
}

int left(int i) {
    return (2 * i + 1);
}

int right(int i) {
    return (2 * i + 2);
}

void HeapSort(int D[], int n) {
    int temp;
    buildHeap(D, n);

    for (int i = n - 1; i >= 1; i--) {
        temp = D[i];
        D[i] = D[0];
        D[0] = temp;
        heap_size--;
        heapify(D, 0);
    }
}
