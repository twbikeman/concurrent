#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

double ellipseArea(int a, int b, int s) {


  srand(time(NULL));
  
  int sum = 0;
  for(int i = 0; i < s; i++) {

    double x = (double)rand()/RAND_MAX * a;
    double y = (double)rand()/RAND_MAX * b;

    double test =  x * x / (a * a) + y * y/ (b * b);
    if (test <= 1.0) sum++;
    //printf("(%f)\n", test);
  }

  double area = 4 * a *  b *  (double)sum / s; 
  //  return a * b * (double)sum / s;

  char buf[800];
  sprintf(buf,
	  "%*cEllipse Area Process\n" \
	  "%*cTotal random Number Pairs %d\n" \
	  "%*cSemi-Major Axis Length %d\n" \
	  "%*cSemi-Minor Axis Lenght %d\n" \
	  "%*cTotal Hits %d\n" \
	  "%*cEstimated Area is %f\n" \
	  "%*cEllipse Area Process Exit\n",
	  6, ' ', \
	  6, ' ', s, \
	  6, ' ', a,\
	  6, ' ', b, \
	  6, ' ', sum, \
	  6, ' ', area, \
	  6, ' '
 
   	  );
  
  int num = strlen(buf);
  write(0, buf, num);
  
  
}



int main() {
  ellipseArea(6,2,200000);
  int pairs = 200000;
  
  //printf("%f",ellipseArea(6,2, 200));
  //  printf("%f\n", ellipseArea(6, 2 ,200000));
  return 0;
}
