/* Write a C program to convert specified days into years, weeks and days.
Note: Ignore leap year.

Test Data :
Number of days : 1329
Expected Output :
Years: 3
Weeks: 33
Days: 3 */

#include <stdio.h>

int main()
{
  int days;
  
  printf("Number of days : ");
  scanf("%d",&days);

  printf("Years: %d\n",days/365);

  int rest=days%365;
  printf("%d",rest/7);
  rest=rest%7;

  printf("Days: %d\n",rest);

  return 0;
}
