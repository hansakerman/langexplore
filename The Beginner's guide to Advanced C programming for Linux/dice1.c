
/* dice1.c */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int balance=1000;
int guess, bet, dice;

int play()
{
  printf("Please bet: ");
  fflush(stdout);
  scanf("%d", &bet);

  printf("Please guess (1-6, 0=quit): ");
  fflush(stdout);
  scanf("%d", &guess);

  if(guess==0)
    balance = -1;
    return 0;

  /*sleep(2);*/

  dice=rand()%6+1;

  printf("You guessed %d and the dice rolled %d.",guess,dice);
  
  if (guess==dice)
    {
      printf("You won %d !\n",bet*3);
      balance = balance + bet * 3;
      printf("Your new balance is: %d\n",balance);
    }
  else
   {
     printf("You lost your bet of %d !\n",bet);
     balance = balance - bet;
     printf("Your new balance is: %d\n",balance);
   }
  
  if (balance == 0)
    return 0;
  return 0;
}

int main ()
{
  
  while (balance>0)
    play();

  return 0;
}
