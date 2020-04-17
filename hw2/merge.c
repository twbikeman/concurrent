#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



void MergeSort(int left, int right) {
  
  char param[5][80];
  
  sprintf(param[0], "./merge");
  sprintf(param[1], "%d", left);
  sprintf(param[2], "%d", right);
  sprintf(param[3], "mproc");
  sprintf(param[4], "%d", getpid());
  char *params[6] = {param[0],param[1],param[2],param[3],param[4],NULL}; 

  if (fork() == 0) {
execvp(params[0], params); 
  }
  else
    return;
}

  



int main(int argc ,char **argv) {
  int left, right, middle, num, proc, ppid = 0;
  left = atoi(argv[1]);
  right = atoi(argv[2]);
  proc = (int)*argv[3];
  if (argv[4] != NULL)
    ppid = atoi(argv[4]);

  char message_enter[80];
  char *message_enterPtr = message_enter;


  middle = (right + left) / 2;
  num = right - left + 1;

  if (num == 1) exit(EXIT_SUCCESS);



  

  /* dispaly entering info */
  
  switch(proc) {
  case 'm':
    message_enterPtr += sprintf(message_enterPtr, "### M-PROC(%d)", getpid() );
    if (ppid != 0)
      message_enterPtr += sprintf(message_enterPtr, " created by M-PROC(%d)", ppid);
    message_enterPtr += sprintf(message_enterPtr, ": entering with a[%d..%d]\n", left, right);
    write(1, message_enter, strlen(message_enter));   
    break;
  case 'b':
    break;
  }


  MergeSort(left, middle);
  MergeSort(middle + 1, right);

  wait(NULL);
  wait(NULL);
  


}
