#include "huffman.h"

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