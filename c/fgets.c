#include<stdio.h>

int main()
{
  char name[30];

  printf("Name: ");
  fgets(name, sizeof(name), stdin);

  printf("hello %s",name);
  return 0;
}
