#include <stdio.h>
#include <sys/param.h>


int my_max(int x, int y)
{
  return (x>y)?x:y;
}

int main()
{
  int a=25;
  int b=35;
  int c=15;

  // MAX worked
  //  printf("%d \n",MAX(MAX(a,b),c));

  // But let's do an own max-function for int:s.
  printf("Maximum: %d\n", my_max(my_max(a,b),c));

  return 0;
}
