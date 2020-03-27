#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void myrand(double *d, double *theta) {
  srand(time(NULL));
  *d = (double)rand() / (RAND_MAX);
  *theta = (double)rand() / (RAND_MAX) * acos(-1.0);

}

double  needlePos() {
  double d = (double)rand() / (RAND_MAX);
  double theta = (double)rand() / (RAND_MAX) * 2 * acos(-1.0);
  double l = sin(theta);
  return d + l;

}


int main() {

  srand(time(NULL));

  
  int cross = 0;
  double test = 0.0;
  for(int i = 0; i < 1000; i++) {
    test = needlePos();
    if (test > 1.0 || test < 0.0) cross++;
  }
  

  printf("%f\n", (double)cross / 1000);
  return 0;

  
}
