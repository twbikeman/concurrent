#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>


int main() {
  int n, i;
  scanf("%d", &n);

  key_t key= ftok("shmfile", 'a');
  int shm_id = shmget(key, n * sizeof(int), IPC_CREAT | 0666);
  int *shm_ptr = (int *)shmat(shm_id, NULL, 0);

  for (i = 0; i < n; i++)
    scanf("%d", shm_ptr + i);



  
  for(i = 0; i < n; i++)
     printf("%d ", shm_ptr[i]);
  printf("\n");

  printf("shmid: %d\n", shm_id);

  /* shmctl(shm_id, IPC_RMID, NULL); */


  char *cmd = "./merge";

  char *params[4];
  params[0] = "./merge";
  params[1] = "0";
  char temp[80];
  sprintf(temp, "%d", n -1);
  params[2] = temp;
  params[3] = '\0';

  printf("%s\n", params[0]);
  printf("%s\n", params[1]);
  printf("%s\n", params[2]);
  printf("%p\n", params[3]);
  
  execvp(params[0], params);

  return 0;
}
