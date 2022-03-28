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
