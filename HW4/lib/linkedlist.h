#ifndef LINKEDLIST
#define LINKEDLIST

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	void* item;
	struct Node*  next;
}Node;

typedef struct {
	Node* head;
	Node* tail;
}List;

// Initialize an empty list
void initList(List* list_pointer);

// Create node containing item, return reference of it.
Node* createNode(void* item);

// Insert new item at the end of list.
void insertAtTail(List* list_pointer, void* item);

// Insert item at start of the list.
void insertAtHead(List* list_pointer, void* item);

// Insert item at a specified index.
void insertAtIndex(List* list_pointer, int index, void* item);

// Remove item from the end of list and return a reference to it
void* removeTail(List* list_pointer);

// Remove item from start of list and return a reference to it
void* removeHead(List* list_pointer);

// Insert item at a specified index and return a reference to it
void* removeAtIndex(List* list_pointer, int index);

// Return item at index
void* itemAtIndex(List* list_pointer, int index);

// Print List
void printList(List* list_pointer);

#endif