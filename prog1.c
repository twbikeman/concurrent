
/*----------------------------------------------------*/
/*NAME: Tsung-che Tsai             User ID:           */
/*DUE DATE : 03/30/2020                               */
/*FILE NAME : prog1.c                                 */
/*PROGRAM PURPOSE :                                   */
/*    cocurrent class's 1 first homework              */
/*----------------------------------------------------*/



#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include <math.h>


/*---------------------------*/
/* FUNCTION fib              */
/*  get fibonacii number     */ 
/* PARAMETER USAGE:          */
/*  index number             */
/* FUNCTION CALLED:          */
/*  none                     */
/*---------------------------*/


long fib(long x) {
  if (x == 1 || x == 2)
    return 1;
  else
    return fib(x-1) + fib(x-2);
}

void fib_print(int x) {
  char buf[500];
  char *buf_p = buf;
  char *buf_h = buf;
  long number = fib(x);

  buf_p += sprintf(buf_p, "   Fibonacci Proccess Started\n");
  buf_p += sprintf(buf_p, "   Input Number %d\n", x);
  buf_p += sprintf(buf_p, "   Fibonacci Number f(%d) is %ld\n", x , number);
  buf_p += sprintf(buf_p, "   Fibonacci Proccess Exits\n");
  buf_p = '\0';
  write(1, buf_h, strlen(buf_h));  
}




void buffon(int r) {
  srand(time(NULL));
  double d,theta, l;
  int i, cross = 0;
  for(i = 0; i < r; i++) {
    d = (double)rand() / (RAND_MAX);
    theta = (double)rand() / (RAND_MAX) * acos(-1.0);
    l = sin(theta);
    if (d + l > 1.0 || d + l < 0.0) cross++;
  }
  printf("      Buffon's Needle Process Started\n");
  printf("      Input Number %d\n", r);
  printf("      Estimated Probability is %6.5f\n", (double)cross / r);
  printf("      Buffon's Needle Process Exits\n");
}





void  ellipseArea(int a, int b, int s) {
  srand(time(NULL));
  int sum = 0;
  for(int i = 0; i < s; i++) {
    double x = (double)rand()/RAND_MAX * a;
    double y = (double)rand()/RAND_MAX * b;
    double test =  x * x / (a * a) + y * y/ (b * b);
    if (test <= 1.0) sum++;
  }
  double area = 4 * a *  b *  (double)sum / s;
  
  printf("         Total random Number Paris %d\n", s);
  printf("         Semi-Major Axis Length %d\n", a);
  printf("         Semi-Major Axis Lenght %d\n", b);
  printf("         Total Hits %d\n", sum);
  printf("         Estimated Area is %f\n", area);
  printf("         Actual Area is %f\n", a * b * acos(-1.0));
  printf("         Ellipse Area Process Exits\n");
}









int main(int argc, char *argv[]) {


  int n = atoi(argv[1]);
  int r = atoi(argv[2]);
  int a = atoi(argv[3]);  
  int b = atoi(argv[4]);
  int s = atoi(argv[5]);
  

  int status;
  pid_t pid;
  printf("Main Proccess Started\n");
  printf("Fibonacci Input            =  %d\n", n);
  printf("Buffon's Needle Iteration  = %d\n", r);
  printf("\n");


  pid = fork();
  if(pid == 0) {                // child 0
    sleep(1);
    char buf[80];
    sprintf(buf, "Fibonacci Process Created\n");
    write(1, buf, strlen(buf));
    fib_print(n);
  }
  else {

    pid = fork();
    if (pid == 0) {               //child 1
      sleep(2);
      char buf[80];
      sprintf(buf, "Buffon's Needle Proccess Created\n");
      write(1, buf, strlen(buf));
      buffon(r); 
    }
    else {
      pid = fork();            //chide 2
      if (pid == 0) {
	sleep(3);
        char buf[80];
	sprintf(buf, "Ellipse Area Proccess Created\n");
	write(1, buf, strlen(buf));
	ellipseArea(a, b, s); 
      }
      else {
	wait(&status);
	wait(&status);
	wait(&status);
	printf("parent\n");
      }

    }
  }

  
  return 0;  
}
