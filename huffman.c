#include "huffman.h"
#include "linkedList.h"

int main() {
    printf("Hello World!\n");
    
    
    // LetterNode* aNode = initializeLetterNode(8, 'a');
    // TreeNode* aTree = initializeTreeNode(aNode, NULL, NULL);
    LinkedList* list = initializeLinkedList();
    char* newStr = "Hello, World!";
    for(int i=0; i<13; i++) {
        addOrIncrement(list, newStr[i]);
    }
    printList(list);
    bubbleSort(list);
    printList(list);
    Node* grabbed = grab(list);
    printf("\n\n");
    printList(list);
    printf("\n");
    printLetterNode(grabbed->pData);
}

/**
 * @brief initializes a letterNode
 * 
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
 * @param ln (letterNode) the letterNode that it is storing
 */
TreeNode* initializeTreeNode(LetterNode* ln) {
    printf("Initializing tree node for letter '%c'\n",ln->c);
    TreeNode* tn = (TreeNode*) calloc(1, sizeof(TreeNode));
    tn->ln = ln;
    tn->left = NULL;
    tn->right = NULL;
    return tn;
}

void printLetterNode(LetterNode* ln) {
    printf("LetterNode: {freq: %d, c: %c}\n", ln->freq, ln->c);
}