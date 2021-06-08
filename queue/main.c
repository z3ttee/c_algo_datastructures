#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void enqueue(int value);
int dequeue();
void output();

Node *front = NULL;
Node *back = NULL;

int main() {
    enqueue(25);
    enqueue(30);
    enqueue(21);

    output();

    int result1 = dequeue();
    fprintf(stdout, "Dequeued: '%d'\n", result1);

    output();
    return 0;
}

/**
 * Enqueue an int value
 * @param value Value to enqueue
 */
void enqueue(int value) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    if(newNode == NULL) {
        fprintf(stderr, "No memory could be allocated for the newly enqueued element '%d'.", value);
        return;
    }

    newNode->value = value;
    newNode->next = NULL;

    // Queue is empty -> Set front and back to the new element
    if(front == NULL) {
        front = newNode;
        back = newNode;
        return;
    }

    // Always append to the back of the Queue
    back->next = newNode;
    back = newNode;
}

/**
 * Pull the first element from the queue
 * @return
 */
int dequeue() {
    if(front == NULL) {
        fprintf(stderr, "Nothing found to dequeue: Queue is empty!");
        return -1;
    }

    Node *tmpFront = front;
    int value = tmpFront->value;

    front = tmpFront->next;
    free(tmpFront);

    return value;
}

/**
 * Output the queue
 */
void output() {
    fprintf(stdout, "\n");

    Node *tmpFront = front;
    for(int i = 0; tmpFront; tmpFront = tmpFront->next, ++i) {
        fprintf(stdout, "%d >> %d\n", i, tmpFront->value);
    }

    fprintf(stdout, "\n");
}
