#include<stdio.h>

int main()
{
  int foo[] = {12,43,17,42};

  // Size
  printf("%lu\n", sizeof(foo));
  // length
  printf("%lu\n", sizeof(foo)/sizeof(foo[0]));
}
