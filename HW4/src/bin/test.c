#include "hashset.h"
#include "stdbool.h"

int test(char* label, bool a, bool b) {
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

	HashSet *hs;

	hs = (HashSet*) malloc(sizeof(HashSet));

	initHashSet(hs, 10);

  int a = 0x12ab345;
  int b = 0xfeed425;
  int c = 0xabcd38;
  int d = 0x1235698;
  int e = 0x2c374;
  int f = 0xa0f8982;
  int g = 0x053eba;
  int h = 0x61c2f5e;
  int i = 0xe0295f2;
  int j = 0x5e700eaa;
  int k = 0xe75bf1;
  int l = 0x6baa9bb;
  int m = 0x8b1390a;
  int n = 0x59dd1;
  int o = 0xfc32;
  int p = 0xa9d89d8;
  int q = 0x5b2c9e;
  int r = 0x2431e3;
  int s = 0x1910a;
  int t = 0x72;

	insertItem(hs,&a,sizeof(int)); // insert an item into the table

 	test("Test1", findItem(hs, &a, sizeof(int)), true); // find the item
  test("Test2", insertItem(hs,&a,sizeof(int)), false); // can't insert the same item twice

  insertItem(hs,&b,sizeof(int));
  insertItem(hs,&c,sizeof(int));
  insertItem(hs,&d,sizeof(int));
  insertItem(hs,&e,sizeof(int));
  insertItem(hs,&f,sizeof(int));

  test("Test3", findItem(hs, &f, sizeof(int)), true);

  insertItem(hs,&g,sizeof(int));
  insertItem(hs,&h,sizeof(int)); // 7 of 10 buckets should be filled on this insert, causing a resize

  test("Test4", hs->size == 20, true); // test that the table was resized

  insertItem(hs,&i,sizeof(int));
  insertItem(hs,&j,sizeof(int));
  insertItem(hs,&k,sizeof(int));
  insertItem(hs,&l,sizeof(int));
  insertItem(hs,&m,sizeof(int));
  insertItem(hs,&n,sizeof(int));
  insertItem(hs,&o,sizeof(int));
  insertItem(hs,&p,sizeof(int));
  insertItem(hs,&q,sizeof(int));
  insertItem(hs,&r,sizeof(int));
  insertItem(hs,&s,sizeof(int));
  insertItem(hs,&t,sizeof(int)); // 14 of 20 buckets should be filled on this insert, causing another resize

  test("Test5", hs->size == 40, true); // test that the table was resized again

  test("Test6", removeItem(hs,&a,sizeof(int)), true); // test remove
  test("Test7", findItem(hs,&a,sizeof(int)), false); // the item should be gone
  test("Test8", removeItem(hs,&a,sizeof(int)), false); // can't remove again
  test("Test9", insertItem(hs,&a,sizeof(int)), true); // but we can add it back


  return 0;
}