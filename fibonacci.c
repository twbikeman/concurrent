#include <stdio.h>
#include <stdlib.h>

int fib(int x) {
  if (x == 1 || x == 2)
    return 1;
  else
    return fib(x-1) + fib(x-2);

}

int main() {


  int y = fib(10);
  printf("%d\n", y);
  return 0;
}
