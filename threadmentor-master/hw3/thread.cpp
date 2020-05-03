#include <iostream>
#include "thread.h"
#include <string.h>
#include <stdio.h>

using namespace std;

PrefixSumThread::PrefixSumThread(int *B, int N, int I, int J) : b(B), n(N), i(I), j(J){
  ThreadName.seekp(0, ios::beg);
  ThreadName << "PrefixSum" << "(" << i << "," << j << ")";
}

void PrefixSumThread::ThreadFunc() {
  Thread::ThreadFunc();
  int num;
  size_t result;
  int gap = 1;
  gap <<= i - 1;
  
    
  char message[80];
  char * message_ptr = message;
  num = sprintf(message_ptr, "      Thread %d Created\n",  j);
  message_ptr += num;


  if (j - gap < 0) {
    b[i * n + j] = b[(i-1) * n + j];

    num = sprintf(message_ptr, "      Thread %d copies x[%d]\n",  j, j);
    message_ptr += num;

    
  }
  else {
    b[i * n + j] = b[(i -1) * n + j] + b[(i-1) * n + j - gap];
    num = sprintf(message_ptr, "      Thread %d computes x[%d] + x[%d]\n",  j, j, j - gap);
    message_ptr += num;
    num = sprintf(message_ptr, "      Thread %d copies x[%d]\n", j, j);
    message_ptr += num;
  }

    num = sprintf(message_ptr, "      Thread %d exits\n",  j, i-1, j);
    message_ptr += num;
  
    result =  write(1, message, (size_t)(strlen(message)));

 
    Exit();
}
