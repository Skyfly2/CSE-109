#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "binarytree.h"

void initBinaryTree(BinaryTree *tree)
{
    // Initialize tree pointer values
    tree->depth = 0;
    tree->root = NULL;
}

bool insertItem(BinaryTree *tree, void *item)
{
    if (tree->root == NULL)
    {
        // Initialize root
        Node *new = (Node *)malloc(sizeof(Node));
        new->item = item;
        tree->root = new;
        tree->depth++;
    }
    else
    {
        char currdepth = 1;
        Node *curr = tree->root;
        // Loop through tree, following left and right children to find the correct node placement
        // Consulted given BST source: https://en.wikipedia.org/wiki/Binary_search_tree
        while (curr != NULL)
        {
            if (*(int *)item < *(int *)curr->item)
            {
                if (curr->left == NULL)
                {
                    // When the end is reached, initialize a new node
                    curr->left = (Node *)malloc(sizeof(Node));
                    curr = curr->left;
                    curr->item = item;
                    // Update depth
                    currdepth++;
                    break;
                }
                else
                {
                    // Continue to the left
                    curr = curr->left;
                }
            }
            else if (*(int *)item > *(int *)curr->item)
            {
                if (curr->right == NULL)
                {
                    // When the end is reached, initialize a new node
                    curr->right = (Node *)malloc(sizeof(Node));
                    curr = curr->right;
                    curr->item = item;
                    // Update depth
                    currdepth++;
                    break;
                }
                else
                {
                    // Continue to the right
                    curr = curr->right;
                }
            }
            else
            {
                return false;
            }
            currdepth++;
        }
        if (currdepth > tree->depth)
        {
            // Update current depth
            tree->depth = currdepth;
        }
        return true;
    }
}

// I technically referenced: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
// But my printtree works and looks completely differently
void printTree(BinaryTree *tree, Node *node, int depth, Node *parent, bool left)
{
    if (node == NULL)
    {
        if (parent = NULL)
        {
            printf("Empty tree");
        }
        return;
    }
    // Recursively print the children
    printTree(tree, node->left, depth + 1, node, true);
    printTree(tree, node->right, depth + 1, node, false);

    // Print details of the the children
    printf("Node: %d\n", *(int *)node->item);
    printf("Depth :%d\n", depth);
    if (parent != NULL)
    {
        if (left)
        {
            printf("Left child of: %d\n\n", *(int *)parent->item);
        }
        else
        {
            printf("Right child of: %d\n\n", *(int *)parent->item);
        }
    }
    else
    {
        printf("Root\n");
    }
}

// I did not consult anything while writing this function
char findItem(BinaryTree *tree, void *item)
{
    char currdepth = 1;
    // Get root node
    Node *curr = tree->root;
    while (curr != NULL)
    {
        // Compare value of current node to the item
        if (*(int *)item < *(int *)curr->item)
        {
            // Go to the left child
            curr = curr->left;
            currdepth++;
        }
        else if (*(int *)item > *(int *)curr->item)
        {
            // Go to the right child
            curr = curr->right;
            currdepth++;
        }
        else
        {
            // Found it
            return currdepth;
        }
    }
    // Did not find it
    return -1;
}

void *removeItem(BinaryTree *tree, void *item)
{
    Node *curr = tree->root;
    Node *parent = tree->root;
    bool left;
    while (curr != NULL)
    {
        // Compare value of current node to the item
        if (*(int *)item < *(int *)curr->item)
        {
            // Go to the left child
            curr = curr->left;
        }
        else if (*(int *)item > *(int *)curr->item)
        {
            // Go to the right child
            curr = curr->right;
        }
        else
        {
            if (parent != curr)
            {
                while (parent != NULL)
                {
                    if (*(int *)item < *(int *)parent->item)
                    {
                        if (parent->left != curr)
                        {
                            // Go to the left child
                            parent = parent->left;
                        }
                        else
                        {
                            left = true;
                            break;
                        }
                    }
                    else if (*(int *)item > *(int *)parent->item)
                    {
                        if (parent->right != curr)
                        {
                            // Go to the right child
                            parent = parent->right;
                        }
                        else
                        {
                            left = false;
                            break;
                        }
                    }
                }
            }
            int *deleted = (int *)curr->item;
            // Found it, now remove it
            // For all 3 removal algorithms, I consulted the provided BST info: https://en.wikipedia.org/wiki/Binary_search_tree
            if ((curr->right == NULL) && (curr->left == NULL))
            {
                // Case where node has no children BST info: https://en.wikipedia.org/wiki/Binary_search_tree
                tree->depth--;

                curr->item = NULL;
                free(curr);
                if (left)
                {
                    // Free left side of parent
                    parent->left = NULL;
                }
                else
                {
                    // Free left side of child
                    parent->right = NULL;
                }
            }
            else if ((curr->right == NULL) || (curr->left == NULL))
            {
                // Case where node has one child BST info: https://en.wikipedia.org/wiki/Binary_search_tree
                Node *child;
                if (curr->right == NULL)
                {
                    // Go down left side of tree
                    child = curr->left;
                }
                else
                {
                    // Go down right side of tree
                    child = curr->right;
                }

                // Free the deleted node
                free(curr);
                if (left)
                {
                    // Make grandchild node the child
                    parent->left = child;
                }
                else
                {
                    // Make grandchild node the child
                    parent->right = child;
                }
                // Update tree depth
                if (findItem(tree, child->item) < tree->depth - 1)
                {
                }
                else
                {
                    tree->depth--;
                }
            }
            else
            {
                // Node has 2 children BST info: https://en.wikipedia.org/wiki/Binary_search_tree
                // Get succeeding node from in order traversal
                Node *s = curr->right;
                Node *child;
                // Go through tree find the successor node in the inorder traversal
                while (s->left != NULL)
                {
                    s = s->left;
                }

                // Set the current node equal to the successor
                curr->item = s->item;
                child = s->right;
                // Find where the memory of the successor is and delete it
                if (curr->right = s)
                {
                    free(s);
                    curr->right = child;
                }
                else
                {
                    curr = curr->right;
                    // Free the successor node by traversing the tree to get to it
                    while (curr != NULL)
                    {
                        if (curr->left == s)
                        {
                            free(s);
                            // Set the current node's right child to the successor's child
                            curr->right = child;
                        }
                    }
                    // Update depth
                    if (findItem(tree, child->item) < tree->depth - 1)
                    {
                    }
                    else
                    {
                        tree->depth--;
                    }
                }
            }
            return deleted;
        }
    }
    return NULL;
}

void freeNodes(BinaryTree *tree, Node *root)
{
    if (root == NULL)
    {
        // End of tree
        return;
    }
    else
    {
        // Free the left and right children first
        freeNodes(tree, root->left);
        freeNodes(tree, root->right);
        // Remove everything
        root->right = NULL;
        root->left = NULL;
        root->item = NULL;
        root = NULL;
        // Free the memory
        // I had some issues with free() not freeing all fields, so I consulted: https://stackoverflow.com/questions/7774443/function-free-in-c-isnt-working-for-me
        free(root);
    }
}