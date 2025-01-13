/* Write a C program that reads three floating-point values and checks if it is possible to make a triangle with them. Determine the perimeter of the triangle if the given values are valid. */
/* Test Data : */
/* Input the first number: 25 */
/* Input the second number: 15 */
/* Input the third number: 35 */
/* Expected Output: */
/* Perimeter = 75.0 */

#include <stdio.h>

int main()
{
  int a,b,c;
  printf("Triangle sides (a b c): ");
  scanf("%d %d %d",&a,&b,&c);

  if(!(a<(b+c)&&b<(a+c)&&c<(a+b)))
    {
      printf("Not a valid triangle\n");
      return -1;
    }

  printf("Parimeter = %d\n",a+b+c);
  return 0;
}

