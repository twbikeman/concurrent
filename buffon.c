#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void myrand(double *d, double *theta) {
  srand(time(NULL));
  *d = (double)rand() / (RAND_MAX);
  *theta = (double)rand() / (RAND_MAX) * acos(-1.0);

}


int main() {
  double d, theta;
  myrand(&d, &theta);
  printf("(%f,%f)\n", d, theta);
  return 0;
}
