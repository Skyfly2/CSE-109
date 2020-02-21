/*
Name: Asher Hamrick
Lehigh e-mail id: alh223

Instructions: For each problem, write the English interpretation of each line of code. For each problem, indicate what the memory would contain after the associated line is execuated. Indicate a memory location with teh & symbol.

 For instance:

  //Ex1: Declare an interger pointer called integer_ptr
  // Memory: integer_ptr - Uninitialized
  int *integer_ptr;
  
  //Ex2: Declare an integer called integer with the value 10
  // Memory: integer_ptr = Uninitialized, integer = 10
  int integer = 10;
  
  // Ex3: Set the value of integer_pointer to the address of integer
  // Memory: integer_ptr = &integer, integer = 10
  integer_pointer = &integer
  

*/

#include <stdio.h>

int main()
{
  // Problem 1: Declare a character pointer called a
  // Memory: a = uninitialized
  char *a;

  // Problem 2: Declare an integer pointer called b
  // Memory: a = uninitialized, b = uninitialized
  int *b;

  // Problem 3: Declare an integer called c with the value of 1632
  // Memory: a = uninitialized, b = uninitialized, c = 1632
  int c = 1632;

  // Problem 4: Declare a character called d with the value of 96
  // Memory: a = uninitialized, b = uninitialized, c = 1632, d = 96
  char d = 96;

  // Problem 5: Initialize the value of b to point to the memory address of c
  // Memory: a = uninitialized, b = &c, c = 1632, d = 96
  b = &c;

  // Problem 6: Initialize the value of a to point to the memory address of d
  // Memory: a = &d, b = &c, c = 1632, d = 96
  a = &d;

  // Problem 7: Set the value of the address a is pointing to to the value at the address b is pointing to
  // Memory: a = Memory address of d (&d); but the value at that location is changed to become 256 (truncated value of *b), b = &c, c = 1632, d = 96
  *a = *b;

  return 0;
}