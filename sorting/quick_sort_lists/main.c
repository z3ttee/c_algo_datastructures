#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

void quickSort(Node **list, int start, int end) {

    if(*list == NULL || end - start < 1) {
        return;
    }

    // Pivot (Vergleichswert) auswählen
    // In diesem Fall soll der Pivotwert der erste Wert der liste sein
    int pivot = start;

    // Zwei "Zeiger"
    int i = start;
    int k = end;

    // Solange der linke Zeiger den rechten Zeiger noch nicht überschritten hat
    while (i < k) {

        // Vergleiche Wert vom linken Zeiger, falls <= dann zeiger weiterwandern lassen (bis max. zum Ende)
        while(getNodeAt(*list, i)->value <= getNodeAt(*list, pivot)->value && i < end) ++i;

        // Vergleiche Wert vom rechten Zeigen, falls > als Pivotwert, dann weiterwandern lassen (bis max. zum Start)
        while(getNodeAt(*list, k)->value > getNodeAt(*list, pivot)->value) --k;

        if(i < k) {
            swapNodes(*list, i, k);
        }
    }

    swapNodes(*list, k, pivot);

    quickSort(list, start, k - 1);
    quickSort(list, k + 1, end);
}

int main(void) {
    srand(time(NULL));

    while(1) {
        int size;

        printf("\nWie gross soll die Liste sein?\n");
        scanf("%d", &size);

        Node *list = listeFuellen(size, 50);
        // printList(list);

        clock_t start = clock();
        quickSort(&list, 0, size - 1);
        clock_t end = clock();

        // printList(list);

        double elapsed = ((double) (end - start) / CLOCKS_PER_SEC) * 1000;
        printf("\nTime elapsed: %.2fms\n", elapsed);


    }
    return 0;
}
