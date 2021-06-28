//
// Created by Cedric Zitzmann on 22.06.2021.
//

#ifndef QUICK_SORT_LISTS_LIST_H
#define QUICK_SORT_LISTS_LIST_H


typedef struct Node {
    int value;
    struct Node *next;
} Node;

void addNode(Node** liste, int wert);
void printList(Node* liste);
int getNodePositionByValue(Node* liste, int wert);
Node *getNodeAt(Node *list, int index);
Node* listeFuellen(int nodeCount, int maxValue);
Node* copyList(Node* source);
void swapNodes(Node *list, int index, int index2);

#endif //QUICK_SORT_LISTS_LIST_H
