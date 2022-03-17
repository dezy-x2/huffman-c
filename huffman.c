#include <stdio.h>
#include <stdlib.h>

typedef struct letterNode {
    int freq;
    char c;
} letterNode;

typedef struct treeNode {
    letterNode* c;
    struct treeNode* left;
    struct treeNode* right;
} treeNode;

int main() {
    printf("Hello World!\n");
}