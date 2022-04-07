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
    if (pos < 0) return NULL;
    Node* curr = list->pHeadNode;
    int count = 0;
    printf("\nRUNNING GET\n");
    while(curr != NULL) {
        if (count == pos) return curr;
        curr = curr->pNext;
        count++;
    }
    return NULL;
}

void swap(LinkedList* list, Node* node1, Node* node2) {
    LetterNode* node1Data = node1->pData;
    LetterNode* node2Data = node2->pData;
    node1->pData = node2Data;
    node2->pData = node1Data;
}

void replace(LinkedList* list, int pos, Node* newNode) {
    if (pos == 0) {
        Node* elm1 = list->pHeadNode->pNext;
        list->pHeadNode = newNode;
        newNode->pNext = elm1;
        return;
    }
    Node* prevNode = get(list, pos-1);
    Node* oldNode = get(list, pos);
    newNode->pNext = oldNode->pNext;
    prevNode->pNext = newNode;
}

// still working on this
void bubbleSort(LinkedList* list) {
    bool wasSorted = true;
    while(wasSorted) {
        wasSorted = false;
        Node* curr = list->pHeadNode;
        Node* nextCurr = list->pHeadNode->pNext;
        while(nextCurr != NULL) {
            if(curr->pData->freq < nextCurr->pData->freq) {
                swap(list, curr, nextCurr);
                wasSorted = true;
            }
            curr = nextCurr;
            nextCurr = nextCurr->pNext;
        }
    }
}

int idxOf(LinkedList* list, Node* target) {
    Node* curr = list->pHeadNode;
    int count = 0;
    printf("\nRUNNING IDXOF\n");
    while(curr != NULL) {
        if (target == curr) {
            return count;
        }
        count++;
        curr = curr->pNext;
    }
    return -1;
}

Node* pop(LinkedList* list) {
    if (list->pHeadNode == NULL) return NULL;
    Node* curr = list->pHeadNode;
    Node* prev = NULL;
    while(curr != NULL) {
        curr = curr->pNext;
        prev = curr;
    }
    prev->pNext = NULL;
    return curr;
}