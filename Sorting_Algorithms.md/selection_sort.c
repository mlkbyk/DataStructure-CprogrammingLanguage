//file:selection_sort.c
//How  work  Selection Sort algorithm.

#include<stdio.h>

//Definition Part
void SelecetionSort(int D[], int n);

//function main begings with program execution
int main() {
	int example_arr[6] = { 8,5,2,3,7,6};
	printf("Array before:\n");
	for (int j = 0; j < 6; j++) {
		printf("%d ", example_arr[j]);
	}

	SelecetionSort(example_arr, 6);
	printf("\nSorted version is:\n");
	for (int m = 0; m < 6; m++) {
		printf("%d ", example_arr[m]);

	}
	printf("\n");

	return 0;
}//end function main

void SelecetionSort(int D[], int n) {
	int i, min, min_index, j, temp;
	for (i = 0; i < n; i++) {
		min = D[i];
		min_index = i;

		for (j = i + 1; j < n; j++) {
			if (D[j] < min) {
				min = D[j];
				min_index = j;
			}


		}

		if (i != min_index) {
			temp = D[i];
			D[i] = D[min_index];
			D[min_index] = temp;

		}
	}

}
