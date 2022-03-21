#include <stdio.h>
#include <stdlib.h>

/**
 * @brief node to hold the letter and its frequency count
 * @param freq (int) the frequency that the letter shows
 * @param c (char) the letter that the node stores
 */
typedef struct letterNode {
    int freq;
    char c;
} letterNode;

/**
 * @brief node to hold a letter node along with its left and right tree nodes
 * @param ln (letterNode) the letterNode being held
 * @param left (treeNode) the left side treeNode
 * @param right (treeNode) the right side treeNode
 */
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

/**
 * @brief initializes a letterNode
 * 
 * @param ln (letterNode) the letterNode that is being initialized
 * @param f (int) the frequency that this letter appears
 * @param c (char) the letter that this node is storing
 */
void initializeLetterNode(letterNode* ln, int f, char c) {
    printf("Initializing letter node with %d freq and '%c' char\n", f,c);
    ln->freq = f;
    ln->c=c;
}

/**
 * @brief initializes a treeNode
 * 
 * @param tn (treeNode) the treeNode that is being initialized
 * @param ln (letterNode) the letterNode that it is storing
 * @param leftTn (treeNode) the left treeNode that it will be holding
 * @param rightTn (treeNode) the right treeNode that it will be holding
 */
void initializeTreeNode(treeNode* tn, letterNode* ln, treeNode* leftTn, treeNode* rightTn) {
    printf("Initializing tree node for letter '%c'\n",ln->c);
    tn->ln = ln;
    tn->left = leftTn;
    tn->right = rightTn;
}