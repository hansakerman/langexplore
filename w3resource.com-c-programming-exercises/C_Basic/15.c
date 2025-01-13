/*Write a C program to calculate the distance between two points.
Test Data :
Input x1: 25
Input y1: 15
Input x2: 35
Input y2: 10
Expected Output:
Distance between the said points: 11.1803 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  float x1,y1,x2,y2,l,h,d;

  printf("Enter 4 int that would represent 2 points (x1 y1 x2 y2)");
  scanf("%f %f %f %f", &x1, &y1 ,&x2, &y2);

  l=fabsf(x1-x2);
  h=fabsf(y1-y2);  

  d=sqrt(l*l+h*h);

  printf("%.4f", d);

  return 0;
}

  
