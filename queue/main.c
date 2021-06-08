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
    // Dynamically allocate memory to a new node
    Node *newNode = (Node *) malloc(sizeof(Node));

    // Check if node was allocated correctly
    if(newNode == NULL) {
        fprintf(stderr, "No memory could be allocated for the newly enqueued element '%d'.", value);
        return;
    }

    // Initialize node: Set the value from the parameter and set the next element to NULL (there is no, because
    // this element will be at the "back" of the queue
    newNode->value = value;
    newNode->next = NULL;

    // Queue is empty if front is NULL: Set front and back to the new element, because in this case, both back
    // and front are the same element
    if(front == NULL) {
        front = newNode;
        back = newNode;
        return;
    }

    // At this point, front is not NULL, so the Queue already has some nodes.
    // This needs us to append the new node always to the back of the queue. (FIFO)
    // We do this by setting the "next" node of the current "back" to our new node.
    // After that it is required to let the back pointer point to the right value, in this case it is
    // our new node.
    back->next = newNode;
    back = newNode;
}

/**
 * Pull the first element from the queue
 * @return
 */
int dequeue() {

    // Check if the queue ("front") is empty.
    if(front == NULL) {
        fprintf(stderr, "Nothing found to dequeue: Queue is empty!");
        return -1;
    }

    // Get a temporary pointer from the front, because we need some values and
    // use this pointer to free() unused memory. Do not free() front directly!
    Node *tmpFront = front;
    int value = tmpFront->value;

    // We have to free up some memory, so for that we set the front pointer to point
    // to the next element in the queue
    front = tmpFront->next;

    // Free up unused memory for the removed element from the queue
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
