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
  int x[n];
  for (i = 0; i < n; i++)
    scanf("%d", x + i);

  key_t key= ftok("a.out", 'a');
  int shm_id = shmget(key, n * sizeof(int), IPC_CREAT | 0666);
  int *shm_ptr = (int *)shmat(shm_id, NULL, 0);
  memcpy(shm_ptr, x, n *sizeof(int));
  
  for(i = 0; i < n; i++)
     printf("%d ", shm_ptr[i]);

  printf("\n%d\n", shm_id);

  shmctl(shm_id, IPC_RMID, NULL);


  char *cmd = "./merge";
  char *argv[1];
  *argv = '\0';
  execvp(cmd, argv);

  return 0;
}
