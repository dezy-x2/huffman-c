#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "huffman.h"

#pragma once

/**
 * @brief the basic node that holds its next node and one letterNode
 * @param pNext - (Node*) the next node in the linkedlist
 * @param pData - (LetterNode*) the letter node that this node stores
 */
typedef struct Node {
    struct Node* pNext;
    LetterNode* pData;
} Node;

/**
 * @brief parents struct that holds the first node and a bit of data about the whole thing
 * @param pHeadNode - (Node*) the first node in the list
 * @param numNodes - (int) how many nodes are in the list
 */
typedef struct LinkedList {
    Node* pHeadNode;
    int numNodes;
} LinkedList;

Node* initializeNode(LetterNode* data);
LinkedList* initializeLinkedList();
void add(LinkedList* list, Node* newNode);
void addOrIncrement(LinkedList* list, char c);
void printList(LinkedList* list);
Node* get(LinkedList* list, int pos);
void swap(LinkedList* list, Node* node1, Node* node2);
void replace(LinkedList* list, int pos, Node* newNode);
void bubbleSort(LinkedList* list);
int idxOf(LinkedList* list, Node* target);
Node* pop(LinkedList* list);