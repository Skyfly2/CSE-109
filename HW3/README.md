# CSE 109 - Homework 3

You will implement a linked list data structure in this assignment. The linked list will consist of a head pointer and a tail pointer. The head pointer will point to a node struct, which will hold a data void pointer as well as a pointer to the next node in the list. The final item in the list will be pointed to by a tail pointer. The next pointer on the tail will point to NULL.

The List and Node structs are declared in `linkedlist.h`, along with a number of functions you will need to implement.

```c
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
```

There is a print function that is already implemented for you. This will help you inspect the list as you write the above functions.

## Build Instructions

Write build instructions here.

## Usage

Write usage insturcitons here.

## Examples

Write two examples demonstrating how to use the linked list struct.

## Assignment Instructions

1. Fork the relevant repository into your CSE 109 group namespace. [Instructions](https://docs.gitlab.com/ee/workflow/forking_workflow.html#creating-a-fork)

2. Clone your newly forked repository to your computer. Your repository should be hosted at 
```
https://gitlab.com/<your user name>-cse109/<assignment name>
```
You can use the following git command with the appropriate values substituted to customize it for you:
```
git clone https://gitlab.com/<your user name>-cse109/<assignment name>
```
[Instructions](https://docs.gitlab.com/ee/gitlab-basics/start-using-git.html#clone-a-repository) 

3. Write the necessary code to get your project to pass the tests in `src/bin/tests.c`. Do not modify this file. As you work on your project, you can use `src/bin/main.c` to write any scratch code you need to test your assignment as you're working on it.

4. Commit the changes you made locally to your gitlab repository. Follow the instructions [here](https://githowto.com/staging_and_committing) (read sections 6, 7 and 8) about staging and committing changes.

5. Check the status of your commit with the appropriate values substituted to customize it for you at: 
```
https://gitlab.com/<your user name>-cse109/<assignment name>/pipelines
```