#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void printList(List *list)
{
	Node *node;

	// Handle an empty node. Just print a message.
	if (list->head == NULL)
	{
		printf("\nEmpty List");
		return;
	}

	// Start with the head.
	node = (Node *)list->head;

	printf("\nList: \n\n\t");
	while (node != NULL)
	{
		printf("[ %x ]", node->item);

		// Move to the next node
		node = (Node *)node->next;

		if (node != NULL)
		{
			printf("-->");
		}
	}
	printf("\n\n");
}

void initList(List *list_pointer)
{
	list_pointer->tail = NULL;
	list_pointer->head = NULL;
	list_pointer->size = 0;
}

Node *createNode(void *item)
{
	Node *newNode = malloc(sizeof(Node));
	// // Initialize fields
	newNode->item = item;
	newNode->next = NULL;
	return newNode;
}

void insertAtTail(List *list_pointer, void *item)
{
	if (list_pointer->size == 0)
	{
		insertAtHead(list_pointer, item);
	}
	else if (list_pointer->size == 1)
	{
		list_pointer->tail = createNode(item);
		list_pointer->head->next = list_pointer->tail;
		list_pointer->size++;
	}
	else
	{
		Node *old = list_pointer->tail;
		list_pointer->tail = createNode(item);
		old->next = list_pointer->tail;
		list_pointer->size++;
	}
}

void insertAtHead(List *list_pointer, void *item)
{
	if (list_pointer->size == 0)
	{
		list_pointer->head = createNode(item);
	}
	else if (list_pointer->size == 1)
	{
		list_pointer->tail = createNode(list_pointer->head->item);
		list_pointer->head->item = item;
		list_pointer->head->next = list_pointer->tail;
	}
	else
	{
		Node *old = list_pointer->head;
		list_pointer->head = createNode(item);
		// Point the new head to the old head
		list_pointer->head->next = old;
	}
	list_pointer->size++;
}

void insertAtIndex(List *list_pointer, int index, void *item)
{
	if (index == 0)
	{
		insertAtHead(list_pointer, item);
	}
	else if (index == list_pointer->size)
	{
		insertAtTail(list_pointer, item);
	}
	else if (index > list_pointer->size)
	{
	}
	else
	{
		Node *curr = list_pointer->head;

		for (int c = 0; c < index - 1; c++)
		{
			curr = curr->next;
		}
		Node *newNode = createNode(item);
		newNode->next = curr->next;
		curr->next = newNode;

		//printf("%x\n", *curr->item);
		// int c = 0;
		// while (curr->next != NULL)
		// {
		// 	if (c == index - 1)
		// 	{
		// 		Node *next = curr->next;
		// 		newNode->next = next;
		// 		curr->next = newNode;
		// 		break;
		// 	}
		// 	c++;
		// 	curr = curr->next;
		// }
		list_pointer->size++;
	}
}

// Remove item from the end of list and return a reference to it
void *removeTail(List *list_pointer)
{
	if (list_pointer->size <= 1)
	{
		return removeHead(list_pointer);
	}
	Node *curr = list_pointer->head;
	while (curr)
	{
	}
}

// Remove item from start of list and return a reference to it
void *removeHead(List *list_pointer)
{
	if (list_pointer->size == 0)
	{
		return NULL;
	}
	else if (list_pointer->size == 1)
	{
		//Node *old = list_pointer->head;
		//free(list_pointer->head);
		//list_pointer->head = NULL;
		list_pointer->size--;
		//return old;
	}
	Node *old = list_pointer->head;
	//free(list_pointer->head);
	list_pointer->head = old->next;
	list_pointer->size--;
	return old;
}

// Insert item at a specified index and return a reference to it
void *removeAtIndex(List *list_pointer, int index)
{
	if (index == list_pointer->size - 1)
	{
		removeTail(list_pointer);
	}
	else if (index == 0)
	{
		removeHead(list_pointer);
	}
	else if (index >= list_pointer->size)
	{
		return NULL;
	}
	else
	{
		Node *curr = list_pointer->head;
		for (int c = 0; c < index - 1; c++)
		{
			curr = curr->next;
		}
		Node *nex = curr->next;
		*nex = *nex;
		free(curr->next);
		curr->next = nex->next;
		list_pointer->size--;
		return nex;
	}
}

// Return item at index
void *itemAtIndex(List *list_pointer, int index)
{
	if (index == list_pointer->size - 1)
	{
		return list_pointer->tail;
	}
	else if (index >= list_pointer->size)
	{
		return NULL;
	}
	else
	{
		Node *curr = list_pointer->head;
		for (int c = 0; c < index; c++)
		{
			curr = curr->next;
		}
		return curr;
	}
}