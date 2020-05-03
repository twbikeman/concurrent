#include "ThreadClass.h"
class PrefixSumThread : public Thread {
 public:
  PrefixSumThread(int *B, int N, int I, int J);
 private:
  void ThreadFunc();
  int n;
  int i;
  int j;
  int *b;
};
