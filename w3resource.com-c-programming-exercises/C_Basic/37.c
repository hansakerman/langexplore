#include <stdio.h>

int main()
{

  int x, y;

  printf("Input The Coordinate(x,y)\n");
  printf("x: ");
  scanf("%d" ,&x);
  printf("y: ");
  scanf("%d" ,&y);

  if (x==0&&y==0)
    printf("We are in origo\n");
  else if (x>0&&y>0)
    printf("Quadrant I(+ +)\n");
  else if (x<0&&y>0)
    printf("Quadrant II(- +)\n");
  else if (x<0&&y<0)
    printf("Quadrant III(- -)\n");
  else if (x>0&&y<0)
    printf("Quadrant IV(+ -)\n");

  return 0;
  
}
