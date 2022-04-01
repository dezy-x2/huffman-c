#include "linkedList.h"

Node* initializeNode(LetterNode* data) {
    Node* newNode = (Node*) calloc(1, sizeof(Node));
    newNode -> pData = data;
    return newNode;
}

LinkedList* initializeLinkedList() {
    LinkedList* newList = (LinkedList*) calloc(1, sizeof(LinkedList));
    newList -> numNodes = 0;
    return newList;
}

void add(LinkedList* list, Node* newNode) {
    if (list->pHeadNode == NULL) {
        list->pHeadNode = newNode;
    } else {
        Node* curr = list->pHeadNode;
        while(curr->pNext != NULL) {
            curr = curr->pNext;
        }
        curr->pNext = newNode;
    }
    list->numNodes++;
}

void addOrIncrement(LinkedList* list, char c) {
    Node* currNode = list->pHeadNode;
    bool foundChar = false;
    while(currNode) {
        if (currNode->pData->c == c) {
            currNode->pData->freq++;
            foundChar = true;
            break;
        } else {
            currNode = currNode->pNext;
        }
    }
    if (!foundChar) add(list, initializeNode(initializeLetterNode(1, c)));
}

void printList(LinkedList* list) {
    printf("length is: %d\n", list->numNodes);
    Node* currNode = list->pHeadNode;
    while(currNode) {
        printLetterNode(currNode->pData);
        currNode = currNode->pNext;
    }
}

Node* get(LinkedList* list, int pos) {
    Node* curr = list->pHeadNode;
    int count = 0;
    while(curr != NULL) {
        if (count == pos) return curr;
        curr = curr->pNext;
        count++;
    }
    return NULL;
}

void replace(LinkedList* list, int pos, Node* newNode) {
    Node* prevNode = get(list, pos-1);
    Node* oldNode = get(list, pos);
    newNode->pNext = oldNode->pNext;
    prevNode->pNext = newNode;
}