#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

extern int errno;

int main() {
  int n, i;
  char message[200];
  char *messagePtr = message;

  /* create shared memory */
  
  key_t key= ftok("shmfile", 'a');
  int shm_id = shmget(key, 1024 * sizeof(int), IPC_CREAT | 0666);
  int *shm_ptr = (int *)shmat(shm_id, NULL, 0);

  /* show info about shared memory */

  messagePtr = message;
  messagePtr += sprintf(messagePtr, "*** MAIN: shared memory key = %d\n", shm_id);
    messagePtr += sprintf(messagePtr, "*** MAIN: shared memory created\n");
    messagePtr += sprintf(messagePtr, "*** MAIN: shared attched and is ready to use\n\n");

  write(1, message, strlen(message));

  /* show elements info */

  scanf("%d", &n);

   for (i = 0; i < n; i++)
     scanf("%d", shm_ptr + i);
   
   messagePtr = message;
   messagePtr += sprintf(messagePtr, "Input array for mergesort has %d elements\n", n);
   for (i = 0; i < n; i++)
     messagePtr += sprintf(messagePtr, "   %d", shm_ptr[i]);
   messagePtr += sprintf(messagePtr, "\n\n");
   write(1, message, strlen(message));
  

   /* fork */

   if (fork() == 0) {

   char *params[4];
   params[0] = "./merge";
   params[1] = "0";
   char temp[80];
   sprintf(temp, "%d", n -1);
   params[2] = temp;
   params[3] = NULL;
   


  
   execvp(params[0], params);
   }
   else
     wait(NULL);
        




   

   /* show merged array */
   
   messagePtr = message;
   messagePtr += sprintf(messagePtr, "*** MAIN: merged array:\n");
   for (i = 0; i < n; i++)
     messagePtr += sprintf(messagePtr, "   %d", shm_ptr[i]);
   messagePtr += sprintf(messagePtr, "\n\n");
   write(1, message, strlen(message));

   /* show info about being detached */

   if (shmdt(shm_ptr) == 0) {
     messagePtr = message;
     messagePtr += sprintf(messagePtr, "*** MAIN: shared memory successfully detached\n");
     write(1, message, strlen(message));
   }
   else {
     perror("detach failed!");
   }
   
   /* show info about being removed */
   
   if (shmctl(shm_id, IPC_RMID, NULL) == 0) {
     messagePtr = message;
     messagePtr += sprintf(messagePtr, "*** MAIN: shared memory successfully removed\n");
     write(1, message, strlen(message));
   }
   else {
     perror("remove failed!");
   }
   
   

 




  return 0;
}
