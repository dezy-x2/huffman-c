#include <stdio.h>
#include <stdlib.h>

typedef struct letterNode {
    int freq;
    char c;
} letterNode;

typedef struct treeNode {
    letterNode* ln;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

void initializeLetterNode(letterNode* ln, int f, char c);
void initializeTreeNode(treeNode* tn, letterNode* ln, treeNode* leftTn, treeNode* rightTn);

int main() {
    printf("Hello World!\n");
    letterNode aNode;
    treeNode aTree;
    
    initializeLetterNode(&aNode, 8, 'a');
    initializeTreeNode(&aTree, &aNode, NULL, NULL);
}

void initializeLetterNode(letterNode* ln, int f, char c) {
    printf("Initializing letter node with %d freq and '%c' char\n", f,c);
    ln->freq = f;
    ln->c=c;
}

void initializeTreeNode(treeNode* tn, letterNode* ln, treeNode* leftTn, treeNode* rightTn) {
    printf("Initializing tree node for letter '%c'\n",ln->c);
    tn->ln = ln;
    tn->left = leftTn;
    tn->right = rightTn;
}