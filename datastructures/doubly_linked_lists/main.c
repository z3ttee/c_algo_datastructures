#include <stdio.h>
#include <stdlib.h>

typedef struct Element {
    int value;
    struct Element *prev;
    struct Element *next;
} Element;

void appendElement(Element **start, int value);
void insertAt(Element **start, int value, int index);
void deleteAt(Element **start, int index);
void deleteAll(Element **start);
void delete(Element **start, int value);
void output(Element *start);

int main(void) {
    // Get pointer to allocated element
    Element *start = NULL;
    output(start); // list is empty

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

    // Delete all values
    printf("\n### Delete all values:\n");
    deleteAll(&start);
    output(start); // nothing

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
    nextElement->prev = NULL;
    nextElement->next = NULL;

    if(*start == NULL) {
        *start = nextElement;
        return;
    }

    Element *tmp = *start;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }

    nextElement->prev = tmp;
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
    nextElement->prev = NULL;
    nextElement->next = NULL;

    if(*start == NULL) {
        appendElement(start, value);
        return;
    }

    Element *elem = *start;
    int i;
    int inserted = 0;

    if(index == 0) {
        nextElement->next = elem;
        nextElement->next->prev = nextElement;

        *start = nextElement;
        return;
    }

    for(i = 0; i <= index && elem; elem = elem->next, ++i) {
        if(index == i) {
            // Found index where to insert nextElement
            // As a reason, elem must be prev and elem->next must be next

            nextElement->prev = elem->prev;
            nextElement->next = elem;
            elem->prev = nextElement;
            elem->prev->prev->next = nextElement;

            inserted = 1;
            break;
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
        Element *toDelete = *start;

        (*start)->next->prev = NULL;
        *start = (*start)->next;

        free(toDelete);
        return;
    }

    Element *tmp = *start;
    int i;
    int deleted = 0;

    for(i = 0; i <= index && tmp && !deleted; tmp = tmp->next, ++i){

        if(index == i) {
            // Element just before the element that should get deleted
            // So that del is the element that should get deleted.
            Element *toDelete = tmp;

            // In this case, tmp is the element to be deleted
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;

            // To avoid memory leaks, toDelete should be freed.
            free(toDelete);
            deleted = 1;

        }

    }

    if(!deleted) {
        printf("\nCould not delete value at index '%d': Array out of bounds [Size: %d].\n", index, i);
    }
}

/**
 * Delete all elements of the list
 * @param start
 * @param index
 */
void deleteAll(Element **start) {
    if(*start == NULL) {
        return;
    }

    int i;

    while(*start) {
        Element *tmp = (*start)->next;
        (*start) = (*start)->next;
        free(tmp);
    }

    free(*start);
    *start = NULL;
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
