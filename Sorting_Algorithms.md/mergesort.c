#include<stdio.h>
#define MAX_SIZE 12

void mergeSort(int D[], int left, int right);
void merge(int D[], int left, int k, int right);

int main() {
    int arr[] = { 2, 1, 10, 6, 3, 7 };
    printf("Unsorted array:\n");
    for (int m = 0; m < 6; m++) {
        printf("%d ", arr[m]);
    }
    printf("\nMergeSorted version is:\n");
    mergeSort(arr, 0, 5);
    for (int f = 0; f < 6; f++) {
        printf("%d ", arr[f]);
    }
    return 0;
}

void mergeSort(int D[], int left, int right) {
    int k;
    if (left < right) {
        k = (left + right) / 2;
        mergeSort(D, left, k); // Sol yarıyı sırala
        mergeSort(D, k + 1, right); // Sağ yarıyı sırala
        merge(D, left, k, right); // İki yarıyı birleştir
    }
}

void merge(int D[], int left, int k, int right) {
    int i, j, l = 0; // i, j, ve l'nin başlangıç değeri
    int M[MAX_SIZE]; // Geçici dizi

    // Sol ve sağ dizilerden küçük elemanları karşılaştırarak geçici diziye ekle
    for (i = left, j = k + 1; i <= k && j <= right;) {
        if (D[i] < D[j]) {
            M[l] = D[i];
            i++;
        }
        else {
            M[l] = D[j];
            j++;
        }
        l++;
    }

    // Sol dizide kalan elemanları geçici diziye ekle
    while (i <= k) {
        M[l] = D[i];
        i++;
        l++;
    }

    // Sağ dizide kalan elemanları geçici diziye ekle
    while (j <= right) {
        M[l] = D[j];
        j++;
        l++;
    }

    // Geçici diziyi ana diziye geri kopyala
    for (i = left, l = 0; i <= right; i++, l++) {
        D[i] = M[l];
    }
}
