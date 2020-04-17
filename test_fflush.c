#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fp = fopen("test.dat", "r+");
  if (fp == NULL) {
    perror("problem");
    fp = fopen("test.dat", "w+");
      }
  fprintf(fp, "%d", 10);
  fflush(fp);

  return 0;

}
