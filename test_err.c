#include <error.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
  int fd = open("testtest.txt", O_RDONLY);
  err(1, NULL);

  
  return 0;
  
}
