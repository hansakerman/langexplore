
/* random.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//pseudo random functions. Mimicking randomness

int our_random_function(int max)
{
  int x;
  x = rand() % max + 1; // just print the reminder man.
  return x;
}

int main()
{
  int random;

  srand(getpid()); //seed 
  random = our_random_function(5);
  printf("%d\n",random);
    random = our_random_function(10);
  printf("%d\n",random);

  return 0;
}

