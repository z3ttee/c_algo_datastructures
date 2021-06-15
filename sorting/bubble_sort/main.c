#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int size) {
    for(int i = 0; i < size; ++i) {
        for(int k = 0; k < size - 1; ++k) {
            if(arr[k] > arr[k + 1]) {
                int tmp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = tmp;
            }
        }
    }
}

void printList(int arr[], int size) {
    printf("\n");
    for(int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int size;

    printf("\nWie gross soll die Liste sein?\n");
    scanf("%d", &size);

    int arr[size];
    for(int i = 0; i < size; ++i) {
        int rnd = (rand() % 50) + 1;
        arr[i] = rnd;
    }

    printList(arr, size);
    bubbleSort(arr, size);
    printList(arr, size);
    return 0;
}
