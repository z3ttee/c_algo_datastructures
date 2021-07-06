//
// Created by Cedric Zitzmann on 30.06.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "searchTree.h"

void addNode(Node **root, int key) {
    Node *newNode = (Node *) malloc(sizeof(Node));

    if(newNode == NULL)  {
        printf("\nCould not add node: Out of memory!\n");
        return;
    }

    newNode->key = key;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    if(*root == NULL) {
        *root = newNode;
        return;
    }

    Node *tmp = *root;
    while(tmp) {

        // Check if key is smaller, than go left path
        if(tmp->key > key) {

            // If we found a node, that has no left child -> set new node to this location
            if(tmp->leftChild == NULL) {
                tmp->leftChild = newNode;
                break;
            } else {

                // Move along path
                tmp = tmp->leftChild;
            }
        } else {
            // If key is taller, go right path

            // If we found a node, that has no right child -> set new node to this location
            if(tmp->rightChild == NULL) {
                tmp->rightChild = newNode;
                break;
            } else {

                // Move along path
                tmp = tmp->rightChild;
            }
        }
    }
}

/**
 * Search a node
 * @param root Root of the tree
 * @param key Key of the node to search
 * @return Pointer on Node
 */
Node *searchNode(Node *root, int key) {

    while(root) {
        if(root->key > key) {
            root = root->leftChild;
            continue;
        }

        if(root->key < key) {
            root = root->rightChild;
            continue;
        }

        if(root->key == key) {
            break;
        }
    }

    return root;
}

void deleteNode(Node **root, int key) {
    Node *parent = findParent(*root, key);
    Node *toDelete = getChild(parent, key);
    Node *swapWith = findSwapNode(toDelete);

    swap(parent, toDelete, swapWith);
    free(toDelete);
}

/**
 * Find the parent node of the node with key
 * @param root Root of the tree
 * @param key Key of the child node
 * @return Parent node pointer
 */
Node *findParent(Node *root, int key) {
    Node *parent = NULL;

    while(root) {
        parent = root;

        if(root->key > key) root = root->leftChild;
        if(root->key < key) root = root->rightChild;

        if(root->key == key) break;
    }

    return parent;
}

/**
 * Find the node to swap with
 * @param root Beginning where to search
 * @return Node as pointer
 */
Node *findSwapNode(Node *root) {
    if(root == NULL) return root;

    // If node has rightChild, search last left child
    if(root->rightChild != NULL) {
        root = root->rightChild;

        while (root) {
            if(root->leftChild == NULL) break;
            root = root->leftChild;
        }

        return root;
    }

    // If node has leftChild, search last right child
    if(root->leftChild != NULL) {
        root = root->leftChild;

        while (root) {
            if(root->rightChild == NULL) break;
            root = root->rightChild;
        }

        return root;
    }

    return root;
}

/**
 * Get the direct child of the parent by comparing the childs key
 * @param parent Parent
 * @param childKey Child's key
 * @return Child as pointer
 */
Node *getChild(Node *parent, int childKey) {
    if(parent->key > childKey) return parent->leftChild;
    else return parent->rightChild;
}

/**
 * Swap two nodes in the tree.
 * @param ancestor Parent of the parent, to adjust pointers
 * @param parent Partner 1 for swapping
 * @param swapWithParent Partner 2 for swapping
 */
void swap(Node *ancestor, Node *parent, Node *swapWithParent) {
    if(ancestor == NULL) return;

    // Check on which path to swap
    if(ancestor->leftChild != NULL && ancestor->key > parent->key) {
        // Left path
        ancestor->leftChild = swapWithParent;

    } else {
        // Right path
        ancestor->rightChild = swapWithParent;
    }

    parent->leftChild = swapWithParent->leftChild;
    parent->rightChild = swapWithParent->rightChild;
}