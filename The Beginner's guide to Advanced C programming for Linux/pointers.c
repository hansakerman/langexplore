
/* pointer.c */
#include <stdio.h>
#include <string.h>

int main()
{
  char str[32];
  char *p;
  
  strncpy(str, "I like apples",31);
  p = str;

  //Increment pointers
  //p = p + 1;
  printf("%c\n",*p);
  printf("%s\n",p+3);
}
