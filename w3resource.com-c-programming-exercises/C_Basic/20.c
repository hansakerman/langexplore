/* 20. Solve quadratic equation using Bhaskara's formula

Write a C program to print the roots of Bhaskara’s formula from the given three floating numbers. Display a message if it is not possible to find the roots.
Test Data :
Input the first number(a): 25
Input the second number(b): 35
Input the third number(c): 12
Expected Output:
Root1 = -0.60000
Root2 = -0.80000 */
#include <stdio.h>
#include <math.h>

int main()
{

  float a=25,b=35,c=12,r1,r2;
  /*
  printf("Input the first number(a): ");
  scanf("%f",&a);
  printf("Input the first number(b): ");
  scanf("%f",&b);
  printf("Input the first number(c): ");
  scanf("%f",&c);
  */
  
  //  printf("%f \n", sqrt(double(a)));

  float part_solve = (b*b-4*a*c);
  if (part_solve < 0 || a == 0)
    {
      printf("NOT SOLVABLE MATE");
      printf("%f",part_solve);
      return 0;
    }
  else
    {
      part_solve = sqrt(part_solve);
      printf("SOLVABLE \n");
      printf("%f \n",(-b+part_solve)/(2*a));
      printf("%f \n",(-b-part_solve)/(2*a));
    }
  
  //  r1 = (-b+sqrt(b*b-4*a*c)/(2*a));
  //  printf("%.3f", r1);
  
  return 0;
}
