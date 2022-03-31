#include "huffman.h"
#include "linkedList.h"

int main() {
    printf("Hello World!\n");
    
    
    LetterNode* aNode = initializeLetterNode(8, 'a');
    TreeNode* aTree = initializeTreeNode(aNode, NULL, NULL);
    LinkedList* list = initializeLinkedList();
}

/**
 * @brief initializes a letterNode
 * 
 * @param ln (letterNode) the letterNode that is being initialized
 * @param f (int) the frequency that this letter appears
 * @param c (char) the letter that this node is storing
 */
LetterNode* initializeLetterNode(int f, char c) {
    printf("Initializing letter node with %d freq and '%c' char\n", f,c);
    LetterNode* ln = (LetterNode*) calloc(1, sizeof(LetterNode));
    ln->freq = f;
    ln->c = c;
    return ln;
}

/**
 * @brief initializes a treeNode
 * 
 * @param tn (treeNode) the treeNode that is being initialized
 * @param ln (letterNode) the letterNode that it is storing
 * @param leftTn (treeNode) the left treeNode that it will be holding
 * @param rightTn (treeNode) the right treeNode that it will be holding
 */
TreeNode* initializeTreeNode(LetterNode* ln, TreeNode* leftTn, TreeNode* rightTn) {
    printf("Initializing tree node for letter '%c'\n",ln->c);
    TreeNode* tn = (TreeNode*) calloc(1, sizeof(TreeNode));
    tn->ln = ln;
    tn->left = leftTn;
    tn->right = rightTn;
    return tn;
}