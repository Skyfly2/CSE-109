#include <stdio.h>
#include <stdlib.h>

double *multiplyByTwo(double *input)
{
  double *twice = malloc(8);
  *twice = *input * 2.0;
  return twice;
  free(twice);
}

int main(int argc, char *argv[])
{
  int *age = malloc(4);
  *age = 30;
  free(age);
  double *salary = malloc(8);
  *salary = 12345.67;
  double *myList = malloc(24);
  myList[0] = 1.2;
  myList[1] = 2.3;
  myList[2] = 3.4;
  free(myList);
  double *doublesalary = malloc(8);
  doublesalary = multiplyByTwo(salary);
  free(salary);
  printf("double your salary is %.3f\n", *doublesalary);
  free(doublesalary);

  return 0;
}