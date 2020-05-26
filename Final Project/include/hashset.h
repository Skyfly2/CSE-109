#ifndef HASHSET
#define HASHSET

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"

typedef struct {
	List** table;
	unsigned long size;
	char load_factor; // 0 - 100
}HashSet;

// Generate a prehash for an item with a given size
unsigned long prehash(void* item, unsigned int item_size);

// Hash an unsigned long into an index that fits into a hash set
unsigned long hash(unsigned long prehash, unsigned long buckets);

// Initialize an empty hash set with a given size
void initHashSet(HashSet* hashset_pointer, unsigned int size);

// Insert item in the set. Return true if the item was inserted, false if it wasn't (i.e. it was already in the set)
// Recalculate the load factor after each successful insert (round to nearest whole number).
// If the load factor exceeds 70 after insert, resize the table to hold twice the number of buckets.
bool insertItem(HashSet* hashset_pointer, void* item, unsigned int item_size);

// Remove an item from the set. Return true if it was removed, false if it wasn't (i.e. it wasn't in the set to begin with)
bool removeItem(HashSet* hashset_pointer, void* item, unsigned int item_size);

// Return true if the item exists in the set, false otherwise
bool findItem(HashSet* hashset_pointer, void* item, unsigned int item_size);

// Resize the underlying table to the given size. Recalculate the load factor after resize
void resizeTable(HashSet* hashset_pointer, unsigned int new_size);

// Print Table
void printHashSet(HashSet* hashset_pointer);

#endif