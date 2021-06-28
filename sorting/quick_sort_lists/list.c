//
// Created by Cedric Zitzmann on 22.06.2021.
//

#include "list.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void addNode(Node** liste, int wert) {
    Node* neu = (Node*) malloc(sizeof(Node));
    if (neu == NULL) return;

    neu->next = NULL;
    neu->value = wert;

    if (*liste == NULL) {
        *liste = neu;
        return;
    }

    //Ende der Liste suchen
    Node* tmp = *liste;
    while (tmp->next != NULL)
        tmp = tmp->next;
    //Neuen Node anhaengen
    tmp->next = neu;
}

void printList(Node* liste) {
    if (liste == NULL){
        printf("Die Liste ist leer!\n");
        return;
    }

    while (liste != NULL) {
        printf("%d, ", liste->value);
        liste = liste->next;
    }
    printf("\n");
}

int getNodePositionByValue(Node* liste, int wert){
    if (liste == NULL) return -1;

    int i = 0;
    //zum richtigen Element springen
    while(liste->value != wert) {
        //zu wenig Elemente
        if (liste->next == NULL) return -2;

        liste = liste->next;
        i++;
    }
    //Position erreicht
    return i;
}

Node *getNodeAt(Node *list, int index) {
    Node *tmp = list;
    for(int i = 0; i < index && tmp != NULL; ++i, tmp = tmp->next);
    return tmp;
}

void swapNodes(Node *list, int index, int index2) {
    Node *firstNode = getNodeAt(list, index);
    Node *secondNode = getNodeAt(list, index2);

    Node tmp = *firstNode;
    firstNode->value = secondNode->value;
    secondNode->value = tmp.value;
}

Node* listeFuellen(int nodeCount, int maxValue){
    if (nodeCount < 1) return NULL;

    Node* liste = NULL;
    srand(time(NULL));

    for(int i=0; i< nodeCount; i++) {
        addNode(&liste, rand() % maxValue);
    }

    return liste;
}

Node* copyList(Node* source) {
    if (source == NULL) return NULL;

    Node* copy = NULL;
    while (source != NULL) {
        addNode(&copy, source->value);
        source = source->next;
    }

    return copy;
}
