# CSE 109 - Midterm Exam II

Spring 2020

## Ethics Contract

**FIRST**: Please read the following carefully:

-	I have not received, I have not given, nor will I give or receive, any assistance to another student taking this exam, including discussing the exam with students in another section of the course. Do not discuss the exam after you are finished until final grades are submitted.
-	I will not plagiarize someone else's work and turn it in as my own. If I use someone else's work in this exam, I will cite that work. Failure to cite work I used is plagiarism.
-	I understand that acts of academic dishonesty may be penalized to the full extent allowed by the Lehigh University Code of Conduct, including receiving a failing grade for the course. I recognize that I am responsible for understanding the provisions of the Lehigh University Code of Conduct as they relate to this academic exercise.

If you agree with the above, type your full name in the following space along with the date. Your exam **will not be graded** without this assent.

*** Writing your name and the date below binds you to the above agreement

Asher Hamrick 4/20/2020

*** Writing your name and the date above binds you to the above agreement

## Prelude

Now... on to the exam. There are two parts to this exam. In part 1 you're going to implement a binary tree data structure in C. If you need a refresher on binary trees [here's a good one](https://en.wikipedia.org/wiki/Binary_search_tree) that has implementations on the general algorithms. There's also literally a million videos on you tube about binary trees.

In the last two homeworks I gave you a skeleton project to get you started. For this exam, you're going to work from scratch. This repository is blank except for the readme. You are going to lay out the directory structure, create a Makefile, create a header file, create a library file, and then implement your tree, and then finally provide tests to verify the tree works. You can use any libraries and functions you like (except one implementing a binary tree of course!).

In part 2 I'll ask you to answer a couple open ended questions.

Some ground rules though: I'm going to divide the project into discrete "questions". E.g. question 1 will be to create blank files to flesh out your directory structure. After each question you need to commit your progress to gitlab. This is how I will know you are not just copying and pasting an entire solution from the internet. I will be able to see how much time you spend on each question based on your commit times. For each question, I want you to copy and paste the hash of the commit (you can copy the hash of the commit from the commit menu after you push to gitlab into this README. See this image: https://imgur.com/fSIRINb. The hash of the commit in the example image looks like this: 0258b14275288e117b704cce59d8cb7bb7b2c3c4). This means for each question you will have two commits: one to commit the work, and another to commit the hash into this readme. Each commit message will be the associate question number. For Question 1 the commit message will be "Question 1". And the subsequent hash will be "Question 1 hash".

If you complete a question and need to go back and modify code in a previous question that's okay. The hash should just represent your first commit of that code.

Each question will be worth the same number of points, for a total of 100 points for all questions. 

Also, **and this is very important** if you use any information from the internet or anywhere else, you have to **CITE IT** in your exam. This includes the wiki article I posted above. If you use that, cite it every time you use it. I don't care about the format, just make it clear.

## Part 1

### Question 1

Lay out your directory. Create a src folder, a include folder, and a blank Makefile. 

- Inside the `src` folder create a `bin` directory. 
- Inside the `src/bin` directory create `test.c`
- Inside the `src` directory create `lib.c`
- Inside the `include` directory, create `binarytree.h`


Hash: 5e04e572480197b40c3676e91c70b592adfd5fcb

### Question 2

Implement the Makefile to build your project. It will be a little different than the HW so pay attention to these instructions.

- `make static` will generate a static library (libbinarytree.a) and put it in `build/lib`
- `make shared` will generate a shared library (libbinarytree.so) and put it in `build/lib`
- `make test` will generate a test executable from test.c and statically link to libbinarytree.a (it should make that as well if it doesn't exist). Put that in `build/bin`
- `make clean` will clean the project of all build artifacts (*.so *.a *.o test)

Hash: a85627788a21ed09f1a246c5850bb050a45a4819

### Question 3

In `binarytree.h`, write a struct to represent the nodes of the binary tree. Each node should have at least:

- `void*` a pointer to an item held on the node
- `Node**` An array of pointers to other nodes

You can include any other fields you see fit to make this work.

Hash: 9e3466b56318fb7c67609868a0a3461a3db28614

### Question 4

In `binarytree.h`, write a struct to represent the binary tree. The binary tree should have at least:

- `Node*` a pointer to the root node
- `char` a character to hold the depth of the tree.

You can include any other fields you see fit to make this work.

Hash: 3f4c37d2d971a6a84c370325ac3dc745a1baf46b

### Question 5

Stub out the relevant functions for your binary tree in `binarytree.h`

The functions you will implement are:

- `initBinaryTree()` takes a binary tree pointer and initialize the values on it.
- `insertItem()` takes a pointer to a binary tree and a pointer to an item and insert it into the tree. Returns `true` on success and `false` on failure (think about under what condition an insert would fail. It's probably not common). Updates the depth on the tree after each insert.
- `removeItem()` takes a pointer to a binary tree and a pointer to an item and remove that item from the tree if it exists in the tree. Returns a pointer to the item if the item was removed and `NULL` if the item was not removed (because it's not there). Updates the depth of the tree after each remove.
- `findItem()` takes a pointer to a binary tree and a pointer to an item and returns the depth of the item. It returns -1 if the item is not found in the list.
- `freeNodes()`takes a pointer to a binary tree and free all the nodes. It will not free the binary tree pointer.
- `printTree()` takes a pointer to a binary tree and print the entire tree. This can be in any format that helps you visualize the tree.

You can add any other function arguments you see fit to make your functions work.

Hash: 3a3de444245bc175741246aba43aec26261d063f

### Question 6

Implement `initBinaryTree()` in `lib.c`

Hash: de8174ecf243bcba6f3f90f2730b11dc8f80f046

### Question 7

Implement `insertItem()` in `lib.c`

Hash: 32544400709392b41edf369953bdc489f24d9dfa

### Question 8

Implement `printTree()` in `lib.c`

Hash: 2139c1f1e9366dafa146120b191f8ee355ff5e1a

### Question 9

Implement `findItem()` in `lib.c`

Hash: 1688dafdd37542a5056eb9946f9c958c767a2b42

### Question 10

Implement `removeItem()` in `lib.c`

Hash: fa33274a919543fac7622462a557daefa44542e4

### Question 11

Implement `freeNodes()` in `lib.c`

Hash: 76ef34ac9b8e8e76cc54a77ba77e0a2d547c880a

### Question 12

Write at least 5 tests in `test.c` to verify your code works.

Hash: 5fcc89c93fd0195b13f3ceff6809f5b4e395ce81

### Bonus

Set up a test runner on gitlab so that your test runs automatically and passes with a green checkmark.
(I consulted the Ci pipelines documentation at: https://docs.gitlab.com/ee/ci/quick_start/README
I also consulted the provided .gitlab-ci.yml from homework 4)
Hash: b46155e67bdc0e90dc90d499242984d56eac421f

## Part 2

Now answer the following questions. You can commit the answers here in this file. You'll do two commits again, one for the content, and one for the hash of the commit. These questions are very open ended. I want you to write as much as you can to convince me you know what you're talking about. Minimum 100 words for each question.

### Question 13

What is the difference between the stack and the heap? What variables go on the stack? What variables go on the heap?

(I consulted my notes to help me answer this question)
The stack and the heap have numerous differences that make them good and bad for certain tasks. The stack is a contiguous piece of memory, so all of the data stored on it is stored right next to each other, meaning that data stored on it should be static. The stack is managed by the operating system, and it figures out how to arrange everything. The stack has a fixed memory size, which allows it to be faster than the heap because everything can be accessed quickly using offsets. Memory used during a function is freed after the function ends because the compiler knows that those pieces of memory won't need to be used again. Unlike this, the heap is a fragmented piece of memory, so data is scattered across it and not necessarily connected. The heap is also larger and its fragmented nature and increased size allow for data stored on it to be dynamic. Memory on the heap also needs to be manually managed. In order to store something on the heap, memory must be manually allocated and manually freed when you no longer want to use the data field. Because data is fragmented on the heap, it is slower to access because offsets can not be used to get data, a series of pointers needs to be followed. The stack tends to store fixed and static variables because of its contiguous nature and size constraint, where as the heap tends to store dynamically sized variables like arrays because of its dynamically increasing size. 

Hash: 89ada7a70f17702909a2927a2b4882d24c562796

### Question 14

What are the pros of hash tables? What are the cons? What are some applications where hash tables are useful, and why are they good for those applications?

(I consulted my notes to help with this question)
Hash Tables are a type of data structure that has some very interesting use cases. The major pros of a hash table is that it has a constant (or nearly constant) time for inserting, removing and finding data within it. This is because each item is prehashed and then hashed, which provides a location based off of the prehashing and hashing algorithm as to where that item can be found/inserted/removed. Because of this, it only has to search through any data that was placed into the same bucket as it, meaning it doesn't have to search through every item in the hash table to find something, only a small number of them. The cons of hash tables are that it takes up a lot of memory and the prehashing process can take a lot of time. In order to have enough buckets for few collisions to happen, a lot of memory must be allocated for the hash table. If the table needs to be resized to increase the number of buckets, every item must be rehashed, which can take a long time. If there aren't enough buckets, and many collisions occur, then the time it takes to search for an item can go up dramatically. The prehashing process can also take long enough that in cases of small datasets, it may make sense to just brute force the data. Hash tables are useful for things like spellcheck or a login system because with spell check, it can quickly tell if a word is in the dictionary without searching the whole thing, and a login system can do the same with usernames and passwords. On some websites and dictionaries these sets of data are so long it would take an unreasonable amount of time to search through every data point every time.

Hash: c29b370b70233065b00b2522f6d46e3db93f4c6d

### Question 15

Create a segfault in your binary tree program and commit it to gitlab. What are the steps you would use in gdb to debug this segfault? How do you compile your program to use with gdb? Give the output of a stack trace at the point at which the segfault occurs. Fix the segfault again and commit the fix.

(I forgot the command to go from one breakpoint to the next without just using "next" a bunch of time, so I consulted: http://web.eecs.umich.edu/~sugih/pointers/gdbQS.html to figure out the command was 'continue')

The segfault I created is a failed attempt to print the item of a Node that is NULL. To use gdb with a program, the gcc flag -g must be used when compiling so that debugging symbols are added to the program. In order to start a debugging session in gdb, you type in the console: gdb test. After doing this, gdb will open and you hit enter to start the debugging session. By running the 'run' command in gdb, it tells me that the segfault occurred while running the printtree function at line 89 of the printtree function. Because I run the printtree function at line 98, and everything before that works, I can use the 'break' command like: "break 98" to stop the program at line 98. I can then use the 'step' command to go into the printtree function. Because gdb said the segfault occurred at line 89, I can use the 'break' command like: "break 89" and then the 'continue' command to continue to it. The program will continue executing until that point and then stop. I know that this line is the seg-fault point, so analyzing it, I see the only issue could be with the Node: node. I can type "print node->item" and gdb will display the item to me. It says it is in a memory location that can not be accessed. I can type "print node" and see that the node s Null and therefore doesn't have set fields. I can use this info to edit the program so it doesn't access info that doesn't exist in memory because it is on a null node. I can also check the stacktrace using the 'backtrace' command. The stacktrace at this point is given by gdb as this: 
#0  printTree (tree=0x8403260, node=0x0, depth=4, parent=0x8403590, left=true) at src/lib.c:89
#1  0x0000000008000c91 in printTree (tree=0x8403260, node=0x8403590, depth=3, parent=0x8403550, left=true) at src/lib.c:97
#2  0x0000000008000c91 in printTree (tree=0x8403260, node=0x8403550, depth=2, parent=0x84034b0, left=true) at src/lib.c:97
#3  0x0000000008000c91 in printTree (tree=0x8403260, node=0x84034b0, depth=1, parent=0x8403280, left=true) at src/lib.c:97
#4  0x0000000008000c91 in printTree (tree=0x8403260, node=0x8403280, depth=0, parent=0x0, left=false) at src/lib.c:97
#5  0x0000000008000a2b in main () at src/bin/test.c:98

Hash of segfault: ee9aa6357ebaa40dad67841ebdf4780ef6ccace0
Hash of fix: 46801b40edabd4d204b45ef80bd864db607f28fb
Hash of Question 15 answer: 9a22e19cbd4beeeca9a50d700d02e1ab1e599e07