#include <stdio.h>
#include <stdlib.h>
void main(void)
{
  int I = 105;
  int *p;
  p = &I;
  printf(" Value of I = %u",*p);
  printf(" Value of I = %d",I);
  printf(" address of I = %d",&I);
  printf(" address of I = %d",&I);
  printf(" address of I = %u",p);
}