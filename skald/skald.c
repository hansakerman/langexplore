#include <stdio.h>
#include <stdlib.h>
#include <uuid/uuid.h>

int main()
{
  uuid_t binuuid;
  uuid_generate_random(binuuid);

  // let's 
  
  char *uuid = malloc(37);
  uuid_unparse(binuuid, uuid);
  printf("%s\n", uuid);

  //  write_block
  return 0;

    
}

