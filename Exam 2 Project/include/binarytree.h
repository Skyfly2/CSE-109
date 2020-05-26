#include <stdbool.h>

// Struct for a Node with a left and right child
typedef struct
{
    void *item;
    struct Node *left;
    struct Node *right;
} Node;

// Struct for a binary tree
typedef struct
{
    Node *root;
    char depth;
} BinaryTree;

// Descriptions taken from the readme in the gitlab assignment
// Takes a binary tree pointer and initializes the values on it
void initBinaryTree(BinaryTree *tree);

// Takes a pointer to a binary tree ad a pointer to an item and inserts it into the tree
bool insertItem(BinaryTree *tree, void *item);

// Takes a pointer to a binary tree and a pointer to an item and removes that item from the tree if it exists in the tree
void *removeItem(BinaryTree *tree, void *item);

// Takes a pointer to a binary tree and a pointer to an item and returns the depth of the item
char findItem(BinaryTree *tree, void *item);

// Takes a pointer to a binary tree and frees all nodes in the tree
void freeNodes(BinaryTree *tree, Node *root);

// Takes a pointer to a binary tree and prints the entire tree
void printTree(BinaryTree *tree, Node *node, int depth, Node *parent, bool left);