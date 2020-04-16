#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>


int search(int *a, int left, int right, int x) {
  int middle =  (left + right) / 2;
  if (x < a[left]) return left;
  if (x > a[right]) return right + 1;
  if ( a[middle] >  x &&  x > a[middle - 1]) return middle;
  if (x < a[middle] )
    return search(a, left, middle - 1, x);
  else
    return search(a, middle + 1, right, x);
}




int main(int argc, char **argv) {
  int left, right, middle;
  left = atoi(argv[1]);
  right = atoi(argv[2]);
  middle = (left + right) / 2;

  int *mem = malloc((right - left + 1) * sizeof(int));


  key_t key= ftok("shmfile", 'a');
  int shm_id = shmget(key, 1024 * sizeof(int), 0666);
  int *shm_ptr = (int *)shmat(shm_id, NULL, 0);


  
  
  

  

  if (left == right) {
    free(mem);
    exit(EXIT_SUCCESS);
  }
  else if (right == left + 1) {
    printf("left : %d\tright: %d\n", left, right);
    free(mem);
    exit(EXIT_SUCCESS);
  }
    


  char *param[4];
  char params[4][80];



  if (fork() != 0) { /* parent */
    if (fork () != 0) {
      wait(NULL);
      wait(NULL);
      printf("left : %d\tright: %d\n", left, right);
      free(mem);
    }
    else {           /* child 2 */
      sprintf(params[0], "%s", "./merge");
      sprintf(params[1], "%d", middle + 1);
      sprintf(params[2], "%d", right);
      param[0] = params[0];
      param[1] = params[1];
      param[2] = params[2];
      param[3] = NULL;
      execvp(param[0], param);
    }
  }
  else {   /* child 1 */
    sprintf(params[0], "%s", "./merge");
    sprintf(params[1], "%d", left);
    sprintf(params[2], "%d", middle);
    param[0] = params[0];
    param[1] = params[1];
    param[2] = params[2];
    param[3] = NULL;
    execvp(param[0], param);
  }

  

  
  /* int a[] = {1,2,9,10}; */
  /* int b[] = {4,5,6}; */
  /* int c[7] = {0}; */
  /* int x, i; */
  /* for (i = 0; i < 3; i++) { */
  /*   x = search(a, 0, 3, b[i]); */
  /*   c[x + i] = b[i]; */
  /* } */
  /* for (i = 0; i < 4; i++) { */
  /*   x = search(b, 0, 2, a[i]); */
  /*   c[x + i] = a[i]; */
  /* } */

  /* for(i = 0; i < 7; i++) */
  /*   printf("%d\t", c[i]); */


  return 0;
}
