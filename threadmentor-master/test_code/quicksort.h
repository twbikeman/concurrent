#include "ThreadClass.h"

class QuickSortThread : public Thread {
 public:
  QuickSortThread(int Lowerbound, int Upperbound, int Array[]);
 private:
  void ThreadFunc();
  int lowerbound;
  int upperbound;
  int *a;
};
