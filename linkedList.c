#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedList.h"

int main() {
    printf("Hello World\n");
}

Node* initializeNode(Node* nextNode, LetterNode* data) {
    Node* newNode = (Node*) calloc(1, sizeof(Node));
    newNode -> pNext = nextNode;
    newNode -> pData = data;
    return newNode;
}

LinkedList* initializeLinkedList(Node* headNode) {
    LinkedList* newList = (LinkedList*) calloc(1, sizeof(LinkedList));
    newList -> pHeadNode = headNode;
    if (headNode != NULL) {
        newList->numNodes = 1;
    } else {
        newList->numNodes = 0;
    }
    return newList;
}