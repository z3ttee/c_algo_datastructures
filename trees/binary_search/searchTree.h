//
// Created by Cedric Zitzmann on 30.06.2021.
//

#ifndef BINARY_SEARCH_SEARCHTREE_H
#define BINARY_SEARCH_SEARCHTREE_H

#pragma once

typedef struct Node {
    int key;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

void addNode(Node **root, int key);
Node *searchNode(Node *root, int key);
void deleteNode(Node **root, int key);

Node *findParent(Node *root, int key);
Node *findSwapNode(Node *root);
Node *getChild(Node *parent, int childKey);

void swap(Node *ancestor, Node *parent, Node *swapWithParent);

#endif //BINARY_SEARCH_SEARCHTREE_H
