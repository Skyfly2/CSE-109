#include "linkedlist.h"
#include <stdlib.h>

int main()
{

	List *lp;

	void *item;

	lp = (List *)malloc(sizeof(List));

	initList(lp);

	int *v = 0x12ab34;
	int *w = 0xfeed42;
	int *x = 0xabcdef;
	int *y = 0x123456;
	int *z = 0xa1b2c3;
	insertAtHead(lp, x);
	//insertAtHead(lp, y);
	// insertAtHead(lp, y);
	// insertAtTail(lp, z);
	// insertAtIndex(lp, 2, v);
	// insertAtTail(lp, w);
	// insertAtHead(lp, x);
	//printf("%x", lp->head->item);
	// //insertAtHead(lp, x);

	printf("%x\n", *(int *)removeHead(lp));
	printList(lp);
	// insertAtHead(lp, y);
	// insertAtHead(lp, v);
	// insertAtHead(lp, w);
	// insertAtHead(lp, z);
	//insertAtIndex(lp, 1, y);
	//printList(lp);
	printf("%x", lp->head->item);

	// insertAtHead(lp, w);
	//printf("%x\n", *(int *)removeHead(lp));
	//printf("%x\n", *(int *)itemAtIndex(lp, 0));
	//insertAtTail(lp, z);
	// insertAtTail(lp, v);
	// insertAtIndex(lp, 1, w);

	return 0;
}