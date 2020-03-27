#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

  int status;
  pid_t pid;

  pid = fork();
  if(pid == 0) {                // child 0
    sleep(1);
    printf("child 0: %s\n", argv[1]);
  }
  else {

    pid = fork();
    if (pid == 0) {
      sleep(2);
      printf("child 1: %s\n", argv[2]);
    }
    else {
      pid = fork();
      if (pid == 0) {
	sleep(3);
	printf("child 2: %s\n", argv[3]);
      }
      else {
	wait(&status);
	wait(&status);
	wait(&status);
	printf("parent\n");
      }

    }
  }

  
  return 0;  
}
