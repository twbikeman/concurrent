#include <stdio.h>
#include <stdlib.h>

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
  int a[] = {1,2,9,10};
  int b[] = {4,5,6};
  int c[7] = {0};
  int x, i;
  for (i = 0; i < 3; i++) {
    x = search(a, 0, 3, b[i]);
    c[x + i] = b[i];
  }
  for (i = 0; i < 4; i++) {
    x = search(b, 0, 2, a[i]);
    c[x + i] = a[i];
  }

  for(i = 0; i < 7; i++)
    printf("%d\t", c[i]);

  return 0;
}
