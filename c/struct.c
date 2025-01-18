#include<stdio.h>
#include<string.h>

struct MyStruct {
  int myNum;
  char myLetter;
  char myString[30];
};
    
int main()
{
  struct MyStruct fooStruct;
  fooStruct.myNum=30;
  fooStruct.myLetter='f';
  strcpy(fooStruct.myString, "Foobar");

  printf("%s\n", fooStruct.myString);
  printf("%d\n", fooStruct.myNum);


  struct MyStruct barStruct = {13, 'B', "some text"};
  printf("%s\n", barStruct.myString);
  printf("%d\n", barStruct.myNum);


  // copy values from an other struct.
  fooStruct=barStruct;

  

  return 0;
  
}




