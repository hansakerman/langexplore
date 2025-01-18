#include<stdio.h>

int main()
{
  float f1 =35e3;
  float f2 =35e-3;
  int i =35e3;
  int i2 =35e-3; // -> 0

  printf("%f\n",f1);
  printf("%i\n",i);
  printf("%i\n",i2);
  printf("%f\n",f2);
}
