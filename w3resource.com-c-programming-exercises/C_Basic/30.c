/* 30. Print squares of all even numbers up to a given value */

/* Write a C program to find and print the square of all the even values from 1 to a specified value. */
/* Test Data : */
/* List of square of each one of the even values from 1 to a 4 : */
/* Expected Output: */
/* 2^2 = 4 */
/* 4^2 = 16  */


#include <stdio.h>

int main()
{
  int top,i;

  printf("Max cube: ");
  scanf("%d",&top);
      
  for(i=2;i <= top;i++)
    {
      if(i%2)
	continue;
      printf("%d^%d = %d\n",i,i,i*i);
    }
  

	 return 0;

}
