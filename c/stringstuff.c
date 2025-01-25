#include<stdio.h>
#include<string.h>

int main()
{
  char foo[]="123456ABCDEF";
  printf("LENGTH MEIN FREUND %d\n", (int)strlen(foo));

  char bar[20]="FOOBAR"; // we should cram in the stuff in this so MORE SPACE
  printf("CONCATZE %s", strcat(bar,foo));


  
}
