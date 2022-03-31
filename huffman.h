#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#pragma once
/**
 * @brief node to hold the letter and its frequency count
 * @param freq (int) the frequency that the letter shows
 * @param c (char) the letter that the node stores
 */
typedef struct LetterNode {
    int freq;
    char c;
} LetterNode;

/**
 * @brief node to hold a letter node along with its left and right tree nodes
 * @param ln (letterNode) the letterNode being held
 * @param left (treeNode) the left side treeNode
 * @param right (treeNode) the right side treeNode
 */
typedef struct TreeNode {
    LetterNode* ln;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

LetterNode* initializeLetterNode(int f, char c);
TreeNode* initializeTreeNode(LetterNode* ln, TreeNode* leftTn, TreeNode* rightTn);
void printLetterNode(LetterNode* ln);