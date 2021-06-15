#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertSort(int arr[], int size) {

    // Begin at second element
    for(int i = 1; i < size - 1; ++i) {
        int value = arr[i];
        int k = i;

        // While k > 0 and the previous value is larger than
        // the current to be sorted in value
        while(k > 0 && (arr[k - 1] > value)) {
            // Switch current with previous value
            int tmp = arr[k];
            arr[k] = arr[k - 1];
            arr[k - 1] = tmp;

            --k;
        }

        // Set value in correct order
        arr[k] = value;
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
    insertSort(arr, size);
    printList(arr, size);
    return 0;
}
