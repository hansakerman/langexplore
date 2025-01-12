
/* switch.c */
#include <stdio.h>


int main() {

  int x;
  printf("Choose 1-3: ");
  scanf("%d",&x);

  switch (x)
    {
    case 1:
      printf("Apples\n");
      break;
    case 2:
      printf("Tao 2\n");
      break;
    case 3:
      printf("Foobar\n");
      break;
    default:
      printf("default hurray\n");
   }    

  return 0;
}
