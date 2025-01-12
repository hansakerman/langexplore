
/* struct.c */
#include <stdio.h>
#include <string.h>

struct person{
  char title[8];
  char lastname[32];
  int age;
};

int main()
{

  struct person anders;
  strncpy(anders.title, "Mr.", 7);
  strncpy(anders.lastname, "Andersson",31);
  anders.age = 100;
  
  printf("%s %s of age %d",anders.title,anders.lastname,anders.age);

  return 0;
}



