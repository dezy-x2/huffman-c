#include <stdio.h>
#include <stdlib.h>
#include "huffman.h"

int main() {
    printf("Hello World!\n");
    LetterNode aNode;
    TreeNode aTree;
    
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
void initializeLetterNode(LetterNode* ln, int f, char c) {
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
void initializeTreeNode(TreeNode* tn, LetterNode* ln, TreeNode* leftTn, TreeNode* rightTn) {
    printf("Initializing tree node for letter '%c'\n",ln->c);
    tn->ln = ln;
    tn->left = leftTn;
    tn->right = rightTn;
}