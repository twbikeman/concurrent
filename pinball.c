#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void pinball(int x, int y) {

  char buf[500] = {'\0'};
  char *bufp = buf;
  char *head = buf;
  
  int *bin = (int *)calloc(x, sizeof(int));
;  int num;
  int i, j;
  srand(time(NULL));

  for(i = 0; i < y; i++) {
    num = 0;
    for (j = 0; j < x -1; j++)
      if ((double)rand()/RAND_MAX > 0.5) num++;
    bin[num] += 1;
    /* printf("%d\n", num);     */
  }


  int largest = 0;
  for(i = 0; i < x; i++)
  if (largest < bin[i]) largest = bin[i];
  
  for(i=0; i < x; i++) {
     printf("%d-(%7d)-(%5.2f%%)|",i + 1, bin[i], (double)bin[i] / y * 100);
     bufp += sprintf(bufp, "%d-(%7d)-(%5.2f%%)|",i + 1, bin[i], (double)bin[i] / y * 100);
     for(j = 0; j < (double)bin[i] / largest * 50; j++) {
     printf("*");
     bufp += sprintf(bufp, "*");
     }
     printf("\n");
     bufp += sprintf(bufp, "\n");
  }

  *bufp = '\0';
  write(1, head , strlen(head));
  

  /* for(i=0; i < x; i++) { */
  /*    printf("%d-(%7d)-(%5.2f%%)|",i + 1, bin[i], (double)bin[i] / y * 100); */
  /*    for(j = 0; j < (double)bin[i] / largest * 50; j++) */
  /*    printf("*"); */
  /*    printf("\n"); */
  /* } */




  
}


int main() {
  pinball(6, 30000000);
  return 0;
}
