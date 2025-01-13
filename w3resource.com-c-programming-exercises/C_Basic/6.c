/* Write a C program to compute the perimeter and area of a circle with a given radius.
Expected Output:
Perimeter of the Circle = 37.680000 inches
Area of the Circle = 113.040001 square inches */

#include <stdio.h>
#include <math.h>

int main()
{
  int radius;
  printf("Enter radius: ");
  scanf("%d",&radius);

  printf("Circumference: %f\n",M_PI*2*radius);
  printf("Circle area: %f\n",M_PI*radius*radius);

  return 0;
}
