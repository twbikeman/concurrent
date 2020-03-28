#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

void main(int argc, char **argv) {
  int i, n = atoi(argv[1]);
  for (i = 1; i < n; i++)
    if(fork() == -1) break;
  printf("Process %ld with parent %ld\n", (long int)getpid(), (long int)getppid());
  sleep(1);
}
