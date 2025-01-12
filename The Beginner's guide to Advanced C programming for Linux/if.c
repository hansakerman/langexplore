
/* if.c */
#include <stdio.h>

int main()
{
  int speed;

  printf("How fast are you driving? (km/h)\n");
  scanf("%d", &speed);

  if(speed >= 100)
    {
      printf("You are speeding\n");
    }
  else if (speed >80)
    {
      printf("You are cruising, nice!\n");
    }
  else
    {
      printf("You are driving within the speed limits\n");
    }
  return 0;
}
