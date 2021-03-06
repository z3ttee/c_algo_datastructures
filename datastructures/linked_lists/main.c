#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int value;
    struct Element *next;
} Element;

void appendElement(Element **start, int value);
void insertAt(Element **start, int value, int index);
void deleteAt(Element **start, int index);
void delete(Element **start, int value);
void output(Element *start);

int main(void) {
    // Get pointer to allocated element
    Element *start = NULL;
    output(start); // list is empty

    /*(Element *) malloc(sizeof(Element));

    // Set default values
    start->value = 23;
    start->next = NULL;*/

    // Append elements
    printf("\n### Append:\n");
    appendElement(&start, 1);
    appendElement(&start, 2);
    appendElement(&start, 3);
    appendElement(&start, 4);
    appendElement(&start, 5);
    output(start); // 1, 2, 3, 4, 5

    // Insert at position
    printf("\n### InsertAt:\n");
    insertAt(&start, 0, 0);
    insertAt(&start, 55, 5);
    output(start); // 0, 1, 2, 3, 4, 55, 5

    // Delete at position
    printf("\n### DeleteAt:\n");
    deleteAt(&start, 0);
    deleteAt(&start, 1);
    deleteAt(&start, 100); // out of bounds
    output(start); // 1, 3, 4, 55, 5

    // Delete value
    printf("\n### Delete value:\n");
    delete(&start, 55);
    delete(&start, 1337); // not found
    output(start); // 1, 3, 4, 5

    return 0;
}

/**
 * Append an element to a list
 * @param start Starting pointer of the list
 * @param value Value to be appended
 */
void appendElement(Element **start, int value) {
    Element *nextElement = (Element *) malloc(sizeof(Element));
    nextElement->value = value;
    nextElement->next = NULL;

    if(*start == NULL) {
        *start = nextElement;
        return;
    }

    Element *tmp = *start;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = nextElement;
}

/**
 * Insert element at index
 * @param start Start of list
 * @param value Value to insert
 * @param index Position to insert at
 */

// Before: *start
// Now: **start
// So now we have a pointer pointing to a pointer so we can change
// the pointer itself. (Call by reference)
void insertAt(Element **start, int value, int index) {
    Element *nextElement = (Element *) malloc(sizeof(Element));
    nextElement->value = value;
    nextElement->next = NULL;

    if(*start == NULL) {
        appendElement(start, value);
        return;
    }

    Element *elem = *start;
    int i;
    int inserted = 0;

    if(index == 0) {
        nextElement->next = *start;
        *start = nextElement;
        return;
    }

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
void deleteAt(Element **start, int index) {
    if(*start == NULL) {
        return;
    }

    if(index == 0) {
        *start = (*start)->next;
        return;
    }

    Element *tmp = *start;
    int i;
    int deleted = 0;

    for(i = 0; i <= index && tmp && !deleted; tmp = tmp->next, ++i){

        if(index == i + 1) {
            // Element just before the element that should get deleted
            // So that del is the element that should get deleted.
            Element *del = tmp->next;

            // In this case, tmp is the previous element and del->next is the following
            // element. Everything in between (del) needs to be deleted (or
            // del->next should become tmp->next).
            // To avoid memory leaks, del should be freed.
            tmp->next = del->next;
            free(del);

            deleted = 1;

        }

    }

    if(!deleted) {
        printf("\nCould not delete value at index '%d': Array out of bounds [Size: %d].\n", index, i);
    }
}

/**
 * Delete a value from the list
 * @param start Start of the list
 * @param value Value to be deleted
 */
void delete(Element **start, int value) {
    if(*start == NULL) {
        return;
    }

    Element *tmp = *start;
    int i;
    int deleted = 0;

    for(i = 0; tmp; tmp = tmp->next, ++i){
        if(tmp->value == value) {
            deleteAt(start, i);
            deleted = 1;
            break;
        }
    }

    if(!deleted) {
        printf("\nCould not delete value '%d': Value not found in list\n", value);
    }
}

/**
 * Output the all list elements
 * @param start List starting point
 */
void output(Element *start) {
    Element* tmp = start;
    printf("\n%-8s | %-8s | %-8s\n", "Index", "Nummer", "Wert");

    if(start == NULL) {
        printf("List is empty!\n");
        return;
    }

    for(int i = 0; tmp != NULL; tmp = tmp->next, ++i) {
        printf("%-8d   %-8d   %-8d\n", i, i + 1, tmp->value);
    }
}
