#include<stdio.h>
#include<stdlib.h>
#include<uuid/uuid.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024
#define FILENAME "SKALDB_BLOCKFILE"

// Function to write a block of data to the file
int write_block(const char *block, size_t size) {
    int fd;
    // strcat
    //    strncpy(uuid_generate_random(binuuid);

    // Open the file for writing (append mode), creating it if it doesn't exist
    fd = open(FILENAME, O_WRONLY | O_APPEND | O_CREAT, 0600);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }
    
    // Write the block to the file
    ssize_t bytes_written = write(fd, block, size);
    if (bytes_written < 0) {
        perror("Error writing to file");
        close(fd);
        return 1;
    }

    printf("Successfully wrote %ld bytes to %s\n", bytes_written, FILENAME);

    // Close the file
    close(fd);
    return 0;
}

int main() {

  char storage_block[BLOCKSIZE];
  
  memset(storage_block, 'A', sizeof(storage_block));

  // but let's create an UUID
  // Binary typ for uuid's:
  uuid_t binuuid;
  char uuid_str[37];
  uuid_unparse(binuuid, uuid_str);
  printf("%s\n", uuid_str);
  // Lets do cleartext
  // WHY HAVE I DONE THE BLOX IN 8-BIT CHARS?
  // Well. I have to redo it all : )
  strncpy(storage_block, uuid_str, sizeof(uuid_str));
    
  // Test to write a block to the file
  if (write_block(storage_block, sizeof(storage_block)) != 0) {
    fprintf(stderr, "Failed to write block\n");
    return 1;
  }

  return 0;
}

