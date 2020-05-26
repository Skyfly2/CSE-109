#include "linkedlist.h"

int test(char* label, int a, int b) {
  printf("%s: ", label);
  if (a==b) {
    printf("Passed\n");
    return 1;
  } else {
    printf("Failed. lhs=%x, rhs= %x\n",a,b);
    exit(1);
  }
}

int main() {

	List *lp;

	void* item;

	lp = (List *) malloc(sizeof(List));

	initList(lp);

  int v = 0x12ab34;
  int w = 0xfeed42;
  int x = 0xabcdef;
  int y = 0x123456;
  int z = 0xa1b2c3;
	insertAtHead(lp,&x);
  insertAtHead(lp,&y);
  insertAtTail(lp,&z);
  insertAtTail(lp,&v);
  insertAtIndex(lp, 1, &w);

 	test("Test1", *(int*)itemAtIndex(lp, 0), 0x123456); 
 	test("Test2", *(int*)itemAtIndex(lp, 1), 0xfeed42); 
 	test("Test3", *(int*)itemAtIndex(lp, 2), 0xabcdef); 
 	test("Test4", *(int*)itemAtIndex(lp, 3), 0xa1b2c3); 
 	test("Test5", *(int*)itemAtIndex(lp, 4), 0x12ab34); 
 	test("Test6", *(int*)removeTail(lp), 0x12ab34); 
 	test("Test7", *(int*)removeHead(lp), 0x123456); 
 	test("Test8", *(int*)removeAtIndex(lp,1), 0xabcdef); 

  return 0;
}