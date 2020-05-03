#include <iostream>
#include "quicksort.h"

QuickSortThread::QuickSortThread(int Lowerbound, int Upperbound, int Array[]) : lowerbound(Lowerbound), upperbound(Upperbound), a(Array) {
  ThreadName.seekp(0, ios::beg);
  ThreadName << "Sorting" << '(' << Lowerbound << ':' << Upperbound << ')' << '\0';  
}

void QuickSortThread::ThreadFunc() {
  Thread::ThreadFunc();
  int pivot = a[upperbound];
  int left = lowerbound - 1, right = upperbound, tmp, pivotIndex;
  QuickSortThread *leftSortThread, *rightSortThread;
  if (lowerbound >= upperbound) Exit();
  while(left < right) {
    do {left++;} while (a[left] < pivot);
    do {right--;} while (a[right] > pivot);
    if (left < right) {
      tmp = a[left];
      a[left] = a[right];
      a[right] = tmp;
    }
  }

  pivotIndex = left;
  tmp = a[pivotIndex];
  a[pivotIndex] = pivot;
  a[upperbound] = tmp;

  leftSortThread = new QuickSortThread(lowerbound, pivotIndex -1, a);
  leftSortThread->Begin();
  rightSortThread = new QuickSortThread(pivotIndex + 1, upperbound, a);
  rightSortThread->Begin();

  leftSortThread->Join();
  rightSortThread->Join();
  Exit();
 
}



