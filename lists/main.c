#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int value;
    struct Element *next;
} Element;

void appendElement(Element *start, int value);
void insertAt(Element *start, int value, int index);
// void deleteAt(Element *start, int index);
void output(Element *start);

int main(void) {
    // Get pointer to allocated element
    Element *start = (Element *) malloc(sizeof(Element));

    // Set default values
    start->value = 23;
    start->next = NULL;

    // Append elements
    appendElement(start, 16);
    appendElement(start, 18);
    appendElement(start, 30);
    appendElement(start, 20);
    appendElement(start, 19);
    output(start);

    // Insert at position
    insertAt(start, 19, 1);
    insertAt(start, 19, 8);
    output(start);

    // Delete at position
    // deleteAt(start, 0);
    // output(start);

    return 0;
}

/**
 * Append an element to a list
 * @param start Starting pointer of the list
 * @param value Value to be appended
 */
void appendElement(Element *start, int value) {
    Element *nextElement = (Element *) malloc(sizeof(Element));
    nextElement->value = value;
    nextElement->next = NULL;

    while(start->next != NULL) {
        start = start->next;
    }

    start->next = nextElement;
}

/**
 * Insert element at index
 * @param start Start of list
 * @param value Value to insert
 * @param index Position to insert at
 */
void insertAt(Element *start, int value, int index) {
    Element *nextElement = (Element *) malloc(sizeof(Element));
    nextElement->value = value;
    nextElement->next = NULL;

    Element *elem = start;
    int i;
    int inserted = 0;

    for(i = 0; i <= index && elem && !inserted; elem = elem->next, ++i){

        if(i == index - 1) {
            nextElement->next = elem->next;
            elem->next = nextElement;
            inserted = 1;
        }

    }

    if(!inserted) {
        printf("\nCould not insert value '%d' at index '%d': Array out of bounds [Size: %d].\n", value, index, i);
    }
}

/**
 * Delete element at index from list
 * @param start
 * @param index
 */
/*void deleteAt(Element *start, int index) {
    Element *elem = start;
    int i;
    int deleted = 0;

    for(i = 0; i <= index && elem && !deleted; elem = elem->next, ++i){
        printf("%d ", i);

        if(i == index) {
            printf("next: %d", elem->next->value);

            Element *newNext = elem->next;
            elem = newNext;
            //nextElement->next = elem->next;
            //elem->next = nextElement;
            deleted = 1;
            printf("head: %d", elem->value);
        }

    }

    if(!deleted) {
        printf("\nCould not delete index '%d': Array out of bounds [Size: %d].\n", index, i);
    }
}*/

/**
 * Output the all list elements
 * @param start List starting point
 */
void output(Element *start) {
    Element* listPtr = start;

    printf("\n");
    printf("\n");

    printf("%-8s | %-8s | %-8s\n", "Index", "Nummer", "Wert");

    for(int i = 0; listPtr != NULL; listPtr = listPtr->next, ++i) {
        printf("%-8d   %-8d   %-8d\n", i, i + 1, listPtr->value);
    }

}
