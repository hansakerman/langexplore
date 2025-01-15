#include <stdio.h>

int main()
{

  int numbers[] = {5,7,15,23,45};
  int i,pos;

  int max=numbers[0];
  for (i=1;i<5;i++){
    if(numbers[i]>max){
      max=numbers[i];
      pos=i;
    }
  }

  printf("Highest value %d at position %d\n", max,pos);
  
}
