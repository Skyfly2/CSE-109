#include <stdio.h>
#include <stdlib.h>
#include "hashset.h"

// Prehash algorithm for item randomness
unsigned long prehash(void *item, unsigned int item_size)
{
    unsigned long h = 5381;
    char i;
    for (int c = 0; c < item_size; c++)
    {
        // Get value at each byte
        i = *((char *)item++);
        // Update h
        h = ((h << 5) + h) + (long)i;
    }

    return h;
}

// Hash an unsigned long into an index that fits into a hash set
unsigned long hash(unsigned long prehash, unsigned long buckets)
{
    // Find remainder due to number of buckets
    long h = prehash % buckets;
    return h;
}

// Initialize an empty hash set with a given size
void initHashSet(HashSet *hashset_pointer, unsigned int size)
{
    // Set values
    hashset_pointer->load_factor = 0;
    hashset_pointer->size = size;
    hashset_pointer->table = malloc(sizeof(List *) * size);

    // Initialize each bucket as an empty linked list
    for (int c = 0; c < size; c++)
    {
        hashset_pointer->table[c] = malloc(sizeof(List));
        initList(hashset_pointer->table[c]);
    }
}

// Insert item in the set. Return true if the item was inserted, false if it wasn't (i.e. it was already in the set)
// Recalculate the load factor after each successful insert (round to nearest whole number).
// If the load factor exceeds 70 after insert, resize the table to hold twice the number of buckets.
bool insertItem(HashSet *hashset_pointer, void *item, unsigned int item_size)
{
    // Hash item
    long ph = prehash(item, item_size);
    long h = hash(ph, hashset_pointer->size);

    // Insert Item
    insertAtTail(hashset_pointer->table[h], item);

    Node *curr = hashset_pointer->table[h]->head;
    if (curr->next == NULL)
    {
    }
    else
    {
        // Look for duplicate
        while (curr->next != NULL)
        {
            if (curr->item == item)
            {
                // If duplicate exists, remove it
                removeTail(hashset_pointer->table[h]);
                return false;
            }
            curr = curr->next;
        }
    }

    // Check number of filled buckets
    int fullBuckets = 0;
    for (int c = 0; c < hashset_pointer->size; c++)
    {
        if (hashset_pointer->table[c]->head != NULL)
        {
            fullBuckets++;
        }
    }
    // Update load factor
    hashset_pointer->load_factor = 100 * fullBuckets / hashset_pointer->size;
    if (hashset_pointer->load_factor >= 70)
    {
        // Double table size
        resizeTable(hashset_pointer, hashset_pointer->size * 2);
    }
    return true;
}

// Remove an item from the set. Return true if it was removed, false if it wasn't (i.e. it wasn't in the set to begin with)
bool removeItem(HashSet *hashset_pointer, void *item, unsigned int item_size)
{
    // Hash item
    long ph = prehash(item, item_size);
    long h = hash(ph, hashset_pointer->size);

    if (hashset_pointer->table[h]->head != NULL)
    {
        // Get head of bucket
        Node *curr = hashset_pointer->table[h]->head;
        int c = 0;
        while (curr != NULL)
        {
            if (curr->item == item)
            {
                if (c == 0)
                {
                    // Remove the head
                    removeHead(hashset_pointer->table[h]);
                    return true;
                }
                else
                {
                    // Remove the item
                    removeAtIndex(hashset_pointer->table[h], c);
                    return true;
                }
            }
            // Update Node
            curr = curr->next;
            // Update Index
            c++;
        }
    }
    return false;
}

// Return true if the item exists in the set, false otherwise
bool findItem(HashSet *hashset_pointer, void *item, unsigned int item_size)
{
    // Hash item
    long ph = prehash(item, item_size);
    long h = hash(ph, hashset_pointer->size);

    if (hashset_pointer->table[h] != NULL)
    {
        // Get head of proper bucket
        Node *curr = hashset_pointer->table[h]->head;
        while (curr != NULL)
        {
            // Search each node in the list to check for match
            if (curr->item == item)
            {
                return true;
            }
            // Update node
            curr = curr->next;
        }
    }
    return false;
}

// Resize the underlying table to the given size. Recalculate the load factor after resize
void resizeTable(HashSet *hashset_pointer, unsigned int new_size)
{
    // Allocate memory for new HashSet on the heap
    HashSet *new = malloc(sizeof(HashSet));
    initHashSet(new, new_size);

    // Loop through old HashSet
    for (int c = 0; c < hashset_pointer->size; c++)
    {
        // Get head node at each bucket
        Node *curr;
        if (hashset_pointer->table[c]->head != NULL)
        {
            curr = hashset_pointer->table[c]->head;
        }
        // Add each item into the new HashSet
        while (curr != NULL)
        {
            insertItem(new, curr->item, sizeof(int));
            curr = curr->next;
        }
    }
    // Dereference and assign the value of new to the dereferenced value of hashset_pointer
    *hashset_pointer = *new;
    // Free new
    free(new);
}

// Print Table
void printHashSet(HashSet *hashset_pointer)
{
    // Loop through each bucket
    for (int c = 0; c < hashset_pointer->size; c++)
    {
        // Grab data from each bucket
        Node *curr;
        if (hashset_pointer->table[c] != NULL)
        {
            curr = hashset_pointer->table[c]->head;
        }
        while (curr != NULL)
        {
            // Print each item
            printf("Bucket: %d, %x\n", c, *(int *)curr->item);
            curr = curr->next;
        }
    }
}