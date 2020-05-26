#include <stdio.h>
#include <stdlib.h>
#include "hashset.h"
int main()
{
    int a = 3, b = 4, c = 5;
    HashSet *hs = malloc(sizeof(HashSet));
    initHashSet(hs, 10);
    insertItem(hs, &a, sizeof(int));
    insertItem(hs, &b, sizeof(int));
    insertItem(hs, &c, sizeof(int));
    removeItem(hs, &b, sizeof(int));
    insertItem(hs, &a, sizeof(int)); // Will not insert
    insertItem(hs, &b, sizeof(int));
    insertItem(hs, &c, sizeof(int)); // Will not insert
    printHashSet(hs);
    return 0;
}