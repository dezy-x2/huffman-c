#include "huffman.h"

typedef struct Node {
    struct Node* pNext;
    LetterNode* pData;
} Node;

typedef struct LinkedList {
    Node* pHeadNode;
    int numNodes;
} LinkedList;