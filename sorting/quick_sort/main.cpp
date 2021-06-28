#include <cstdio>
#include <cstdlib>
#include <ctime>

void quickSort(int *arr, int start, int end) {
    if((end - start) < 1) {
        return;
    }

    int pivot = start;
    int i = start;
    int k = end;
    int tmp;

    while(i < k) {
        while(arr[i] <= arr[pivot] && i < end) i++;
        while(arr[k] > arr[pivot]) k--;
        if(i < k){
            tmp = arr[i];
            arr[i] = arr[k];
            arr[k] = tmp;
        }
    }

    tmp = arr[pivot];
    arr[pivot] = arr[k];
    arr[k] = tmp;

    quickSort(arr, start, k - 1);
    quickSort(arr, k + 1, end);
}

void printList(int arr[], int size) {
    printf("\n");
    for(int i = 0; i < size; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(nullptr));
    int size;

    printf("\nWie gross soll die Liste sein?\n");
    scanf("%d", &size);

    int *arr = (int *) malloc(sizeof(int) * size);
    for(int i = 0; i < size; ++i) {
        int rnd = (rand() % 50) + 1;
        arr[i] = rnd;
    }

    // printList(arr, size);

    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();

    // printList(arr, size);

    double elapsed = ((double) (end - start) / CLOCKS_PER_SEC) * 1000;
    printf("\nTime elapsed: %.2fms\n", elapsed);
    return 0;
}
