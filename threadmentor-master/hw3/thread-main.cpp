#include <iostream>
#include "thread.h"

int main(int argc, char *argv[]) {

  
  int n;
  cin >> n;
  int log_n = n;
  int k = 0;
  while (log_n >>= 1) k++;
  
  int B[k+1][n] = {0};

  int i = 1;
  int j = 1;

  for (i = 0; i < n; i++)
    cin >> B[0][i];

  cout << "Concurrent Prefix Sum Computation\n" << endl;
  cout << "Number of input data = " << n << endl;
  
  cout << "Input array:\n" << endl;
  for (i = 0; i < n; i++)
    cout << "   " << B[0][i];
  cout << endl;

  
  PrefixSumThread *prefixSumThread[n];

  for (i = 1; i <= k; i++) {
          cout << "Run " << i << ":" << endl;
    for(j = 0; j < n; j++) {

      prefixSumThread[j] = new PrefixSumThread((int *)B, n, i, j);
      prefixSumThread[j]->Begin();
    }
    for (j = 0; j < n; j++) {
      prefixSumThread[j]->Join();
     
    }
    cout << "Result after run " << i << ":" << endl;
    for (j = 0; j < n; j++)
      cout << "   " << B[i][j];
    cout << endl;
  }

  cout << "\n\nFinal Result after run " << k << ":" << endl;
    for (j = 0; j < n; j++)
      cout << "   " << B[k][j];
    cout << endl;

  
  Exit();
  
  return 0;
}
