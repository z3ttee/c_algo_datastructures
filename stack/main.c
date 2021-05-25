#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Element {
    int value;
    struct Element *prev;
} Element;

void output(Element *top);
void push(Element **top, int value);
int pop(Element **top);
bool isEmpty(Element *top);

int main(void) {
    Element *top = NULL;

    if(isEmpty(top)) {
        fprintf(stdout, "\nThe stack is empty!\n");
    }

    push(&top, 1);
    push(&top, 6);
    push(&top, 2);
    output(top); // 2, 6, 1

    int a = pop(&top);
    fprintf(stdout, "\nPop: %d\n", a);
    output(top); // 2, 6

    return 0;
}

/**
 * Check if the stack is empty
 * @param top Top of the stack
 * @return True or False
 */
bool isEmpty(Element *top) {
    return top == NULL;
}

/**
 * Add a new element to the top of the stack
 * @param top
 * @param value
 */
void push(Element **top, int value) {
    Element *newElem = (Element *) malloc(sizeof(Element));
    newElem->value = value;
    newElem->prev = NULL;

    // If stack is empty, make the new element the top of the stack
    if(isEmpty(*top)) {
        Element *oldTop = *top;
        newElem->prev = oldTop;
        *top = newElem;
        return;
    }

    // Add element to the top
    Element *tmp = *top;
    newElem->prev = tmp;
    *top = newElem;
}

/**
 * Get the first added element from the stack
 * @param top Top of the stack
 * @return Value as int
 */
int pop(Element **top) {
    if(isEmpty(*top)) {
        return -1;
    }

    // Set pointer to the first element of the stack
    Element *tmp = *top;
    Element *next = NULL;
    for(; tmp->prev; tmp = tmp->prev) {
        next = tmp;
    }

    //printf("\n%d\n", next->value);

    int value = tmp->value;
    next->prev = NULL;
    free(tmp);
    return value;
}

/**
 * Print the stack to the command line
 * @param top Top of the stack
 */
void output(Element *top) {
    printf("\n%-8s | %-8s | %-8s\n", "Index", "Nummer", "Wert");

    if(isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }

    Element *tmp = top;
    for(int i = 0; tmp; tmp = tmp->prev, ++i) {
        fprintf(stdout, "%-8d   %-8d   %-8d\n", i, i + 1, tmp->value);
    }
}