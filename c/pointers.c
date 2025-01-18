#include <stdio.h>

int main ()

{

  int i=7;
  // a pointer variable should have the same data type.
  // assign *j to the adress of i (&i) "& = adress of"
  int *j=&i;
  // dereference and refer to the value (7)
  printf("%d\n", *j);
  printf("This be an adress: %p\n", j);
  printf("This be an adress: %p\n", &i);
  printf("This be the next adress: %p\n", j+1);
  // %zu is the format spec for return tupe size_t
  // size should on my system be 4 bytes.
  printf("Size of i: %zu\n bytes", sizeof(i));
 
  return 0;
}

	
