#include <stdio.h>
#include <stdlib.h>


#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>



int smSearch(int *a, int left, int right, int x) {
  int middle =  (left + right) / 2;
  if (x < left) return left;
  if (x > right) return right + 1;
  if ( *(a + middle) >  x &&  x > *(a + middle - 1)) return middle;
  if (x < *(a + middle) )
    return search(a, left, middle - 1, x);
  else
    return search(a, middle + 1, right, x);
}



int main() {
  
  shmget()

  int a[] = {2, 4, 5, 7, 8, 9};
  int x = 90;
  int pos = smSearch(a, 0, 5, x);
  printf("%d\n", pos);



  

  
  return 0;

}
