#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>


void child() {
  char mess[] = "child\n";
  write(1, mess, strlen(mess));
}
void parent() {
  int status;
  wait(&status);
  char mess[] = "parent\n";
  write(1, mess, strlen(mess));
}




int main() {
  pid_t pid;
  pid = fork();
  int status;

  if (pid < 0)
    printf("fail!\n");
  else if (pid == 0) {
    sleep(1);
    child();
  }
  else {
    wait(&status);  
    parent();
  }

  return 0;
}
