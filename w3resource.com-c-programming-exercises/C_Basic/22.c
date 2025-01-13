/* Write a C program that reads 5 numbers and sums all odd values
   between them. */
/* Test Data : */
/* Input the first number: 11 */
/* Input the second number: 17 */
/* Input the third number: 13 */
/* Input the fourth number: 12 */
/* Input the fifth number: 5 */
/* Expected Output: */
/* Sum of all odd values: 46 */

#include <stdio.h>

int o(int x)
{
  // return only odd numbers and return zero if even.
  return (x%2)?x:0;
}
     
int main()
{
  int a,b,c,d,e,total;
  printf("5 numbers:");
  scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);

  total=o(a)+o(b)+o(c)+o(d)+o(e);
  printf("\n %d \n", total);
  return 0;
}

