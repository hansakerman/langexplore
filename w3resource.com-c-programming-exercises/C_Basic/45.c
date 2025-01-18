#include<stdio.h>

float ratio(int i)
{
  if(i>50)return 0;
  return 1.0/i+ratio(i+1);
}

int main()
{
  float result = ratio(1);
  printf("%.2f\n",result);
  return 0;
}


