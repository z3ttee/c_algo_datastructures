#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copy(int **dest, const int *src, int size) {
    if (src == NULL) return;
    if(*dest == NULL) *dest = (int*)malloc(sizeof(int) * size);

    if (*dest != NULL){
        for (int i = 0; i < size; i++){
            (*dest)[i] = src[i];
        }
    }
}

void shellSort(int **arr, int amountElements) {
    if(*arr == NULL) {
        return;
    }

    int step = amountElements;

    do {
        step = (step - 1 ) / 3 + 1;



    } while (step > 1);
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

    int *arr = (int *) malloc(sizeof(int) * size);
    for(int i = 0; i < size; ++i) {
        int rnd = (rand() % 50) + 1;
        arr[i] = rnd;
    }

    printList(arr, size);

    clock_t start = clock();
    mergeSort(&arr, 0, size - 1);
    clock_t end = clock();

    printList(arr, size);

    double elapsed = ((double) (end - start) / CLOCKS_PER_SEC) * 1000;
    printf("\nTime elapsed: %.2fms\n", elapsed);
    return 0;
}
