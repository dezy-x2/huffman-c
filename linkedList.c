#include "linkedList.h"

/**
 * @brief initializes linked list node
 * 
 * @param data (LetterNode*) the data that will be stored in the node
 * @return Node* 
 */
Node* initializeNode(LetterNode* data) {
    Node* newNode = (Node*) calloc(1, sizeof(Node));
    newNode -> pData = data;
    return newNode;
}

/**
 * @brief initializes new linked list with size 0
 * 
 * @return LinkedList* 
 */
LinkedList* initializeLinkedList() {
    LinkedList* newList = (LinkedList*) calloc(1, sizeof(LinkedList));
    newList -> numNodes = 0;
    return newList;
}

/**
 * @brief adds a new node to the end of list
 * 
 * @param list (LinkedList*) list that the node will be added to
 * @param newNode (Node*) the node that will be added to the list
 */
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

/**
 * @brief iterates over the list and if the char is already in the list it increments the freq; if its not it adds it the list
 * 
 * @param list (LinkedList*) list to add or increment on
 * @param c (char) the char that it will be checking for
 */
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

/**
 * @brief prints out a linked list
 * 
 * @param list (LinkedList*) list to be printed
 */
void printList(LinkedList* list) {
    printf("length is: %d\n", list->numNodes);
    Node* currNode = list->pHeadNode;
    while(currNode) {
        printLetterNode(currNode->pData);
        currNode = currNode->pNext;
    }
}

/**
 * @brief gets a node at a certain position in the list (zero indexed)
 * 
 * @param list (LinkedList*) the list to get the node from
 * @param pos (int) position to get the node from
 * @return Node*
 */
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

/**
 * @brief swaps two node's data | WARNING: this does not swap the nodes place in memory just the data that they hold
 * 
 * @param list (LinkedList*) list to swap the two nodes from
 * @param node1 (Node*) first node to be swapped
 * @param node2 (Node*) second node to be swapped
 */
void swap(LinkedList* list, Node* node1, Node* node2) {
    LetterNode* node1Data = node1->pData;
    LetterNode* node2Data = node2->pData;
    node1->pData = node2Data;
    node2->pData = node1Data;
}

/**
 * @brief replaces a node at a certain position with a different node
 * 
 * @param list (LinkedList*) list to work on
 * @param pos (int) position that the old node is in
 * @param newNode (Node*) node to be added to the list
 */
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

/**
 * @brief sorts a list in least to greatest order by the frequency count of each letter using bubble sorting algo
 * 
 * @param list (LinkedList*) the list that the bubble sort will be acting on
 */
void bubbleSort(LinkedList* list) {
    bool wasSorted = true;
    while(wasSorted) {
        wasSorted = false;
        Node* curr = list->pHeadNode;
        Node* nextCurr = list->pHeadNode->pNext;
        while(nextCurr != NULL) {
            if(curr->pData->freq > nextCurr->pData->freq) {
                swap(list, curr, nextCurr);
                wasSorted = true;
            }
            curr = nextCurr;
            nextCurr = nextCurr->pNext;
        }
    }
}

/**
 * @brief takes a target node and returns the idx that it is at in the list (zero indexed)
 * 
 * @param list (LinkedList*) list that the func will be searching for the target in
 * @param target (Node*) the target node being searched for
 * @return int
 */
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

/**
 * @brief grabs the first node in the list
 * 
 * @param list (LinkedList*) list that the node will be grabbed from
 * @return Node*
 */
Node* grab(LinkedList* list) {
    Node* target = list->pHeadNode;
    Node* second = list->pHeadNode->pNext;
    list->pHeadNode = second;
    list->numNodes--;
    return target;
}