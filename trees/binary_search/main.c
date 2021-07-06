#include <stdio.h>


#include "searchTree.h"

int main() {

    Node *root = NULL;

    addNode(&root, 4);
    addNode(&root, 12);
    addNode(&root, 10);
    addNode(&root, 2);
    addNode(&root, 3);
    addNode(&root, 8);
    addNode(&root, 26);
    addNode(&root, 1);
    addNode(&root, 43);
    addNode(&root, 7);

    Node *test = searchNode(root, 4);
    printf("\nNode: %p \n", test);

    deleteNode(&root, 8);

    return 0;
}
