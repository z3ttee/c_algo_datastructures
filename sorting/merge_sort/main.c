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

void merge(int **arr, int start, int mid, int end) {
    if(*arr == NULL) return;

    int ptrStart = start; // Für kopieren
    int start2 = mid + 1;
    int size = end - start;
    int *tmp = (int *) malloc(sizeof(int) * (size));

    if(tmp == NULL) return;

    int i;

    for(i = 0; i < size; ++i) {
        if((*arr)[start] < (*arr)[start2]) {
            tmp[i] = (*arr)[start];
            ++start;
        } else {
            tmp[i] = (*arr)[start2];
            ++start2;
        }

        if(start > mid || start2 > end) break;
    }

    while(mid >= start) {
        tmp[i] = (*arr)[start];
        ++start;
        ++i;
    }

    while(end >= start2) {
        tmp[i] = (*arr)[start2];
        ++start2;
        ++i;
    }

    (*arr) += ptrStart;
    copy(arr, tmp, size);
    (*arr) -= ptrStart;
}

void mergeSort(int **arr, int start, int end) {
    if(*arr == NULL || end - start <= 1) {
        return;
    }

    int mid = (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
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
