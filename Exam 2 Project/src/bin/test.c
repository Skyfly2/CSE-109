#include <stdlib.h>
#include "binarytree.h"
int main(void)
{
    BinaryTree *tree = malloc(sizeof(BinaryTree));
    initBinaryTree(tree);

    int a = 5;
    int b = 3;
    int c = 7;
    int d = 6;
    int e = 4;
    int f = 8;
    int g = 2;
    int h = 10;
    int i = 0;
    int j = 9;
    int k = 1;
    int m = 77;

    // Test 1
    if (insertItem(tree, &a))
    {
        printf("Test 1: Passed\n");
    }
    else
    {
        printf("Test 1: Failed\n");
        return;
    }

    // Test 2
    if (!insertItem(tree, &a))
    {
        printf("Test 2: Passed\n");
    }
    else
    {
        printf("Test 2: Failed\n");
        return;
    }

    insertItem(tree, &b);
    insertItem(tree, &c);
    insertItem(tree, &d);
    insertItem(tree, &e);
    insertItem(tree, &f);
    insertItem(tree, &g);
    insertItem(tree, &h);
    insertItem(tree, &i);
    insertItem(tree, &j);
    insertItem(tree, &k);

    // Test 3
    if (removeItem(tree, &m) == NULL)
    {
        printf("Test 3: Passed\n");
    }
    else
    {
        printf("Test 3: Failed\n");
        return;
    }

    // Test 4
    if (*(int *)removeItem(tree, &a) == a)
    {
        printf("Test 4: Passed\n");
    }
    else
    {
        printf("Test 4: Failed\n");
        return;
    }

    // Test 5
    if (findItem(tree, &a) == -1)
    {
        printf("Test 5: Passed\n");
    }
    else
    {
        printf("Test 5: Failed\n");
        return;
    }

    // Test 6, I know we only have to do , but I needed to show that findItem actually works
    if (findItem(tree, &d) == 1)
    {
        printf("Test 6: Passed\n");
    }
    else
    {
        printf("Test 6: Failed\n");
        return;
    }

    printTree(tree, tree->root, 0, NULL, NULL);
    freeNodes(tree, tree->root);
    return 0;
}